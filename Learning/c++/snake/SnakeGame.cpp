#include "SnakeGame.hpp"

void SnakeGame::generateFruit() {
    fruit.first = rand() % width;
    fruit.second = rand() % height;
}

void SnakeGame::draw() {
    std::system("clear");
    std::cout << "\033[H"; // Move cursor to the top-left corner
    for (int i = 0; i < width + 2; i++) std::cout << "#";
    std::cout << std::endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) std::cout << "#";
            if (i == snake[0].second && j == snake[0].first)
                std::cout << "O";
            else if (i == fruit.second && j == fruit.first)
                std::cout << "F";
            else {
                bool print = false;
                for (int k = 1; k < snake.size(); k++) {
                    if (snake[k].first == j && snake[k].second == i) {
                        std::cout << "o";
                        print = true;
                    }
                }
                if (!print) std::cout << " ";
            }
            if (j == width - 1) std::cout << "#";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < width + 2; i++) std::cout << "#";
    std::cout << std::endl;
    std::cout << "Score: " << score << std::endl;
}

int SnakeGame::kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

char SnakeGame::getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror ("tcsetattr ~ICANON");
    return buf;
}

SnakeGame::SnakeGame() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    width = w.ws_col / 2;
    height = w.ws_row / 2;
    score = 0;
    gameOver = false;
    dir = RIGHT;
    snake.push_back({ width / 2, height / 2 });
    generateFruit();
}

void SnakeGame::input() {
    if (kbhit()) {
        switch (getch()) {
            case 'w': if (dir != DOWN) dir = UP; break;
            case 's': if (dir != UP) dir = DOWN; break;
            case 'a': if (dir != RIGHT) dir = LEFT; break;
            case 'd': if (dir != LEFT) dir = RIGHT; break;
            case 'x': gameOver = true; break;
        }
    }
}

void SnakeGame::logic() {
    std::pair<int, int> prev = snake[0];
    std::pair<int, int> prev2;

    switch (dir) {
    case UP: snake[0].second--; break;
    case DOWN: snake[0].second++; break;
    case LEFT: snake[0].first--; break;
    case RIGHT: snake[0].first++; break;
    }

    for (int i = 1; i < snake.size(); i++) {
        prev2 = snake[i];
        snake[i] = prev;
        prev = prev2;
    }

    if (snake[0].first >= width) snake[0].first = 0; else if (snake[0].first < 0) snake[0].first = width - 1;
    if (snake[0].second >= height) snake[0].second = 0; else if (snake[0].second < 0) snake[0].second = height - 1;

    for (int i = 1; i < snake.size(); i++)
        if (snake[i] == snake[0])
            gameOver = true;

    if (snake[0] == fruit) {
        score += 10;
        snake.push_back({ -1, -1 });
        generateFruit();
    }
}

void SnakeGame::run() {
    while (!gameOver) {
        draw();
        input();
        logic();
        usleep(100000);
    }
}
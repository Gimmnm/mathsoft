#include "../src/common.h"
//gcc -lncurses -o snake snake.c

int main() { 
    int ch;
    int x[1000], y[1000];
    int vx = 0, vy = 1;
    int height = 0, width = 0;
    int speed = 150000;
    int length = 1;
    int egg = 0, pos_egg = 0;
    int* plate = NULL;
    int flag_ate = true;

    initscr();
    raw();
    noecho();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);   

    getmaxyx(stdscr, height, width);
    height = height / 2;
    width = width / 2;
    for (int i = 0; i < width + 1; i++) {
        mvaddch(0, i, '#');
        mvaddch(height, i, '#');
    }
    for (int i = 0; i < height; i++) {
        mvaddch(i, 0, '#');
        mvaddch(i, width, '#');
    }
    
    y[0] = height / 2;
    x[0] = width / 2;
    mvaddch(y[0], x[0], '*');

    if ((plate = (int*) malloc(width * height * sizeof(int))) == NULL) {
        printf("Outof memory!\n");
        exit(-1); 
    }

    while (1) {
        ch = getch();
        switch (ch)
        {
            case KEY_UP:
                if (vy != 1) {
                    vy = -1;
                    vx = 0;
                }
                break;
            case KEY_DOWN:
                if (vy != -1) {
                    vy = 1;
                    vx = 0;
                }
                break;
            case KEY_LEFT:
                if (vx != 1) {
                    vy = 0;
                    vx = -1;
                }
                break;
            case KEY_RIGHT:
                if (vx != -1) {
                    vy = 0;
                    vx = 1;
                }
                break;
            case 'q':
                endwin();
                free(plate);
                return 0;
        }

        usleep(speed);
        speed -= 100;

        if (length < 4)
            length ++;

        mvaddch(y[length - 1], x[length - 1], ' ');
        for (int i = length; i > 0; i--) {
            x[i] = x[i - 1];
            y[i] = y[i - 1];
        }
        x[0] += vx;
        y[0] += vy;
 
        chtype ch = mvinch(y[0], x[0]);
        ch = ch & A_CHARTEXT;
        char c = (char) ch;
        if (c == '$') {
            flag_ate = true;
            length ++;
        } else if (c == '*' || c == '#')
            break;

        mvaddch(y[0], x[0], '*');
        
        if (flag_ate == true) {
            for (int i = 0; i < (width - 2) * (height - 2); i++)
                plate[i] = 1;
            for (int i = 0; i < length; i++)
                plate[y[i] * (width - 2) + x[i]] = 0;
            egg = rand() % ((width - 2) * (height - 2) - length);
            for (pos_egg = 0; egg != 1; pos_egg++)
                egg = egg - plate[pos_egg];
            mvaddch(1 + pos_egg / (width - 2), 1 + pos_egg % (width - 2), '$');
            flag_ate = false;
        }
        refresh();
    }
}
#include <iostream>

// #define LOG(x) std::cout << x << std::endl

// class Player {
// public:
//     int x, y;
//     int speed;

//     void Move(int xa, int ya) {
//         x += xa * speed;
//         y += ya * speed;
//     }
 
// };

class Log {
public:
    // const int LogLevelError = 0;
    // const int LogLevelWarning = 1;
    // const int LogLevelInfo = 2;
    enum Level {
        LevelError = 0, LevelWarning, LevelInfo
    };
private:
    // int m_LogLevel = LogLevelInfo;
    Level m_LogLevel = LevelInfo;
public:
    void SetLevel(Level level) {
        m_LogLevel = level;
    }

    void Error(const char* message) {
        if (m_LogLevel >= LevelError)
            std::cout << "[ERROR]: " << message << std::endl;
    }

    void Warn(const char* message) {
        if (m_LogLevel >= LevelWarning)
            std::cout << "[WARNING]: " << message << std::endl;
    }

    void Info(const char* message) {
        if (m_LogLevel >= LevelInfo)
            std::cout << "[INFO]: " << message << std::endl;
    }
};

int main() {

    // Player player;
    // player.x = 5;
    // player.Move(1, 2);

    Log log;
    log.SetLevel(Log::LevelWarning); // why Log:: ? not log:: ? 
    log.Warn("Hello");

    

    std::cin.get();
    return 0;
}
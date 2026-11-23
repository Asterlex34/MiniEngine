#ifndef MINILOGGER_H
#define MINILOGGER_H

#include <cstdio>


// Available logging priority levels
enum LogPriority {
    TracePriority,
    DebugPriority,
    InfoPriority,
    WarnPriority,
    ErrorPriority,
    CriticalPriority    
};

// Static Logger
class MiniLogger {
    public:
        MiniLogger() = delete;
        MiniLogger(const MiniLogger&) = delete;
        MiniLogger operator=(const MiniLogger&) = delete;
    
        // Minimun logging priority
        static inline void SetPriority(LogPriority npriority) { priority = npriority; }

        // Print a formatted log message to stdout
        template<typename... Args>
        static void Log(LogPriority level, const char* module, const char* message, Args... args) {
            if (level < priority) return;
            
            std::printf("[%s] [%s] ", LevelToString(level), module);
            std::printf(message + "\n", args...);
        }

    private:
        // Default logging priority 
        static inline LogPriority priority = InfoPriority;

        // Convert logging priotity to string
        static inline const char* LevelToString(LogPriority level) {
            switch (level) {
                case TracePriority: return "TRACE";
                case DebugPriority: return "DEBUG";
                case InfoPriority: return "INFO";
                case WarnPriority: return "WARN";
                case ErrorPriority: return "ERROR";
                case CriticalPriority: return "CRITICAL";
                default: return "UNKNOWN";  // dih???
            }
        }
};

#endif /* MINILOGGER_H */

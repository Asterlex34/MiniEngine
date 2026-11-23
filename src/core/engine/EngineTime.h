#ifndef ENGINETIME_H
#define ENGINETIME_H

#include <stdint.h>


namespace MiniEngine {
    // Static class for providing time-related information regarding the game engine
    class EngineTime {
        public:
            EngineTime() = delete;
            EngineTime(const EngineTime&) = delete;
            EngineTime& operator=(const EngineTime&) = delete;

            static inline float deltaTime() { return _deltaTime; }
            static inline float unscaledDeltaTime() { return _unscaledDeltaTime; }
            static inline float timeScale() { return _timeScale; }
            static inline float realTimeSinceStartup() { return _realTimeSinceStartup; }
            static inline float gameTime() { return _gameTime; }
            static inline uint32_t frameCount() { return _frameCount; }

        private:
            // Time elapsed during the previous frame scaled by dt
            static inline float _deltaTime = 0.0f;

            // Time elapsed during the previous frame unscaled
            static inline float _unscaledDeltaTime = 0.0f;

            // Multiplier for game-time progression
            static inline float _timeScale = 1.0f;

            // Total real-time elapsed since engine startup
            static inline float _realTimeSinceStartup = 0.0f;

            // Total accumulated game time affected by timeScale
            static inline float _gameTime = 0.0f;

            // Total number of frames processed since engine startup
            static inline uint32_t _frameCount = 0;
        
        friend class Engine;
    };
}

#endif /* ENGINETIME_H */

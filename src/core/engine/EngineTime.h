#ifndef ENGINETIME_H
#define ENGINETIME_H

#include <stdint.h>

namespace MiniEngine
{
    class EngineTime
    {
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

            friend class Engine;

        private:
            static inline float _deltaTime = 0.0f;
            static inline float _unscaledDeltaTime = 0.0f;
            static inline float _timeScale = 1.0f;
            static inline float _realTimeSinceStartup = 0.0f;
            static inline float _gameTime = 0.0f;
            static inline uint32_t _frameCount = 0;
    };
}

#endif /* ENGINETIME_H */

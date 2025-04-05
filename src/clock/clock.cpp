#include "clock.hpp"

#include <chrono>

namespace game_clock {

class Clock {
 private:
    using clock = std::chrono::high_resolution_clock;
    using time_point = std::chrono::time_point<clock>;
    using duration = std::chrono::duration<double>;
 public:
    Clock();
    void start();
    double tickSeconds();
    double getLastTick();
 private:
    time_point last_point_;
    duration last_tick_;
};

Clock::Clock()
    : last_point_(clock::now()), last_tick_(0) {
}

void Clock::start() {
    last_point_ = clock::now();
}

double Clock::tickSeconds() {
    auto now = clock::now();
    last_tick_ = now - std::exchange(last_point_, now);
    return last_tick_.count();
}

double Clock::getLastTick() {
    return last_tick_.count();
}

static Clock GAME_CLOCK;

void start() {
    GAME_CLOCK.start();
}

void tick() {
    GAME_CLOCK.tickSeconds();
}

double getLastTick() {
    return GAME_CLOCK.getLastTick();
}

} // namespace game_clock
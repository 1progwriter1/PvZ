#ifndef PLANTSVSZOMBIES_SRC_CLOCK_CLOCK_HPP_
#define PLANTSVSZOMBIES_SRC_CLOCK_CLOCK_HPP_

#include <chrono>

namespace game_clock {

void start();

void tick();

double getLastTick();

} // namespace game_clock

#endif //PLANTSVSZOMBIES_SRC_CLOCK_CLOCK_HPP_

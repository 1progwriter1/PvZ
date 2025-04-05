#ifndef PLANTSVSZOMBIES_SRC_CONFIG_CONFIG_HPP_
#define PLANTSVSZOMBIES_SRC_CONFIG_CONFIG_HPP_

#include <cstddef>
#include <sys/point.hpp>
#include <filesystem>
#include <chrono>

using namespace std::chrono_literals;

namespace config {

namespace screen {

static const size_t WIDTH = 1600;
static const size_t HEIGHT = 900;

} // namespace screen

namespace arena {

const std::filesystem::path ARENA_LAWN = "../assets/arena/arena_lawn.png";
constexpr float SCALE = static_cast<float>(screen::HEIGHT) / 1538;

constexpr sys::Point<size_t> FIELD_SIZE = {95, 110};
constexpr sys::Point<float> FIELD_LEFT_CORNER = {629, 239};

inline constexpr sys::Point<float> getField(sys::Point<int> field) {
    if (field.x < 0 || field.x > 8 || field.y < 0 || field.y > 4) {
        throw std::out_of_range("field");
    }

    return FIELD_LEFT_CORNER + sys::Point<float>({FIELD_SIZE.x * static_cast<float>(field.x), FIELD_SIZE.y * static_cast<float>(field.y)});
}

} // namespace arena

namespace characters {

namespace pea_shooter {

constexpr float SCALE = static_cast<float>(arena::FIELD_SIZE.x) / 442;
const std::filesystem::path TEXTURE = "../assets/characters/plants/pea_shooter.png";

constexpr double SHOOT_PERIOD = 2; // sec

const std::filesystem::path SHELL_TEXTURE = "../assets/characters/plants/pea.png";
constexpr float SHELL_SCALE = static_cast<float>(arena::FIELD_SIZE.x) / 64 / 3;
constexpr double SPEED = arena::FIELD_SIZE.x * 4; // pixels/sec

} // namespace pea_shooter

namespace zombie {

constexpr float SCALE = static_cast<float>(arena::FIELD_SIZE.x) / 1454;
const std::filesystem::path TEXTURE = "../assets/characters/zombies/zombie.png";

constexpr double SPEED = arena::FIELD_SIZE.x / 5; // pixels/sec

}

} // namespace characters

} // namespace config

#endif //PLANTSVSZOMBIES_SRC_CONFIG_CONFIG_HPP_

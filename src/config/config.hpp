#ifndef PLANTSVSZOMBIES_SRC_CONFIG_CONFIG_HPP_
#define PLANTSVSZOMBIES_SRC_CONFIG_CONFIG_HPP_

#include <cstddef>
#include <sys/point.hpp>
#include <filesystem>

namespace config {

namespace screen {

static const size_t WIDTH = 1600;
static const size_t HEIGHT = 900;

} // namespace screen

namespace arena {

const std::filesystem::path ARENA_LAWN = "../assets/arena/arena_lawn.png";
constexpr float SCALE = static_cast<float>(screen::HEIGHT) / 1538;

constexpr sys::Point<size_t> FIELD_SIZE = {70, 70};
constexpr sys::Point<int> FIELD_LEFT_CORNER = {635, 245};

inline constexpr sys::Point<int> getField(sys::Point<int> field) {
    return FIELD_LEFT_CORNER + sys::Point<int>({static_cast<int>(FIELD_SIZE.x) * field.x, static_cast<int>(FIELD_SIZE.y) * field.y});
}

} // namespace arena

namespace characters {

namespace pea_shooter {

constexpr float SCALE = static_cast<float>(arena::FIELD_SIZE.x) / 442;
const std::filesystem::path TEXTURE = "../assets/characters/plants/pea_shooter.png";

} // namespace pea_shooter

} // namespace characters

} // namespace config

#endif //PLANTSVSZOMBIES_SRC_CONFIG_CONFIG_HPP_

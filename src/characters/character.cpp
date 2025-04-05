#include "character.hpp"

namespace character {

Character::Character(const std::filesystem::path &texture_path)
    : draw::Textured(texture_path) {}

} // namespace character

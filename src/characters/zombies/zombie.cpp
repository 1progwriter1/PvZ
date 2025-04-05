#include "zombie.hpp"

#include <config/config.hpp>
#include <clock/clock.hpp>
#include <iostream>

namespace character {

std::unique_ptr<Character> createZombie() {
    std::unique_ptr<Zombie> zombie = std::make_unique<Zombie>(config::characters::zombie::TEXTURE);
    zombie->setScale({config::characters::zombie::SCALE, config::characters::zombie::SCALE});
    return zombie;
}

Zombie::Zombie(const std::filesystem::path &texture_path)
    : Character(texture_path) {}


void Zombie::move() {
    double elapsed = game_clock::getLastTick();
    sys::Point pos = getPosition();
    pos.x -= elapsed * config::characters::zombie::SPEED;
    setPosition(pos);
}

} // namespace character
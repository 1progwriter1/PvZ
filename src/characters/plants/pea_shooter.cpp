#include "pea_shooter.hpp"

#include <arena/arena.hpp>
#include <config/config.hpp>
#include <clock/clock.hpp>

#include <iostream>

namespace character {

std::unique_ptr<Character> createPlantPeaShooter(sys::Point<int> field) {
    std::unique_ptr<PeaShooter>
        pea_shooter = std::make_unique<PeaShooter>(config::characters::pea_shooter::TEXTURE, field);
    pea_shooter->setScale({config::characters::pea_shooter::SCALE, config::characters::pea_shooter::SCALE});
    return pea_shooter;
}

std::unique_ptr<Shell> createShellPea() {
    std::unique_ptr<Pea> pea = std::make_unique<Pea>(config::characters::pea_shooter::SHELL_TEXTURE);
    pea->setScale({config::characters::pea_shooter::SHELL_SCALE, config::characters::pea_shooter::SHELL_SCALE});
    return pea;
}

PeaShooter::PeaShooter(const std::filesystem::path &texture_path, sys::Point<int> field)
    : Character(texture_path), field_(field) {
}

void PeaShooter::move() {
    static double elapsed = 0;
    elapsed += game_clock::getLastTick();

    if (elapsed >= config::characters::pea_shooter::SHOOT_PERIOD) {
        playground::getArena().addShell(createShellPea(), field_);
        elapsed = 0;
    }
}

Pea::Pea(const std::filesystem::path &path)
    : Shell(path) {
}

void Pea::fly() {
    double elapsed = game_clock::getLastTick();
    sys::Point pos = getPosition();
    pos.x += elapsed * config::characters::pea_shooter::SPEED;
    setPosition(pos);
}

} // character
#include "plant.hpp"

#include <cassert>
#include <config/config.hpp>

namespace character {

Plant::Plant(const std::filesystem::path& texture_path)
    : texture_(std::make_unique<sf::Texture>()), sprite_(std::make_unique<sf::Sprite>()) {
    texture_->loadFromFile(texture_path);
    sprite_->setTexture(*texture_);
}

void Plant::draw(sf::RenderWindow &window) {
    window.draw(*sprite_);
}

void Plant::setScale(const sys::Point<float> scale) {
    sprite_->setScale(scale.x, scale.y);
}

void Plant::setPosition(sys::Point<int> pos) {
    sprite_->setPosition(static_cast<float>(pos.x), static_cast<float>(pos.y));
}

void Plant::setSize(sys::Point<size_t> size) {
    assert(0 && "Not implemented");
}

sys::Point<int> Plant::getPosition() const {
    sf::Vector2f pos = sprite_->getPosition();
    return {static_cast<int>(pos.x), static_cast<int>(pos.y)};
}

sys::Point<size_t> Plant::getSize() const {
    assert(0 && "Not implemented");
    return {};
}

std::unique_ptr<Plant> createPlantPeaShooter() {
    std::unique_ptr<Plant> pea_shooter = std::make_unique<Plant>(config::characters::pea_shooter::TEXTURE);
    pea_shooter->setScale({config::characters::pea_shooter::SCALE, config::characters::pea_shooter::SCALE});
    return pea_shooter;
}

} // character
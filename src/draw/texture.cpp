#include "texture.hpp"

namespace draw {

Textured::Textured(const std::filesystem::path &texture_path)
    :   texture_(std::make_unique<sf::Texture>()) {
    if (!texture_->loadFromFile(texture_path)) {
        throw std::runtime_error("failed to load texture");
    }
    sprite_ = std::make_unique<sf::Sprite>(*texture_);
}

void Textured::draw(sf::RenderWindow &window) {
    window.draw(*sprite_);
}

void Textured::setScale(const sys::Point<float> scale) {
    sprite_->setScale(sf::Vector2f(scale.x, scale.y));
}

void Textured::setPosition(sys::Point<float> pos) {
    sprite_->setPosition(sf::Vector2f(pos.x, pos.y));
}

void Textured::setSize(sys::Point<size_t> size) {
    assert(0 && "Not implemented");
}

sys::Point<float> Textured::getPosition() const {
    sf::Vector2f pos = sprite_->getPosition();
    return {pos.x, pos.y};
}

sys::Point<size_t> Textured::getSize() const {
    auto size = texture_->getSize();
    auto scale = sprite_->getScale();

    return {static_cast<size_t>(static_cast<float>(size.x) * scale.x), static_cast<size_t>(static_cast<float>(size.y) * scale.y)};
}

} // namespace draw
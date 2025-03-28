#include "arena.hpp"

#include <config/config.hpp>

namespace playground {

Arena::Arena()
    : texture_(std::make_unique<sf::Texture>()), sprite_(std::make_unique<sf::Sprite>()) {
    texture_->loadFromFile(config::arena::ARENA_LAWN);
    sprite_->setTexture(*texture_);
    sprite_->setScale(sf::Vector2f(config::arena::SCALE, config::arena::SCALE));
}

void Arena::draw(sf::RenderWindow &window) {
    window.draw(*sprite_);

    for (auto &character : characters_) {
        character->draw(window);
    }
}

void Arena::addCharacter(std::unique_ptr<character::Character> character, sys::Point<int> field) {
    character->setPosition(config::arena::getField(field));
    characters_.push_back(std::move(character));
}

} // namespace playground
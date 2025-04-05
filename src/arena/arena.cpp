#include "arena.hpp"

#include <config/config.hpp>
#include <log/logger.hpp>
#include <iostream>

namespace playground {

Arena::Arena()
    : texture_(std::make_unique<sf::Texture>()) {
    if (!texture_->loadFromFile(config::arena::ARENA_LAWN)) {
        throw std::runtime_error("failed to load texture");
    }
    sprite_ = std::make_unique<sf::Sprite>(*texture_);
    sprite_->setScale(sf::Vector2f(config::arena::SCALE, config::arena::SCALE));

    characters_.resize(5);
    shells_.resize(5);
}

Arena::~Arena() {
}

void Arena::draw(sf::RenderWindow &window) {
    window.draw(*sprite_);

    for (auto &line : characters_) {
        for (auto &character : line) {
            character->draw(window);
        }
    }
    for (auto &line : shells_) {
        for (auto &shell : line) {
            shell->draw(window);
        }
    }
}

void Arena::addCharacter(std::unique_ptr<character::Character> character, sys::Point<int> field) {
    sys::Point pos = config::arena::getField(field);
    pos.y -= static_cast<float>(character->getSize().y) - config::arena::FIELD_SIZE.y;
    character->setPosition(pos);
    characters_[field.y].push_back(std::move(character));
}

void Arena::addShell(std::unique_ptr<character::Shell> shell, sys::Point<int> field) {
    sys::Point pos = config::arena::getField(field);
    shell->setPosition(pos);
    shells_[field.x].push_back(std::move(shell));
}

void Arena::action() {
    for (auto &line : characters_) {
        for (auto &character : line) {
            character->move();
        }
    }
    for (auto &line : shells_) {
        for (auto &shell : line) {
            shell->fly();
        }
    }
}

Arena &Arena::getInstance() {
    static Arena arena;
    return arena;
}

Arena &getArena() {
    return Arena::getInstance();
}

} // namespace playground
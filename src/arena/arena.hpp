#ifndef PLANTSVSZOMBIES_SRC_ARENA_ARENA_HPP_
#define PLANTSVSZOMBIES_SRC_ARENA_ARENA_HPP_

#include <draw/drawable.hpp>
#include <characters/character.hpp>

#include <SFML/Graphics.hpp>

namespace playground {

class Arena : public draw::Drawable {
 public:
    Arena();

    void draw(sf::RenderWindow &window) override;
    void addCharacter(std::unique_ptr<character::Character> character, sys::Point<int> field);
 private:
    std::unique_ptr<sf::Texture> texture_;
    std::unique_ptr<sf::Sprite> sprite_;

    std::vector<std::unique_ptr<character::Character>> characters_;
};

} // namespace playground

#endif //PLANTSVSZOMBIES_SRC_ARENA_ARENA_HPP_

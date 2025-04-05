#ifndef PLANTSVSZOMBIES_SRC_ARENA_ARENA_HPP_
#define PLANTSVSZOMBIES_SRC_ARENA_ARENA_HPP_

#include <draw/drawable.hpp>
#include <characters/character.hpp>
#include <characters/shell.hpp>
#include <list>

#include <SFML/Graphics.hpp>

namespace playground {

class Arena : public draw::Drawable {
 public:
    ~Arena();
    void draw(sf::RenderWindow &window) override;
    void action();

    void addCharacter(std::unique_ptr<character::Character> character, sys::Point<int> field);
    void addShell(std::unique_ptr<character::Shell> shell, sys::Point<int> field);

    static Arena &getInstance();

 private:
    Arena();

    std::unique_ptr<sf::Texture> texture_;
    std::unique_ptr<sf::Sprite> sprite_;

    std::vector<std::list<std::unique_ptr<character::Character>>> characters_;
    std::vector<std::list<std::unique_ptr<character::Shell>>> shells_;
};


Arena &getArena();

} // namespace playground

#endif //PLANTSVSZOMBIES_SRC_ARENA_ARENA_HPP_

#ifndef PLANTSVSZOMBIES_SRC_CHARACTERS_ZOMBIES_ZOMBIE_HPP_
#define PLANTSVSZOMBIES_SRC_CHARACTERS_ZOMBIES_ZOMBIE_HPP_

#include <characters/character.hpp>
#include <filesystem>
#include <SFML/Graphics.hpp>

namespace character {

class Zombie : public Character {
 public:
    explicit Zombie(const std::filesystem::path &texture_path);

    void move() override;
 private:
};

std::unique_ptr<Character> createZombie();

} // namespace character

#endif //PLANTSVSZOMBIES_SRC_CHARACTERS_ZOMBIES_ZOMBIE_HPP_

#ifndef PLANTSVSZOMBIES_SRC_PLANTS_PLANT_HPP_
#define PLANTSVSZOMBIES_SRC_PLANTS_PLANT_HPP_

#include <characters/character.hpp>
#include <filesystem>
#include <SFML/Graphics.hpp>
#include <sys/point.hpp>
#include <characters/shell.hpp>

namespace character {

std::unique_ptr<Character> createPlantPeaShooter(sys::Point<int> field);
std::unique_ptr<Shell> createShellPea();

class PeaShooter : public Character {
 public:
    PeaShooter(const std::filesystem::path& texture_path, sys::Point<int> field);

    void move() override;
 private:
    sys::Point<int> field_;
};

class Pea : public Shell {
 public:
    explicit Pea(const std::filesystem::path &path);

    void fly() override;
 private:
};


} // character

#endif //PLANTSVSZOMBIES_SRC_PLANTS_PLANT_HPP_

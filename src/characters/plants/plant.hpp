#ifndef PLANTSVSZOMBIES_SRC_PLANTS_PLANT_HPP_
#define PLANTSVSZOMBIES_SRC_PLANTS_PLANT_HPP_

#include <characters/character.hpp>
#include <draw/drawable.hpp>
#include <filesystem>
#include <SFML/Graphics.hpp>
#include <sys/point.hpp>

namespace character {

class Plant : public Character {
 public:
    Plant(const std::filesystem::path& texture_path);

    void draw(sf::RenderWindow &window) override;

    void setScale(const sys::Point<float> scale) override;
    void setPosition(sys::Point<int> pos) override;
    void setSize(sys::Point<size_t> size) override;

    sys::Point<int> getPosition() const override;
    sys::Point<size_t> getSize() const override;
 private:
    std::unique_ptr<sf::Texture> texture_;
    std::unique_ptr<sf::Sprite> sprite_;
};

std::unique_ptr<Plant> createPlantPeaShooter();

} // character

#endif //PLANTSVSZOMBIES_SRC_PLANTS_PLANT_HPP_

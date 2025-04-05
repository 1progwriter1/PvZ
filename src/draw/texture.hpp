#ifndef PLANTSVSZOMBIES_SRC_DRAW_TEXTURE_HPP_
#define PLANTSVSZOMBIES_SRC_DRAW_TEXTURE_HPP_

#include "drawable.hpp"

#include <filesystem>
#include <SFML/Graphics.hpp>
#include <sys/point.hpp>

namespace draw {

class Textured : public Drawable {
 public:
    Textured(const std::filesystem::path &texture_path);
    virtual ~Textured() = default;

    void draw(sf::RenderWindow &window) override;

    void setScale(const sys::Point<float> scale);
    void setPosition(sys::Point<float> pos);
    void setSize(sys::Point<size_t> size);

    sys::Point<float> getPosition() const;
    sys::Point<size_t> getSize() const;
 private:
    std::unique_ptr<sf::Texture> texture_;
    std::unique_ptr<sf::Sprite> sprite_;
};

} // namespace draw

#endif //PLANTSVSZOMBIES_SRC_DRAW_TEXTURE_HPP_

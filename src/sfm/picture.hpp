#ifndef PLANTSVSZOMBIES_SRC_SFM_SPRITE_HPP_
#define PLANTSVSZOMBIES_SRC_SFM_SPRITE_HPP_

#include <SFML/Graphics.hpp>

#include <filesystem>

#include "drawable.hpp"
#include "utils/vector.hpp"

namespace sfm {

class Picture : public Drawable {
 public:
    explicit Picture(std::filesystem::path& path);

    void draw(RenderWindow &window) override;

    Vector<unsigned int> getSize() const;
    Vector<int> getPos() const;

    void setSize(Vector<size_t> size);
    void setPos(Vector<int> pos);
 private:
    sf::Texture texture_;
    sf::Sprite sprite_;
};

} // namespace smf

#endif //PLANTSVSZOMBIES_SRC_SFM_SPRITE_HPP_

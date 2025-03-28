#ifndef PLANTSVSZOMBIES_SRC_DRAWABLE_DRAWABLE_HPP_
#define PLANTSVSZOMBIES_SRC_DRAWABLE_DRAWABLE_HPP_

#include <SFML/Graphics/RenderWindow.hpp>
namespace draw {

class Drawable {
 public:
    virtual ~Drawable() = default;

    virtual void draw(sf::RenderWindow &window) = 0;
};

} // namespace draw

#endif //PLANTSVSZOMBIES_SRC_DRAWABLE_DRAWABLE_HPP_

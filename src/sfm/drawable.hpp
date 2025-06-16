#ifndef PLANTSVSZOMBIES_SRC_SFM_DRAWABLE_HPP_
#define PLANTSVSZOMBIES_SRC_SFM_DRAWABLE_HPP_

#include "render_window.hpp"

namespace sfm {

class Drawable {
 public:
    virtual void draw(RenderWindow& window) = 0;
 protected:
    sf::RenderWindow& getSFMLWindow(RenderWindow& window) {
        return window.getSFMLWindow();
    }
};

} // namespace sfm

#endif //PLANTSVSZOMBIES_SRC_SFM_DRAWABLE_HPP_

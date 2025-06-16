#ifndef PLANTSVSZOMBIES_SRC_SFM_RENDER_WINDOW_HPP_
#define PLANTSVSZOMBIES_SRC_SFM_RENDER_WINDOW_HPP_

#include <SFML/Graphics.hpp>

#include "events.hpp"

namespace sfm {

class Drawable;

class RenderWindow {
    friend Drawable;
 public:
    RenderWindow(unsigned int width, unsigned int height);

    void draw(Drawable* drawable);
    void display();
    void close();

    bool isOpened();

    std::optional<sfm::Event> getEvent();
 private:
    sf::RenderWindow& getSFMLWindow();

 private:
    sf::RenderWindow window_;
};

} // namespace sfm

#endif //PLANTSVSZOMBIES_SRC_SFM_RENDER_WINDOW_HPP_

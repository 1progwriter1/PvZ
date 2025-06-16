#include "render_window.hpp"

#include "drawable.hpp"

namespace sfm {

RenderWindow::RenderWindow(unsigned int width, unsigned int height)
    : window_(sf::VideoMode({width, height}), "Main Window") {}

void RenderWindow::draw(sfm::Drawable *drawable) {
    drawable->draw(*this);
}

bool RenderWindow::isOpened() {
    return window_.isOpen();
}

void RenderWindow::display() {
    window_.display();
}

sf::RenderWindow &RenderWindow::getSFMLWindow() {
    return window_;
}

std::optional<sfm::Event> RenderWindow::getEvent() {
    return window_.pollEvent();
}

void RenderWindow::close() {
    window_.close();
}

} // namespace sfm
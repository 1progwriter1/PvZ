#include "picture.hpp"

namespace sfm {

Picture::Picture(std::filesystem::path &path)
    : texture_(path), sprite_(texture_) {}

void Picture::draw(sfm::RenderWindow &window) {
    auto &sf_window = getSFMLWindow(window);

    sf_window.draw(sprite_);
}

Vector<int> Picture::getPos() const {
    auto pos = sprite_.getPosition();

    return {static_cast<int>(pos.x), static_cast<int>(pos.y)};
}

Vector<unsigned int> Picture::getSize() const {
    return Vector(texture_.getSize());
}

void Picture::setPos(Vector<int> pos) {
    sprite_.setPosition({static_cast<float>(pos.x), static_cast<float>(pos.y)});
}

void Picture::setSize(Vector<size_t> size) {
    auto texture_size = getSize();
    Vector<float> scale = {static_cast<float>(size.x) / texture_size.x, static_cast<float>(size.y) / texture_size.y};
    sprite_.setScale({scale.x, scale.y});
}



} // namespace sfm
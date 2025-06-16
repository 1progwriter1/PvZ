#ifndef PLANTSVSZOMBIES_SRC_SFM_UTILS_VECTOR_HPP_
#define PLANTSVSZOMBIES_SRC_SFM_UTILS_VECTOR_HPP_

#include <SFML/Graphics.hpp>

namespace sfm {

template<typename T>
struct Vector {
    T x = T();
    T y = T();

    Vector(T init_x, T init_y)
        : x(init_x), y(init_y) {}

    explicit Vector(sf::Vector2<T> vec)
        : x(vec.x), y(vec.y) {}
};

} // namespace sfm

#endif //PLANTSVSZOMBIES_SRC_SFM_UTILS_VECTOR_HPP_

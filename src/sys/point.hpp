#ifndef PLANTSVSZOMBIES_SRC_SYS_POINT_HPP_
#define PLANTSVSZOMBIES_SRC_SYS_POINT_HPP_

namespace sys {

template<typename T>
struct Point {
    Point() = default;
    constexpr Point(T x, T y);

    T x;
    T y;
};

template<typename T> constexpr
Point<T>::Point(T x_init, T y_init)
    :   x(x_init), y(y_init) {
}

template<typename T>
Point<T> operator+(Point<T> lhs, Point<T> rhs) {
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}

} // namespace sys

#endif //PLANTSVSZOMBIES_SRC_SYS_POINT_HPP_

#ifndef PLANTSVSZOMBIES_SRC_CHARACTERS_CHARACTER_HPP_
#define PLANTSVSZOMBIES_SRC_CHARACTERS_CHARACTER_HPP_

#include <draw/drawable.hpp>
#include <sys/point.hpp>

namespace character {

class Character : public draw::Drawable {
 public:
    virtual ~Character() = default;

    virtual void setScale(const sys::Point<float> scale) = 0;

    virtual void setPosition(const sys::Point<int> pos) = 0;
    virtual void setSize(const sys::Point<size_t> size) = 0;
    virtual sys::Point<int> getPosition() const = 0;
    virtual sys::Point<size_t> getSize() const = 0;
};

} // namespace playground

#endif //PLANTSVSZOMBIES_SRC_CHARACTERS_CHARACTER_HPP_

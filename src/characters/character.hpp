#ifndef PLANTSVSZOMBIES_SRC_CHARACTERS_CHARACTER_HPP_
#define PLANTSVSZOMBIES_SRC_CHARACTERS_CHARACTER_HPP_

#include <draw/texture.hpp>
#include <filesystem>
#include <sys/point.hpp>
#include <SFML/Graphics.hpp>

namespace character {

class Character : public draw::Textured {
 public:
    Character(const std::filesystem::path& texture_path);
    virtual ~Character() = default;

    virtual void move() = 0;
 private:
};

} // namespace playground

#endif //PLANTSVSZOMBIES_SRC_CHARACTERS_CHARACTER_HPP_

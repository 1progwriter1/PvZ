#ifndef PLANTSVSZOMBIES_SRC_CHARACTERS_SHELL_HPP_
#define PLANTSVSZOMBIES_SRC_CHARACTERS_SHELL_HPP_

#include <draw/texture.hpp>
#include <sys/point.hpp>
#include <filesystem>
#include <SFML/Graphics.hpp>

namespace character {

class Shell : public draw::Textured {
 public:
    Shell(const std::filesystem::path &texture_path);
    virtual ~Shell() = default;

    virtual void fly() = 0;
};

} // namespace shell

#endif //PLANTSVSZOMBIES_SRC_CHARACTERS_SHELL_HPP_

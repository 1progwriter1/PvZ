#include "shell.hpp"

namespace character {

Shell::Shell(const std::filesystem::path &texture_path)
    : draw::Textured(texture_path) {}

} // namespace character
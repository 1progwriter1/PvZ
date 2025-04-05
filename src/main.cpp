#include <iostream>
#include <SFML/Graphics.hpp>

#include <arena/arena.hpp>
#include <config/config.hpp>
#include <characters/plants/pea_shooter.hpp>
#include <characters/zombies/zombie.hpp>
#include <clock/clock.hpp>

int main() {

    sf::RenderWindow
        window(sf::VideoMode(sf::Vector2<unsigned int>(config::screen::WIDTH, config::screen::HEIGHT)), "PvZ");

    playground::getArena().addCharacter(character::createPlantPeaShooter({0, 0}), {0, 0});
    playground::getArena().addCharacter(character::createZombie(), {8, 0});
    playground::getArena().addCharacter(character::createZombie(), {7, 1});

    game_clock::start();

    while (window.isOpen()) {

        game_clock::tick();

        while (std::optional<sf::Event> event = window.pollEvent()) {
            if (event.value().is<sf::Event::Closed>()) {
                window.close();
            }
        }

        playground::getArena().action();

        window.clear();
        playground::getArena().draw(window);
        window.display();
    }

    return 0;
}

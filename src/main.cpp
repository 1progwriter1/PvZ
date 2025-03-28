#include <iostream>
#include <SFML/Graphics.hpp>

#include <arena/arena.hpp>
#include <config/config.hpp>
#include <characters/plants/plant.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode(config::screen::WIDTH, config::screen::HEIGHT), "PvZ");

    playground::Arena arena;
    for (int i =0 ; i < 9; i++) {
        arena.addCharacter(character::createPlantPeaShooter(), {0, i});
    }

    while (window.isOpen()) {

        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        arena.draw(window);
        window.display();
    }

    return 0;
}

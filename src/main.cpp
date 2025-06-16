#include <sfm/graphics.hpp>

int main() {
    sfm::RenderWindow window(800, 600);

    while (window.isOpened()) {
        while (auto event = window.getEvent()) {
            if (event->is<sfm::Event::Closed>()) {
                window.close();
            }
        }
    }

    return 0;
}

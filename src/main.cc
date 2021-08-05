#include <SFML/Main.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <stdio.h>

int main() {
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Game", sf::Style::Fullscreen);
	window.setVerticalSyncEnabled(true);
	sf::RenderTexture canvas;
	canvas.create(window.getSize().x,window.getSize().y);
	canvas.clear();

	bool MouseButtonStates[2] = {0,0};
	float MousePos[2] = {0,0};

	while (window.isOpen()) {
		sf::Event event;

		window.clear();
		
		// logic shit goes here
		while (window.pollEvent(event))
		{
			switch (event.type) {
				case sf::Event::Closed: {
					window.close();
					break;
				}
				case sf::Event::MouseButtonPressed: {
					MouseButtonStates[event.mouseButton.button] = true;
					break;
				}
				case sf::Event::MouseButtonReleased: {
					MouseButtonStates[event.mouseButton.button] = false;
					break;
				}
				case sf::Event::MouseMoved: {
					MousePos[0] = event.mouseMove.x;
					MousePos[1] = event.mouseMove.y;
					break;
				}
				case sf::Event::KeyPressed: {
					if (event.key.code == sf::Keyboard::Q)
						window.close();
					break;
				}
				default: {
					break;
				}
			}
		}

		// render shit goes here

		canvas.display();
		const sf::Texture& tex = canvas.getTexture();
		sf::Sprite sp(tex);
		window.draw(sp);
		window.display();
	}
}

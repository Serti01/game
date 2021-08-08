#include "game.hh"
#include <X11/Xlib.h>
#include <stdio.h>
#include <ctime>
#include <random>

int main() {
	XInitThreads();
	srand(std::time(NULL));
	game::engine engine;
	
	while (engine.graphics->Window->isOpen()) {
		engine.pollEvents();
		engine.update();
		engine.render();
	}

	return 0;
}

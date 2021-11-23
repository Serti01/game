#include "game.hh"
#include <X11/Xlib.h>

int main() {
	XInitThreads();

	game::engine engine;
	engine.eRun();

	return 0;
}

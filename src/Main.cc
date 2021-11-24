#include "include/mEngine.hh"
#include <X11/Xlib.h>

int main() {
	XInitThreads();

	mEngine engine;
	engine.eRun();

	return 0;
}

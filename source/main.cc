#include "main.hh"
#include "util.hh"
#include "args.hh"

int main(int argc, char **argv) {
  handleArgs(argc, argv);

  // Init ncurses
  initscr();
  nocbreak();
  noecho();
  nonl();
  intrflush(stdscr, FALSE);
  keypad(stdscr, TRUE);
  clear();

  printf("hello!");
  

  return 0;
}
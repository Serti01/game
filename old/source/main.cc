#include "main.hh"
#include "util.hh"
#include "args.hh"
#include <error.h>

int main(int argc, char **argv) {
  handleArgs(argc, argv);

  // Init ncurses
  initscr();
  nocbreak();
  noecho();
  nonl();
  curs_set(0);
  setlocale(LC_ALL,"");
  // keypad(stdscr, TRUE);
  clear();
  refresh();

  // flashy main screen
  int maxx = getmaxx(stdscr)-1, maxy = getmaxy(stdscr)-1;

  int tracker = 4;
  std::mutex mutex;

  std::thread msleft([&](){
    for (int y = 0; y < maxy+1; y++) {
      mutex.lock();
      move(y,0);
      addwstr(L"⏐");
      refresh();
      mutex.unlock();
      usleep(10000);
    }
    mutex.lock();
    tracker--;
    mutex.unlock();
    return 0;
  });
  std::thread msright([&](){
    for (int y = maxy; y > 0; y--) {
      mutex.lock();
      move(y,maxx);
      addwstr(L"⏐");
      refresh();
      mutex.unlock();
      usleep(10000);
    }
    mutex.lock();
    tracker--;
    mutex.unlock();
    return 0;
  });
  std::thread mstop([&](){
    for (int x = 0; x < maxx+1; x++) {
      mutex.lock();
      move(0,x);
      addwstr(L"―");
      refresh();
      mutex.unlock();
      usleep(5000);
    }
    mutex.lock();
    tracker--;
    mutex.unlock();
    return 0;
  });
  std::thread msbottom([&](){
    for (int x = maxx; x > 0; x--) {
      mutex.lock();
      move(maxy,x);
      addwstr(L"―");
      refresh();
      mutex.unlock();
      usleep(5000);
    }
    mutex.lock();
    tracker--;
    mutex.unlock();
    return 0;
  });

  mstop.detach();
  msbottom.detach();
  msleft.detach();
  msright.detach();

  while (tracker) {
    usleep(10e3);
  }

  putstrxy((char *)((std::string)"Welcome, "+(std::string)getenv("USER")+(std::string)".").c_str(), 2, 1, OPT_TIMED);

  // putstrxymid("Welcome!", getmaxx(stdscr)/2, 1);
  refresh();
  usleep(10e5*3);
  curs_set(1);

  return 0;
}

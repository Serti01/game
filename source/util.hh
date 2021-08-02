#pragma once

#include <string>
#include <ncurses.h>
#include <unistd.h>
#include <memory>

int strlen(char *str);
bool strcmp(char *a, char *b);
bool strcmp(std::string a, std::string b);
const int OPT_MID = 1<<0;
const int OPT_TIMED = 1<<1;
void putstrxy_scr(char *s, int x, int y, WINDOW *scr, const int opt = 0);
void putstrxy(char *s, int x, int y, const int opt = 0);


// void putstrxy_scr(char *s, int x, int y, WINDOW *scr);
// void putstrxy_scr(const char *s, int x, int y, WINDOW *scr);
// void putstrxy(char *s, int x, int y);
// void putstrxy(const char *s, int x, int y);
// void putstrxymid_scr(char *s, int x, int y, WINDOW *scr);
// void putstrxymid_scr(const char *s, int x, int y, WINDOW *scr);
// void putstrxymid(char *s, int x, int y);
// void putstrxymid(const char *s, int x, int y);
// void putstrxytimed_scr(char *s, int x, int y, WINDOW *scr);
// void putstrxytimed(char *s, int x, int y);
// void putstrxytimedmid_scr(char *s, int x, int y, WINDOW *scr);
// void putstrxytimedmid(char *s, int x, int y);
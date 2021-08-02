#include "util.hh"

int strlen(char *str) {
    int i = 0;
    for (; str[i] != 0; i++);
    return i;
}

bool strcmp(char *a, char *b) {
    int len = strlen(a);
    if (len != strlen(b)) return false;

    for (int i = 0, ac = 0, bc = 0; i < len; i++, ac = a[i], bc = b[i])
        if (ac != bc) return false;

    return true;
}

bool strcmp(std::string a, std::string b) {
    return !a.compare(b);
}

void putstrxy_scr(char *s, int x, int y, WINDOW *scr, const int opt) {
    int ox = getcurx(scr), oy = getcury(scr);
    
    if (opt&OPT_MID)
        wmove(scr, y, x-(strlen(s)/2));
    else
        wmove(scr, y, x);
    
    if (opt&OPT_TIMED) {
        for (int i = 0, c = s[0]; i < strlen(s); i++, c = s[i]) {
            char sc[2] = " ";
            sc[0] = c;
            printw(sc);
            refresh();
            usleep(10e4);
        }
    } else {
        wprintw(scr,s);
        wrefresh(scr);
    }
    wmove(scr,oy,ox);
}
void putstrxy(char *s, int x, int y, const int opt) {
    putstrxy_scr(s, x, y, stdscr, opt);
}
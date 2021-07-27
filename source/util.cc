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
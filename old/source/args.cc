#include "args.hh"
#include "util.hh"

void handleArgs(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], (char *)"--version")) {
            
            exit(0);
        }
        if (strcmp(argv[i], (char *)"--help")) {
            exit(0);
        }
    }
}
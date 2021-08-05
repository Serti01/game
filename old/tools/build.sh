# /bin/sh

mkdir -p build

g++ -pthread -lncurses -lncursesw source/**.c* -o build/game
# make it linear so the gitub bot can build it correctly
# g++ $extra $(python tools/get-depends.py) source/**.c* -o build/$(python tools/get-version.py nospace nocaps)
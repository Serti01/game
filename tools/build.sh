# /bin/sh

mkdir -p build

g++ $(python tools/get-depends.py) source/**.c* -o build/$(python tools/get-version.py nospace)
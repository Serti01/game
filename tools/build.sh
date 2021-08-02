# /bin/sh

mkdir -p build

extra="-pthread"

if [[ $1 -eq "debug" ]]; then
    extra="-pthread -static-libstdc++ -g -fsanitize=address"
fi

g++ $extra $(python tools/get-depends.py) source/**.c* -o build/$(python tools/get-version.py nospace nocaps)
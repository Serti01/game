#! /bin/sh

./tools/build.sh
./build/$(python tools/get-version.py nospace nocaps) $@
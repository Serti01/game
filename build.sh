#! /usr/bin/sh

g++ $@ -std=c++17 -pthread -o game src/*.cc -lsfml-graphics -lsfml-window -lsfml-system -lX11

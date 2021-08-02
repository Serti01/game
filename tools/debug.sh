g++ -pthread -static-libstc++ -g -fstanitize=address -lncurses -lncursesw source/**.c* -o build/game
./tools/test.sh
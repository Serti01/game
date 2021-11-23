SFML_LIBS = system window graphics audio
LIBS = X11
OUTPUT_PATH = ./bin

OBJ = main.o engine.o graphics.o events.o

# [Default] Release, optimized
%.o: src/%.cc src/game.hh
	mkdir -p $(OUTPUT_PATH) && g++ -c -O2 -o $(OUTPUT_PATH)/$@ $<

# Debug
d%.o: src/%.cc src/game.hh
	mkdir -p $(OUTPUT_PATH) && g++ -c -g -o $(OUTPUT_PATH)/$@ $<

# [Default] Release, optimized
game: $(OBJ)
	g++ -o $(OUTPUT_PATH)/$@ \
	$(patsubst %,$(OUTPUT_PATH)/%,$^) \
	$(patsubst %,-lsfml-%,$(SFML_LIBS)) \
	$(patsubst %,-l%,$(LIBS))

# Debug
game-debug: $(patsubst %,d%,$(OBJ))
	g++ -o $(OUTPUT_PATH)/$@ \
	$(patsubst %,$(OUTPUT_PATH)/%,$^) \
	$(patsubst %,-lsfml-%,$(SFML_LIBS))
	$(patsubst %,-l%,$(LIBS))

.PHONY: clean
clean:
	rm -f $(wildcard $(OUTPUT_PATH)/*.o)

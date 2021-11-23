SFML_LIBS = system window graphics audio
LIBS = X11 cairo
OUTPUT_PATH = ./bin
DEPS = $(wildcard src/include/*.hh)
OBJ = $(patsubst src/%.cc,%.o,$(wildcard src/*.cc))

# [Default] Release, optimized
%.o: src/%.cc $(DEPS)
	mkdir -p $(OUTPUT_PATH) && g++ -c -O2 -o $(OUTPUT_PATH)/$@ $<

# Debug
d%.o: src/%.cc $(DEPS)
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
	$(patsubst %,-lsfml-%,$(SFML_LIBS)) \
	$(patsubst %,-l%,$(LIBS))

.PHONY: clean
clean:
	rm -f $(wildcard $(OUTPUT_PATH)/*.o)

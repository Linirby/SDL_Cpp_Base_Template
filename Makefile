CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -I./include
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
SRC_DIR = src
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OUT_DIR = bin
TARGET = $(OUT_DIR)/my_game

all: $(OUT_DIR) $(TARGET)

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -rf $(OUT_DIR)

rebuild: clean all

.PHONY: all clean
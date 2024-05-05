SRC = src/main.cpp src/Window.cpp src/KeyboardManager.cpp src/MouseManager.cpp src/Level.cpp src/LevelEditor.cpp
INCLUDES = -I include -L lib -lmingw32 -lSDL2main -lSDL2
OUT = main.exe

CC = g++


all:
	$(CC) $(SRC) $(INCLUDES) -o $(OUT)
	./$(OUT)
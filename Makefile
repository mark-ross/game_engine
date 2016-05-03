#broken down sections for source code to be organized
CHARACTERS = src/character.cpp
OPEN_TEMPLATES = src/window.cpp src/state.cpp
MANAGERS = src/ResourceManager.cpp src/CharacterManager.cpp
STATES = src/start.cpp
ENGINE = src/engine.cpp

#OBJS specifies which files to compile as part of the project
OBJS = main.cpp $(CHARACTERS) $(OPEN_TEMPLATES) $(MANAGERS) $(STATES) $(ENGINE)

#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -IC:\mingw_includes\SDL2\include\SDL2

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -LC:\mingw_includes\SDL2\lib

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
#COMPILER_FLAGS = -w -Wl,-subsystem,windows
COMPILER_FLAGS = -w -Wall

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = game

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

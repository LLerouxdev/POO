CXX = g++
CXXFLAGS = -std=c++17 -Wall -I.
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SOURCES = main.cpp JeuDeLaVie.cpp Grille.cpp Cellule.cpp Affichage.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = JeuDeLaVie

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

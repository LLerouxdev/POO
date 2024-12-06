CXX = g++  # Le compilateur C++ à utiliser
CXXFLAGS = -std=c++17 -Wall -I.  # Options de compilation (C++17, warnings, répertoires d'inclusion)
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system  # Liens nécessaires pour SFML

# Liste des fichiers source
SOURCES = main.cpp Jeu.cpp Grid.cpp Cell.cpp Affichage.cpp

# Liste des fichiers objets générés à partir des sources
OBJECTS = $(SOURCES:.cpp=.o)

# Nom de l'exécutable final
EXECUTABLE = Jeu

# Règle par défaut : construit l'exécutable
all: $(EXECUTABLE)

# Règle pour créer l'exécutable à partir des fichiers objets
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

# Règle pour créer les fichiers objets à partir des fichiers source
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

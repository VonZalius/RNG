# Nom de l'exécutable
EXEC = RNG.exe

# Nom du fichier source
SRC = main.cpp

# Compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -Wall -Wextra -std=c++98

# Règle par défaut : compilation de l'exécutable
all: $(EXEC)

# Règle pour créer l'exécutable
$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(SRC)

# Règle pour nettoyer les fichiers compilés
clean:
	rm -f $(EXEC)

# Règle pour nettoyer les fichiers compilés et les fichiers temporaires
distclean: clean

# Règles factices (non liées à des fichiers réels)
.PHONY: all clean distclean

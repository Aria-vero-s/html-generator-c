# Définir les variables
CC = gcc
CFLAGS = -Wall -std=c99
EXEC = generate

# Cibles par défaut
all: $(EXEC)

# Compilation du programme
$(EXEC): generate.c
	$(CC) $(CFLAGS) -o $(EXEC) generate.c

# Cible pour exécuter le programme
run: $(EXEC)
	./$(EXEC)

# Cible pour nettoyer les fichiers générés
clean:
	rm -f $(EXEC) index.html

# Cible pour recompiler et exécuter
rebuild: clean all run

.PHONY: all run clean rebuild

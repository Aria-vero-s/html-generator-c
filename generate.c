#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

void replace_placeholder(FILE *output_file, const char *placeholder, const char *value) {
    char buffer[MAX_LENGTH];

    // Lire le contenu du template ligne par ligne
    while (fgets(buffer, MAX_LENGTH, output_file) != NULL) {
        // Remplacer les placeholders
        char *pos = strstr(buffer, placeholder);
        if (pos != NULL) {
            // Copier la partie avant le placeholder
            *pos = '\0';
            fprintf(output_file, "%s%s%s", buffer, value, pos + strlen(placeholder));
        } else {
            // Copier la ligne sans modification
            fprintf(output_file, "%s", buffer);
        }
    }
}

int main() {
    FILE *template_file = fopen("template.html", "r");
    FILE *output_file = fopen("index.html", "w");
    FILE *data_file = fopen("data.txt", "r");

    if (template_file == NULL || output_file == NULL || data_file == NULL) {
        perror("Erreur d'ouverture de fichier");
        return 1;
    }
    if (data_file == NULL) {
        perror("Erreur d'ouverture de data.txt");
        return 1;
    }

    // Variables pour les placeholders
    char title[MAX_LENGTH];
    char content[MAX_LENGTH];

    // Lire les données du fichier data.txt (ex: title=Mon titre, content=Mon contenu)
    while (fscanf(data_file, "title=%s\n", title) != EOF && fscanf(data_file, "content=%s\n", content) != EOF) {
        // Remplacer les placeholders dans le template
        replace_placeholder(template_file, "{{ title }}", title);
        replace_placeholder(template_file, "{{ content }}", content);
    }

    fclose(template_file);
    fclose(output_file);
    fclose(data_file);

    printf("Page HTML générée avec succès !\n");

    return 0;
}

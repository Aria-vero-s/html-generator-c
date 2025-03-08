#include <stdio.h>
#include <string.h>

int main() {
    FILE *dataFile = fopen("data.txt", "r");
    if (!dataFile) {
        printf("Erreur d'ouverture du fichier data.txt\n");
        return 1;
    }

    char title[100], content[100];
    fscanf(dataFile, "title=%99[^\n]\n", title);
    fscanf(dataFile, "content=%99[^\n]\n", content);
    fclose(dataFile);

    FILE *templateFile = fopen("template.html", "r");
    if (!templateFile) {
        printf("Erreur d'ouverture du fichier template.html\n");
        return 1;
    }

    FILE *outputFile = fopen("index.html", "w");
    if (!outputFile) {
        printf("Erreur d'ouverture du fichier index.html\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), templateFile)) {
        // Remplacer les placeholders par les données de data.txt
        if (strstr(line, "{{ title }}")) {
            fprintf(outputFile, "%s", line);
        } else if (strstr(line, "{{ content }}")) {
            fprintf(outputFile, "%s", line);
        } else {
            fprintf(outputFile, "%s", line);
        }
    }

    fclose(templateFile);
    fclose(outputFile);

    printf("Fichier index.html généré avec succès.\n");
    return 0;
}

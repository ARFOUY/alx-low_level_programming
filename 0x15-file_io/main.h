

Pour respecter la structure du code, on peut réécrire le code de la manière suivante :

#ifndef MAIN_H
#define MAIN_H

// inclusion des bibliothèques nécessaires
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// prototype de la fonction read_textfile
ssize_t read_textfile(const char *filename, size_t letters);

// prototype de la fonction create_file
int create_file(const char *filename, char *text_content);

// prototype de la fonction append_text_to_file
int append_text_to_file(const char *filename, char *text_content);

#endif

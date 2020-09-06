#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <errno.h>

// Med den her kommando kan koden afprøves: "make file && ./file testFile.c && echo $?"
// Ved at følge arbejdssedlen kan i også prøve at køre det uden noget filnavn: "make file && ./file && echo $?"
enum file_type {
    DATA,
    EMPTY,
    ASCII,
};

int print_error(char *path, int errnum) {
    return fprintf(stdout, "%s: cannot determine (%s)\n",
    path, strerror(errnum));
}

int main (int argc, char* argv[]) {
    char* filename = argv[1];
    if (argc == 1) {
        printf("Usage: %s\n", filename);
        return(EXIT_FAILURE);
    }
    FILE* f_in = fopen(filename, "r");

    if (f_in == NULL) {
        print_error(filename, errno);
        return(EXIT_SUCCESS);
    }
    enum file_type var;

    char c = fgetc(f_in);
    if (c == EOF) {
        var = 1;
    }
    // Prøv at bruge char *fgets(char *str, int n, FILE *stream), den vil måske løse problemet.
    while (c != EOF) {
        if ((c >= 0x07 && c <= 0x0D) || (c == 0x1B) || (c >= 0x20 && c <= 0x7E)) { 
            c = fgetc(f_in);
            var = 2;
        }
        else {
            var = 0;
            c = EOF;
        }
    }

    switch (var)
    {
    case DATA: printf("%s: data\n", filename); break;
    case EMPTY: printf("%s: empty\n", filename); break;
    case ASCII: printf("%s: ASCII text\n", filename); break;
    }
    
    fclose(f_in);
    return(EXIT_SUCCESS);
}
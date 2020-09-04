#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>


int main (int argc, char* argv[]) {
    assert(argc == 2);
    char* filename = argv[1];
    FILE* f_in = fopen(filename, "r");
    assert(f_in != NULL);
    int i = 0x14;
    int c = fgetc(f_in);
    for (int i=0; i<4; i++) {
        printf("\n%i\n", c);
        c = fgetc(f_in);
    }

    // char c = fgetc(f_in);
    // while (c != EOF) {
    //     if (c == 'A') {
    //         printf("%c", c);
    //         printf("\nNo A's are allowed\n");
    //         return EXIT_FAILURE;
    //     }
    //     else {
    //         printf("%c", c);
    //         c = fgetc(f_in);
    //     }
    // }

    // fprintf(f_in, "Number of bytes: #%d", i);
    fclose(f_in);
}
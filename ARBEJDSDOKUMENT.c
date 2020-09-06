#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <errno.h>

enum file_type {
    DATA,
    EMPTY,
    ASCII,
};

const char * const FILE_TYPE_STRINGS[] = {
    "data",
    "empty",
    "ascii",
};

// enum file_type files(int i) {
//     if (i == 0) {
//         return DATA;
//     }
//     if (i == 1) {
//         return EMPTY;
//     }
//     if (i == 2) {
//         return ASCII;
//     }
// }

//     }
// }
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
    // assert(f_in != NULL);
    if (f_in == NULL) {
        print_error(filename, errno);
        return(EXIT_SUCCESS);
    }
    char c = fgetc(f_in);
    // switch(c){
    //     case EOF: printf("%s: empty\n", filename); break;

    //     case 48:  while (c != EOF) {
    //     if ((c >= 0x07 && c <= 0x0D) || (c == 0x1B) || (c >= 0x20 && c <= 0x7E)) { 
    //     //  '0' || '1' || '2' || '3' || '4' ||'5' || '6' ||'7' ||'8' ||'9' ||'A' ||'B' || 'C' ||'D' || 'E' || 'F') {
    //         c = fgetc(f_in);

    //     }
    //     else {
    //         printf("%c", c);
    //     }
    // }   printf("%s: ascii text\n", filename); break;

    //     default: printf("%s: data\n ", filename); break;
        
        // case ASCII: printf("%s: \n", filename); return 3;
        // default: printf("not special"); break;
    // }
//     switch (FILE_TYPE_STRINGS)
//     {
//     // case :
//         /* code */
//         break;
    
//     default:
//         break;
//     }
//     if (c == EOF) {
//         printf("%s: empty\n", filename);
//     }

//     while (c != EOF) {
//         if ((c >= 0x07 && c <= 0x0D) || (c == 0x1B) || (c >= 0x20 && c <= 0x7E)) { 
//             c = fgetc(f_in);
//             return(files(2));
//         }
//         else {
//             return(files(0));
//         }
//     }
//     if (files(0)) {
//         printf("%s: data\n", filename);
//     }

//     if (files(1)) {
//         printf("%s: empty\n", filename);
//     }

//     if (files(2)) {
//         printf("%s: ASCII text\n", filename);
//     }



//     // byg logikken op på en ny måde så jeg starter med while loopet der looper over det hele
//     fclose(f_in);
//     return(EXIT_SUCCESS);
// }
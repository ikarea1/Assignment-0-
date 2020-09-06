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

/// <summary> The function print_error takes the path of a file and serves as a print error </summary>
/// <return> Returns a print statement containing a path and errnum </return>
int print_error(char *path, int errnum) {
    return fprintf(stdout, "%s: cannot determine (%s)\n",
    path, strerror(errnum));
}

/// <summary> Takes the first argument and if there only is one argc it will exit with failure </summary>
/// <return> Returns a EXIT_FAILURE and prints and error message </return> 
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

    /// <summary> Checks if the first character is the end of the file, and in that case set enum variable to EMPTY </summary>
    /// <returns> Returns the enum variable var </returns> 
    char c = fgetc(f_in);
    if (c == EOF) {
        var = 1;
    }

    /// <summary> It checks if it is end of file and if it not, it will access either flow chart and determines if it is 
    /// either ASCII text of data and sets the enum variable var to either DATA or ASCII </summary>
    /// <return> It updates the variable and if it accesses the else loop it will terminate the while
    /// loop and return data </return>
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

    /// <summary> A switch statement on the enum variable var that decides which case and a filename plus data type </summary>
    /// <returns> Prints a filename and data type </returns>
    switch (var)
    {
    case DATA: printf("%s: data\n", filename); break;
    case EMPTY: printf("%s: empty\n", filename); break;
    case ASCII: printf("%s: ASCII text\n", filename); break;
    }
    
    fclose(f_in);
    return(EXIT_SUCCESS);
}
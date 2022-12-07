#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

char * render_static_file(char* fileName) {
    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Error opening file, %s does not exist", fileName); 
        return NULL;
    }
    else {
        printf("File opened successfully");
    }

    fseek(file, 0, SEEK_END); 
    long fsize = ftell(file); 
    fseek(file, 0, SEEK_SET); 

    char *string = malloc(fsize) // it should be fsize + 1, but I'm not sure why :D
    fread(string, fsize, 1, file); 
    fclose(file);
    printf("File contents:", string); 
    return string;
}

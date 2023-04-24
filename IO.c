//
// Created by skakm on 24/04/2023.
//
#include <stdio.h>
#include <string.h>
#include "IO.h"
#include "game.h"



char IOmessage[MAX_LIMIT];
int readfile(char* filename){
    FILE *fptr;

// Open a file in read mode
    if(filename[0] == '\0'){
        fptr = fopen("cards.txt", "r");
    }else{
        fptr = fopen(filename, "r");
    }


    if(fptr != NULL) {
        char card[2];
        // Read the content and print it
        while (fgets(card, 2, fptr)) {
            printf("%s", card);
        }
    }else {// Print some text if the file does not exist
        strcpy(IOmessage, "Not able to open the file.");
        return 0;
    }

// Close the file
    strcpy(IOmessage, "OK");
    fclose(fptr);

    return 1;
}
int writefile(char* filename){
    FILE *fptr;

// Open a file in read mode
    if(filename[0] == '\0'){
        fptr = fopen("cards.txt", "w");
    }else{
        fptr = fopen(filename, "w");
    }

    if(fptr != NULL) {
        char suit = 'S';
        char value = 'A';
        fprintf(fptr, "%c%c", value, suit);
    }else {// Print some text if the file does not exist
        strcpy(IOmessage, "Not able to open the file.");
        return 0;
    }

    strcpy(IOmessage, "OK");
// Close the file
    fclose(fptr);

    return 1;
}
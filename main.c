#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmake-build-debug/game.h"
#include "cmake-build-debug/IO.h"

#define MAX_LIMIT 50




void printInitView();
void printDefaultView(cardNode *head, int show);
int main() {

    char input[MAX_LIMIT];
    char instruction[3] = "";
    char variable[MAX_LIMIT] = "";
    char message[MAX_LIMIT] = "";
    char lastCommand[MAX_LIMIT] = "";
    char variableExists = 1;
    int check;
    char initBool = 0;
    char foundCommand = 0;
    int show = 0;
    while(1){

        variableExists = 1;
        variable[0] = '\0';
        instruction[0] = '\0';
        //puts("Setting up game, please choose a command...");
        if(!initBool){
            printInitView();
        }else {
            printDefaultView(mainDeckHead, show);
            show = 0;
        }


        printf("LAST Command: %s\n", lastCommand);
        printf("Message: %s\n", message);
        printf("Input > ");
        fgets(input, MAX_LIMIT, stdin);
        input[strlen(input)-1] = '\0';
        strcpy(lastCommand, input);
        char * token = strtok(input, " ");
        // loop through the string to extract all other tokens
        if ( token != NULL) {
            strcpy(instruction, token);
            token = strtok(NULL, " ");
            if (token != NULL){
                strcpy(variable, token);
            }

        }
        if(variable[0] == '\0'){
            variableExists= 0;
        }
        printf("Instruction: %s, variable: %s\n", instruction, variable);

        if (strcmp(instruction, "LD") == 0){

            if (variableExists){
                printf("Reading file: %s\n", variable);
                puts("Loading deck...");
            }else{
                puts("Loading default deck..");
            }

            check = readfile(variable);
            if(check){
                initBool = 1;
            }

            strcpy(message, IOmessage);
            printList(mainDeckHead);
        }
        else if (strcmp(instruction, "SW") == 0){
            puts("Showing deck...");
            show = 1;
        }
        else if (strcmp(instruction, "SI") == 0){
            if (variableExists){

                int splitNum = atoi(variable);
                if (splitNum > 0 && splitNum < 52){
                    printf("Num: %d\n", splitNum);
                    puts("Shuffling split...");
                    shufflesplit(mainDeckHead, splitNum);
                }else{
                    puts("Please pick a number between 1 and 51");
                }

            }else{
                shufflesplit(mainDeckHead, 0);
            }
        }
        else if (strcmp(instruction, "SR") == 0){
            puts("Shuffling...");
        }
        else if (strcmp(instruction, "SD") == 0){
            puts("Saving deck...");
            if (variableExists){
                printf("Saving to file: %s\n", variable);
            }else{
                printf("Saving to file: %s", "cards.txt");
            }
            writefile(variable, mainDeckHead);
        }
        else if (strcmp(instruction, "QQ") == 0){
            puts("Thanks for playing");
            freeList(mainDeckHead);
            return 0;
        }
        else if (strcmp(instruction, "P") == 0){
            puts("Starting game...");
            gameLoop();
            strcpy(lastCommand, "Q");
        }

        puts("\n");


    }
}
void printInitView(){
    printf("C1\tC2\tC3\tC4\tC6\tC7\n\n");
    printf("\t\t\t\t\t\t\t[]\tF1\n\n");
    printf("\t\t\t\t\t\t\t[]\tF2\n\n");
    printf("\t\t\t\t\t\t\t[]\tF3\n\n");
    printf("\t\t\t\t\t\t\t[]\tF4\n\n");
}

void printDefaultView(cardNode *head, int show){
    printf("C1\tC2\tC3\tC4\tC5\tC6\tC7\n\n");
    int counter = 2;
    while(head != NULL){
        for (int i = 0; i < 7; ++i) {
            if(head == NULL){
                break;
            }
            if(show){
                printf("%c%c\t", head->value, head->suit);
            }else{
                printf("[]\t");
            }
            head = head->next;

        }
        if(counter % 2 == 0){
            printf("\t[]\tF1\n");
        }else{
            puts("");
        }
        counter++;
    }
    puts("");
}
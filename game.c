//
// Created by skakm on 24/04/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "IO.h"



int gameLoop() {

    char input[20];
    while(1){
        scanf("%s", input);
        getchar();

        if (strcmp(input, "Q") == 0){
            puts("Exiting game...");
            return 0;
        }
    }

}
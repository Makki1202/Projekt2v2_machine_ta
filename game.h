//
// Created by skakm on 24/04/2023.
//

#ifndef PROJEKT2V2_MACHINE_TA_GAME_H
#define PROJEKT2V2_MACHINE_TA_GAME_H

#endif //PROJEKT2V2_MACHINE_TA_GAME_H

typedef struct cardNode{
    char suit;
    char value;
    char facedown;
    struct cardNode *next;
}cardNode;

cardNode *coloums[7];

int gameLoop();
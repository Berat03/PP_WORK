#include "langton.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void turn_left(struct ant *ant) {
    switch(ant->direction){
        case UP:
            ant -> direction = LEFT;
            break;
        case DOWN:
            ant -> direction = RIGHT;
            break;
        case LEFT:
            ant -> direction = DOWN;
            break;
        case RIGHT:
            ant -> direction = UP;
            break;
    }
}

void turn_right(struct ant *ant) {
    switch(ant->direction){
        case UP:
            ant -> direction = RIGHT;
            break;
        case DOWN:
            ant -> direction = LEFT;
            break;
        case LEFT:
            ant -> direction = UP;
            break;
        case RIGHT:
            ant -> direction = DOWN;
            break;
    }
}

void move_forward(struct ant *ant){
    switch(ant->direction) {
        case UP:
            ant -> y -=  1;
            break;
        case DOWN:
            ant -> y += 1;
            break;
        case LEFT:
            ant -> x -= 1;
            break;
        case RIGHT:
            ant -> x += 1;
            break;
    }
}

void apply_rule(enum colour *colour, struct ant *ant) {
    switch (*colour) {
        case WHITE:
            turn_left(ant);
            *colour = BLACK;
            break;
        case BLACK:
            turn_right(ant);
            *colour = WHITE;
            break;

    }
}
char* colourNames[] = { " ", "A", "B", "C", "D","E", "F", "G", "H", "I", "J", "K", "L", "M", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "£", "$", "%", "&", "*"};

void apply_rule_general(enum colour *colour, struct ant *ant, struct rule *rule) {
    int rule_len;
    rule_len = (int) strlen(rule->rules);
    int value = *colour;
    char individualRule = (rule->rules)[value];
    switch (individualRule) {
        case 'L':
            turn_left(ant);
            *colour = *colour + 1;
            if (*colour >= rule_len){
                *colour = 0;
            }
            break;
        case 'R':
            turn_right(ant);
            *colour = *colour + 1;
            if (*colour >= rule_len){
                *colour = 0;
            }
            break;
        default:
            printf("An error has occurred- the conditions for accepting rule inputs has changed from LR.");
            exit(EXIT_FAILURE); // as this is a void function, we can't just return a 1
    }
}

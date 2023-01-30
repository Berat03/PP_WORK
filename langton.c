#include "langton.h"
#include "visualiser.h"
#include <stdio.h>
#include <string.h>

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
    printf("%d",max_x);
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
char* colourNames[] = { " ", "A", "B", "C", "D",
                        "E", "F", "G", "H", "I",};

void apply_rule_general(enum colour *colour_gen, struct ant *ant, struct rule *rule) {
    int rule_len = strlen(rule->rules);
    int value = *colour_gen;
    char individualRule = (rule->rules)[value]; // can refactor later
    switch (individualRule) { // why is this red??????
        case 'L':
            turn_left(ant);
            *colour_gen = *colour_gen + 1;
            if (*colour_gen >= rule_len){
                *colour_gen = 0;
            }
            break;
        case 'R':
            turn_right(ant);
            *colour_gen = *colour_gen + 1;
            if (*colour_gen >= rule_len){
                *colour_gen = 0;
            }
            break;
    }
}

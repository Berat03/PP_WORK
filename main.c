#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "langton.h"
#include "visualiser.h"

int main(int argc,  char *argv[]){
    if(argv[1]){ //if we have an input
        char input_rules[] = "LR";
        if (strspn(argv[1], input_rules) != strlen(argv[1])) { //True if invalid input, close program
            printf("Invalid input\n"); //do `I print this?
            return 1;
        }

        struct rule general_rule;
        struct rule * general_rule_p;
        general_rule.rules = malloc(sizeof(char) * (strlen(argv[1]) + 1));
        if (general_rule.rules == NULL) { // if malloc fails
            printf("Error: malloc() failed.\n");
            return 1;
        }
        strcpy(general_rule.rules, argv[1]);
        general_rule_p = &general_rule;
        // do general version here
        struct ant *antp;
        struct ant bob;
        antp = &bob;

        start_visualisation(antp);
        while (not_quit())
            visualise_and_advance_general(antp, general_rule_p);
        end_visualisation();
        free(general_rule.rules);
        return 0;
    }
    // if no input
    // base rule if none are passed in
    struct ant *antp;
    struct ant bob;
    antp = &bob;
    start_visualisation(antp);
    while (not_quit())
        visualise_and_advance(antp);
    end_visualisation();
    return 0;
}

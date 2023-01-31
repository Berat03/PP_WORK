#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "langton.h"
#include "visualiser.h"


int main(/*@unused@*/ int argc, char *argv[]) {
    // just to define variable
    struct ant bob = {
            .x = 0,
            .y = 0,
            .direction = RIGHT
    };
    struct ant *ant_p;
    ant_p = &bob;
    // argv[1] only takes the first argument from user

    // argv[1] will be TRUE if we have any input, so we need the check
    if (argv[1]) {
        char input_rules[] = "LR";

        // TRUE if invalid input
        if (strspn(argv[1], input_rules) != strlen(argv[1])) {
            printf("Invalid input\n");
            return 1;
        }
        struct rule general_rule;
        general_rule.rules = malloc(sizeof(char) * (strlen(argv[1]) + 1));


        // if malloc fails general_rule.rules will return NULL
        if (general_rule.rules == NULL) {
            printf("Error: malloc() failed.\n");
            return 1;
        }
        strcpy(general_rule.rules, argv[1]);
        struct rule * general_rule_p;
        general_rule_p = &general_rule;

        // Advanced version loop including freeing malloc memory
        start_visualisation(ant_p);
        while (not_quit())
            visualise_and_advance_general(ant_p, general_rule_p);
        end_visualisation();
        free(general_rule.rules);
        return 0;
    }
    // if no input, we run the basic version with rule LR

    start_visualisation(ant_p);
    while (not_quit())
        visualise_and_advance(ant_p);
    end_visualisation();
    return 0;
}

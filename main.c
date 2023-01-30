#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "langton.h"
#include "visualiser.h"

int main(int argc,  char *argv[]){
    struct ant *ant_p;
    struct ant bob;
    ant_p = &bob;
    // use argv[1] so that is user inputs two rules or any second input (separate by a space) it will only read the original rule
    if(argv[1]){ //if we have an input
        char input_rules[] = "LR";
        if (strspn(argv[1], input_rules) != strlen(argv[1])) { //TRUE if invalid input
            printf("Invalid input\n");
            return 1;
        }
        struct rule general_rule;
        struct rule * general_rule_p;
        general_rule.rules = malloc(sizeof(char) * (strlen(argv[1]) + 1)); //Allocating memory w.r.t length of rule
        if (general_rule.rules == NULL) { // if malloc fails general_rule.rules will return NULL
            printf("Error: malloc() failed.\n");
            return 1;
        }
        strcpy(general_rule.rules, argv[1]);
        general_rule_p = &general_rule;

        // general version
        start_visualisation(ant_p);
        while (not_quit())
            visualise_and_advance_general(ant_p, general_rule_p);
        end_visualisation(); // could not have to repeat this code using if else, but better readability*
        free(general_rule.rules); // to ensure no memory leak
        return 0;
    }

    // if no input (base LR rule)
    start_visualisation(ant_p);
    while (not_quit())
        visualise_and_advance(ant_p);
    end_visualisation();
    return 0;
}

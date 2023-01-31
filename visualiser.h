#ifndef visualiser_h
#define visualiser_h

#include "langton.h"
#include <stdbool.h>


typedef enum colour cell;

void start_visualisation(struct ant* ant);
void visualise_and_advance(struct ant* ant);
void visualise_and_advance_general(struct ant* ant, struct rule* rule);
void cell_at_fct(struct ant *ant);
bool not_quit();
void end_visualisation();
const char* direction_to_s(enum direction d);

#endif

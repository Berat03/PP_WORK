#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include "visualiser.h" // this way we acn access max_x and max_y

#define cell_at(y, x) cells[(y * max_x) + x]
#define cell_under_ant cell_at(ant->y, ant->x)
cell *cells;

void start_visualisation(struct ant* ant) {
    setlocale(LC_ALL, "");
    initscr();
    curs_set(FALSE);
    max_x = getmaxx(stdscr);
    max_y = getmaxy(stdscr);
    cells = calloc(max_y*max_x, sizeof(cell));
    ant->x = max_x/2;
    ant->y = max_y/2;
    ant->direction = RIGHT;
}

void cell_at_fct(struct ant *ant){
    if(ant -> x < 0){
        ant -> x = (max_x - 1);
    }
    else if(ant -> x >= max_x){
        ant -> x = 0;
    } else if(ant -> y < 0){
        ant -> y = (max_y - 1);
    } else if (ant -> y >= max_y){
        ant -> y = 0;
    }
}

void visualise_and_advance(struct ant* ant) {
    /* Draw cells and ant */
    for (int y=0; y<max_y; y++){
        for (int x=0; x<max_x; x++){
            mvprintw(y,x,
                     ant_is_at(y,x)
                     ? direction_to_s(ant->direction)
                     : cell_at(y,x)
                       ? "1"
                       : "0"
            );
        }
    }
    refresh();

    /* Advance to next step */
    apply_rule(&cell_under_ant, ant);
    move_forward(ant);
    cell_at_fct(ant);
}

// max_x and max_y are 0 outside the scope of this file??
bool not_quit() {
    return 'q' != getch();
}

void end_visualisation() {
    free(cells);
    endwin();
}


const char* direction_to_s(enum direction d) {
    return UP   == d ? "^" :
           DOWN == d ? "v" :
           LEFT == d ? "<" :
           /* else */  ">" ;
}

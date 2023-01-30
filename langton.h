#ifndef langton_h
#define langton_h

enum direction { UP, DOWN, LEFT, RIGHT };

struct ant {
    int x;
    int y;
    enum direction direction;
};
// could use @out@  to get rid of some linting however I'm not too sure if allowed
struct rule {
    /*@out@*/ char* rules;
};

#define ant_is_at(posy, posx) ((ant->x == (posx)) && (ant->y == (posy))) //! DONE

enum colour { WHITE, BLACK };
extern char* colourNames[];

void turn_left(struct ant *ant); //! DONE
void turn_right(struct ant *ant); //! DONE
void move_forward(struct ant *ant); //! DONE

void apply_rule(enum colour *colour, struct ant *ant); //! DONE
void apply_rule_general(enum colour *colour, struct ant *ant, struct rule *rule); //! DONE
#endif
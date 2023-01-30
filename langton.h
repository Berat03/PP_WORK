#ifndef langton_h
#define langton_h

enum direction { UP, DOWN, LEFT, RIGHT };

struct ant {
    int x;
    int y;
    enum direction direction;
};

struct rule {
    char* rules;
};
extern char *passed_rule;

#define ant_is_at(posy, posx) (ant->x == posx && ant->y == posy)

enum colour { WHITE, BLACK };
//enum colour_gen {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z};

extern char* colourNames[];


void turn_left(struct ant *ant); //! DONE
void turn_right(struct ant *ant); //! DONE
void move_forward(struct ant *ant); //! DONE

void apply_rule(enum colour *colour, struct ant *ant); //! DONE
void apply_rule_general(enum colour *colour, struct ant *ant, struct rule *rule); //! Todo, can change color enum
#endif
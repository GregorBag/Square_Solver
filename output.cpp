#include <stdio.h>
#include "colors.h"
#include "structs.h"
#include "output.h"

#define TWO_ROOTS 2
#define ONE_ROOT 1
#define NO_ROOTS 0
#define INF_ROOTS -1

void output(struct Answer an){
    switch (an.num){
        case TWO_ROOTS:
            printf(COLOR_GREEN "%.2f\n%.2f\n" COLOR_RESET, an.x1, an.x2);
            break;
        case ONE_ROOT:
            printf(COLOR_GREEN "%.2f\n" COLOR_RESET, an.x1);
            break;
        case INF_ROOTS:
            printf(COLOR_YELLOW "Any x is suitable\n" COLOR_RESET);
            break;
        case NO_ROOTS:
            printf(COLOR_YELLOW "There are no roots\n" COLOR_RESET);
            break;
        default:
            break;
    }
}
#include <stdio.h>
#include "colors.h"
#include "structs.h"
#include <math.h>
#include "solver.h"
#include "tests.h"

#define epsilon 0.001

void one_test(struct Test test) {
    bool fine = true;
    struct Answer an = {NAN, NAN, 0};
    struct Answer exp_an = {NAN, NAN, 0};
    an = machine(test.cf);
    exp_an = test.exp_an;

    if (fabsf(an.x1 - exp_an.x1) > epsilon) {
        fine = false;
        printf(COLOR_RED "Invalid x1: %.2f, expected  x1: %.2f. " COLOR_RESET, an.x1, exp_an.x1);
    }

    if (fabsf(an.x2 - exp_an.x2) > epsilon) {
        fine = false;
        printf(COLOR_RED "Invalid  x2: %.2f, expected  x2: %.2f. " COLOR_RESET, an.x2, exp_an.x2);
    }

    if (an.num != exp_an.num) {
        fine = false;
        printf(COLOR_RED "Incorrect number of roots: %d, expected number of roots: %d. " COLOR_RESET, an.num, exp_an.num);
    }

    if (fine == true) {
        printf(COLOR_GREEN "OK\n" COLOR_RESET);
    } else {
        printf("\n");
    }
}

void all_tests() {
    int k = 0, i = 0;
    FILE *fp = fopen("tests.txt", "r");
    struct Test tt = {{NAN, NAN, NAN}, {NAN, NAN, 0}};

    while ((k = fscanf(fp, "%f%f%f%f%f%d", &tt.cf.a, &tt.cf.b, &tt.cf.c, &tt.exp_an.x1, &tt.exp_an.x2, &tt.exp_an.num)) == 6) {
        printf(COLOR_CYAN "Test %d: " COLOR_RESET, i+1);
        one_test(tt);
        i++;
    }
    
    fclose(fp);
}

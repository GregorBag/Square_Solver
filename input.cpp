#include <stdio.h>
#include "colors.h"
#include "structs.h"
#include "input.h"
#include <math.h>

#define TEST true
#define SOLUTION false

int clean_buffer() {
    int i = 0;
    int c = 0;

    while ((c = getchar()) != '\n') {
        i = i + 1;
    }

    return i;
}

bool check(){
    printf(COLOR_CYAN "Select the operation mode. 'T' - tests, 'S' - solution\n" COLOR_RESET);
    char c = ' ';
    int k = scanf("%[TS]", &c);
    int i = clean_buffer();
    bool b = false;

    while (k != 1 || i != 0){
        printf(COLOR_CYAN "Incorrect input format. Select the operation mode. 'T' - tests, 'S' - solution\n" COLOR_RESET);
        k = scanf("%[TS]", &c);
        i = clean_buffer();
    }

    if (c == 'T'){
        b = TEST;
    } else {
        b = SOLUTION;
    }

    return b;
}

struct Coeff enter() {
    struct Coeff cf = {NAN, NAN, NAN};
    printf (COLOR_CYAN "Enter the coefficients a, b, c: " COLOR_RESET);
    int k = scanf ("%f%f%f", &cf.a, &cf.b, &cf.c);

    while (k != 3) {
        printf (COLOR_CYAN "The data format is incorrect, please enter the coefficients again: " COLOR_RESET);
        clean_buffer();
        k = scanf ("%f%f%f", &cf.a, &cf.b, &cf.c);
    }
    
    return cf;
}
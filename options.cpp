#include <stdio.h>
#include "options.h"
#include "structs.h"
#include <math.h>
#include "input.h"
#include "structs.h"
#include "solver.h"
#include "tests.h"
#include "output.h"

#define TEST true
#define SOLUTION false

void help_option() {
    bool c = check();
    
    if (c == SOLUTION) {
        struct Coeff cf = {NAN, NAN, NAN};
        struct Answer an = {NAN, NAN, 0};
        cf = enter();
        an = machine(cf);
        output(an);
    } 
    else {
        all_tests();
    }
}

void solution_option() {
    struct Coeff cf = {NAN, NAN, NAN};
    struct Answer an = {NAN, NAN, 0};
    cf = enter();
    an = machine(cf);
    output(an);
}
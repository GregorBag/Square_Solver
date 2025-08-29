#include "structs.h"
#include <math.h>
#include "solver.h"

#define TWO_ROOTS 2
#define ONE_ROOT 1
#define NO_ROOTS 0
#define INF_ROOTS -1

#define epsilon 0.001

struct Answer sol_square(float a, float b, float c) {
    struct Answer an = {NAN, NAN, 0};
    float D = b * b - (4 * a * c);

    if (D > epsilon) {
        an.x1 = (- b + sqrt(D)) / (2 * a);
        an.x2 = (- b - sqrt(D)) / (2 * a);
        an.num = TWO_ROOTS;
    }
    else if (fabsf(D) <= epsilon) {
        an.x1 = (-b) / (2 * a);
        an.x2 = NAN;
        an.num = ONE_ROOT;
    }
    else {
        an.x1 = NAN;
        an.x2 = NAN;
        an.num = NO_ROOTS;
    }

    return an;
}

struct Answer linear(float b, float c) {
    struct Answer an = {NAN, NAN, 0};
    an.x1 = -(c / b);
    an.x2 = NAN;
    an.num = ONE_ROOT;

    return an;
}

struct Answer machine(struct Coeff cf) {
    struct Answer an = {NAN, NAN, 0};
    float a = cf.a;
    float b = cf.b;
    float c = cf.c;

    if (fabsf(a) > epsilon) {
        an = sol_square(a, b, c);
    } 
    else if (fabsf(b) > epsilon) {
        an = linear(b, c);
    } 
    else if (fabsf(c) > epsilon) {
        an.x1 = NAN;
        an.x2 = NAN;
        an.num = NO_ROOTS;
    } 
    else {
        an.x1 = NAN;
        an.x2 = NAN;
        an.num = INF_ROOTS;
    }
    
    return an;
}


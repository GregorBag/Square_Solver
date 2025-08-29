#ifndef STRUCTS_
#define STRUCTS_

typedef float coef;
typedef float root;

struct Answer {
    root x1;
    root x2;
    int num;
};

struct Coeff {
    coef a;
    coef b;
    coef c;
};

struct Test {
    struct Coeff cf;
    struct Answer exp_an;
};

#endif
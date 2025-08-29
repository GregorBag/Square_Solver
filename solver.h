#ifndef SOLVER_
#define SOLVER_

struct Answer sol_square(float a, float b, float c);

struct Answer linear(float b, float c);

struct Answer machine(struct Coeff cf);

#endif 
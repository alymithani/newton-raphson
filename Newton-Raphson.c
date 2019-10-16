#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float f(float x);

float df(float x);

float newtons_method(float initial_point, float allowed_error, int maximum_iterations);

int main(int argc, char *argv[]) {
    // Make sure function is called with three parameters
    if (argc != 4) {
        printf("Usage: ./Newton-Raphson initial_point allowed_error maximum_iterations\n");
        return 1;
    }

    // Create initial_point, allowed_error and maximum_iterations variables using the command-line arguments
    float initial_point = atof(argv[1]);
    float allowed_error = atof(argv[2]);
    int maximum_iterations = atoi(argv[3]);

    // Call newtons_method() method using initiated variables
    float approximation = newtons_method(initial_point, allowed_error, maximum_iterations);

    // Print approximatie value of root
    printf("Approximate value found: %f\n", approximation);
}

float f(float x) {
    // Function f(x) for which Newton's Method will approximate root
    return 4*pow(x,2) - 7;
}

float df(float x) {
    // Function df(x) which is the derivative of function f(x) with respect to x
    return 8*x;
}

float newtons_method(float initial_point, float allowed_error, int maximum_iterations) {
    // Initialize x0, x1 to store iterative x values and e to store the offset
    float x0, x1, e;

    // Set the initial x value to the initial_point parameter
    x0 = initial_point;

    // Iterate over loop up to number indicated in maximum_iterations parameter
    for (int i = 0; i < maximum_iterations; i++) {

        // Set offset equal to - f(x)/f'(x)
        e = - f(x0)/df(x0);

        // Change x value by offset
        x1 = x0 + e;

        // Return x value if the absolute value of the offset is less than allowed_error
        if (fabsf(e) < allowed_error) {
            return x1;
        }

        // Set value of x0 to x1 from previous iteration
        x0 = x1;
    }

    // Return x0 after max number of iterations are reached
    return x0;
}

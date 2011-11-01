#include <iostream>

/**
 * power
 *
 * Raises x to the y power.
 *
 * y must be >= 0
 *
 * \param x input to the function
 * \param y input to the function
 * \return returns x^y
 */
int power(int x, int y) {
    if (y <= 0)
        return 1;
    return power(x, y-1) * x;
}

/**
 * Main function
 *
 * Similar to the hello world program
 */
int main(void) {
    //call the function and print the result
    std::cout << power(2,12) << std::endl;
    return 0;
}


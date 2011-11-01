#include <iostream>

//comment this out and the code will cube instead of square
//#define SQUARE

/**
 * squareValue
 *
 * A basic function
 *
 * \param x input to the function
 * \return returns x^2
 */
int squareValue(int x) {
#ifdef SQUARE
    return x*x;
#else
    return x*x*x;
#endif
}

/**
 * Main function
 *
 * Similar to the hello world program
 */
int main(void) {
    //call the function and print the result
    std::cout << squareValue(14) << std::endl;
    return 0;
}


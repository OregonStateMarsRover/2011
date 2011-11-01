#include <iostream>

int myGlobal = 2;

/**
 * squareValue
 *
 * A basic function
 *
 * \param x input to the function
 * \return returns x^2
 */
int squareValue(int x) {
    myGlobal = myGlobal+1;
    return x*x;
}

/**
 * Main function
 *
 * Similar to the hello world program
 */
int main(void) {
    std::cout << myGlobal << std::endl;

    //call the function and print the result
    std::cout << squareValue(14) << std::endl;

    //this won't compile
    std::cout << myGlobal << std::endl;

    return 0;
}


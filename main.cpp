#include <iostream>
#include <math.h>
#include <valarray>
#include <pstl/glue_numeric_defs.h>

void test();
void is_power_of_two_loop(int num);
void is_power_of_two_no_loop(int num);
void isPrime(const int num);
void reduceFraction(int numerator, int denominator);
//class Fraction;
//Fraction reduce(Fraction input);

int main() {
    test();
}

void test() {

    //Tests if a number is a power of two using a loop in the function
    is_power_of_two_loop(-4); //Should be FAIL
    is_power_of_two_loop(1); //Should be PASS
    is_power_of_two_loop(2); //Should be PASS
    is_power_of_two_loop(3); //Should be FAIL
    is_power_of_two_loop(4); //Should be PASS
    is_power_of_two_loop(5); //Should be FAIL
    is_power_of_two_loop(64); //Should be PASS
    is_power_of_two_loop(18); //Should be FAIL

    std::cout << std::endl;

    //Tests if a number is a power of two using no loop in the function
    is_power_of_two_no_loop(-4); //Should be FAIL
    is_power_of_two_no_loop(1); //Should be PASS
    is_power_of_two_no_loop(2); //Should be PASS
    is_power_of_two_no_loop(3); //Should be FAIL
    is_power_of_two_no_loop(4); //Should be PASS
    is_power_of_two_no_loop(5); //Should be FAIL
    is_power_of_two_no_loop(64); //Should be PASS
    is_power_of_two_no_loop(18); //Should be FAIL   NOT CORRECT

    std::cout << std::endl;

    //Tests if a number is prime
    isPrime(-10); //Should be FAIL
    isPrime(1); //Should be FAIL
    isPrime(2); //Should be PASS
    isPrime(3); //Should be PASS
    isPrime(4); //Should be FAIL
    isPrime(20); //Should be FAIL
    isPrime(15); //Should be FAIL
    isPrime(59); //Should be PASS

    std::cout << std::endl;

    //Reduces a fraction if possible
    reduceFraction(2, 4); //Should be PASS (1/2)
    reduceFraction(2, 3); //Should be FAIL
    reduceFraction(3, 2); //Should be FAIL
    reduceFraction(12, 14); //Should be PASS (6/7)
    reduceFraction(12, 18); //Should be PASS (2/3)

}
//Function that checks if a number is a power of 2 (completed in class)
void is_power_of_two_loop(int num) {
    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            std::cout << "FAIL" << std::endl;
            return;
        }
    }
    std::cout << "PASS" << std::endl;
}

void is_power_of_two_no_loop(int num) {
    if (num <= 0) {
        std::cout << "FAIL" << std::endl;
    } else if (num == 1) {
        std::cout << "PASS" << std::endl;
    } else if (num % 2 == 0) {
        int sqrt_num = sqrt(num);
        if (sqrt_num % 2 == 0) {
            std::cout << "PASS" << std::endl;
        } else {
            std::cout << "FAIL" << std::endl;
        }
    } else {
        std::cout << "FAIL" << std::endl;
    }
}

void isPrime(const int num) {
    if (num <= 1) {
        std::cout << "FAIL" << std::endl;
    } else if (num == 2) {
        std::cout << "PASS" << std::endl;
    } else if (num % 2 == 0) {
        std::cout << "FAIL" << std::endl;
    } else {
        for (int i = 3; i <= sqrt(num); i += 2) { //Used the "tab" fill on and CLion filled in the rest of the code
            if (num % i == 0) {
                std::cout << "FAIL" << std::endl;
                return;
            }
        }
        std::cout << "PASS" << std::endl;
    }
}

//Reduce fraction to the smallest fraction
void reduceFraction(int numerator, int denominator) {
    int prevNum = numerator;
    int prevDen = denominator;
    int GCD = 1;
    for (int i = 1; i <= denominator; i++) {
        if (denominator % i == 0 && numerator % i == 0) {
            GCD = i;
        }
    }
    numerator = numerator / GCD;
    denominator = denominator / GCD;
    if (prevNum != numerator || prevDen != denominator) {
        std::cout << "PASS " << numerator << "/" << denominator << std::endl;
    } else {
        std::cout << "FAIL " << numerator << "/" << denominator << std::endl;
    }
}
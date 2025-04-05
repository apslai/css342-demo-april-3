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
    is_power_of_two_no_loop(18); //Should be FAIL but doesn't work

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
    isPrime(21); //Should be FAIL

    std::cout << std::endl;

    //Reduces a fraction if possible
    reduceFraction(2, 4); //Should be PASS (1/2)
    reduceFraction(2, 3); //Should be FAIL
    reduceFraction(3, 2); //Should be FAIL
    reduceFraction(12, 14); //Should be PASS (6/7)
    reduceFraction(12, 18); //Should be PASS (2/3)
    reduceFraction(5, 5); //Should be PASS (1/1)
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
        for (int i = 3; i <= sqrt(num); i += 2) { //Used the "tab" fill and CLion filled in this code algorithm
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

/*
IN CLASS April 3, 2025 Work
void test() {
    Fraction inputs[4] = {Fraction (1,2), Fraction (2, 4), Fraction(4, 2), Fraction (6, 8)};
    Fraction outputs[4] = {Fraction (1,2), Fraction (1, 2), Fraction(2, 1), Fraction (3, 4)};

    //call the function
    for (int i = 0; i < 4; i++) {
        Fraction input = inputs[i];
        Fraction expect = outputs[i];

        Fraction actual = reduce(input);

        //compare expected vs actual
        if (expect == actual) {
            std::cout << "PASS" << std::endl;
        } else {
            std::cout << "FAIL case is: " << input.to_string() << std::endl;
        }

    }

}

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int numerator, int denominator)
        : numerator(numerator),
          denominator(denominator) {
    }

    std::string to_string() {
        return std::to_string(numerator) + "/" + std::to_string(denominator);

    }

    //operator overload
    bool operator == (Fraction &other) {
        return this->numerator == other.numerator && this->denominator == other.denominator;
    }
};

Fraction reduce(Fraction input) {
    int divider = 2;
    while (divider <= input.numerator && divider <= input.denominator) {
        if (input.numerator % divider == 0 && input.denominator % divider == 0) {
            input.numerator /= divider;
            input.denominator /= divider;
            continue;
        }
        divider++;
    }
    return input;
}
*/

/* In Class Notes (4/3/25)
HW is treated as a single project
Include comments, structure to make code more readable, make sure code works or can compile, show tests to prove code/functions works, must be efficient, readability
Comments: FOCUS on the WHY side
Explain what the code does
Write as few comments as possible
Be about the why - why did you create the code this way
Write a comment about where a number comes from
Style should be consistent
Focus on making the code work first and then can revise and make it more efficient

Git/GitHub
Helps manage changes
“Commit” saves a version/copy, it is like a snapshot
Git is what runs on the machine, GitHub is like a cloud version on my machine
“Repository/repo” is like a folder for all your files
“Branch” is a line of development that consists of a series of commits
Steps:
Commit and push to the repository

Steps for working on a project:
Create project
Put it into a repository on Git
Create a repository on GitHub
Push local repository to GitHub
Create tests first
*/
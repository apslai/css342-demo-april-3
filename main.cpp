#include <iostream>
#include <math.h>
#include <valarray>

void is_power_of_two_loop(int num);
void is_power_of_two_no_loop(int num);
void isPrime(const int num);
void reduceFraction(int numerator, int denominator);
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.

    isPrime(1); //Should be FAIL
    isPrime(2); //Should be PASS
    isPrime(4); //Should be FAIL
    isPrime(20); //Should be FAIL
    isPrime(15); //Should be FAIL
    isPrime(59); //Should be PASS

    reduceFraction(2, 4); //Should be PASS (1/2)
    reduceFraction(2, 3); //Should be FAIL
    reduceFraction(3, 2); //Should be FAIL
    reduceFraction(12, 14); //Should be PASS (6/7)
    reduceFraction(12, 18); //Should be PASS (2/3)

    is_power_of_two_no_loop(1); //Should be PASS
    is_power_of_two_no_loop(2); //Should be PASS
    is_power_of_two_no_loop(3); //Should be FAIL
    is_power_of_two_no_loop(4); //Should be PASS
    is_power_of_two_no_loop(5); //Should be FAIL
    is_power_of_two_no_loop(64); //Should be PASS
    is_power_of_two_no_loop(18); //Should be FAIL



    return 0;
}

void is_power_of_two_loop(int num) {

    std::cout << "FAIL" << std::endl;
}

void is_power_of_two_no_loop(int num) {
    if (num <= 0) {
        std::cout << "FAIL" << std::endl;
    } else if (num == 1) {
        std::cout << "PASS" << std::endl;
    } else if (num % 2 == 0) {
        std::cout << "PASS" << std::endl;
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
        for (int i = 3; i <= sqrt(num); i += 2) {
            if (num % i == 0) {
                std::cout << "FAIL" << std::endl;
                return;
            }
        }
        std::cout << "PASS" << std::endl;
    }
}

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


// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
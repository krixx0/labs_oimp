#include "Fraction.h"
#include <iostream>

int main() {
     
    Proper_Fraction f1(2, 4);  
    Proper_Fraction f2(-3, 5); 

    Proper_Fraction f3(1, 1);
    Proper_Fraction f4(-3, -4);

    Proper_Fraction f5(-5, 6);
    Proper_Fraction f6(0, 5);

    Proper_Fraction f7(6, -4);
    Proper_Fraction f8(-3, 5);

    f1.print();
    std::cout << "\n";

    f2.print();
    std::cout << "\n";

    {
        Proper_Fraction sum = f1.add(f2);
        std::cout << "sum ";
        sum.print();
        std::cout << "\n";

        Proper_Fraction multi = f1.multiply(f2);
        std::cout << "multiplication ";
        multi.print();
        std::cout << "\n";

        Proper_Fraction div = f1.divide(f2);
        std::cout << "division ";
        div.print();
        std::cout << "\n\n";
    }

    f3.print();
    std::cout << "\n";

    f4.print();
    std::cout << "\n";

    {
        Proper_Fraction sum = f3.add(f4);
        std::cout << "sum ";
        sum.print();
        std::cout << "\n";

        Proper_Fraction multi = f3.multiply(f4);
        std::cout << "multiplication ";
        multi.print();
        std::cout << "\n";

        Proper_Fraction div = f3.divide(f4);
        std::cout << "division ";
        div.print();
        std::cout << "\n\n";
    }

    f5.print();
    std::cout << "\n";

    f6.print();
    std::cout << "\n";

    {
        Proper_Fraction sum = f5.add(f6);
        std::cout << "sum ";
        sum.print();
        std::cout << "\n";

        Proper_Fraction multi = f5.multiply(f6);
        std::cout << "multiplication ";
        multi.print();
        std::cout << "\n\n";
    }

    f7.print();
    std::cout << "\n";

    f8.print();
    std::cout << "\n";

    {
        Proper_Fraction sum = f7.add(f8);
        std::cout << "sum ";
        sum.print();
        std::cout << "\n";

        Proper_Fraction multi = f7.multiply(f8);
        std::cout << "multiplication ";
        multi.print();
        std::cout << "\n";

        Proper_Fraction div = f7.divide(f8);
        std::cout << "division ";
        div.print();
        std::cout << "\n\n";
    }

    Proper_Fraction f(1, 0);

    return 0;
}

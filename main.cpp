#include <iostream>
#include "fraction.h"
using namespace std;
int main()
{
    //Testing default constructor
    fraction a;
    cout << "Fraction a is: " << a << '\n';

    //Testing parameterized (double) constructor
    fraction b(2, -4);
    cout << "Fraction b is: " << b << '\n';
    fraction c(-3, 7);
    cout << "Fraction c is: " << c << '\n';

    //Testing parameterized (single) constructor
    fraction d(-8);
    cout << "Fraction d is: " << d << '\n';

    //Testing copy constructor
    fraction e(b);
    cout << "Fraction e is: " << e << '\n';

    //Testing = operator
    b = c;
    cout << "Fraction b is: " << b << '\n';

    //Testing unary plus operator;
    cout << "Fraction +b is: " << +b << '\n';
    cout << "Fraction b is: " << b  << '\n';

    //Testing unary minus operator
    cout << "Fraction -b is: " << -b << '\n';
    cout << "Fraction b is: " << b << '\n';

    //Testing += operator
    c += d;
    cout << "Fraction c is: " << c << '\n';

     //Testing -= operator
    c -= d;
    cout << "Fraction c is: " << c << '\n';

     //Testing *= operator
    c *= d;
    cout << "Fraction c*=d is: " << c << '\n';

    //Testing /= operator
    c /= d;
    cout << "Fraction c is: " << c << '\n';

    //Testing ++x operator
    b = ++c;
    cout << "Fraction b = ++c is: " << b << '\n';
    cout << "Fraction c is: " << c << '\n';

    //Testing --x operator
    b = --c;
    cout << "Fraction b== --c is: " << b << '\n';
    cout << "Fraction c is: " << c << '\n';

    //Testing x++ operator
    b = c++;
    cout << "Fraction b = c++ is: " << b << '\n';
    cout << "Fraction c is: " << c << '\n';

    //Testing x-- operator
    b = c--;
    cout << "Fraction b = c-- is: " << b << '\n';
    cout << "Fraction c is: " << c << '\n';

    //Testing == operator
    cout << "Is a == b: " << (a == b) << '\n';

    //Testing != operator
    cout << "Is e != b: " << (e != b) << '\n';

    //Testing < operator
    cout << "Is e < b: " << (e < b) << '\n';

    //Testing <= operator
    cout << "Is e <= b: " << (e <= b) << '\n';

    //Testing > operator
    cout << "Is e > b: " << (e > b) << '\n';

    //Testing >= operator
    cout << "Is e >= b: " << (e >= b) << '\n';

    //Testing + operator
    a = b + e;
    cout << "Fraction a is: " << a << '\n';

     //Testing - operator
    a = b - e;
    cout << "Fraction a is: " << a << '\n';

    //Testing * operator
    a = b * e;
    cout << "Fraction a is: " << a << '\n';

    //Testing / operator

}


#include <iostream>
#include "frac.h"
using namespace std;
int main()
{
    //Testing default constructor
    frac a;
    cout << "frac a is: " << a << '\n';

    //Testing parameterized (double) constructor
    frac b(2, -4);
    cout << "frac b is: " << b << '\n';
    frac c(-3, 7);
    cout << "frac c is: " << c << '\n';

    //Testing parameterized (single) constructor
    frac d(-8);
    cout << "frac d is: " << d << '\n';

    //Testing copy constructor
    frac e(b);
    cout << "frac e is: " << e << '\n';

    //Testing = operator
    b = c;
    cout << "frac b is: " << b << '\n';

    //Testing unary plus operator;
    cout << "frac +b is: " << +b << '\n';
    cout << "frac b is: " << b  << '\n';

    //Testing unary minus operator
    cout << "frac -b is: " << -b << '\n';
    cout << "frac b is: " << b << '\n';

    //Testing += operator
    c += d;
    cout << "frac c is: " << c << '\n';

     //Testing -= operator
    c -= d;
    cout << "frac c is: " << c << '\n';

     //Testing *= operator
    c *= d;
    cout << "frac c is: " << c << '\n';

    //Testing /= operator
    c /= d;
    cout << "frac c is: " << c << '\n';

    //Testing ++x operator
    b = ++c;
    cout << "frac b is: " << b << '\n';
    cout << "frac c is: " << c << '\n';

    //Testing --x operator
    b = --c;
    cout << "frac b is: " << b << '\n';
    cout << "frac c is: " << c << '\n';

    //Testing x++ operator
    b = c++;
    cout << "frac b is: " << b << '\n';
    cout << "frac c is: " << c << '\n';

    //Testing x-- operator
    b = c--;
    cout << "frac b is: " << b << '\n';
    cout << "frac c is: " << c << '\n';

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
    cout << "frac a is: " << a << '\n';

     //Testing - operator
    a = b - e;
    cout << "frac a is: " << a << '\n';

    //Testing * operator
    a = b * e;
    cout << "frac a is: " << a << '\n';

    //Testing / operator

}


# fraction-cpp
Fraction cplusplus library to deal with fractions encountered mainly in Gaussian Elimination

This library has the following functionality as public methods.
Most importantly the code will crash anytime the denominator is zero.
Also during any modification the numerators and denominators are reduced to co-prime.
fraction() { it will set to 0/1 }

operator=

fraction(const type& nume)

fraction(const type& nume, const type& deno)

unary +, unary-

+=, -=, *=, /=

operator++ (), operator-- (), operator++ (int), operator-- (int)

==, !=, <, <=, >, >=

+ - * /

Overloaded ostream<< and istream>>

# fraction-cpp
fraction cplusplus library to deal with fractions


This library has the following functionality as public methods
Most importantly the code will crash anytime the denominator is zeop.
Also during any modification the numerators and denominators are simplified.

fraction()
fraction(const fraction& other)
~fraction()
fraction& operator= (const fraction& other)
fraction(const type& nume)
explicit fraction(const type& nume, const type& deno)

fraction operator+ ()
fraction operator- ()
fraction& operator+= (const fraction& other)
fraction& operator-= (const fraction& other)
fraction& operator*= (const fraction& other)
fraction& operator/= (const fraction& other)

fraction& operator++ ()
fraction& operator-- ()
fraction operator++ (int)
fraction operator-- (int)

bool operator== (const fraction& other)
bool operator!= (const fraction& other)
bool operator< (const fraction& other)
bool operator<= (const fraction& other)
bool operator> (const fraction& other)
bool operator>= (const fraction& other)

fraction operator+ (fraction a, const fraction& b)
fraction operator- (fraction a, const fraction& b)
fraction operator* (fraction a, const fraction& b)
fraction operator/ (fraction a, const fraction& b)

std::ostream& operator<< (std::ostream& os, const fraction& a)
std::istream& operator>> (std::istream& is, fraction& a)

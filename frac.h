#ifndef _FRACTION_H
#define _FRACTION_H
#include <iostream>

class frac
{
public:	
	typedef long long int type;
    frac(): nume(0), deno(1) {}
    frac(const frac& other) = default;
    ~frac() = default; 
    frac& operator= (const frac& other) = default;
	frac(const type& nume): nume(nume), deno(1) {}
    explicit frac(const type& nume, const type& deno);

	frac operator+ () const;
	frac operator- () const;

    frac& operator+= (const frac& other);
    frac& operator-= (const frac& other);
    frac& operator*= (const frac& other);
    frac& operator/= (const frac& other);

    frac& operator++ ();
    frac& operator-- ();
    frac operator++ (int);
    frac operator-- (int);
	
	type read_nume() const;
	type read_deno() const;
    friend std::istream& operator>> (std::istream&, frac&);
		
private:
    type nume;
	type deno;

	void check_zero_deno() const;
    type gcd(const type& a, const type& b) const;
	type abs(const type& n) const;
    void simplify();
	void flip_negative();
};

void frac::check_zero_deno() const
{
	if(deno == 0)
	{
		std::cout << "Division by zero";
		exit(1);
	}
}

frac::type frac::gcd(const type& a, const type& b) const
{
	if(a)
	{
		return gcd(b % a, a);
	}
	return b;
}

frac::type frac::abs(const type& n) const
{
	if(n > 0)
	{
		return n;
	}
	return -n;
}

void frac::simplify()
{
	auto divider = gcd(abs(nume), deno);
	nume /= divider;
	deno /= divider;
}

void frac::flip_negative()
{
	if(deno < 0)
	{
		nume *= -1;
		deno *= -1;
	}
}

frac::frac(const type& nume, const type& deno): nume(nume), deno(deno)
{
	check_zero_deno();
	flip_negative();
	simplify();
}

frac frac::operator+ () const 
{
	return *this;
}

frac frac::operator- () const
{
	frac temp(*this);
	temp.nume *= -1;
	return temp;
}

frac& frac::operator+= (const frac& other)
{
	nume = nume * other.deno + other.nume * deno;
	deno *= other.deno;
	simplify();
	return *this;
}

frac& frac::operator-= (const frac& other) 
{
	return operator+= (-other);
}

frac& frac::operator*= (const frac& other)
{
	nume *= other.nume;
	deno *= other.deno;
	simplify();
	return *this;
}

frac& frac::operator/= (const frac& other)
{
	return operator*= (frac(other.deno, other.nume));
}

frac& frac::operator++ ()
{
	return operator+= (1);
}

frac& frac::operator-- ()
{
	return operator-= (1);
}

frac frac::operator++ (int)
{
	frac temp(*this);
	operator++();
	return temp;
}

frac frac::operator-- (int)
{
	frac temp(*this);
	operator--();
	return temp;
}

frac::type frac::read_nume() const
{
	return nume;
}

frac::type frac::read_deno() const
{
	return deno;
}

bool operator== (const frac& a, const frac& b)
{
	return a.read_nume() == b.read_nume() && a.read_deno() == b.read_deno();
}

bool operator!= (const frac& a, const frac& b)
{
	return !(a == b);
}
	
bool operator< (const frac& a, const frac& b)
{
	return a.read_nume() * b.read_deno() < b.read_nume() * a.read_deno();
}

bool operator<= (const frac& a, const frac& b)
{
	return a == b || a < b;
}

bool operator> (const frac& a, const frac& b)
{
	return !(a <= b);
}

bool operator>= (const frac& a, const frac& b)
{
	return !(a < b);
}
	
frac operator+ (frac& a, const frac& b)
{
	return a += b;
}

frac operator- (frac& a, const frac& b)
{
	return a -= b;
}

frac operator* (frac& a, const frac& b)
{
	return a *= b;
}
	
frac operator/ (frac& a, const frac& b)
{
	return a /= b;
}
	
std::ostream& operator<< (std::ostream& os, const frac& a)
{
    os << a.read_nume() << '/' << a.read_deno();
    return os;
}

std::istream& operator>> (std::istream& is, frac& a)
{
	frac::type nume, deno;
	is >> nume >> deno;
	a = frac(nume, deno);
    return is;
}
#endif
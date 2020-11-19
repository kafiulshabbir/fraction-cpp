#ifndef _FRACTION_H
#define _FRACTION_H
#include <iostream>

class fraction
{
	typedef long long int type;
	
private:
    type nume;
    type deno;

	void check_zero_deno() const
	{
		if(deno == 0)
		{
			std::cout << "Division by zero";
			exit(1);
		}
	}

    type gcd(const type& a, const type& b) const
    {
        if(a)
        {
            return gcd(b % a, a);
        }
        return b;
    }

	type abs(const type& n) const
	{
		if(n > 0)
		{
			return n;
		}
		return -n;
	}

    void simplify()
    {
        auto divider = gcd(abs(nume), deno);
        nume /= divider;
        deno /= divider;
    }

	void flip_negative()
	{
		if(deno < 0)
		{
			nume *= -1;
			deno *= -1;
		}
	}

public:	
    fraction(): nume(0), deno(1) {}
    fraction(const fraction& other) = default;
    ~fraction() = default; 
    fraction& operator= (const fraction& other) = default;
    
	fraction(const type& nume): nume(nume), deno(1) {}
    explicit fraction(const type& nume, const type& deno): nume(nume), deno(deno)
    {
		check_zero_deno();
		flip_negative();
        simplify();
    }

	fraction operator+ () const {return *this;}

	fraction operator- () const
	{
		fraction temp(*this);
		temp.nume *= -1;
		return temp;
	}

    fraction& operator+= (const fraction& other)
    {
		nume = nume * other.deno + other.nume * deno;
        deno *= other.deno;
        simplify();
        return *this;
    }

    fraction& operator-= (const fraction& other) {return operator+= (-other);}

    fraction& operator*= (const fraction& other)
    {
        nume *= other.nume;
        deno *= other.deno;
        simplify();
        return *this;
    }

    fraction& operator/= (const fraction& other)
	{
		return operator*= (fraction(other.deno, other.nume));
	}

    fraction& operator++ () {return operator+= (1);}
    fraction& operator-- () {return operator-= (1);}

    fraction operator++ (int)
    {
        fraction temp(*this);
        operator++();
        return temp;
    }

    fraction operator-- (int)
    {
        fraction temp(*this);
		operator--();
        return temp;
    }

    bool operator== (const fraction& other) const {return nume == other.nume && deno == other.deno;}
    bool operator!= (const fraction& other) const {return !(operator== (other));}
    bool operator< (const fraction& other) const {return nume * other.deno < other.nume * deno;}
    bool operator<= (const fraction& other) const {return operator== (other) || operator< (other);}
    bool operator> (const fraction& other) const {return !(operator<= (other));}
    bool operator>= (const fraction& other) const {return !(operator< (other));}

    friend std::ostream& operator<< (std::ostream&, const fraction&);
    friend std::istream& operator>> (std::istream&, fraction&);
};

fraction operator+ (fraction a, const fraction& b) {return a += b;}
fraction operator- (fraction a, const fraction& b) {return a -= b;}
fraction operator* (fraction a, const fraction& b) {return a *= b;}
fraction operator/ (fraction a, const fraction& b) {return a /= b;}

std::ostream& operator<< (std::ostream& os, const fraction& a)
{
    os << a.nume << '/' << a.deno;
    return os;
}

std::istream& operator>> (std::istream& is, fraction& a)
{
	fraction::type nume, deno;
	is >> nume >> deno;
	a = fraction(nume, deno);
    return is;
}
#endif
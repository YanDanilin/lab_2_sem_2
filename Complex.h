#pragma once

#include <iostream>

class Complex {
public:
	double re = 0.0;
	double im = 0.0;

	Complex(double a = 0.0, double b = 0.0) {
		re = a;
		im = b;
	}
	Complex(const Complex& z) {
		re = z.re;
		im = z.im;
	}
	~Complex() {}
	Complex& operator=(Complex z) {
		std::swap(re, z.re);
		std::swap(im, z.im);
		return *this;
	}
	Complex& operator+=(const Complex& z) {
		re += z.re;
		im += z.im;
		return *this;
	}
	Complex& operator-=(const Complex& z) {
		re -= z.re;
		im -= z.im;
		return *this;
	}
	Complex& operator++() {
		*this += 1;
		return *this;
	}
	Complex& operator--() {
		*this -= 1;
		return *this;
	}
	Complex operator++(int) {
		Complex copy = *this;
		++(*this);
		return copy;
	}
	Complex operator--(int) {
		Complex copy = *this;
		--(*this);
		return copy;
	}
	void Print() {
		std::cout << re << ((im >= 0) ? " + " : " ") << im << "i\n";
	}
};


Complex operator+(const Complex& a, const Complex& b) {
	Complex copy = a;
	copy += b;
	return copy;
}
Complex operator-(const Complex& a, const Complex& b) {
	Complex copy = a;
	copy -= b;
	return copy;
}
bool operator<(const Complex& a, const Complex& b) {
	return a.re * a.re + a.im * a.im < b.re * b.re + b.im * b.im;
}
bool operator>(const Complex& a, const Complex& b) {
	return b < a;
}
bool operator==(const Complex& a, const Complex& b) {
	return !(a < b || b < a);
}
bool operator!=(const Complex& a, const Complex& b) {
	return !(a == b);
}
std::ostream& operator<<(std::ostream& out, const Complex& z) {
	out << z.re << ((z.im >= 0) ? " + " : " ") << z.im << "i";
	return out;
}
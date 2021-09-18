#include <iostream>
#include <cstdio>
#include <cmath>

class Complex_t {
public:
	Complex_t(double re = 0, double im = 0) :
		re(re), 
		im(im) {
		};
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
	~Complex_t() {
	}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
	Complex_t(Complex_t &other) {
		re = other.re;
		im = other.im;
	}

	Complex_t(Complex_t &&other) {
		re = other.re;
		im = other.im;
	}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
	Complex_t &operator= (Complex_t &right) {
		re = right.re;
		im = right.im;
		return *this;
	}

	Complex_t &operator= (Complex_t &&right) {
		re = right.re;
		im = right.im;
		return *this;
	}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
	Complex_t &operator-= (Complex_t &right) {
		re -= right.re;
		im -= right.im;
		return *this;
	}

	Complex_t &operator-= (Complex_t &&right) {
		re -= right.re;
		im -= right.im;
		return *this;
	}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
	Complex_t &operator+= (Complex_t &right) {
		re += right.re;
		im += right.im;
		return *this;
	}

	Complex_t &operator+= (Complex_t &&right) {
		re += right.re;
		im += right.im;
		return *this;
	}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
	Complex_t &operator*= (Complex_t &right) {
		double tempRe = re;
		double tempIm = im;

		re = tempRe * right.re - tempIm * right.im;
		im = tempIm * right.re + tempRe * right.im;
		return *this;
	}

	Complex_t &operator*= (Complex_t &&right) {
		double tempRe = re;
		double tempIm = im;

		re = tempRe * right.re - tempIm * right.im;
		im = tempIm * right.re + tempRe * right.im;
		return *this;
	}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
	Complex_t &operator/= (Complex_t &right) {
		double tempRe = re;
		double tempIm = im;

		if (right.re == 0 && right.im == 0) {
			std::cout << "floating point exception" << std::endl;
			return *this;
		}

		re = (tempRe * right.re + tempIm * right.im) / (right.re * right.re + right.im * right.im);
		im = (tempIm * right.re - tempRe * right.im) / (right.re * right.re + right.im * right.im);
		return *this;
	}

	Complex_t &operator/= (Complex_t &&right) {
		double tempRe = re;
		double tempIm = im;

		if (right.re == 0 && right.im == 0) {
			std::cout << "floating point exception" << std::endl;
			return *this;
		}

		re = (tempRe * right.re + tempIm * right.im) / (right.re * right.re + right.im * right.im);
		im = (tempIm * right.re - tempRe * right.im) / (right.re * right.re + right.im * right.im);
		return *this;
	}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
	Complex_t operator- () {
		re = -re;
		im = -im;
		return *this;
	}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
	Complex_t operator+ (){
		return *this;
	}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
	Complex_t operator~ (){
		Complex_t res = *this;
		res.im = -res.im;
		return res;
	}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
	bool operator== (Complex_t &other) const{
		if (re == other.re && im == other.im) return true;
		return false;
	}

	bool operator== (Complex_t &&other) const{
		if (re == other.re && im == other.im) return true;
		return false;
	}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
	double re;
	double im;
};
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
Complex_t operator- (Complex_t &left, Complex_t &right) {
	Complex_t res = left;
	res -= right;
	return res;
}

Complex_t operator- (Complex_t &&left, Complex_t &right) {
	Complex_t res = left;
	res -= right;
	return res;
}

Complex_t operator- (Complex_t &left, Complex_t &&right) {
	Complex_t res = left;
	res -= right;
	return res;
}

Complex_t operator- (Complex_t &&left, Complex_t &&right) {
	Complex_t res = left;
	res -= right;
	return res;
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
Complex_t operator+ (Complex_t &left, Complex_t &right) {
	Complex_t res = left;
	res += right;
	return res;
}

Complex_t operator+ (Complex_t &&left, Complex_t &right) {
	Complex_t res = left;
	res += right;
	return res;
}

Complex_t operator+ (Complex_t &left, Complex_t &&right) {
	Complex_t res = left;
	res += right;
	return res;
}

Complex_t operator+ (Complex_t &&left, Complex_t &&right) {
	Complex_t res = left;
	res += right;
	return res;
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
Complex_t operator* (Complex_t &left, Complex_t &right) {
	Complex_t res = left;
	res *= right;
	return res;
}

Complex_t operator* (Complex_t &&left, Complex_t &right) {
	Complex_t res = left;
	res *= right;
	return res;
}

Complex_t operator* (Complex_t &left, Complex_t &&right) {
	Complex_t res = left;
	res *= right;
	return res;
}

Complex_t operator* (Complex_t &&left, Complex_t &&right) {
	Complex_t res = left;
	res *= right;
	return res;
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
Complex_t operator/ (Complex_t &left, Complex_t &right) {
	Complex_t res = left;
	res /= right;
	return res;
}

Complex_t operator/ (Complex_t &&left, Complex_t &right) {
	Complex_t res = left;
	res /= right;
	return res;
}

Complex_t operator/ (Complex_t &left, Complex_t &&right) {
	Complex_t res = left;
	res /= right;
	return res;
}

Complex_t operator/ (Complex_t &&left, Complex_t &&right) {
	Complex_t res = left;
	res /= right;
	return res;
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
std::ostream &operator<< (std::ostream &left, Complex_t &right)  {
	left << "(" << right.re << " + " << right.im << "i)"; 
	return left;
}

std::istream &operator>> (std::istream &left, Complex_t &right)  {
	left >> right.re >> right.im; 
	return left;
}
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
Complex_t exp(Complex_t &z) {
	Complex_t res;
	double mult = exp(z.re);
		 res.re = mult * cos(z.im);
		 res.im = mult * sin(z.im);
	return res;
}

Complex_t exp(Complex_t &&z) {
	Complex_t res;
	double mult = exp(z.re);
		 res.re = mult * cos(z.im);
		 res.im = mult * sin(z.im);
	return res;
}
//-----------------------------------------------------------------------------------------------------------------
Complex_t sin(Complex_t &z) {
	Complex_t res(cosh(z.re) * sin(z.im), sinh(z.im) * cos(z.re));
	return res;
}

Complex_t sin(Complex_t &&z) {
	Complex_t res(cosh(z.re) * sin(z.im), sinh(z.im) * cos(z.re));
	return res;
}
//-----------------------------------------------------------------------------------------------------------------
double norm(Complex_t &z) {
	return sqrt(z.re * z.re + z.im * z.im);
}

double norm(Complex_t &&z){
	return sqrt(z.re * z.re + z.im * z.im);
}
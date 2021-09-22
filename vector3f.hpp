#include <iostream>
#include <stdio.h>
#include <cmath>

struct Vector3f_t {

	Vector3f_t(double x = 0, double y = 0, double z = 0) :
		x(x), 
		y(y), 
		z(z) {
	}
//----------------------------------------------------------------------------------------------------------------
	~Vector3f_t() {
	}
//----------------------------------------------------------------------------------------------------------------
	Vector3f_t(Vector3f_t &other) {
		x = other.x;
		y = other.y;
		z = other.z;
	}

	Vector3f_t(Vector3f_t &&other) {
		x = other.x;
		y = other.y;
		z = other.z;
	}

	Vector3f_t(const Vector3f_t &other) {
		x = other.x;
		y = other.y;
		z = other.z;
	}
//----------------------------------------------------------------------------------------------------------------
	Vector3f_t &operator= (Vector3f_t &other) {
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

	Vector3f_t &operator= (Vector3f_t &&other) {
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}
//----------------------------------------------------------------------------------------------------------------
	Vector3f_t &operator+= (Vector3f_t &other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	Vector3f_t &operator+= (Vector3f_t &&other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}
//----------------------------------------------------------------------------------------------------------------
	Vector3f_t &operator-= (Vector3f_t &other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	Vector3f_t &operator-= (Vector3f_t &&other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}
//----------------------------------------------------------------------------------------------------------------
	Vector3f_t &operator*= (double lambda) {
		x *= lambda;
		y *= lambda;
		z *= lambda;
		return *this;
	}
//----------------------------------------------------------------------------------------------------------------
	Vector3f_t &operator/= (double lambda) {
		if (lambda == 0) {
			std::cout << "Floating point exception\n" ;
			return *this;
		}
		x /= lambda;
		y /= lambda;
		z /= lambda;
		return *this;
	}
//----------------------------------------------------------------------------------------------------------------
	double operator*= (Vector3f_t &other) {
		return x * other.x + y * other.y + z * other.z;
	}

	double operator*= (Vector3f_t &&other) {
		return x * other.x + y * other.y + z * other.z;
	}
//----------------------------------------------------------------------------------------------------------------
	Vector3f_t operator- () const{
		Vector3f_t result = *this;
		result.x = -result.x;
		result.y = -result.y;
		result.z = -result.z;
		return result;
	}
//----------------------------------------------------------------------------------------------------------------
	Vector3f_t operator+ () const{
		Vector3f_t result = *this;
		return result;
	}
//----------------------------------------------------------------------------------------------------------------
	bool operator==(Vector3f_t &other) const{
		return (x == other.x && y == other.y && z == other.z);
	}

	bool operator==(Vector3f_t &&other) const{
		return (x == other.x && y == other.y && z == other.z);
	}

	bool operator!=(Vector3f_t &other) const{
		return (!(*this == other));
	}

	bool operator!=(Vector3f_t &&other) const{
		return (!(*this == other));
	}
//----------------------------------------------------------------------------------------------------------------
	double x;
	double y;
	double z;
};
//----------------------------------------------------------------------------------------------------------------
	Vector3f_t operator* (double k, Vector3f_t &other) {
		Vector3f_t result = other;
		return (result *= k);
	}

	Vector3f_t operator* (double k, Vector3f_t &&other) {
		Vector3f_t result = other;
		return (result *= k);
	}

	Vector3f_t operator* (Vector3f_t &other, double k) {
		Vector3f_t result = other;
		return (result *= k);
	}

	Vector3f_t operator* (Vector3f_t &&other, double k) {
		Vector3f_t result = other;
		return (result *= k);
	}
//----------------------------------------------------------------------------------------------------------------
	double operator* (Vector3f_t &left, Vector3f_t &right) {
		Vector3f_t result = left;
		return (result *= right);
	}

	double operator* (Vector3f_t &left, Vector3f_t &&right) {
		Vector3f_t result = left;
		return (result *= right);
	}

	double operator* (Vector3f_t &&left, Vector3f_t &right) {
		Vector3f_t result = left;
		return (result *= right);
	}

	double operator* (Vector3f_t &&left, Vector3f_t &&right) {
		Vector3f_t result = left;
		return (result *= right);
	}
//----------------------------------------------------------------------------------------------------------------
	Vector3f_t operator/ (Vector3f_t &other, double k) {
		Vector3f_t result = other;
		return (result *= k);
	}

	Vector3f_t operator/ (Vector3f_t &&other, double k) {
		Vector3f_t result = other;
		return (result *= k);
	}
//----------------------------------------------------------------------------------------------------------------
	Vector3f_t operator+ (Vector3f_t &left, Vector3f_t &right) {
		Vector3f_t result = left;
		return (result += right);
	}

	Vector3f_t operator+ (Vector3f_t &left, Vector3f_t &&right) {
		Vector3f_t result = left;
		return (result += right);
	}

	Vector3f_t operator+ (Vector3f_t &&left, Vector3f_t &right) {
		Vector3f_t result = left;
		return (result += right);
	}

	Vector3f_t operator+ (Vector3f_t &&left, Vector3f_t &&right) {
		Vector3f_t result = left;
		return (result += right);
	}
//----------------------------------------------------------------------------------------------------------------
	Vector3f_t operator- (Vector3f_t &left, Vector3f_t &right) {
		Vector3f_t result = left;
		return (result -= right);
	}

	Vector3f_t operator- (Vector3f_t &left, Vector3f_t &&right) {
		Vector3f_t result = left;
		return (result -= right);
	}

	Vector3f_t operator- (Vector3f_t &&left, Vector3f_t &right) {
		Vector3f_t result = left;
		return (result -= right);
	}

	Vector3f_t operator- (Vector3f_t &&left, Vector3f_t &&right) {
		Vector3f_t result = left;
		return (result -= right);
	}
//----------------------------------------------------------------------------------------------------------------
std::ostream &operator<< (std::ostream &left, Vector3f_t &right)  {
	left << "{" << right.x << " ; " << right.y << " ; " << right.z <<  "}"; 
	return left;
}

std::ostream &operator<< (std::ostream &left, Vector3f_t &&right)  {
	left << "{" << right.x << " ; " << right.y << " ; " << right.z <<  "}"; 
	return left;
}

std::ostream &operator<< (std::ostream &left,const Vector3f_t &right)  {
	left << "{" << right.x << " ; " << right.y << " ; " << right.z <<  "}"; 
	return left;
}

std::istream &operator>> (std::istream &left, Vector3f_t &right)  {
	left >> right.x >> right.y >> right.z; 
	return left;
}

std::istream &operator>> (std::istream &left, Vector3f_t &&right)  {
	left >> right.x >> right.y >> right.z; 
	return left;
}

std::istream &operator>> (std::istream &left, const Vector3f_t &right)  {
	left >> right.x >> right.y >> right.z; 
	return left;
}
//----------------------------------------------------------------------------------------------------------------
double squared_norm(Vector3f_t &a) {
	return (a * a);
}

double squared_norm(Vector3f_t &&a) {
	return (a * a);
}
//----------------------------------------------------------------------------------------------------------------
double norm(Vector3f_t &a) {
	return sqrt(squared_norm(a));
}

double norm(Vector3f_t &&a) {
	return sqrt(squared_norm(a));
}
//----------------------------------------------------------------------------------------------------------------
void normalize(Vector3f_t &a) {
	a /= norm(a);
}
//----------------------------------------------------------------------------------------------------------------
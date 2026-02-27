#include <iostream>
#include <cmath>

using namespace std;

class ComplexNumber {
private:
    double real;
    double imag;

public:
    // Constructor
    ComplexNumber(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    // Getter
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // ================= Operator + =================
    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    ComplexNumber operator+(double value) const {
        return ComplexNumber(real + value, imag);
    }

    friend ComplexNumber operator+(double value, const ComplexNumber& c) {
        return ComplexNumber(value + c.real, c.imag);
    }

    // ================= Operator - =================
    ComplexNumber operator-(const ComplexNumber& other) const {
        return ComplexNumber(real - other.real, imag - other.imag);
    }

    ComplexNumber operator-(double value) const {
        return ComplexNumber(real - value, imag);
    }

    friend ComplexNumber operator-(double value, const ComplexNumber& c) {
        return ComplexNumber(value - c.real, -c.imag);
    }

    // ================= Operator * =================
    ComplexNumber operator*(const ComplexNumber& other) const {
        return ComplexNumber(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    ComplexNumber operator*(double value) const {
        return ComplexNumber(real * value, imag * value);
    }

    friend ComplexNumber operator*(double value, const ComplexNumber& c) {
        return ComplexNumber(c.real * value, c.imag * value);
    }

    // ================= Operator / =================
    ComplexNumber operator/(const ComplexNumber& other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        return ComplexNumber(
            (real * other.real + imag * other.imag) / denom,
            (imag * other.real - real * other.imag) / denom
        );
    }

    ComplexNumber operator/(double value) const {
        return ComplexNumber(real / value, imag / value);
    }

    friend ComplexNumber operator/(double value, const ComplexNumber& c) {
        double denom = c.real * c.real + c.imag * c.imag;
        return ComplexNumber(
            (value * c.real) / denom,
            (-value * c.imag) / denom
        );
    }

    // ================= Operator == =================
    bool operator==(const ComplexNumber& other) const {
        return real == other.real && imag == other.imag;
    }

    bool operator==(double value) const {
        return real == value && imag == 0;
    }

    friend bool operator==(double value, const ComplexNumber& c) {
        return c.real == value && c.imag == 0;
    }

    // ================= abs() =================
    double abs() const {
        return sqrt(real * real + imag * imag);
    }

    // ================= angle() =================
    double angle() const {
        double rad = atan2(imag, real);
        return rad * 180.0 / M_PI;
    }

    // ================= Operator << =================
    friend ostream& operator<<(ostream& os, const ComplexNumber& c) {

        if (c.real == 0 && c.imag == 0) {
            os << 0;
        }
        else if (c.imag == 0) {
            os << c.real;
        }
        else if (c.real == 0) {
            if (c.imag == 1)
                os << "i";
            else if (c.imag == -1)
                os << "-i";
            else
                os << c.imag << "i";
        }
        else {
            os << c.real;
            if (c.imag > 0)
                os << "+" << c.imag << "i";
            else
                os << c.imag << "i";
        }

        return os;
    }
};
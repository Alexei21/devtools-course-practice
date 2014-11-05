// Copyright 2014 Julia Buchina

#include "include/fraction.h"

#include <stdint.h>
#include <limits.h>
#include <string>

Fraction::Fraction(): numerator(0), denominator(1) {}
Fraction::~Fraction() {}

void CheckValue(int64_t a);
int64_t GCD(int64_t a, int64_t b);

void CheckValue(int64_t a) {
    if (a > INT_MAX)
        throw std::string("Value is larger than INT_MAX");
    else if (a < -INT_MAX)
        throw std::string("Value is less than -INT_MAX");
}

int64_t GCD(int64_t a, int64_t b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

Fraction::Fraction(int _numerator, int _denominator) {
    CheckValue(_numerator);
    CheckValue(_denominator);

    if (_denominator != 0) {
        numerator = _numerator;
        denominator = _denominator;
    } else {
        throw std::string("Can't divide by zero");
    }
}

Fraction::Fraction(const Fraction& fraction):
    numerator(fraction.getNumerator()), denominator(fraction.getDenominator()) {
}

int Fraction::getNumerator() {
    return numerator;
}

int Fraction::getDenominator() {
    return denominator;
}

void Fraction::setNumerator(int _numerator) {
    numerator = _numerator;
}

void Fraction::setDenominator(int _denominator) {
    if (_denominator != 0) {
        denominator = _denominator;
    } else {
        throw std::string("Can't divide by zero");
    }
}

const Fraction& Fraction::operator=(const Fraction& fraction) {
    numerator = fraction.getNumerator();
    denominator = fraction.getDenominator();
    return *this;
}

Fraction& Fraction::operator+(const Fraction& a) {
    Fraction tmp;
    int64_t tmpNumerator = static_cast<int64_t>(a.getNumerator()) *
                           static_cast<int64_t>(this->getDenominator()) +
                           static_cast<int64_t>(this->getNumerator()) *
                           static_cast<int64_t>(a.getDenominator());
    int64_t tmpDenominator = static_cast<int64_t>(a.getDenominator()) *
                             static_cast<int64_t>(this->getDenominator());

    int64_t tmpGCD = GCD(tmpNumerator, tmpDenominator);
    tmpNumerator = tmpNumerator / tmpGCD;
    tmpDenominator = tmpDenominator / tmpGCD;

    CheckValue(tmpNumerator);
    CheckValue(tmpDenominator);

    tmp.setNumerator(static_cast<int>tmpNumerator);
    tmp.setDenominator(static_cast<int>tmpDenominator);
    return tmp;
}

Fraction& Fraction::operator-(const Fraction& a) {
    Fraction tmp;
    int64_t tmpNumerator = static_cast<int64_t>(a.getNumerator()) *
                           static_cast<int64_t>(this->getDenominator()) -
                           static_cast<int64_t>(this->getNumerator()) *
                           static_cast<int64_t>(a.getDenominator());
    int64_t tmpDenominator = static_cast<int64_t>(a.getDenominator()) *
                             static_cast<int64_t>(this->getDenominator());

    int64_t tmpGCD = GCD(tmpNumerator, tmpDenominator);
    tmpNumerator = tmpNumerator / tmpGCD;
    tmpDenominator = tmpDenominator / tmpGCD;

    CheckValue(tmpNumerator);
    CheckValue(tmpDenominator);

    tmp.setNumerator(static_cast<int>tmpNumerator);
    tmp.setDenominator(static_cast<int>tmpDenominator);
    return tmp;
}

Fraction& Fraction::operator*(const Fraction& a) {
    Fraction tmp;
    int64_t tmpNumerator = static_cast<int64_t>(a.getNumerator()) *
                           static_cast<int64_t>(this->getNumerator());
    int64_t tmpDenominator = static_cast<int64_t>(a.getDenominator()) *
                             static_cast<int64_t>(this->getDenominator());

    int64_t tmpGCD = GCD(tmpNumerator, tmpDenominator);
    tmpNumerator = tmpNumerator / tmpGCD;
    tmpDenominator = tmpDenominator / tmpGCD;

    CheckValue(tmpNumerator);
    CheckValue(tmpDenominator);

    tmp.setNumerator(static_cast<int>tmpNumerator);
    tmp.setDenominator(static_cast<int>tmpDenominator);
    return tmp;
}

Fraction& Fraction::operator/(const Fraction& a) {
    Fraction tmp;
    int64_t tmpNumerator = static_cast<int64_t>(a.getNumerator()) *
                           static_cast<int64_t>(this->getDenominator());
    int64_t tmpDenominator = static_cast<int64_t>(a.getDenominator()) *
                             static_cast<int64_t>(this->getNumerator());

    int64_t tmpGCD = GCD(tmpNumerator, tmpDenominator);
    tmpNumerator = tmpNumerator / tmpGCD;
    tmpDenominator = tmpDenominator / tmpGCD;

    CheckValue(tmpNumerator);
    CheckValue(tmpDenominator);

    tmp.setNumerator(static_cast<int>tmpNumerator);
    tmp.setDenominator(static_cast<int>tmpDenominator);
    return tmp;
}

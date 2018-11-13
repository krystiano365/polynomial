//
// Created by krystian on 12.11.18.
//

#include <iostream>
#include <math.h>
#include "Poly.h"

//Poly::Poly(double coeff) {
//	word w1(coeff);
//	w1.index = 0;
//	polynomial.at(words_no) = w1;
//}
//
//Poly::word Poly::operator[] (const unsigned int i) {
//	return polynomial.at(i);
//}
//
double& Poly::operator[] (const int index) {
	unsigned int i = words_no;
	words_no++;
	word w;
	w.index = index;
	polynomial.emplace_back(w);
	return polynomial.at(i).coeff;
}




//Poly& Poly::operator= (const double coeff) {
//	word w;
//	w.coeff = coeff;
//	return w;
//}


Poly::Poly() {
	words_no = 0;
}

//void Poly::print(){
//	cout << to_string(polynomial.at(words_no - 1).index) + ", " + to_string(polynomial.at(words_no - 1).coeff) << endl;
//}

ostream &operator<<(ostream &os, const Poly &poly) {
	bool notFirst = false;
	bool sign = false;
	for (auto iterator : poly.polynomial) {
		double coeff = iterator.coeff;
		int index = iterator.index;

		if(coeff < 0) {
			os << " - ";
			sign = true;
		}

		if(notFirst && !sign) {
				os << " + ";
		}

		if(coeff != 0) {
			os << fabs(coeff);
		}

		if(index >= 1) {
			os << "x";
		}

		if(index > 1) {
			os << "^" << index;
		}
		notFirst = true;
	}
	return os;
}

//double Poly::operator[] (int index) {
//	return polynomial.at(index).coeff;
//}
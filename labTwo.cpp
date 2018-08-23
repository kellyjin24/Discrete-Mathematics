/* Name: Kai Li Jin
 * Date: November 2, 2017
 * Description: This program has multiple functions: the Euclidean
 * algorithm, the inverse modulo, primality test using Fermat's Little Theorem,
 * relative prime, and RSA algorithm.
 */

#include <iostream>
#include <cmath>
#include <assert.h>
using namespace std;

int setModulus(int, int);
int gcd(int, int, int&, int&);
int relativePrime(int);
int inverse(int, int);
int encode(int, int, int);
int decode(int, int, int);
int rsa(int, int);
int modExponent(int, int, int);

int a = 0, b = 0;
int s, t;

int main() {

	cout << "Enter two numbers (a, b) to calculate their greatest common divisor: " << endl;
	cout << "a = ";
	cin >> a;

	cout << "b = ";
	cin >> b;
	cout << endl;

	if (a >= b && b >= 0) {
		gcd(a, b, s, t);
	}

	while (a <= b && b <= 0) {

		cout << "Precondition must be a >= b >= 0! Please try again." << endl;
		cout << "a = "; 
		cin >> a;

		cout << "b = ";
		cin >> b;

		gcd(a, b, s, t);
	} 

	cout << "gcd(" << a << ", " << b << ") = " << gcd(a, b, s, t) << " and" << endl; 
	cout << gcd(a, b, s, t) << " = (" << a << " * s) ";
	cout << " + (" << b << " * t)" << endl;
	cout << "where s = " << s << " and t = " << t << endl;
	cout << endl;

	int y = relativePrime(a);
	cout << y << " is relative prime with " << a << "." << endl;
	cout << endl;

	int w = inverse(y, a);
	cout << w << " is the inverse modulo." << endl;	
	cout << endl;
	
	int h = rsa(a, b);
	cout << "After encryption and decryption, the message is: " << h << endl;

	return 0;
}

// Calculate modulo
int setModulus(int a, int b) {
	int m = 0, r = 0;
	
	if (a > 0) {
		m = a % b; // remainder when a is divided by n
	}

	else {
		r = a; // set the value of a to r;

		do {
			a = a + b; // continue adding n to the value of a, and update the new value of a, until a is positive

		} while (a < 0 );

		m = a;
	}

	return m;
}

// 1) Extended Euclidean Algorithm
int gcd(int a, int b, int& s, int& t) {
	if (b == 0) {
		s = 1;
		t = 0;

		return a; // a = (a*s) + (b*t)
	}
	
	else {
		int q = a/b;
		int r = setModulus(a, b); 

		int s1, t1;

		int d = gcd(b, r, s1, t1);

		s = t1;
		t = s1 - (t1*q);

		return d;
	}
}

// 4) Relative Prime
int relativePrime(int a) {

	for (int y = 3; y < a - 1; y++) {	
		if ((gcd(a, y, s, t)) == 1) {
			return y;
		}
	}
}

// 2) Inverse modulo
int inverse(int a, int y) {
	int d = gcd(y, a, s, t);

	if (d == 1) {
		return setModulus(t, y);
	}

	else {
		cout << a << " and " << b << " are NOT relative primes." << endl;
	}
}

// Function that calculates only the exponent result
int modExponent(int M, int d, int PQ) {

	if (d == 0) {
		return 1;
	}

	int result = modExponent(M, d/2, PQ); // Recursion

	if (d % 2 == 0) {
		return setModulus((result * result), PQ);
	}

	else {
		return setModulus((setModulus(result * result, PQ) * M), PQ);
	}
}

// Called by RSA function
int encode(int M, int d, int PQ) { // return M^d mod PQ
	return modExponent(M, d, PQ);
}

// Called by RSA function
int decode(int C, int e, int PQ) { // return C^e mod PQ
	return modExponent(C, e, PQ);
}

// 5) RSA algorithm
int rsa(int a, int b) {
	int M = 0;
	int P, Q;
	cout << "Enter a P value: ";
	cin >> P;

	cout << "Enter a Q value: ";
	cin >> Q;

	int PQ = P * Q;
	int l = (P - 1) * (Q - 1);

	int d = relativePrime(l); // d is relatively prime with (P - 1)(Q - 1)
	int e = inverse(d, l); // e and d are inverse modulo of each other

	assert (setModulus((e * d), l) == 1);

	cout << "d = " << d << endl;
	cout << "e = " << e << endl;
	cout << "l = " << l << endl;


	cout << "Enter an integer that is less than " << PQ << ": ";
	cin >> M;

	int C = encode(M, d, PQ);
	int M1 = decode(C, e, PQ);

	assert (M == M1);

	return M1;
}




/* Name: Kai Li Jin
 * Date: October 17, 2017
 * Description: This program consists of various functions that returns the modulus, primality,
 * and prime factorization.
 */

#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

int setModulus(int, int);
bool isPrime(int);
void primeFactorization(int);
void firstHundred();
int modAddition(int);
int modSubtraction(int);
int modMultiplication(int);
int modExponent(int, int);
// void modMultTable(int);

int a = 0, b = 0, n = 0, e = 0, f = 0, g = 0, j = 0; // initialize variables

int main() {

	cout << endl;
	cout << "a mod n = ___" << endl;
	cout << "Enter an integer for a: ";
	cin >> a;

	cout << "Enter an integer for n where n > 1: ";
	cin >> n;
	cout << endl;

	if (n > 1) {

		// 1. Modular arithmetic
		cout << a << " mod " << n << " = " << setModulus(a, n) << endl;

		// 2. Primality
		if (isPrime(n) == true) { // if n is prime
			cout << n << " is a prime number!" << endl;
		}

		if (isPrime(n) == false) { // if n is not prime
			cout << n << " is NOT a prime number!" << endl;
		}

		// 3. Prime Factorization
		primeFactorization(n); // pass this function the entered value of n


		// 4. The first 100 prime numbers
		cout << endl;
		cout << "The first hundred prime numbers are: ";
		firstHundred(); // display the first two hundred prime numbers... function is not passed any values
		cout << endl;
		cout << endl;

		// 5. Modular addition, subtraction, and multiplication
		cout << "Enter a number to add to a (a+b), (a-b), and (a*b): ";
		cin >> b;
		modAddition(b); // pass the value of b to the function that performes modular arithmetics
		cout << "(" << a << " + " << b << ") mod " << n << " = " << modAddition(b) << endl;
		cout << "(" << a << " - " << b << ") mod " << n << " = " << modSubtraction(b) << endl;
		cout << "(" << a << " * " << b << ") mod " << n << " = " << modMultiplication(b) << endl;

		cout << endl;

		// 6. Modular exponents
		cout << a + b << "^e mod " << n << " = ___" << endl;
		cout << "Enter a number for the value of e that is greater than 0: ";
		cin >> e;
	
		if (e > 0) {
			modExponent(a, e);
			cout << a + b << "^" << e << " mod " << n << " = ";
			cout << modExponent(a, e) << endl;
		}
	}

	cout << endl;

	return 0;
}

int setModulus(int a, int n) {
	int r = 0;
	
	if (a > 0) {
		r = a % n; // remainder when a is divided by n
	}

	else {
		r = a; // set the value of a to r;

		do {
			a = a + n; // continue adding n to the value of a, and update the new value of a, until a is positive

		} while (a < 0 );

		r = a;
	}

	return r;
}

bool isPrime(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) { // if the number can be divded by a number other than 1 and itself, then it is NOT prime => return false
			return false;
		}
	}

	return true; // return true if the number can only be divided by 1 and itself
}

void primeFactorization (int n) {
	if (isPrime(n)) { // if it is prime, then its prime factorization is n^1 * 1^1.
		cout << n << " = " << "1^1 * " << n << "^1" << endl;
	}

	else { // if it is not prime
		if (n % 2 == 0) { // if n is even
			int counterOne = 0;

			cout << n << " = ";

			while (n % 2 == 0) {
				n = n / 2; // update new value of n

				counterOne++; // keeps track of exponent value
			}

			cout << "2^" << counterOne << " * " << n << "^1" << endl;
		}

		if (n % 2 == 1) { // if n is odd
			int counterTwo = 0;

			cout << n << " = ";

			for (int i = 3; i <= n - 2; i++) {
				while (n % i == 0) { // while i divides n
					n = n / i; // update new value of n

					counterTwo++; // keeps track of exponent value
				}

				cout << i << "^" << counterTwo << " * ";
			}

			cout << n << "^1" << endl;
		}
	}
}

void firstHundred() {
	clock_t t;
	t = clock();	

	for (int i = 2; i <= 100; i++) { // range being tested for primality

		if (isPrime(i) == true) { // each i is passed to the primality function
			cout << " " << i; // if it is prime, then it is displayed.
		}
	}
}

int modAddition(int b) {
	int s, a, c;

	c = setModulus(a, n) + setModulus(b, n);
	s = setModulus(c, n);

	return s;
}

int modSubtraction(int b) {
	int s, a, c;

	c = setModulus(a, n) - setModulus(b, n);
	s = setModulus(c, n);

	return s;
}

int modMultiplication(int b) {
	int s, a, c;

	c = setModulus(a, n) * setModulus(b, n);
	s = setModulus(c, n);

	return s;
}

// Function that calculates only the exponent result
int exponent(int a, int e) {

	if (e == 0) {
		return 1;
	}

	int result = exponent(a, e/2); // Recursion

	if (e % 2 == 0) {
		return result * result;
	}

	else {
		return result * result * a;
	}
}

// Function that calculates the modular exponent
int modExponent(int a, int e) {
	j = exponent(a, e); // Assigns the value of the exponent function to an integer variable

	return setModulus(j, n);
}


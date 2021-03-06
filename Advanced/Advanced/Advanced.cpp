#include "pch.h"
#include <iostream>
#include <exception>
#include <vector>
#include <array>
#include <string>

using namespace std;

class derivedexception : public exception {
	virtual const char* what() const throw() {
		return "My derived exception";
	}
} myderivedexception;

int f(int n)
{
	vector<int> v;
	int j(0);

	while (n != 0) {
		v.push_back(n % 1000);
		n = n / 1000;
	}

	if (not v.empty()) {
		for (size_t i(v.size() - 1); i > 0; --i) {
			for (++j; v[i] >= j; j = j + 2) {
				v[i] = v[i] - j;
			}

			j = 10 * (j - 1);
			v[i - 1] = v[i - 1] + 10 * v[i];
		}

		for (++j; v[0] >= j; j = j + 2) {
			v[0] = v[0] - j;
		}

		// code manquant
		return 2 * j;
	}
}
template<class TContainer>
class VecScopeGuard {
public:
	VecScopeGuard(TContainer* vecptr)
		: engaged_(true), vecptr_(vecptr) { //Assign vecptr and set guard to true.
	}

	~VecScopeGuard() {
		if (engaged_) {
			//Remove last vector entry
			vecptr_->pop_back();
		}
	}
	void disengage() {
		engaged_ = false;
		//Vectors updated so release guard
	}
private:
	bool engaged_;
	TContainer* vecptr_;
};


int stuff()
{
	vector<string> firstvector;
	vector<string> secondvector;
	string mystring("Hello world!");

	try {
		firstvector.push_back(mystring);
		VecScopeGuard<vector<string>> guard1(&firstvector);
		secondvector.push_back(mystring);
		VecScopeGuard<vector<string>> guard2(&secondvector);

		guard1.disengage();
		guard2.disengage();
	}
	catch (...) {
		cout << "Caught error." << endl;
	}

	cout << "First use of scope guards ok, first vector size is  " << firstvector.size() << " second vector size is " << secondvector.size() << endl;

	//Clear vectors.
	firstvector.clear();
	secondvector.clear();

	try {
		firstvector.push_back(mystring);
		VecScopeGuard<std::vector<std::string>> guard1(&firstvector);
		std::bad_alloc excp;
		throw excp; //Replicate error updating second vector.
		secondvector.push_back(mystring);
		VecScopeGuard<std::vector<std::string>> guard2(&secondvector);
		guard1.disengage();
		guard2.disengage();
	}
	catch (std::bad_alloc e) {
		cout << "Caught exception " << endl;
		cout << "Second use of scope guards error, first vector size is  " << firstvector.size() << " second vector size is " << secondvector.size() << endl;
	}

	cout << endl << endl;

	cout << f(20000) << endl;
	vector<vector <double>> tab(10, vector<double>(3));

	cout << sizeof(tab[5]) << endl;

	vector<int> v(4, 3);

	for (size_t i(0); i < v.size(); ++i) {
		v[i] = v[i] + i;
	}
	v.back() = 8;
	v.push_back(10);
	v.front() = 2;

	for (int i = 0; i < 5; i++) {
		try {
			cout << v[i] << " ";
		}
		catch (...) {
			cout << "Error!";
		}
	}

	cout << endl;
	try {
		throw myderivedexception;
	}
	catch (exception& e) {
		cout << e.what() << '\n';
	}

	return 0;
}

int conv(string s) {
	int i(0);
	for (size_t j(0); j < s.size(); ++j) {
		i = i * 10 + (s[j] - '0');
		/* Note: (s[j] - '0') convertit le caractere s[j] en
		 *       sa valeur entière :
		 *          '0' en l'entier 0, '1' en 1, '2 'en 2, etc.
		 */
	}
	return i;
}

void go(string s1, string s2) {
	string sub1;
	string sub2;
	int v(conv(s2));
	size_t size(s1.size());

	for (size_t i(0); i < size; ++i) {
		sub1 = s1.substr(0, i + 1);
		sub2 = s1.substr(i + 1, size - i);
		if (i + 1 == size) sub2 = "0";
		if ((conv(sub1) + conv(sub2)) == v) {
			cout << sub1 << " + " << sub2;
			cout << " = " << v << endl;
		}
	}
}

char decale(char c, char debut, int decalage) {
	return debut + (((c - debut) + decalage) % 26);
}

char code(char c, int d) {
	if (d < 0) {
		d += 26;
	}
	if (c >= 'a' && c <= 'z') {
		return decale(c, 'a', d);
	}
	if (c >= 'A' && c <= 'Z') {
		return decale(c, 'A', d);
	}
	else {
		return c;
	}
}

string code(string s, int d) {
	string encoded = "";

	for (auto c : s) {
		encoded += code(c, d);
	}
	return encoded;
}

string decode(string s, int d) {
	return code(s, -d);
}

int main() {
	cout << decale('g', 'a', -28) << endl;

	string raw = "Fuyez manants";
	int shift = -4;
	string encoded = code(raw, shift);
	
	cout << encoded << endl;

	cout << decode(encoded, shift) << endl;

	char c('c');
	char debut('a');
	int decalage = 1;
	cout << decale(c, debut, decalage) << endl;

	vector<vector<string>> s(3, vector<string>(1));
	s[2][0] = "c";

	string essai("essai");
	string test;

	for (int i(1); i <= 3; ++i) {
		test = test + essai[6 - 2 * i];
		test = essai[i] + test;
	}

	cout << test << endl;

	cout << f(40000) << endl;

	array<array<int, 5>, 6> tab;

	cout << "tab[0] " << tab[0].size() << endl;
	//cout << "tab[6] " << tab[6].size() << endl;
	cout << "tab[3] " << tab[3].size() << endl;

	vector<int> v(3, 1);

	v.pop_back();
	v.push_back(5);
	v[1] = 3;
	v.push_back(7);
	v.push_back(9);

	cout << v.size() << endl;
	cout << "Front: " << v.front() << endl;
	cout << "Back: " << v.back() << endl;

	for (auto item : v) {
		cout << item << " ";
	}

	return 0;
}

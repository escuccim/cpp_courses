#include <iostream>
#include <exception>
#include <vector>
#include <array>
#include <string>

using namespace std;

char decale(char c, char debut, int decalage) {
	return debut + (((c - debut) + decalage) % 26);
}

char code(char c, int d) {
	while (d < 0) {
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
	string raw = "Fuyez manants";
	string encoded = code(raw, 6);
	cout << encoded << endl;

	cout << decode(encoded, 6) << endl;
    
    return 0;
}
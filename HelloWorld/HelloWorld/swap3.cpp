#include <iostream>

using namespace std;

int main()
{
	int a(5);
	int b(7);
	int c(13);

	if (a + b > c) {
		cout << "1" << " ";
		b += 5;
	}
	else {
		cout << "2" << " ";
	}

	if (b % 2 == 0) {
		if (a % c == 0) {
			cout << "3" << " ";
		}
		else {
			cout << "4" << " ";
		}
	}
	else {
		cout << "5" << " ";
	}
	return 0;
}
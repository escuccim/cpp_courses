#include <iostream>
using namespace std;

int main()
{
	int debut(0);
	do {
		cout << "de (>= 1) ? ";
		cin >> debut;
	} while (debut < 1);

	int fin(0);
	do {
		cout << "a (>= " << debut << ") ? ";
		cin >> fin;
	} while (fin < debut);

	/*******************************************
	 * Completez le programme a partir d'ici.
	 *******************************************/
	for (int i = debut; i <= fin; i++) {
		int iterations = 0;
		int val = i;

		while (val > 0) {
			if (val % 3 == 0) {
				val += 4;
			}
			else if (val % 4 == 0) {
				val /= 2;
			}
			else {
				val -= 1;
			}
			iterations++;
		}
		cout << i << " -> " << iterations << endl;
	}

	 /*******************************************
	  * Ne rien modifier apres cette ligne.
	  *******************************************/

	return 0;
}

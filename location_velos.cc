#include <iostream>
using namespace std;

int main()
{
	cout << "Donnez l'heure de début de la location (un entier) : ";
	int debut;
	cin >> debut;

	cout << "Donnez l'heure de fin de la location (un entier) : ";
	int fin;
	cin >> fin;

	bool test_passed = true;

	/*****************************************************
	 * Compléter le code à partir d'ici
	 *****************************************************/
	if ((debut < 0) or (debut > 24) or (fin < 0) or (fin > 24)) {
		cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
		test_passed = false;
	}
	if (debut == fin) {
		cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
		test_passed = false;
	}
	if (fin < debut) {
		cout << "Bizarre, le début de la location est après la fin ..." << endl;
		test_passed = false;
	}
	
	if (test_passed) {
		int cheap_hours = 0;
		int expensive_hours = 0;

		for (int i = debut; i < fin; i++) {
			if ((i < 7) or (i >= 17)) {
				cheap_hours += 1;
			}
			else {
				expensive_hours += 1;
			}
		}
		cout << "Vous avez loué votre vélo pendant" << endl;

		if (cheap_hours > 0) {
			cout << cheap_hours << " heure(s) au tarif horaire de " << 1
				<< " franc(s)" << endl;
		}
		if (expensive_hours > 0) {
			cout << expensive_hours << " heure(s) au tarif horaire de " << 2
				<< " franc(s)" << endl;
		}

		cout << "Le montant total à payer est de " << cheap_hours + (2 * expensive_hours)
			<< " franc(s)." << endl;
	}
	

	/*******************************************
	 * Ne rien modifier après cette ligne.
	 *******************************************/

	return 0;
}

#include <iostream>
#include <iomanip> // pour setprecision()
using namespace std;

int main()
{
	// Réduire le format d'affichage
	cout << setprecision(4);

	// Paramètres
	double taux_croissance_lapins(0.3);
	double taux_attaque(0.01);
	double taux_croissance_renards(0.008);
	double taux_mortalite(0.1);
	int duree(50);

	double renards_i(0.0);
	double lapins_i(0.0);

	/*****************************************************
	 * Compléter le code à partir d'ici
	 *****************************************************/

	 // ===== PARTIE 1 =====
	 // Saisie des populations initiales

	while (renards_i < 2) {
		cout << "Combien de renards au départ (>= 2) ? ";
		cin >> renards_i;
	}

	while (lapins_i < 5) {
		cout << "Combien de lapins au départ  (>= 5) ? ";
		cin >> lapins_i;
	}

	// ===== PARTIE 2 =====
	// Première simulation
	cout << endl << "***** Le taux d'attaque vaut " << taux_attaque * 100 << "%" << endl;

	// initialize our populations
	double nb_renards = renards_i;
	double nb_lapins = lapins_i;
	double old_nb_lapins = lapins_i;

	for (int i = 1; i <= duree; i++) {
		nb_lapins = nb_lapins * (1.0 + taux_croissance_lapins - taux_attaque * nb_renards);
		nb_renards = nb_renards * (1.0 + taux_attaque * old_nb_lapins * taux_croissance_renards - taux_mortalite);
		old_nb_lapins = nb_lapins;

		// catch negative numbers
		if (nb_lapins < 0) {
			nb_lapins = 0;
		}
		if (nb_renards < 0) {
			nb_renards = 0;
		}

		cout << "Après " << i << " mois, il y a " << nb_lapins << " lapins et " << nb_renards << " renards" << endl;
	}
	// ===== PARTIE 3 =====
	// Variation du taux d'attaque
	cout << endl;
	double start_attack_rate = 0;

	while (start_attack_rate < 0.5 || start_attack_rate > 6.0) {
		cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";
		cin >> start_attack_rate;
	}

	double end_attack_rate = 0;
	while (end_attack_rate < start_attack_rate || end_attack_rate > 6.0) {
		cout << "taux d'attaque à la fin  en % (entre " << start_attack_rate << " et 6) ? ";
		cin >> end_attack_rate;
	}

	bool fox_population_low = false;
	bool rabbit_population_low = false;
	int final_month = 0;

	for (double attack_rate = start_attack_rate; attack_rate < end_attack_rate; attack_rate++) {
		taux_attaque = attack_rate / 100;
		cout << endl << "***** Le taux d'attaque vaut " << taux_attaque * 100 << "%" << endl;
		
		// initialize our loop vars
		fox_population_low = false;
		rabbit_population_low = false;
		final_month = 0;

		// reset our initial populations
		nb_renards = renards_i;
		nb_lapins = lapins_i;
		old_nb_lapins = lapins_i;
		
		for (int i = 1; i <= duree; i++) {
			nb_lapins = nb_lapins * (1.0 + taux_croissance_lapins - taux_attaque * nb_renards);
			nb_renards = nb_renards * (1.0 + taux_attaque * old_nb_lapins * taux_croissance_renards - taux_mortalite);
			old_nb_lapins = nb_lapins;
			final_month = i;

			// catch negative numbers
			if (nb_lapins < 2) {
				nb_lapins = 0;
			}
			if (nb_renards < 2) {
				nb_renards = 0;
			}
			if (nb_lapins < 5) {
				rabbit_population_low = true;
			}
			if (nb_renards < 5) {
				fox_population_low = true;
			}
			if (nb_lapins == 0 && nb_renards == 0) {
				break;
			}
		}
		//if (nb_renards > 0 || nb_lapins > 0) {
			cout << "Après " << final_month << " mois, il y a " << nb_lapins << " lapins et " << nb_renards << " renards" << endl;
		//}

		if (fox_population_low) {
			cout << "Les renards ont été en voie d'extinction" << endl;
			if (nb_renards > 5) {
				cout << "mais la population est remontée ! Ouf !" << endl;
			}
		}
		if (nb_renards == 0) {
			cout << "et les renards ont disparu :-(" << endl;
		}
		if (rabbit_population_low) {
			cout << "Les lapins ont été en voie d'extinction" << endl;
			if (nb_lapins > 5) {
				cout << "mais la population est remontée ! Ouf !" << endl;
			}
		}
		if (nb_lapins == 0) {
			cout << "et les lapins ont disparu :-(" << endl;
		}
		
		if (not fox_population_low && not rabbit_population_low && nb_lapins != 0 && nb_renards != 0) {
			cout << "Les lapins et les renards ont des populations stables." << endl;
		}

	}

	/*******************************************
	 * Ne rien modifier après cette ligne.
	 *******************************************/

	return 0;
}
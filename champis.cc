#include <iostream>
#include<string>
using namespace std;

int main()
{
	int lamelles = 0;
	int anneau = 0;
	int chapeau = 0;
	int foret = 0;
	string mushroom = "";

	cout << "Pensez à un champignon : amanite tue-mouches, pied bleu, girolle," << endl
		<< "cèpe de Bordeaux, coprin chevelu ou agaric jaunissant." << endl << endl;
	
	cout << "Est-ce que votre champignon vit en forêt (1 : oui, 0 : non) ? ";
	cin >> foret;

	if (foret == 1) {
		cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
		cin >> chapeau;

		if (chapeau == 1) {
			cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
			cin >> anneau;
			if (anneau == 1) {
				mushroom = "l'amanite tue-mouches";
			}
			else {
				mushroom = "le pied bleu";
			}
		}
		else {
			cout << "Est-ce que votre champignon a des lamelles (1 : oui, 0 : non) ? ";
			cin >> lamelles;

			if (lamelles == 1) {
				mushroom = "la girolle";
			}
			else {
				mushroom = "le cèpe de Bordeaux";
			}
		}
	}
	else {
		if (chapeau == 1) {
			mushroom = "l'agaric jaunissant";
		}
		else {
			mushroom = "le coprin chevelu";
		}
	}
	cout << "==> Le champignon auquel vous pensez est ";
	cout << mushroom;
	
	return 0;
}

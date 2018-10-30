#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int> > Carte;

struct Position {
	int i;
	int j;
};


/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/
void testPond(Carte& carte, Position pos, int composante, vector<Position>& water) {
	if (carte[pos.i][pos.j] == 0) {
		carte[pos.i][pos.j] = composante;
		if (pos.i >= 1 && carte[(pos.i) - 1][pos.j] == 0) {
			Position p = { (pos.i) - 1,(pos.j) };
			water.push_back(p);
			testPond(carte, p, composante, water);
		}
		if (pos.j >= 1 && carte[pos.i][(pos.j) - 1] == 0) {
			Position p = { (pos.i),(pos.j) - 1 };
			water.push_back(p);
			testPond(carte, p, composante, water);
		}
		if (pos.i < carte.size() - 1 && carte[(pos.i) + 1][pos.j] == 0) {
			Position p = { (pos.i) + 1,(pos.j) };
			water.push_back(p);
			testPond(carte, p, composante, water);
		}
		if (pos.j < carte[0].size() - 1 && carte[pos.i][(pos.j) + 1] == 0) {
			Position p = { (pos.i),(pos.j) + 1 };
			water.push_back(p);
			testPond(carte, p, composante, water);
		}
	}
}

void marque_composantes(Carte& carte) {
	vector<Position> pond;
	int composante(1);
	for (size_t i(0); i < carte.size(); ++i) {
		for (size_t j(0); j < carte[i].size(); ++j) {
			if (carte[i][j] == 0) {
				int m(i);
				int n(j);
				Position p = { m,n };
				pond.push_back(p);
				testPond(carte, p, ++composante, pond);
			}
		}
	}
}

void ajoute_unique(vector<int>& ensemble, int valeur)
{
	bool found(false);
	size_t i(0);

	while (i < ensemble.size() && !found) {
		if (ensemble[i] == valeur) {
			found = true;
		}
		++i;
	}
	if (!found) {
		ensemble.push_back(valeur);
	}
}

bool convexite_lignes(Carte& carte, vector<int> const& labels_bords)
{
	return true;
}
bool convexite_lignes(Carte& carte)
{
	return true;
}
//cout << "Votre carte du terrain n'est pas convexe par lignes :" << endl;
//cout << "bord extérieur entrant trouvé en position [";
//cout << "][";
//cout << "]" << endl;

bool binaire(Carte const& carte) {
	int first_elem = carte[0][0];

	for (auto row : carte) {
		for (auto col : row) {
			if (col != 0 && col != 1) {
				return false;
			}
		}
	}
	return true;
}

void affiche(Carte const& carte) {
	for (auto row : carte) {
		for (auto col : row) {
			std::cout << col;
		}
		std::cout << endl;
	}
	std::cout << "----" << endl;
}

bool verifie_et_modifie(Carte& carte) {
	if (!binaire(carte)) {
		cout << "Votre carte du terrain ne contient pas que des 0 et des 1." << endl;
		return false;
	}
	if (!convexite_lignes(carte)) {
		return false;
	}
	// get the size of the map
	size_t height(carte.size());
	size_t width(carte[0].size());

	// loop through the map
	for (size_t i(1); i < height; ++i) {
		for (size_t j(1); j < width; ++j) {
			
			// init a boolean vector of same size as map containing false
			vector<vector<bool> > result(height, vector<bool>(width, false));

			// init border to false
			bool border(false);

			// if the position is different from the previous position
			if (carte[i][j] != 1 && carte[i - 1][j] == 1 && carte[i][j - 1] == 1) {
				size_t m(i);
				size_t n(j);
				do {
					do {
						result[m][n] = true;
						++n;
					} while (n < width && carte[m][n] != 1);
					if (n == width) {
						border = true;
					}
					n = j;
					++m;
					if (m == height) {
						border = true;
					}
				} while (m < height && carte[m][n] != 1 && !border);
			}
			if (!border) {
				for (size_t k(0); k < result.size(); ++k) {
					for (size_t l(0); l < result[k].size(); ++l) {
						if (result[k][l]) {
							carte[k][l] = 1;
						}
					}
				}
			}
		}
	}
	return true;
}

double longueur_cloture(Carte const& carte, double echelle = 2.5) {
	// init the perimeter to 0
	double perimeter(0);

	// init vectors with the left and right borders
	vector<int> left_side(carte.size());
	vector<int> right_side(carte.size());
	vector<int> area(carte.size());

	for (size_t i(0); i < carte.size(); ++i) {
		size_t y(0);
		int z(0);
		while (y < carte[i].size() && carte[i][y] != 1) {
			++y;
		}
		left_side[i] = y;
		z = carte[i].size() - 1;
		while (z >= 0 && carte[i][z] != 1) {
			--z;
		}
		right_side[i] = z + 1;
		area[i] = z + 1 - y;
		if (area[i] > 0) {
			perimeter += (2 * echelle);
			if (i > 0) {
				int a(left_side[i] - left_side[i - 1]);
				int b(right_side[i] - right_side[i - 1]);
				if (a < 0) {
					a *= -1;
				}
				if (b < 0) {
					b *= -1;
				}
				perimeter += a * echelle + b * echelle;
			}
		}
	}
	perimeter += area[0] * echelle + area[area.size() - 1] * echelle;
	return perimeter;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
	int i(5);
	int* p(&i);

	cout << "1. " << *p << endl;
	p = p + 1;
	cout << "2. " << i << endl;

	int** q(&p);

	p = &i;
	**q = 12;

	int j(10 + i);

	cout << "3. " << j << endl;
	i = *p;

	int* r(*q);

	// ...code manquant...
	*q = &j;

	i = i - *r + 35;
	cout << "4. " << *r - *p << endl;

	unique_ptr<int> uptr(new int(3));

	cout << "uptr : " << uptr << endl;
	cout << "*uptr : " << *uptr << endl;

	int *px;
	px = new int(17);
	cout << "px : " << px << endl;
	cout << "*px : " << *px << endl;
	int x = 17;
	int *ptr(nullptr);

	ptr = &x;

	cout << "ptr : " << ptr << endl;
	cout << "*ptr : " << *ptr << endl;
	cout << "*&x : " << *&x << endl;

	/*Carte carte = {
	  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0},
	  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	  {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0},
	  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0},
	  {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0},
	  {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
	  {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
	  {0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
	  {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
	  {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
	  {0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
	  {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
	  {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
	  {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
	  {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
	  {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
	  {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	  {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
	  {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	  {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	  {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

	cout << "Carte au départ :" << endl;
	affiche(carte);
	if (verifie_et_modifie(carte)) {
		cout << "Carte après modification :" << endl;
		affiche(carte);
		cout << "Il vous faut " << longueur_cloture(carte)
			<< " mètres de clôture pour votre terrain."
			<< endl;
	}*/

	return 0;
}

#include <iostream>
using namespace std;

int separer_chiffre_gauche(int& nombre)
{
  int dix(1);
  int temp(nombre);
  while (temp >= 10) {
    dix  *= 10;
    temp /= 10;
  }
  nombre %= dix;
  return temp;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

void ajouter_chiffre_droit(int& nombre, int chiffre)
{
	int temp(nombre);
	temp *= 10;
	temp += chiffre;
	nombre = temp;
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{
	ajouter_chiffre_droit(nombre, repetitions_chiffre);
	ajouter_chiffre_droit(nombre, chiffre);

}

int lire_et_dire(int nombre)
{
	int current_left_digit = separer_chiffre_gauche(nombre);
	int new_left_digit(-1);
	int repetitions = 1;
	int result(0);

	while (current_left_digit != 0) {
		new_left_digit = separer_chiffre_gauche(nombre);
		//cout << "Nombre: " << nombre << endl;
		//cout << "Current_left_digit: " << current_left_digit << endl;
		//cout << "New_left_digit: " << new_left_digit << endl;
		if (new_left_digit == current_left_digit) {
			repetitions += 1;
		}
		else {
			dire_chiffre(result, repetitions, current_left_digit);
			current_left_digit = new_left_digit;
			repetitions = 1;
		}
		//cout << "Current result: " << result << endl;
	}

	//cout << endl;
	//cout << "Current_left_digit: " << current_left_digit << endl;
	//cout << "New_left_digit: " << new_left_digit << endl;
	return result;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void repeter_lire_et_dire(int& nombre, int fois)
{
  while (fois-- > 0) {
    nombre = lire_et_dire(nombre);
  }
}

int main()
{
  int nombre(1);
  int fois(1);
  cin >> nombre >> fois;
  repeter_lire_et_dire(nombre, fois);
  cout << nombre << endl;
  return 0;
}

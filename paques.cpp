#include <iostream>
using namespace std;

int demander_annee()
{
	int annee(0);
	while (annee < 1583 || annee > 4000) {
		cout << "Entrez une annee(1583 - 4000) : ";
		cin >> annee;
	}
	
	return annee;
}

void affiche_date(int year, int number)
{
	cout << "Date de Paques en " << year << " : ";

	if (number <= 31) {
		cout << number << " mars" << endl;
	}
	else {
		cout << number - 31 << " avril" << endl;
	}
}

int date_Paques(int year)
{
	int century = year / 100;
	int p = ((8 * century) + 13) / 25;
	int q = century / 4;
	int M = (15 - p + century - q) % 30;
	int N = (4 + century - q) % 7;
	int d = (M + (19 * (year % 19))) % 30;
	int e = (2 * (year % 4) + 4 * (year % 7) + 6 * d + N) % 7;
	int day = e + d + 22;

	if (e == 6) {
		int extra_value = (11 * (M + 1)) % 30;
		if (d == 29 || (d == 28 && extra_value < 19)) {
			day -= 7;
		}
	}

	return day;
}

int main()
{
	int year = demander_annee();
	int date_paques = date_Paques(year);
	affiche_date(year, date_paques);
	return 0;
}

#include <iostream>
#include <ctime>

// pour les nombres aléatoires
#include <random>
#include <cstring> // strlen

using namespace std;

// ======================================================================
// Couleur au hasard
std::uniform_int_distribution<int> distribution;
std::default_random_engine generateur(time(NULL)); /* NOT using std::random_device since not
													* all compilers seems to support it :-( */

char tirer_couleur()
{
	static const char* const couleurs = ".RGBCYM";
	static const int nb = strlen(couleurs) - 1;

	return couleurs[distribution(generateur,
		std::uniform_int_distribution<int>::param_type{ 0, nb })];
}

// ======================================================================
char poser_question()
{
	char lu(' ');
	cout << "Entrez une couleur : ";
	cin >> lu;
	return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

// ======================================================================
char lire_couleur()
{
	char lu(poser_question());
	while (not couleur_valide(lu)) {
		cout << "'" << lu << "' n'est pas une couleur valide." << endl;
		cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
		lu = poser_question();
	}
	return lu;
}

// ======================================================================
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
	cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

// ======================================================================
void afficher(int nb, char c)
{
	while (nb-- > 0) {
		cout << c;
	}
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
	char r1, char r2, char r3, char r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
	char r1, char r2, char r3, char r4)
{
	afficher_couleurs(c1, c2, c3, c4);
	cout << " : ";
	afficher_reponses(c1, c2, c3, c4,
		r1, r2, r3, r4);
	cout << endl;
}

// ======================================================================
void message_gagne(int nb_coups)
{
	cout << "Bravo ! Vous avez trouvé en " << nb_coups << " coups." << endl;
}

// ======================================================================
void message_perdu(char c1, char c2, char c3, char c4)
{
	cout << "Perdu :-(" << endl;
	cout << "La bonne combinaison était : ";
	afficher_couleurs(c1, c2, c3, c4);
	cout << endl;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

 // ======================================================================
bool couleur_valide(char c)
{
	if (c == '.' || c == 'R' || c == 'G' || c == 'B' || c == 'C' || c == 'Y' || c == 'M')
		return true;
	else
		return false;
}

// ======================================================================
bool verifier(char c1, char &c2, int &score)
{
	bool result = false;

	if (c1 == c2) {
		score += 1;
		result = true;
	}
	c2 = 'x';
	return result;
}

// ======================================================================
void apparier(char candidate, char &r1, char &r2, char &r3, int &score)
{
	if (candidate == r1 || candidate == r2 || candidate == r3) {
		score += 1;
	}
}

// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4, char r1, char r2, char r3, char r4)
{
	int correct_guesses = 0;
	// display the correctly placed colors
	if (c1 == r1) {
		afficher(1, '#');
		r1 = '/';
		correct_guesses += 1;
	}
	if (c2 == r2) {
		afficher(1, '#');
		r2 = '/';
		correct_guesses += 1;
	}
	if (c3 == r3) {
		afficher(1, '#');
		r3 = '/';
		correct_guesses += 1;
	}
	if (c4 == r4) {
		afficher(1, '#');
		r4 = '/';
		correct_guesses += 1;
	}

	// check for correct but misplaced colors
	if (c1 == r2){ 
		afficher(1, '+');
		correct_guesses += 1;
		r2 = '/';
	}
	if (c1 == r3) {
		afficher(1, '+');
		correct_guesses += 1;
		r3 = '/';
	}
	if (c1 == r4) {
		afficher(1, '+');
		correct_guesses += 1;
		r4 = '/';
	}

	if (c2 == r1) {
		afficher(1, '+');
		correct_guesses += 1;
		r1 = '/';
	}
	if (c2 == r3) {
		afficher(1, '+');
		correct_guesses += 1;
		r3 = '/';
	}
	if (c2 == r4) {
		afficher(1, '+');
		correct_guesses += 1;
		r4 = '/';
	}

	if (c3 == r1) {
		afficher(1, '+');
		correct_guesses += 1;
		r1 = '/';
	}
	if (c3 == r2) {
		afficher(1, '+');
		correct_guesses += 1;
		r2 = '/';
	}
	if (c3 == r4) {
		afficher(1, '+');
		correct_guesses += 1;
		r4 = '/';
	}

	if (c4 == r1) {
		afficher(1, '+');
		correct_guesses += 1;
		r1 = '/';
	}
	if (c4 == r2) {
		afficher(1, '+');
		correct_guesses += 1;
		r2 = '/';
	}
	if (c4 == r3) {
		afficher(1, '+');
		correct_guesses += 1;
		r3 = '/';
	}

	while (correct_guesses < 4) {
		afficher(1, '-');
		correct_guesses += 1;
	}
}

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4,
	char r1, char r2, char r3, char r4)
{
	if (c1 == r1 && c2 == r2 && c3 == r3 && c4 == r4)
		return true;
	else
		return false;
}

// ======================================================================
void jouer(int max_guesses = 8)
{
	char r1 = tirer_couleur();
	char r2 = tirer_couleur();
	char r3 = tirer_couleur();
	char r4 = tirer_couleur();

	bool gagner = false;
	int guesses = 0;
	char c1 = ' ';
	char c2 = ' ';
	char c3 = ' ';
	char c4 = ' ';

	while (not gagner && guesses < max_guesses) {
		c1 = lire_couleur();
		c2 = lire_couleur();
		c3 = lire_couleur();
		c4 = lire_couleur();

		afficher_coup(c1, c2, c3, c4, r1, r2, r3, r4);
		guesses += 1;
		gagner = gagne(c1, c2, c3, c4, r1, r2, r3, r4);
	}
	if (gagner) {
		message_gagne(guesses);
	}
	else {
		message_perdu(r1, r2, r3, r4);
	}
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
	jouer();
	return 0;
}

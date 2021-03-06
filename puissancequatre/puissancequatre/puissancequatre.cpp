#include "pch.h"
#include <iostream>
#include <array>

using namespace std;

enum Color { vide, red, yellow };
typedef array< array<Color, 7>, 6> Board;

// create and return an empty board
Board initialize() {
	Board board;

	for (auto &row : board) {
		for (auto &square : row) {
			square = vide;
		}
	}

	return board;
}

// update the board with a move
bool play(Board &board, size_t column, Color player) {
	// return false if the move isn't a valid move
	if (column < 0 or column > 6) {
		return false;
	}

	// return false if the column is full
	if (board[0][column] != vide) {
		cout << "That column is full, please select another!" << endl;
		return false;
	}

	size_t row(board.size() - 1);

	while ((row >= 0) and board[row][column] != vide) {
		--row;
	}

	board[row][column] = player;
	return true;
}

// display the board
void affiche(const Board &board) {
	cout << "---------------" << endl;
	for (auto row : board) {
		cout << '|';
		for (auto square : row) {
			if (square == vide) {
				cout << ' ';
			}
			else if (square == red) {
				cout << 'O';
			}
			else if (square == yellow) {
				cout << 'X';
			}
			cout << '|';
		}
		cout << endl;
		//cout << "---------------" << endl;
	}
	cout << "=1=2=3=4=5=6=7=" << endl;
}

// get the selected player to input a correct move
int getMove(Color player) {
	int column = 0;
	while (column < 1 || column > 7) {
		cout << "Player " << player << " enter your move: ";
		cin >> column;
	}
	return column - 1;
}

// set player to the next player
void nextPlayer(Color &player) {
	if (player == red) {
		player = yellow;
	}
	else {
		player = red;
	}
}

Color checkDiagonal(const Board board, size_t start_col, size_t start_row) {
	int num_pieces = 0;
	Color previous_piece = vide;

	// start with the top row and move up or down in columns depending on which
	// column we start on

		// if the column is on the left hand size we check moving to the right
	if (start_col <= 4) {
		size_t col = start_col;
		for (size_t row = start_row; row < board.size(); row++) {
			if (board[row][col] == vide) {
				num_pieces = 0;
			}
			else if (board[row][col] != previous_piece) {
				num_pieces = 1;
			}
			else {
				num_pieces += 1;
			}
			if (num_pieces >= 4) {
				return board[row][col];
			}
			previous_piece = board[row][col];
			if (col < board[row].size() - 1) {
				col++;
			}
			else {
				// do nothing
			}
		}
	}

	// if the column is on the right hand size we check moving to the left
	if (start_col >= 4) {
		size_t col = start_col;
		for (size_t row = start_row; row < board.size(); row++) {
			if (board[row][col] == vide) {
				num_pieces = 0;
			}
			else if (board[row][col] != previous_piece) {
				num_pieces = 1;
			}
			else {
				num_pieces += 1;
			}
			if (num_pieces >= 4) {
				return board[row][col];
			}
			previous_piece = board[row][col];
			if (col > 0) {
				col--;
			}
			else {
				break;
			}
		}
	}
	return vide;
}

// check if anyone has won
Color won(const Board board) {
	int num_pieces = 0;
	Color previous_piece = vide;

	// check for four in a row
	for (size_t row = 0; row < board.size(); row++) {
		for (size_t col = 0; col < board[row].size(); col++) {
			if (board[row][col] == vide) {
				num_pieces = 0;
			}
			else if (board[row][col] != previous_piece) {
				num_pieces = 1;
			}
			else {
				num_pieces += 1;
			}
			if (num_pieces >= 4) {
				return board[row][col];
			}
			previous_piece = board[row][col];
		}
	}

	num_pieces = 0;
	previous_piece = vide;

	// check for four in a column
	for (size_t col = 0; col < board[0].size(); col++) {
		for (size_t row = 0; row < board.size(); row++) {
			if (board[row][col] == vide) {
				num_pieces = 0;
			}
			else if (board[row][col] != previous_piece) {
				num_pieces = 1;
			}
			else {
				num_pieces += 1;
			}
			if (num_pieces >= 4) {
				return board[row][col];
			}
			previous_piece = board[row][col];
		}
	}

	// check for four in a diagonal - there are 5 spaces in each direction and 1 in both
	// directions that need to be checked. These spots should cover all possible diagonal
	// lines that can be made
	num_pieces = 0;
	previous_piece = vide;
	Color winner = vide;

	// let's start by checking the top row
	for (size_t start_col = 0; start_col < board[0].size(); start_col++) {
		winner = checkDiagonal(board, start_col, 0);
		if (winner != vide) {
			return winner;
		}
	}

	// now we check the second and third rows, only the left and rightmost columns
	winner = checkDiagonal(board, 0, 1);
	if (winner != vide) {
		return winner;
	}
	winner = checkDiagonal(board, 0, 2);
	if (winner != vide) {
		return winner;
	}
	winner = checkDiagonal(board, 6, 1);
	if (winner != vide) {
		return winner;
	}
	winner = checkDiagonal(board, 6, 2);
	if (winner != vide) {
		return winner;
	}
	return vide;
}



int main()
{
	char keep_playing = 'y';
	
	while (keep_playing == 'y' || keep_playing == 'Y') {
		int move = -2;
		Color player = red;
		Board board(initialize());
		Color winning_move = vide;

		affiche(board);

		while (move != -1 and !winning_move) {
			bool played = false;
			while (not played) {
				move = getMove(player);
				played = play(board, move, player);
			}
			affiche(board);
			winning_move = won(board);
			nextPlayer(player);
		}
		cout << "Player " << winning_move << " won!" << endl;
		cout << "Play again (y/n)?";
		cin >> keep_playing;
	}
	
	return 0;
}
///////////////////////////////////////////////////////////////////////////////
// Name			: Jacob Yanicak
// Author		: April 14, 2017
// School		: Essex County College
// Description	: Tic Tac Toe Project. This program is a game of tic tac toe.

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// prototypes
void tictactoe();
void display(char table[3][3]);
void init(char table[3][3]);
void twoplayer(char table[3][3]);
void oneplayer(char table[3][3]);
void playeroneturn(char table[3][3], string name);
void playertwoturn(char table[3][3], string name);
int checker(char table[3][3]);
void displaypositions(char table[3][3]);
void computerturn(char table[3][3]);



int main() {
	bool choice = false;
	int container = 0;

	srand(time(NULL));

	// loop to create option to continue playing when done
	cout << "\n\tHello! It is time for Tic-Tac-Toe!" << endl; // greeting
	do {
		tictactoe(); // call controller
		cout << "\n\t\tDo you want to play again?" << endl; // end game choice
		cout << "\t\tPlease enter a choice:" << endl;
		cout << "\t\t\t(1) for yes" << endl;
		cout << "\t\t\t(2) for no" << endl;
		cin >> container;
		if (container == 2) {
			choice = true;
			cout << "\n\t\tThanks for playing, come back soon!" << endl;
		}
	} while (choice == false);

	return 0;
}

///////////////////////////////////////////////////////////////////////////////
// my menu/controller function for the game
void tictactoe()
{
	int gametype = 0;
	char table1[3][3];

	init(table1); // fill array with dashes
	cout << "\n\t\tPlease choose a game type:" << endl; // gametype options
	cout << "\t\tEnter (1) for 2 - Player" << endl;
	cout << "\t\tEnter (2) for Against Computer" << endl;
	cin >> gametype; // taking gametype choice
	displaypositions(table1); // displays empty array with positions
	switch (gametype) {
	case 1:
		twoplayer(table1); // 2-Player option
		break;
	case 2:
		oneplayer(table1); // 1-Player option
		break;
	default:
		cout << "\n\tFollow instructions!" << endl;
		tictactoe(); // loopback
	break;
	}

}

///////////////////////////////////////////////////////////////////////////////
// display function for 2D array
void display(char table[3][3])
{
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "\t\t\t";
		for (int j = 0; j < 3; j++)
			cout <<  table[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	cout << endl;
}

///////////////////////////////////////////////////////////////////////////////
// function to initialize array with dashes
void init(char table[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			table[i][j] = '-'; // initialize with dashes
	}
}

///////////////////////////////////////////////////////////////////////////////
// function to make array to show user places of positions
void displaypositions(char table[3][3])
{
	cout << endl;
	cout << "\tRow and Column Position numbers :" << endl;
	cout << "\t\t\t1 2 3" << endl;
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "\t\t" << i+1 << "\t";
		for (int j = 0; j < 3; j++)
			cout <<  table[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	cout << endl;
}

///////////////////////////////////////////////////////////////////////////////
// new controller function if 2-player option is chosen
void twoplayer(char table[3][3]){
	string name1 = "Player 1";
	string name2 = "Player 2";
	bool winner = false;

	cout << "\t\tPlayer 1 enter your name : ";
	cin >> name1;
	cout << "\n\t\tPlayer 2 enter your name : ";
	cin >> name2;
	display(table);
	// loop to create environment for game to run until winner or draw
	do {
		int result = 0;
		playeroneturn(table, name1); // player one starts
		result = checker(table); // checks for winning combo
		if (result == 2) { // if draw
			cout << "\tNobody wins!" << endl;
			winner = true;
		}
		else if (result == 1) { // if player one wins
			cout << "\tPlayer 1 : " << name1 << " wins!" << endl;
			winner = true;
		}
		else {
			playertwoturn(table, name2); // player two turn
			result = checker(table); // checks for winning combo
			if (result == 2) { // if draw
				cout << "\tNobody wins!" << endl;
				winner = true;
			}
			else if (result == 1) { // if player two wins
				cout << "\tPlayer 2 : " << name2 << " wins!" << endl;
				winner = true;
			}
		}
	} while (winner == false); // loopback = next turn when applicable

}

///////////////////////////////////////////////////////////////////////////////
// new controller function if 1-player option is chosen
void oneplayer(char table[3][3]) {
	//cout << "\n\t\tSorry, this area is currently under construction" << endl;
	//tictactoe();
	string name1 = "Player 1";
	bool winner = false;

	cout << "\t\tPlease enter your name : ";
	cin >> name1;
	display(table);
	// loop to create environment for game to run until winner or draw
	do {
		int result = 0;
		playeroneturn(table, name1); // player one starts
		result = checker(table); // checks for winning combo
		if (result == 2) { // if draw
			cout << "\tNobody wins!" << endl;
			winner = true;
		}
		else if (result == 1) { // if player one wins
			cout << "\tPlayer 1 : " << name1 << " wins!" << endl;
			winner = true;
		}
		else {
			computerturn(table); // player two turn
			result = checker(table); // checks for winning combo
			if (result == 2) { // if draw
				cout << "\tNobody wins!" << endl;
				winner = true;
			}
			else if (result == 1) { // if player two wins
				cout << "\tThe computer wins!" << endl;
				winner = true;
			}
		}
	} while (winner == false); // loopback = next turn when applicable

}

///////////////////////////////////////////////////////////////////////////////
// function for first player's turn
void playeroneturn(char table[3][3], string name) {
	int row = 0;
	int col = 0;

	cout << "\t" << name << ", it is your turn." << endl;
	cout << "\n\t\tPlease enter a row : ";
	cin >> row;
	row = row - 1;
	cout << endl;
	cout << "\t\tPlease enter a column : \n";
	cin >> col;
	col = col - 1;
	if (table[row][col] == '-') { // allowing placement if empty
		table[row][col] = 'X'; // filling array with player one mark
		//system("cls");
		cout << "\t\tYour move : \n" << endl;
		display(table);
	}
	else {
		cout << "\n\tPlease choose an empty position!\n" << endl; // if player chooses filled position
		playeroneturn(table, name);
	}
}

///////////////////////////////////////////////////////////////////////////////
// function for second player's turn
void playertwoturn(char table[3][3], string name) {
	int row = 0;
	int col = 0;

	cout << "\t" << name << ", it is your turn." << endl;
	cout << "\n\t\tPlease enter a row : ";
	cin >> row;
	row = row - 1;
	cout << endl;
	cout << "\t\tPlease enter a column : \n";
	cin >> col;
	col = col - 1;
	if (table[row][col] == '-') { // allowing placemetn if empty
		table[row][col] = 'O'; // filling array with player two mark
		//system("cls");
		cout << "\t\tYour move : \n" << endl;
		display(table);
	}
	else {
		cout << "\n\tPlease choose an empty position!\n" << endl; // if player chooses filled position
		playertwoturn(table, name);
	}
}

///////////////////////////////////////////////////////////////////////////////
// function for second player's turn
void computerturn(char table[3][3]) {
	int randrow = 0;
	int randcol = 0;

	randrow = rand() % 3;
	randcol = rand() % 3;
	if (table[randrow][randcol] == '-') { // allowing placement if empty
			table[randrow][randcol] = 'O'; // filling array with computer mark
			cout << "\t\tComputer's move : \n";
			display(table);
		}
		else {
			computerturn(table); // if random position if occupied
		}
}

///////////////////////////////////////////////////////////////////////////////
// function that checks for winning combinations in the array
int checker(char table[3][3]) {
	int result = 0;
	if (table[0][0] == table[0][1] && table[0][1] == table[0][2] && table[0][0] != '-') // top horizontal
		result = 1;
	else if (table[1][0] == table[1][1] && table[1][1] == table[1][2] && table[1][0] != '-') // middle horizontal
		result = 1;
	else if (table[2][0] == table[2][1] && table[2][1] == table[2][2] && table[2][0] != '-') // bottom horizontal
		result = 1;
	else if (table[0][0] == table[1][0] && table[1][0] == table[2][0] && table[0][0] != '-') // first vertical
		result = 1;
	else if (table[0][1] == table[1][1] && table[1][1] == table[2][1] && table[0][1] != '-') // second vertical
		result = 1;
	else if (table[0][2] == table[1][2] && table[1][2] == table[2][2] && table[0][2] != '-') // third vertical
		result = 1;
	else if (table[0][0] == table[1][1] && table[1][1] == table[2][2] && table[0][0] != '-') // first diagonal, top left to bottom right
		result = 1;
	else if (table[2][0] == table[1][1] && table[1][1] == table[0][2] && table[2][0] != '-') // second diagonal, bottom left to top right
		result = 1;
	else if (table[0][0] != '-' && table[0][1] != '-' && table[0][2] != '-' && table[1][0] != '-' && table[2][0] != '-' && table[1][1] != '-' && table[1][2] != '-' && table[2][1] != '-' && table[2][2] != '-') // if no winner
		result = 2;
	else
		result = 0;
	return result;
}

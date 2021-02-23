// TicTacToeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>

using namespace std;

char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', };
void show_board(int round);
void get_x_player_choice();
void get_o_player_choice();
void get_computer_choice();
int count_board(char symbol);
char check_winner();
void computer_vs_player(int rounds);
void player_vs_player(int rounds);


// Main function to run program
int main()
{
    int mode, rounds;
    cout << "1. Computer VS Player " << endl;
    cout << "2. Player VS Player " << endl;
    cout << "Select Game Mode: " << endl;
    cin >> mode;

    // Different cases to choose which game mode
    switch (mode)
    {
        case 1 :
            while (true)
            {
                // Ask how many games
                cout << "How Many Games Would You Like to play in Computer VS Player Mode? " << endl;
                cin >> rounds;

                if (rounds <= 0)
                {
                    cout << "Invalid Input" << endl;
                }
                else
                    break;
            }
            computer_vs_player(rounds);
            break;
        case 2 :
            while (true)
            {
                // Ask how many games
                cout << "How Many Games Would You Like to play in Player VS Player Mode? " << endl;
                cin >> rounds;

                if (rounds <= 0)
                {
                    cout << "Invalid Input" << endl;
                }
                else
                    break;
            }
            player_vs_player(rounds);
            break;
        default :
            cout << "Please Select Valid Game Mode." << endl;
            break;
    }

    return 0;
}

// Get computer choice on game
void get_computer_choice() {

    srand(time(0));
    int choice;

    do {
        choice = rand() % 10;

    } while (board[choice] != ' ');

    board[choice] = 'O';

}

// get player X's choice
void get_x_player_choice() {

    while (true)
    {
        cout << "Select Your Position (1 - 9): ";
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8)
        {
            cout << "Position Error!\nPlease Select Your Choice From (1 - 9)." << endl;
        }
        else if (board[choice] != ' ')
        {
            cout << "Position Taken!\nPlease Select An Empty Position." << endl;
        }
        else
        {
            board[choice] = 'X';
            break;
        }
    }

}

//get player O's choice
void get_o_player_choice() {

    while (true)
    {
        cout << "Select Your Position (1 - 9): ";
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8)
        {
            cout << "Position Error!\nPlease Select Your Choice From (1 - 9)." << endl;
        }
        else if (board[choice] != ' ')
        {
            cout << "Position Taken!\nPlease Select An Empty Position." << endl;
        }
        else
        {
            board[choice] = 'O';
            break;
        }
    }

}

// Keep board count to keep track of which player's turn
int count_board(char symbol) {

    int total = 0;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == symbol)
            total += 1;
    }

    return total;
}

// Check all win conditions to see if winner or draw
char check_winner() {

    // Check winner in rows
    if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
        return board[0];
    if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
        return board[3];
    if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
        return board[6];

    // Check winner in columns
    if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
        return board[0];
    if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
        return board[1];
    if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
        return board[2];

    // Check winner in diagonals
    if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
        return board[0];
    if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
        return board[2];

    if (count_board('X') + count_board('O') < 9)
        return 'C';// Continue game
    else
        return 'D';// Game is a Draw

}

// Show visual of tic tac toe board
void show_board(int round) {
    cout << "Game " << round << endl;
    cout << "\n";
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "   " << board[0] << "   |   " << board[1] << "   |   " << board[2] << endl;
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "-----------------------   " << endl;
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "   " << board[3] << "   |   " << board[4] << "   |   " << board[5] << endl;
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "-----------------------   " << endl;
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "   " << board[6] << "   |   " << board[7] << "   |   " << board[8] << endl;
    cout << "   " << "    |   " << "    |   " << endl;

}

// Game mode for computer vs player
void computer_vs_player(int rounds) {

    string player_name;
    int roundNum = 1;
    char confirm = ' ';
    char confirmPlay;
    int computerRounds = 0, playerRounds = 0, drawRounds = 0;
    bool game = true;
    bool askContinue = true;

    // Ask for player name
    cout << "Enter Your Name: ";
    cin >> player_name;
    // Check player name
    while (true)
    {
        cout << "Is This The Correct Name, " << player_name << "?" << endl;
        cout << "Enter Y for Yes or N for No: ";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y')
        {
            break;
        }
        else if (confirm == 'n' || confirm == 'N')
        {
            cout << "Enter Your Name Again: ";
            cin >> player_name;
        }
        else if ((confirm != 'n' || confirm == 'N') || (confirm == 'y' || confirm == 'Y'))
        {
            cout << "Invalid Input." << endl;
        }
    }

    // Start game(s)
    do {

        // Reset board to start fresh game
        for (int i = 0; i < 9; i++)
        {
            board[i] = ' ';
        }

        // Start 1 round of game
        while (game == true) {
            
            system("cls");
            show_board(roundNum);
            if (count_board('X') == count_board('O'))
            {
                cout << player_name << "'s Turn." << endl;
                get_x_player_choice();
            }
            else
            {
                get_computer_choice();
            }

            // Check winner
            char winner = check_winner();
            if (winner == 'X')
            {
                system("cls");
                show_board(roundNum);
                cout << player_name << " Won The Game!" << endl;
                cin.ignore();
                cout << "Press Any Key to Continue..." << endl;
                cin.get();
                playerRounds++;
                game = false;
                
            }
            else if (winner == 'O')
            {
                system("cls");
                show_board(roundNum);
                cout << "Computer Won The Game!" << endl;
                cin.ignore();
                cout << "Press Any Key to Continue..." << endl;
                cin.get();
                computerRounds++;
                game = false;
                
            }
            else if (winner == 'D')
            {
                system("cls");
                show_board(roundNum);
                cout << "Game is a Draw." << endl;
                cin.ignore();
                cout << "Press Any Key to Continue..." << endl;
                cin.get();
                drawRounds++;
                game = false;
            }

            
        }
        roundNum++;
        game = true;
           

    } while (roundNum <= rounds);
    
    // Show stats at end of whole game(s)
    cout << player_name << " Won " << playerRounds << " Rounds." << endl;
    cout << "Computer Won " << computerRounds << " Rounds." << endl;
    cout << "Draw " << drawRounds << " Rounds." << endl;

}

// Game mode for player vs player
void player_vs_player(int rounds) {

    string x_player_name, o_player_name;
    char confirm, confirmPlay;
    int roundNum = 1;
    int x_player_rounds = 0, o_player_rounds = 0, drawRounds = 0;

    // get player X's name
    cout << "Enter X Player Name: ";
    cin >> x_player_name;
    
    // check name
    while (true)
    {
        cout << "Is This The Correct Name, " << x_player_name << "?" << endl;
        cout << "Enter Y for Yes or N for No: ";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y')
        {
            break;
        }
        else if (confirm == 'n' || confirm == 'N')
        {
            cout << "Enter Your Name Again: ";
            cin >> x_player_name;
        }
        else if ((confirm != 'n' || confirm == 'N') || (confirm == 'y' || confirm == 'Y'))
        {
            cout << "Invalid Input." << endl;
        }
    }

    // get player O's name
    cout << "Enter O Player Name: ";
    cin >> o_player_name;

    // check O's name
    while (true)
    {
        cout << "Is This The Correct Name, " << o_player_name << "?" << endl;
        cout << "Enter Y for Yes or N for No: ";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y')
        {
            break;
        }
        else if (confirm == 'n' || confirm == 'N')
        {
            cout << "Enter Your Name Again: ";
            cin >> o_player_name;
        }
        else if ((confirm != 'n' || confirm == 'N') || (confirm == 'y' || confirm == 'Y'))
        {
            cout << "Invalid Input." << endl;
        }
    }

    // Play game(s)
    do {
        // Reset game
        for (int i = 0; i < 9; i++)
        {
            board[i] = ' ';
        }
        // Start 1 round of game
        while (true) {
            system("cls");
            show_board(roundNum);
            if (count_board('X') == count_board('O'))
            {
                cout << x_player_name << "'s Turn." << endl;
                get_x_player_choice();
            }
            else
            {
                cout << o_player_name << "'s Turn." << endl;
                get_o_player_choice();
            }
            char winner = check_winner();
            if (winner == 'X')
            {
                system("cls");
                show_board(roundNum);
                cout << x_player_name << " Won The Game!" << endl;
                cin.ignore();
                cout << "Press Any Key to Continue..." << endl;
                cin.get();

                
               
                x_player_rounds++;
                break;
            }
            else if (winner == 'O')
            {
                system("cls");
                show_board(roundNum);
                cout << o_player_name << " Won The Game!" << endl;
                cin.ignore();
                cout << "Press Any Key to Continue..." << endl;
                cin.get();
                
                o_player_rounds++;
                break;
            }
            else if (winner == 'D')
            {
                system("cls");
                show_board(roundNum);
                cout << "Game is a Draw." << endl;
                cin.ignore();
                cout << "Press Any Key to Continue..." << endl;
                cin.get();
                drawRounds++;
                break;
            }
        }

        roundNum++;

    } while (roundNum <= rounds);
    
    // After all rounds, show player stats
    cout << x_player_name << " Won " << x_player_rounds << " Rounds." << endl;
    cout << o_player_name << " Won " << o_player_rounds << " Rounds." << endl;
    cout << "Draw " << drawRounds << " Rounds." << endl;

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

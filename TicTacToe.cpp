
//Coded and debugged by Rieley Dechenne as a personal project while being a student at Gonzaga University.
// Rieley Dechenne 2/15/25

#include <iostream>  //This is used so I can use cout, cin, etc.
#include <ctime> //Used to generate a random number for the game

using namespace std;  //Included this so i did not have to include std:: in front of many lines of code.

    //These are the function prototypes that will be used in this program.
void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main() {
    //These are the variable declarions for the spaces of the board and the character assigned to the players.
    char spaces[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool isRunning = true;

    drawBoard(spaces);

    while(isRunning){
        playerMove(spaces, player);
        drawBoard(spaces);
        if(checkWinner(spaces, player, computer)) {
            isRunning = false;
            break;
        }
        else if(checkTie(spaces)) {
            isRunning = false;
            break;

        }

        computerMove(spaces, computer);
        drawBoard(spaces);
        if(checkWinner(spaces, player, computer)) {
            isRunning = false;
            break;
        }
        else if(checkTie(spaces)) {
            isRunning = false;
            break;

        }
    }
    cout << "Thank you for playing and I hope that you had fun and play again and again and again and again." << endl;

    return 0;
}
    //These are the functions definitions used throughout this program.
void drawBoard(char *spaces){
    cout << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';   //This is the function of creating the spaces needed for the board.
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    cout << "     |     |     " << '\n';
    cout << '\n';
}
void playerMove(char *spaces, char player){
    int number;
    do{
        cout << "Enter a spot to place a marker (1-9)";
        cin >> number;
        number--;
        if(spaces[number] == ' '){
            spaces[number] = player;                                          
            break;
        }
    }while(!number > 0 || !number < 8);
}
void computerMove(char *spaces, char computer){
    int number;
    srand(time(0));  //Generates a random number

    while(true){
        number = rand() % 9;   //This will limit the random number to be between 1-9
        if(spaces[number] == ' '){
            spaces[number] = computer;
            break;
        }
    }
}
bool checkWinner(char *spaces, char player, char computer){

    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])) {   //This checks if there are three in row for the top three spaces
        spaces[0] == player ? cout << "You win!\n" : cout << "You lose!\n";  //Trying out using the ternary conditional operator '?' in order to write if-else statements on a single line.
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])) {    //This checks if there are three in a row for the second row
        spaces[3] == player ? cout << "You win!\n" : cout << "You lose!\n";  
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])) {    //This checks if there are three in a row for the third/bottom row.
        spaces[6] == player ? cout << "You win!\n" : cout << "You lose!\n"; 
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])) {   //This checks if there are three in a row vertically of the far left column
        spaces[0] == player ? cout << "You win!\n" : cout << "You lose!\n";  
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])) {   //This checks if there are three in a row vertically of the middle column
        spaces[1] == player ? cout << "You win!\n" : cout << "You lose!\n";  
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])) {   //This checks if there are three in a row vertically of the far right column
        spaces[2] == player ? cout << "You win!\n" : cout << "You lose!\n";  
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])) {   //This checks if there are three in row diagonally (0, 4, 8)
        spaces[0] == player ? cout << "You win!\n" : cout << "You lose!\n";  
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])) {   //This checks if there are three in row diagonally (2, 4, 6)
        spaces[2] == player ? cout << "You win!\n" : cout << "You lose!\n";  
    }
    else{
        return false;
    }

    return true;
}
bool checkTie(char *spaces){

    for(int i = 0; i < 9; i++) {
        if(spaces[i] == ' '){
            return false;
        }
    }
    cout << "Its a tie!\n";
    return true;
}
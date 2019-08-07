#include "header.h"
#include "functions.cpp"

bool running = true;                    //for while cycle to end program
int switchCase;                         //int for switch cases
int roundNumber = 0;                    //number of rounds


int main(){
    chessBoardClass chessBoard;
    deque<Round> rounds;

    chessBoard.initBoard();

    system("cls");


    wcout << L"ф";
    wcout << "\u2654";

    SetConsoleOutputCP(65001); 
    printf("ф\n");
    
    while(running){
    chessBoard.printBoard();
    menu();
    cout << "Enter your input: ";
    cin >> switchCase;
    switch (switchCase)
    {
    case 1:
        chessBoard.initBoard();
        break;
    case 2:
        cout << "White is playing: ";
        cin >> rounds[roundNumber].white_move;
        cout << "Black is playing: ";
        cin >> rounds[roundNumber].black_move;
        roundNumber++;
        break;
    case 4:
        running = false;
        break;
    default:
        cout << "Enter valid input!";
        break;
    }
    }
    

    return 0;
}
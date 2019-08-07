#include "header.h"
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
#define X 48
#define Y 24
void menu(){
    cout << " 2 - Zadej tah. " << endl;
    
}

struct Round                                    //data structure for storing rounds
{
  string white_move;
  string black_move;
};

class chessBoardClass
{
public:
    bool inRange(unsigned low, unsigned high, unsigned x) 
        { 
          return  ((x-low) <= (high-low)); 
        } 
    void initBoard(){
        for (int i = 0; i < Y; i++)
        {
            for (int j = 0; j < X; j++)
            {
                board[i][j] = box;
            }
            
        }
        char arrayPiecesWhite[] = {'R', 'N', 'B', 'Q', 'K', 'B','N','R'};  //array of Pieces
        char arrayPiecesBlack[] = {'r', 'n', 'b', 'q', 'k', 'b','n','r'};  //array of Pieces
        int help[2] = {1,2};
        for (int i = 0; i<8;i++){
            help[1] = 2 + i*6;
            placePiece(help, arrayPiecesWhite[i]);
        }
        help[0] = 4;
        for (int i = 0; i<8;i++){
            help[1] = 2 + i*6;
            placePiece(help, 'P');
        }
        help[0] = 22;
        for (int i = 0; i<8;i++){
            help[1] = 2 + i*6;
            placePiece(help, arrayPiecesBlack[i]);
        }
        help[0] = 19;
        for (int i = 0; i<8;i++){
            help[1] = 2 + i*6;
            placePiece(help, 'p');
        }            
    }
    
    void printBoard(){
        int prepinacRow = 0;
        int n = 8;

        cout << endl;
        cout << "       A     B     C     D     E     F     G     H   " << endl;
        cout << endl;


        SetConsoleTextAttribute(color, 8);   //border up
        cout <<"   ";
        for (int a = 0; a < X + 4; a++)
            cout << box ;
        cout << endl;


        for (int i = 0; i < Y; i++)
        {
            if( i%3  == 1){
                    cout <<" " <<  n << " ";
                }else{
                    cout << "   ";
                }  
            SetConsoleTextAttribute(color, 8);
            cout << box << box;
            for (int j = 0; j < X; j++)
            {   
                    if(prepinacRow == 0){
                        if(inRange(0,5,j) || inRange(12,17,j) || inRange(24,29,j) || inRange(36,41,j))
                    {
                        SetConsoleTextAttribute(color, 0);
                    }else if(inRange(6,11,j) || inRange(18,23,j) || inRange(30,35,j) || inRange(42,47,j)){
                        SetConsoleTextAttribute(color, 15);
                     }
                    }else{
                        if(prepinacRow == 1){
                        if(inRange(0,5,j) || inRange(12,17,j) || inRange(24,29,j) || inRange(36,41,j))
                    {
                        SetConsoleTextAttribute(color, 15);
                    }else if(inRange(6,11,j) || inRange(18,23,j) || inRange(30,35,j) || inRange(42,47,j)){
                        SetConsoleTextAttribute(color, 0);
                     }
                     }
                    }
                if((j == 2 || j == 8 || j == 14 || j == 20 || j == 26 || j == 32 || j == 38 || j == 44) && 1 == i%3){
                    SetConsoleTextAttribute(color, 9);
                    cout << board[i][j];
                }else{
                    cout << board[i][j];
                }
                
                   
            }
            
            if(inRange(0,1,i) || inRange(5,7,i) || inRange(11,13,i) || inRange(17,19,i)){
                prepinacRow = 0;
            }else {
                prepinacRow = 1;
            }

            SetConsoleTextAttribute(color, 8);
            cout << box << box;

            SetConsoleTextAttribute(color, 15);
            if( i%3  == 1){
                    cout << "  " << n;
                    n--;
                }else{
                    cout << " ";
                }  
            cout << endl;
        }

        SetConsoleTextAttribute(color, 8);   //border down
        cout <<"   ";
        for (int a = 0; a < X + 4 ; a++)
            cout << box;
        cout << endl;


        SetConsoleTextAttribute(color, 15);
        cout << endl;
        cout << "       A     B     C     D     E     F     G     H   " << endl;

        
    }

    void placePiece(int position[2], char chessType)
    {       
        board[position[0]][position[1]] = chessType; 
    }

    void removePiece(int position[2])
    {
        board[position[0]][position[1]] = box; 
    }

    
private:
    char board[Y][X];                //radek - sloupec
    char box = (char)219;            // bile pole
};

class chessPiece
{
public:

void getPositionfromInput(string userInput)
{
        string delimiter = "-";                             //splitting string with user input

        size_t pos = 0;
        string oldPosotionString;
        while ((pos = userInput.find(delimiter)) != string::npos) 
        {
        oldPosotionString = userInput.substr(0, pos);
        cout << oldPosotionString << endl;
        userInput.erase(0, pos + delimiter.length());
        }
        string newPositionString = userInput;
        cout << newPositionString << endl;
        }

void convertPositionToIndex(string position){
    if(position == "A8"){

    }
}        

private:
    int oldPosition[2];             // first position is X and second is Y value of chess piece
    int newPosition[2];
};







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
        
    }

    void PositionOfPiece(){
        
    }
    
    void printBoard(){
        int prepinac = 0;
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
                        if(j%6 == 0 && prepinac == 0)
                    {
                        SetConsoleTextAttribute(color, 0);
                        prepinac = 1;
                    }else if(j%6 == 0 && prepinac == 1){
                        SetConsoleTextAttribute(color, 15);
                        prepinac = 0;
                     }
                    }else{
                        if(j%6 == 0 && prepinac == 0)
                    {
                        SetConsoleTextAttribute(color, 15);
                        prepinac = 1;
                    }else if(j%6 == 0 && prepinac == 1){
                        SetConsoleTextAttribute(color, 0);
                        prepinac = 0;
                     }
                    }
                  
                cout << board[i][j];
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
    
private:
    char board[Y][X];                //radek - sloupec
    char box = (char)219;            // bile pole
};

class chessPiece
{
public:

private:

};







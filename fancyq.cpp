/*
  Notes before starting:
  Empty spaces are denoted by ' ' 
  Spaces occupied by a queen are denoted by '='.
*/


#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:


    // board is our old board
    vector<vector<int>> board;
    int boardSize = 8;
    int count = 1;

    typedef char box[5][7];
    box blackSpace, whiteSpace, *fancyBoard[8][8];

    box wsQueen =  { {' ',' ',' ',' ',' ',' ',' '},
                     {' ','=',' ','=',' ','=',' '},
                     {' ','=','=','=','=','=',' '},
                     {' ','=','=','=','=','=',' '},
                     {' ',' ',' ',' ',' ',' ',' '} };

    box bsQueen = { {'=','=','=','=','=','=','='},
                    {'=',' ','=',' ','=',' ','='},
                    {'=',' ',' ',' ',' ',' ','='},
                    {'=',' ',' ',' ',' ',' ','='},
                    {'=','=','=','=','=','=','='} };


    Solution(){
      board = createBoard(boardSize);
       setupFancyPrint();
    }


    void setupFancyPrint(){
      //create the blackspace and white space in memory

      for(int i = 0; i < 5; i++){
        for(int j = 0; j < 7; j++){
          blackSpace[i][j] = ' ';
          whiteSpace[i][j] = '=';
        }
      }

      
      for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
          if ((i+j)%2==1 && board[i][j]==0) {
            fancyBoard[i][j]=&whiteSpace;
          } else if((i+j)%2==1 && board[i][j]==1){
            fancyBoard[i][j]=&bsQueen;
          } else if((i+j)%2==0 && board[i][j]==0 ){
            fancyBoard[i][j]=&blackSpace;
          } else{
            fancyBoard[i][j]=&wsQueen;
          }
        }
      }

    }


    void showFancyBoard(){
      cout << "solution #: " << count << endl;
      count += 1;
    for (int i = 0; i<8; i++){
        for(int k=0; k<5; k++){
            for(int j=0;j<8;j++){
                for(int l=0;l<7;l++){
                    cout<<(*fancyBoard[i][j])[k][l];
                }
            }
            cout << endl;
        }
    }
    }


    // Do not touch code below this line and above (look below)...

    vector<vector<int>> createBoard(int n){
        vector<vector<int>> arr(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                arr[i][j] = 0;
            }
        }
        return arr;
    }
    
    void showBoard(){
        cout<<count++<<"\n";
        for(int i = 0; i < boardSize; i++){
            for(int j = 0; j < boardSize; j++){
                cout<<board[i][j]<< "   ";
            }
            cout<<"\n \n";
        }
        cout<<"\n";
    }
    
    bool checkRow(int row, int currCol){
        for(int i = 0; i < currCol; i++){
            if ( board[row][i] == 1 ){
                return false;
            }
        }
        return true;
    }
    bool checkDiagonalUp(int row, int currCol){
        for(int i = 1; (row - i > -1) and (currCol - i > -1); i ++) {
            if (board[row - i][currCol - i] == 1){
                return false;
            }
        }
        return true;       
    }
    
    bool checkDiagonalDown(int row, int currCol){

        for (int i = 0; (row + i < boardSize) and (currCol - i > -1); i++) {
            if (board[row + i][currCol - i] == 1){
                return false;
            }
        }
        return true;
    }
    
    bool checkAll(int row, int currCol){
        if ( checkDiagonalDown(row, currCol) and checkRow(row, currCol) and checkDiagonalUp(row, currCol) ){
            return true;
        }
        else{
            return false;
        }
    }
    
    void helper(int currCol){

        if ( currCol >= boardSize ){
            //showBoard();
            setupFancyPrint();
           showFancyBoard();
            cout << endl;
            return;
        }

        for( int i = 0; i < boardSize; i++){
            if( checkAll(i, currCol) ){
                board[i][currCol] = 1;
                helper(currCol + 1);
                board[i][currCol] = 0;
            }
        }
    }
    
    void solveQueens() {
        helper(0);
    }


  //...and above this line EXCEPT FOR REPLACING showboard WITH showFancyBoard.



};

int main(){
  Solution s; // do not modify this line
 s.solveQueens();   // uncomment this line when you are ready to check final solution

  // use the rest of main to test your functions as you progrss.

  // s.showFancyBoard();



  cout<<"finished";
  return 0;
}
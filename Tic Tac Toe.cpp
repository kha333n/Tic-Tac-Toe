//Tic Tac Toe Game.
#include <iostream>
//#include <random> 
#include <iomanip>
#define O 'O';
#define X 'O';
using namespace std;
// -------
// |1|2|3|
// -------
// |4|5|6|
// -------
// |7|8|9|
// -------
void moves(char game[3][3], char move, int inputPlayerMove, bool* CheckForMultipleX, bool* CheckForMultipleO, int* NumberOfMoves);

// added by swim
void moves(char game[][3], char move, int inputPlayerMove, int* NumberOfMoves);
bool checkDiags(char game[][3], char sym);
bool checkRC(char game[][3], char sym);
bool checkWinner(char game[][3]);
// end addition

void createLayout(char game[3][3]);
void maintence(char* move);
void win(char game[3][3]);
void ifInvalidInput(int *inputPlayerMove, char game[3][3]);
int main()
{

    char game[][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
    int NumberOfMoves = 0; // numberOfMoves
    char move = 'X';
    bool CheckForMultipleX = false; // change it to a varuble name
    bool CheckForMultipleO = false; // change it to a varuble name
    // an array with 5 rows and 2 columns.
    int inputPlayerMove = -1; // x starts
    string cpup2; // inputPlayerMode , create enum gameMode {CPU, 2 players}
    enum inputPlayerMode {CPU = 'c', p2 = 'p'};
    char beforeExecutePlayerMode;
    cout << "Would you like to play c(cpu) or p(2p) " << endl;
    cin >> beforeExecutePlayerMode;
    inputPlayerMode ExecutePlayerMode = (inputPlayerMode)beforeExecutePlayerMode;
    if (ExecutePlayerMode == 'p') {
        createLayout(game);
        while (NumberOfMoves < 9) {
            cout << "Enter the number you'd like to put on" << endl;
            cin >> inputPlayerMove;
            ifInvalidInput(&inputPlayerMove,game);
            
/* 
You don't need CheckForMultipleX or             
CheckForMultipleY. Your first move is always X and NumberOfMoves starts with 0, so if   NumberOfMoves is even your move is 'X' and 'O' if it is odd. I don't think you need maintence function.
*/                                  
             if(NumberOfMoves%2 == 0)
                move = 'X';
            else move = 'O';
            
            moves(game, move, inputPlayerMove,&NumberOfMoves);
            /*
            moves(game, move, inputPlayerMove, &CheckForMultipleX, &CheckForMultipleO, &NumberOfMoves);
            if (CheckForMultipleX == true) {
                move = 'O';
            }
            else if (CheckForMultipleO == true) {
                move = 'X';
            }*/

           /* else 
            {
               maintence(&move);
            }*/
            createLayout(game);
            //win(game);
            if(checkWinner(game)) return 0;
            if (NumberOfMoves == 9) {
                cout << "It's a Draw!" << endl;
            }
        }
    }
    else if (ExecutePlayerMode == 'c') {
        // TD ai
    }
}
void createLayout(char game[3][3]) {
    cout << "-------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << '|';
        for (int j = 0; j < 3; j++) {
            cout << game[i][j];
            cout << '|';
            if (j == 2) {
                cout << endl;
                cout << "-------" << endl;
            }
        }

    }

}
void maintence(char* move) {
    if (*move == 'X') {
        *move = 'O';
    }
    else {
        *move = 'X';
    }
}

// check for comments
void moves(char game[3][3], char move, int inputPlayerMove, bool* CheckForMultipleX, bool* CheckForMultipleO, int* NumberOfMoves) {

    // create a function if the input is valid
    // create a function that excute the move if valid
    if (inputPlayerMove == 1) {
        if (game[0][0] == 'X') {
            cout << "You already used this place! Pleaes choose a diffrent position." << endl;
            *CheckForMultipleX = true;
        }
        else if (game[0][0] == 'O') {
            cout << "You already used this place! Pleaes choose a diffrent position." << endl;
            *CheckForMultipleO = true;
        }
        else {
            *CheckForMultipleO = false;
            *CheckForMultipleX = false;
            game[0][0] = move;
            *NumberOfMoves = *NumberOfMoves + 1;
        }
    }
    if (inputPlayerMove == 2) {
        if (game[0][1] == 'X') {
            cout << "You already used this place! Pleaes choose a diffrent position." << endl;
            *CheckForMultipleX = true;
        }
        else if (game[0][1] == 'O') {
            cout << "You already used this place! Pleaes choose a diffrent position." << endl;
            *CheckForMultipleO = true;
        }
        else {
            game[0][1] = move;
            *CheckForMultipleO = false;
            *CheckForMultipleX = false;
            *NumberOfMoves = *NumberOfMoves + 1;
        }
    }
    if (inputPlayerMove == 3) {
        if (game[0][2] == 'X') {
            cout << "You already used this place! Pleaes choose a diffrent position." << endl;
            *CheckForMultipleX = true;
        }
        else if (game[0][2] == 'O') {
            cout << "You already used this place! Pleaes choose a diffrent position." << endl;
            *CheckForMultipleO = true;
        }
        else {
            game[0][2] = move;
            *CheckForMultipleO = false;
            *CheckForMultipleX = false;
            *NumberOfMoves = *NumberOfMoves + 1;
        }
    }
    if (inputPlayerMove == 4) {
        if (game[1][0] == 'X') {
            cout << "You already used this place! Pleaes choose a diffrent position." << endl;
            *CheckForMultipleX = true;
        }
        else if (game[1][0] == 'O') {
            cout << "You already used this place! Pleaes choose a diffrent position." << endl;
            *CheckForMultipleO = true;
        }
        else {
            game[1][0] = move;
            *CheckForMultipleO = false;
            *CheckForMultipleX = false;
            *NumberOfMoves = *NumberOfMoves + 1;
        }
    }
    if (inputPlayerMove == 5) {
        if (game[1][1] == 'X') {
            cout << "You already used this place! Pleaes choose a diffrent position." << endl;
            *CheckForMultipleX = true;
        }
        else if (game[1][1] == 'O') {
            cout << "You already used this place! Pleaes choose a diffrent position." << endl;
            *CheckForMultipleO = true;
        }
        else {
            game[1][1] = move;
            *CheckForMultipleO = false;
            *CheckForMultipleX = false;
            *NumberOfMoves = *NumberOfMoves + 1;
        }
    }
    if (inputPlayerMove == 6) {
        if (game[1][2] == 'X') {
            cout << "You already used this place! Pleaes choose a diffrent position." << endl;
            *CheckForMultipleX = true;
        }
        else if (game[1][2] == 'O') {
            cout << "You already used this place! Pleaes choose a diffrent position." << endl;
            *CheckForMultipleO = true;
        }
        else {
            game[1][2] = move;
            *CheckForMultipleO = false;
            *CheckForMultipleX = false;
            *NumberOfMoves = *NumberOfMoves + 1;
        }
    }
    if (inputPlayerMove == 7) {
        if (game[2][0] == 'X') {
            cout << "You already used this place! Pleaes choose a diffrent position." << endl;
            *CheckForMultipleX = true;
        }
        else if (game[2][0] == 'O') {
            cout << "You already used this place! Pleaes choose a diffrent position." << endl;
            *CheckForMultipleO = true;
        }
        else {
            game[2][0] = move;
            *CheckForMultipleO = false;
            *CheckForMultipleX = false;
            *NumberOfMoves = *NumberOfMoves + 1;
        }
    }
    if (inputPlayerMove == 8) {
        if (game[2][1] == 'X') {
            cout << "You already used this place! Pleaes choose a diffrent position." << endl;
            *CheckForMultipleX = true;
        }
        else if (game[2][1] == 'O') {
            cout << "You already used this place! Pleaes choose a diffrent position." << endl;
            *CheckForMultipleO = true;
        }
        else {
            game[2][1] = move;
            *CheckForMultipleO = false;
            *CheckForMultipleX = false;
            *NumberOfMoves = *NumberOfMoves + 1;
        }
    }
    if (inputPlayerMove == 9) {
        if (game[2][2] == 'X') {
            cout << "You already used this place! Pleaes choose a diffrent position." << endl;
            *CheckForMultipleX = true;
        }
        else if (game[2][2] == 'O') {
            cout << "You already used this place! Pleaes choose a diffrent position." << endl;
            *CheckForMultipleO = true;
        }
        else {
            game[2][2] = move;
            *CheckForMultipleO = false;
            *CheckForMultipleX = false;
            *NumberOfMoves = *NumberOfMoves + 1;
        }
    }

}

/*
You need to find if the position is already occupied so you need to find row and col corresponding to inputPlayerMove.
dividing (inputPlayerMove-1) by 3 will give you the row and (inputPlayerMove-1) mod 3 will give you the column. Once you get row and column simply check if it is occupied or not. If not add the move and increment the move counter
*/

void moves(char game[][3], char move, int inputPlayerMove, int* NumberOfMoves)
{
    int row = (inputPlayerMove-1)/3;
    int col = (inputPlayerMove-1)%3;
    
    if(game[row][col] == 'X' || 
        game[row][col] == 'O')
    {
        cout << "You already used this place! Pleaes choose a diffrent position.\n";
    }
    else
    {
        game[row][col] = move;
        *NumberOfMoves += 1;
    }
}

// check rows and columns for win
bool checkRC(char game[][3], char sym)
{
    for(int i = 0; i < 3; ++i)
    {
        int sumR = 0, sumC = 0;
        for(int j = 0; j < 3; ++j)
        {
           if(game[i][j] == sym) sumR += 1;
           if(game[j][i] == sym) sumC += 1;
        }
        if (sumR == 3 || sumC == 3) 
            return true;       
    }
    return false;
}

// check diagonals for win
bool checkDiags(char game[][3], char sym)
{
    if((game[0][0] == sym && game[1][1] == sym && game[2][2] == sym) || (game[2][0] == sym && game[1][1] == sym && game[0][2] == sym))
        return true;
        
    return false;
}

// check the winner
bool checkWinner(char game[][3])
{
 if(checkRC(game,'X')||    
    checkDiags(game,'X'))
    {
        cout << "X Wins\n";
        return true;
    }
    else if(checkRC(game,'O') || 
         checkDiags(game,'O'))
    {
        cout << "O Wins\n";
        return true;
    }
 return false;
}
        
/*
// rename
void win(char game[3][3]) {
    bool winorno = false;
    int countt = 0;
    for (int i = 0; i < 3; i++) {
        if (game[0][i] == 'X' && game[1][i] == 'X' && game[2][i] == 'X') {
            cout << "X won!" << endl;
            winorno = true;
            exit(EXIT_FAILURE);
        }
        if (game[0][i] == 'O' && game[1][i] == 'O' && game[2][i] == 'O') {
            cout << "O won!" << endl;
            winorno = true;
            exit(EXIT_FAILURE);
        }
    }
    for (int i = 0; i < 3; i++) {
        if (game[i][0] == 'X' && game[i][1] == 'X' && game[i][2] == 'X') {
            cout << "X won!" << endl;
            winorno = true;
            exit(EXIT_FAILURE);
        }
        if (game[i][0] == 'O' && game[i][1] == 'O' && game[i][2] == 'O') {
            cout << "O won!" << endl;
            winorno = true;
            exit(EXIT_FAILURE);
        }
    }
    if (game[0][0] == 'X' && game[1][1] == 'X' && game[2][2] == 'X') {
        cout << "X won!" << endl;
        winorno = true;
        exit(EXIT_FAILURE);
    }
    if (game[0][2] == 'X' && game[1][1] == 'X' && game[2][0] == 'X') {
        cout << "X won!" << endl;
        winorno = true;
        exit(EXIT_FAILURE);
    }
    if (game[0][2] == 'O' && game[1][1] == 'O' && game[2][0] == 'O') {
        cout << "O won!" << endl;
        winorno = true;
        exit(EXIT_FAILURE);
    }
    if (game[0][0] == 'O' && game[1][1] == 'O' && game[2][2] == 'O') {
        cout << "O won!" << endl;
        winorno = true;
        exit(EXIT_FAILURE);
    }
}
*/


void ifInvalidInput(int *inputPlayerMove,char game[3][3]) {
    while (cin.fail())
    {
        cin.clear(); // clear input
        cin.ignore(INT_MAX, '\n'); // ignore last input
        createLayout(game);
        cout << "Invalid input" << endl;
        cin >> *inputPlayerMove;
    }
    while (*inputPlayerMove > 9 || *inputPlayerMove < 1) {
        createLayout(game);
        cout << "Invalid input" << endl;
        cin >> *inputPlayerMove;
    }
}

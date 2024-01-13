#include "..\HeaderFiles\board.h"

int main(){
    Board board;
    board.display();
    cout << "Press any Key to exit: ";
    string s; getline(cin , s);
    return 0;
}
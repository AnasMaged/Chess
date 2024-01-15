#include "..\HeaderFiles\ChessConstans.h"
#include "..\HeaderFiles\game.h"

int main(){
    
    while(true){
        cout << "-------------------------\n";
        cout << "     Game Menu\n";
        cout << "-------------------------\n";
        cout << "1. Start a New Game\n";
        cout << "2. Exit\n";
        cout << "-------------------------\n";
        cout << "Enter your choice (1 or 2): ";
        
        label:

        string choice;
        cin >> choice; 
    
        if(choice == "1"){
            cout << "Starting a new game...\n\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            Game* game = new Game();
            game->play();
        }

        else if(choice == "2"){
            cout << "Exiting the program. Goodbye!\n\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
        }
        
        else{
            cout << "Invalid input. Please enter 1 or 2: ";
            goto label;
        }
    }

    return 0;
}
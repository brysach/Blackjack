#include "Card.hpp"
#include "Hand.hpp"
#include "Participant.hpp"
#include "Player.hpp"
#include "Dealer.hpp"
#include "Deck.hpp"
#include "Record.hpp"
#include "Blackjack_Game.hpp"

int main(){
    cout << "\nWelcome to Blackjack!" << endl;

    int numPlayers = 0;
    while(numPlayers < 1  || numPlayers > 7){
        cout << "\nEnter number of players (1-7): ";
        cin >> numPlayers;
    }
    cout << endl;

    Record scores(numPlayers);
    vector<string> names;
    for(int i = 0; i < numPlayers; i++){
        string name;
        cout << "Enter player #" << i + 1 << "'s name: ";
        cin.ignore();
        cin >> name; 
        names.push_back(name);
    }

    Blackjack_Game aGame(names);
    char playAgain = 'y';

    while(playAgain != 'n'){
        aGame.play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;
    }

    cout << "\t\tAfter ending the game" << endl;
    scores.recordsToFile(aGame.getPlayers());
    cout << "\t\tAfter recordsToFile()" << endl;
    scores.recordsFromFile();
    scores.retrieveRecord();

    return 0;
}

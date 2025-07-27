#include "Blackjack_Game.hpp"

Blackjack_Game::Blackjack_Game(const vector<string>& names){
    for(int i = 0; i < names.size(); i++){
        mPlayers.push_back(Player(names[i]));
        //Deck's default constructor is executed here
    }
}

Blackjack_Game::~Blackjack_Game(){}

void Blackjack_Game::displayPlayerHand(){
    for(int i = 0; i < mPlayers.size(); i++){
        cout << mPlayers[i] << endl;
    }    
}

vector<Player> Blackjack_Game::getPlayers() const{
    return mPlayers;
}

void Blackjack_Game::play(){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < mPlayers.size(); j++){
            mDeck.deal(mPlayers[j]);
        }
        mDeck.deal(mDealer);
    }

    mDealer.flipFirstCard();

    //Print initial hands
    string iniHands = "INITIAL HANDS";
    cout << endl << "\t" << iniHands << endl << "\t";
    for(int i = 0; i < iniHands.size(); i++){
        cout << "-";
    }
    cout << endl;
    for(int i = 0; i < mPlayers.size(); i++){
        cout << mPlayers[i] << endl;
    }
    cout << mDealer << endl;

    for(int i = 0; i < mPlayers.size(); i++){
        mDeck.additionalCard(mPlayers[i]);      
        //cout << mPlayers[i] << endl;
    }

    cout << "\n\t*Dealer reveals card*" << endl;
    mDealer.flipFirstCard();
    cout << mDealer << endl;

    if(!(mDealer.isBusted()) && mDealer.isHitting()){
        cout << "\n\tDealer hits!" << endl;
    }
    mDeck.additionalCard(mDealer);
    //cout << mDealer << endl;

    if(mDealer.isBusted()){
        for(int i = 0; i < mPlayers.size(); i++){
            if(!(mPlayers[i].isBusted())){
                mPlayers[i].win();
            }
        }
    } else{
        for(int i = 0; i < mPlayers.size(); i++){
            if(!(mPlayers[i].isBusted())){
                if(mPlayers[i].getTotal() > mDealer.getTotal()){
                    mPlayers[i].win();
                } else if(mPlayers[i].getTotal() < mDealer.getTotal()){
                    mPlayers[i].lose();
                } else{
                    mPlayers[i].push();
                }
            }
        }
    }

    for(int i = 0; i < mPlayers.size(); i++){
        mPlayers[i].clearHand();
    }
    
    mDealer.clearHand();
}
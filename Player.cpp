#include "Player.hpp"

Player::Player(const string& name){
    mName = name;
}

Player::~Player(){
}

bool Player::isHitting() const{
    if(mHand.getTotal() < 21){
        char response;
        cout << endl << mName << ", do you want to hit (Y/N): ";
        cin >> response;
        return (response == 'y');
    } else{
        return false;
    }
}

void Player::win(){
    cout << "\n\t" << mName << " wins!" << endl;
    wins++;
}

void Player::lose(){
    cout << "\n\t" << mName << " loses!" << endl;
    losses++;
}

void Player::push(){
    cout << "\n\t" << mName << " pushes!" << endl;
    pushes++;
}

int Player::getWins() const{
    return wins;
}

int Player::getLosses() const{
    return losses;
}

int Player::getPushes() const{
    return pushes;
}

string Player::getName() const{
    return mName;
}


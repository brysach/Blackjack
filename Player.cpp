#include "Player.hpp"

Player::Player(const string& name){
    mName = name;
    wins = 0;
    losses = 0;
    pushes = 0;
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

void Player::setName(string name){
    mName = name;
}

void Player::setWins(int wins){
    this->wins = wins;
}

void Player::setLosses(int losses){
    this->losses = losses;
}

void Player::setPushes(int pushes){
    this->pushes = pushes;
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


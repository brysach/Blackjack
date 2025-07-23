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

void Player::win() const{
    cout << "\n\t" << mName << " wins!" << endl;
}

void Player::lose() const{
    cout << "\n\t" << mName << " loses!" << endl;
}

void Player::push() const{
    cout << "\n\t" << mName << " pushes!" << endl;
}


#include "Player.hpp"

Player::Player(const string& name){
    mName = name;
}

Player::~Player(){
}

bool Player::isHitting() const{
    char response;
    cout << mName << " , do you want to hit (Y/N): ";
    cin >> response;
    return (response == 'y');
}

void Player::win() const{
    cout << mName << " wins." << endl;
}

void Player::lose() const{
    cout << mName << " loses." << endl;
}

void Player::push() const{
    cout << mName << " pushes." << endl;
}


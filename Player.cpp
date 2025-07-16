#include "Player.hpp"

Player::Player(const string& name){
    mName = name;
}

Player::~Player(){
}

bool Player::isHitting() const{
    char response;
    cout << endl << mName << " , do you want to hit (Y/N): ";
    cin >> response;
    return (response == 'y');
}

void Player::win() const{
    cout << "\t" << mName << " wins!" << endl;
}

void Player::lose() const{
    cout << "\t" << mName << " loses!" << endl;
}

void Player::push() const{
    cout << "\t" << mName << " pushes!" << endl;
}


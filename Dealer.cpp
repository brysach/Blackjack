#include "Dealer.hpp"

Dealer::Dealer(const string& name){
    mName = name;
}

Dealer::~Dealer(){}

bool Dealer::isHitting() const{
    return (mHand.getTotal() > 16);
}

void Dealer::flipFirstCard(){
    if(mHand.getTotal() != 0){
        mHand.getCard(0)->flip();
    }else{
        cout << "No card to flip!" << endl;
    }
}
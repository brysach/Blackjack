#include "Hand.hpp"

Hand::Hand(){
    mCards.reserve(7);
}

Hand::~Hand(){
    clear();
}

Card* Hand::getCard(int index){
    if(getTotal() != 0){
        return mCards[index];
    }else{
        return nullptr;
    }
}

void Hand::addCard(Card* pCard){
    mCards.push_back(pCard);
}

//Note: I could use iterator too
void Hand::clear(){
    for(int i = 0; i < mCards.size(); i++){
        delete mCards[i];
    }

    mCards.clear();
}

int Hand::getTotal() const{
    int sum = 0;
    bool hasAce = false;

    for(int i = 0;  i < mCards.size(); i++){
        sum += mCards[i]->getValue();
        
        if(mCards[i]->getValue() == Card::ACE){
            hasAce = true;
        }
    }

    if(hasAce && sum <= 11){
        sum += 10;
    }

    return sum;
}

int Hand::getSize() const{
    return mCards.size();
}
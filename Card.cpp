#include "Card.hpp"

Card::Card(rank r, suit s, bool ifu){
    mRank = r;
    mSuit = s;
    mIsFaceUp = ifu;
}

int Card::getValue() const{
    int value = 0;
    if(mIsFaceUp){
        if(mRank > 10){
            value = 10;
        } else{
            value = mRank;
        }
    }

    return value;
}

void Card::flip(){
    mIsFaceUp = !(mIsFaceUp);
}

ostream& operator<<(ostream& os, const Card& aCard){
    const string RANKS[] = {"", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    const string SUITS[] = {"c", "d", "h", "s"};

    if(aCard.mIsFaceUp){
        os << RANKS[aCard.mRank] << SUITS[aCard.mSuit] << "\t";
    } else{
        cout << "XX\t";
    }

    return  os;
}
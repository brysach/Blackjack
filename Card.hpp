#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>

using namespace std;

class Card{
    public:
        enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
        enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};

        Card(rank r = ACE, suit s = SPADES, bool ifu = true);

        int getValue() const;

        void flip();

        friend ostream& operator<<(ostream& os, const Card& aCard);

    private:
        rank mRank;
        suit mSuit;
        bool mIsFaceUp;

};
#endif
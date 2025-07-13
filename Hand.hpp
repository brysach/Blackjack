#ifndef HAND_HPP
#define HAND_HPP

#include <vector>
#include "Card.hpp"

class Hand{
    protected:
        vector<Card*> mCards;
    public:
        Hand();
        virtual ~Hand();

        Card* getCard(int index);
        void addCard(Card* pCard);
        void clear();
        int getTotal() const;
        int getSize() const;
};
#endif

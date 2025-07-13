#ifndef DECK_HPP
#define DECK_HPP

#include "Hand.hpp"
#include "Participant.hpp"

class Deck : public Hand{
    public:
        Deck();
        virtual ~Deck();

        void populate();

        void shuffle();
        void deal(Participant& aParticipant);
        void additionalCard(Participant& aParticipant);

};
#endif
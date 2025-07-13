#ifndef DEALER_HPP
#define DEALER_HPP

#include "Participant.hpp"

class Dealer : public Participant{
    public:
        Dealer(const string& name = "Dealer");
        virtual ~Dealer();

        virtual bool isHitting() const;

        void flipFirstCard();
};
#endif
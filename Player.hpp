#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Participant.hpp"

class Player : public Participant{
    public:
        Player(const string& name = "");
        virtual ~Player();

        virtual bool isHitting() const;

        void win() const;
        void lose() const;
        void push() const;
};
#endif
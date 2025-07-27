#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Participant.hpp"

class Player : public Participant{
    private:
        int wins = 0;
        int losses = 0;
        int pushes = 0;
    public:
        Player(const string& name = "");
        virtual ~Player();

        virtual bool isHitting() const;

        void win();
        void lose();
        void push();

        int getWins() const;
        int getLosses() const;
        int getPushes() const;
};
#endif
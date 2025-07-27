#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Participant.hpp"

class Player : public Participant{
    private:
        int wins;
        int losses;
        int pushes;
    public:
        Player(const string& name = "");
        virtual ~Player();

        virtual bool isHitting() const;

        void win();
        void lose();
        void push();

        void setName(string name);
        void setWins(int wins);
        void setLosses(int losses);
        void setPushes(int pushes);

        int getWins() const;
        int getLosses() const;
        int getPushes() const;
        string getName() const;
};
#endif
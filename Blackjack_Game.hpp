#ifndef BLACKJACK_GAME_HPP
#define BLACKJACK_GAME_HPP

#include "Participant.hpp"
#include "Player.hpp"
#include "Dealer.hpp"
#include "Deck.hpp"
#include "Record.hpp"

class Blackjack_Game{
    private:
        Deck mDeck;
        Dealer mDealer;
        vector<Player> mPlayers;
        
    public:
        Blackjack_Game(const vector<string>& names);
        virtual ~Blackjack_Game();

        void displayPlayerHand();
        vector<Player> getPlayers() const;
        void play();
};
#endif
#include "Deck.hpp"
#include <algorithm>

Deck::Deck(){
    mCards.reserve(52);
    populate();
}

Deck::~Deck(){}

void Deck::populate(){
    clear();

    for(int s = Card::CLUBS; s <= Card::SPADES; s++){
        for(int r = Card::ACE; r <= Card::KING; r++){
            addCard(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
        }
    }
}

void Deck::shuffle(){
    random_shuffle(mCards.begin(), mCards.end());
}

void Deck::deal(Participant& aParticipant){
    if(!mCards.empty()){
        aParticipant.addCard(mCards.back());
        mCards.pop_back();
    } else{
        cout << "Deck is empty!" << endl;
    }

}

void Deck::additionalCard(Participant& aParticipant){
    while(!(aParticipant.isBusted()) && aParticipant.isHitting()){
       deal(aParticipant); 
       cout << aParticipant << endl;

        if(aParticipant.isBusted()){
            aParticipant.bust();
        }
    }
}


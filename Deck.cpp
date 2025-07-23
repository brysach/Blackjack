#include "Deck.hpp"
#include <algorithm>
#include <ctime>

Deck::Deck(){
    mCards.reserve(52);    
    srand(static_cast<unsigned int>(time(0)));
    populate();
    shuffle();  
}

Deck::~Deck(){}

void Deck::print(){
    cout << "\n{";
    for(int i = 0; i < mCards.size(); i++){
        cout << *mCards[i];
        if(i != 0 && ((i + 1) % 13 == 0) && i != mCards.size() - 1){
            cout << endl;
        }
    }
    cout << "}\n" << endl;
}

void Deck::populate(){
    clear();

    for(int s = Card::CLUBS; s <= Card::SPADES; s++){
        for(int r = Card::ACE; r <= Card::KING; r++){
            addCard(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
        }
    }

    //print();  //Print deck to debug
}

void Deck::shuffle(){
    random_shuffle(mCards.begin(), mCards.end());
    cout << "\tSHUFFLING\n";
}

void Deck::deal(Participant& aParticipant){
    if(!mCards.empty()){
        aParticipant.addCard(mCards.back());
        mCards.pop_back();
        //print();  //Print deck to debug
    } else{
        cout << "\n\tDeck is empty!" << endl;
        cout << "\tShuffling new deck..." << endl;
        populate();
        shuffle();
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


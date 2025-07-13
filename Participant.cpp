#include "Participant.hpp"

Participant::Participant(const string& name){
    mName = name;
}

Participant::~Participant(){}

bool Participant::isBusted() const{
    return (mHand.getTotal() > 21);
}

void Participant::bust() const{
    cout << mName << " busts" << endl;
}

void Participant::addCard(Card* aCard){
    mHand.addCard(aCard);
}

int Participant::getTotal() const{
    return mHand.getTotal();
}

void Participant::clearHand(){
    mHand.clear();
}

ostream& operator<<(ostream& os, const Participant& aParticipant){
    os << aParticipant.mName << ":\t";

    if(aParticipant.getTotal() != 0){
        for(int i = 0; i <  aParticipant.mHand.getSize(); i++){
            os << *(aParticipant.mHand.getCard(i));
        }
    }
}
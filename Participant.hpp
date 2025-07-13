#ifndef PARTICIPANT_HPP
#define PARTICIPANT_HPP

#include <string>
#include "Hand.hpp"
using namespace std;

class Participant{
   protected:
      string mName; 
      Hand mHand;

   public:
      Participant(const string& name = "");
      virtual ~Participant();

      virtual bool isHitting() const = 0;

      bool isBusted() const;

      void bust() const;

      void addCard(Card* aCard);

      int getTotal() const;

      void clearHand();

      friend ostream& operator<<(ostream& os, const Participant& aParticipant);
};
#endif
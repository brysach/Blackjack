#ifndef RECORD_HPP
#define RECORD_HPP

#include "Player.hpp";

class Record{
    private:
        int numPlayers;
        Player* player;

    public:
        Record();
        virtual ~Record();

        void recordsToFile();
        void recordsFromFile();
        void retrieveRecord(Player& playerRecord);

};
#endif


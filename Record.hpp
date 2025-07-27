#ifndef RECORD_HPP
#define RECORD_HPP

#include "Player.hpp"

class Record{
    private:
        int numPlayers;
        Player* mPlayers;

    public:
        Record(int size);
        virtual ~Record();

        void recordsToFile(vector<Player> players);
        void recordsFromFile();
        void retrieveRecord();

};
#endif


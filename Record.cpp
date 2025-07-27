#include "Record.hpp"
#include <fstream>

Record::Record(){

};

Record::~Record(){
    delete [] player;
}

void Record::recordsToFile(){
    ofstream out("record.dat", ios::binary);

    if(out.good()){
        for(int i = 0; i < numPlayers; i++){
            int nameLen = player[i].getName().size();
            out.write(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));
            out.write(player[i].getName().c_str(), nameLen);

            out.write(reinterpret_cast<char*>(player[i].getWins()), sizeof(player[i].getWins()));
            out.write(reinterpret_cast<char*>(player[i].getLosses()), sizeof(player[i].getLosses()));
            out.write(reinterpret_cast<char*>(player[i].getPushes()), sizeof(player[i].getPushes()));
        }
    }
}
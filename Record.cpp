#include "Record.hpp"
#include <fstream>

Record::Record(int size){
    numPlayers = size;
    mPlayers = new Player[numPlayers];
};

Record::~Record(){
    delete [] mPlayers;
}

void Record::recordsToFile(vector<Player> players){
    ofstream out("record.dat", ios::binary);

    if(out.good()){
        for(int i = 0; i < numPlayers; i++){
            //cout << "\tHELLO??" << endl;
            int nameLen = players[i].getName().size();
            //cout << "\t" << players[i].getName() << endl;
            out.write(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));
            out.write(players[i].getName().c_str(), nameLen);

            //cout << "\tIs there a problem?" << endl;
            int* tempInt = new int;
            *tempInt = players[i].getWins();
            out.write(reinterpret_cast<char*>(tempInt), sizeof(int));

            *tempInt = players[i].getLosses();
            out.write(reinterpret_cast<char*>(tempInt), sizeof(int));

            *tempInt = players[i].getPushes();
            out.write(reinterpret_cast<char*>(tempInt), sizeof(int));
            delete tempInt;
        }

        cout << "\tRECORDS TO FILE SUCCESSFUL" << endl;
        out.close();
    }
}

void Record::recordsFromFile(){
    ifstream in("record.dat", ios::binary | ios::in);
    
    if(in.good()){
        for(int i = 0; i < numPlayers; i++){
            int nameLen;
            in.read(reinterpret_cast<char*>(&nameLen), sizeof(int));
            char* name = new char[nameLen + 1];
            in.read(name, nameLen);
            name[nameLen] = '\0';
            mPlayers[i].setName(string(name));
            delete [] name;

            int tempWins;
            int tempLosses;
            int tempPushes;
            in.read(reinterpret_cast<char*>(&tempWins), sizeof(int));
            in.read(reinterpret_cast<char*>(&tempLosses), sizeof(int));
            in.read(reinterpret_cast<char*>(&tempPushes), sizeof(int));

            mPlayers[i].setWins(tempWins);
            mPlayers[i].setLosses(tempLosses);
            mPlayers[i].setPushes(tempPushes);
        }

        in.close();
    }
}

void Record::retrieveRecord(){
    cout << "\tSCORES" << endl;
    for(int i = 0; i < numPlayers; i++){
        cout << mPlayers[i].getName() << "\t";
        cout << mPlayers[i].getWins() << "\t";
        cout << mPlayers[i].getLosses() << "\t";
        cout << mPlayers[i].getPushes() << "\t";
        cout << endl;
    }
}
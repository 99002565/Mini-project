#ifndef __NBA_H
#define __NBA_H

#include<string>

class NBA{
    protected :
        std::string WestChampion;
        std::string EastChampion;
        std::string mvpName;
        std::string mvpTeam;
    public:
        NBA();
        NBA(std::string,std::string,std::string,std::string);

        virtual std::string getChampion(int,int)=0;
        virtual bool checkSweep(int,int)=0;

        std::string getWestChampion();
        std::string getEastChampion();
        std::string getmvpName();
        std::string getmvpTeam();

};

#endif

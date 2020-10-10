#include "NBA.h"
#include "NBA_db.h"
#include "result.h"
#include<fstream>

//Construtor
NBA::NBA(): WestChampion(""),EastChampion(""),mvpName(""),mvpTeam(""){}
NBA::NBA(std::string w_Champ,std::string e_Champ,std::string m_Name,std::string m_Team):
 WestChampion(w_Champ),
 EastChampion(e_Champ),
 mvpName(m_Name),
 mvpTeam(m_Team){}


 // Getters
    std::string NBA::getWestChampion(){
        return WestChampion;
    }
    std::string NBA::getEastChampion(){
        return EastChampion;
    }
    std::string NBA::getmvpName(){
        return mvpName;
    }
    std::string NBA::getmvpTeam(){
        return mvpTeam;
    }



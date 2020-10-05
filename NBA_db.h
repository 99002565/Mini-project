#ifndef __NBADB_H_
#define __NBADB_H_
#include "NBA.h"
#include "result.h"

#include <iostream>
#include <list>
#include <iterator>
#include <fstream>

class NBADatabase
{
    std::list<Result> stats;

public:

   void addStats(std::string, std::string, std::string, std::string, int, int, int);
   void removeStats(int);
   Result* findStatsByYear(int);
   int countMvpbyTeams(std::string);
   int countWestChampionshipsForTeam(std::string);
   int countEastChampionshipsForTeam(std::string);
   int countAll();


};

#endif

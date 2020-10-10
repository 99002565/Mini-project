#include "NBA_db.h"
#include "result.h"

#include <fstream>
#include <list>
#include <iterator>

void NBADatabase::addStats(std::string w_Champ,std::string e_Champ,std::string m_Name,std::string m_Team,int y,int w,int e)
{
	stats.push_back(Result(w_Champ,e_Champ,m_Name,m_Team,y,w,e));

}


void NBADatabase::removeStats(int y)
{
	std::list<Result> :: iterator iter;

   	for(iter=stats.begin();iter!=stats.end();++iter)
    	{
        	if(iter->getYear()== y)
        	{
                stats.erase(iter);
                break;
        	}
    	}
}

Result* NBADatabase::findStatsByYear(int y)
{
	std::list<Result> :: iterator iter;

   	for(iter=stats.begin();iter!=stats.end();iter++)
    	{
        	if(iter->getYear()== y)
        	{
           		return &(*iter);
        	}
    	}
    	return NULL;
}

int NBADatabase::countMvpbyTeams(std::string m_Team)
{
	std::list<Result> :: iterator iter;
	int countMVPs=0;

   	for(iter=stats.begin();iter!=stats.end();iter++)
    	{
        	if(iter->getmvpTeam()== m_Team)
        	{
           		++countMVPs;
        	}
    	}
    	return countMVPs;
}

int NBADatabase::countWestChampionshipsForTeam(std::string w_Champ)
{
	std::list<Result> :: iterator iter;
	int countWins=0;

   	for(iter=stats.begin();iter!=stats.end();iter++)
    	{
        	if(iter->getWestChampion()== w_Champ)
        	{
           		++countWins;
        	}
    	}
    	return countWins;
}

int NBADatabase::countEastChampionshipsForTeam(std::string e_Champ)
{
	std::list<Result> :: iterator iter;
	int countWins=0;

   	for(iter=stats.begin();iter!=stats.end();iter++)
    	{
        	if(iter->getEastChampion()== e_Champ)
        	{
           		++countWins;
        	}
    	}
    	return countWins;
}

int NBADatabase::countAll()
{
	int count=0;
    std::list<Result>::iterator iter;
    for(iter=stats.begin();iter!=stats.end();++iter)
    {
        count++;
    }
    return count;
}


#include "result.h"
#include <iostream>

Result::Result():NBA(),Year(0),WestScore(0),EastScore(0){}
Result::Result(std::string w_Champ,std::string e_Champ,std::string m_Name,std::string m_Team,int y,int w,int e):NBA(w_Champ,e_Champ,m_Name,m_Team),Year(y),WestScore(w),EastScore(e){}

std::string Result::getChampion(int w,int e)
{
    if(w>e)
    {
        return WestChampion;
    }
    else
    {
        return EastChampion;
    }
}

bool Result::checkSweep(int w,int e)
{
    if(((w==4)&&(e==0))||((w==0)&&(e==4)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Result::getYear()
{
    return Year;
}
int Result::getWestScore()
{
    return WestScore;
}

int Result::getEastScore()
{
    return EastScore;
}

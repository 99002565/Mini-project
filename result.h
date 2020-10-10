#ifndef __RESULT_H_
#define __RESULT_H_

#include "NBA.h"
#include<string>
#include<iostream>

class Result : public NBA{

	private:
		int Year;
		int WestScore;
		int EastScore;
	public:
		Result();
		Result(std::string,std::string,std::string,std::string,int,int,int);
		std::string getChampion(int,int);
        bool checkSweep(int,int);
		int getYear();
		int getWestScore();
		int getEastScore();
};
#endif

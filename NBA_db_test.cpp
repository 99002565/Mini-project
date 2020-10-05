#include <iostream>
#include <fstream>
#include"NBA.h"
#include"result.h"
#include"NBA_db.h"
#include <gtest/gtest.h>
#include<semaphore.h>
#include<pthread.h>
using namespace std;
pthread_mutex_t m1=PTHREAD_MUTEX_INITIALIZER;
sem_t s1;
NBADatabase Basket;


void* efun1(void* pv){



        pthread_mutex_lock(&m1);
        Basket.addStats("MEC","RET","Labeeb","MEC",2022,3,1);
        Basket.addStats("SRM","VIT","Nipun","SRM",2023,3,0);
        Basket.addStats("BVM","LT","Nishant","SRM",2021,4,0);
        pthread_mutex_unlock(&m1);
        sem_post(&s1);

}


void* efun2(void* pv)
{


        sem_wait(&s1);
        pthread_mutex_lock(&m1);

        pthread_mutex_unlock(&m1);

}
class NBAListDbTest : public ::testing::Test {

protected:
  void SetUp() {
    std::ifstream nba("NBA1.csv");

         if(!nba.is_open()) std::cout << "ERROR: File Open" << '\n';

         std::string WestChampion;
         std::string EastChampion;
         std::string mvpName;
         std::string mvpTeam;
         std::string year;
         std::string WScore;
         std::string EScore;

         while(nba.good()){

            getline(nba,WestChampion,',');
            getline(nba,EastChampion,',');
            getline(nba,mvpName,',');
            getline(nba,mvpTeam,',');
            getline(nba,year,',');
            getline(nba,WScore,',');
            getline(nba,EScore,',');
            int Year=atoi(year.c_str());
            int WestScore=atoi(WScore.c_str());
            int EastScore=atoi(EScore.c_str());

            if(WestChampion!="")
            n1.addStats(WestChampion, EastChampion, mvpName, mvpTeam, Year, WestScore, EastScore);
        }
  }
  void TearDown() {}
  NBADatabase n1;
};

TEST_F(NBAListDbTest, AddStatsSemTest) {

    pthread_t pt1,pt2;
    sem_init(&s1,0,0);
    pthread_create(&pt1,NULL,efun1,NULL);
    pthread_create(&pt2,NULL,efun2,NULL);
    pthread_join(pt1,NULL);
    pthread_join(pt2,NULL);

    Basket.addStats("Man City","Man United","Josep","Man City",2025,4,0);
    EXPECT_EQ(4, Basket.countAll());

    sem_destroy(&s1);
    pthread_mutex_destroy(&m1);
}

TEST_F(NBAListDbTest, AddStats)
{
  n1.addStats("GSW","Cleveland","Steph","GSW",2019,4,0);
  EXPECT_NE((Result*)NULL, n1.findStatsByYear(2019));
  EXPECT_EQ(61,n1.countAll());
}

TEST_F(NBAListDbTest, RemoveStats)
{
  n1.removeStats(2010);
  EXPECT_EQ(NULL, n1.findStatsByYear(2010));
  EXPECT_EQ(60, n1.countAll());
}

TEST_F(NBAListDbTest, CountMvpbyTeams)
{
  EXPECT_EQ(5, n1.countMvpbyTeams("Boston Celtics"));
}

TEST_F(NBAListDbTest, CountWestChampionshipsForTeam)
{
  EXPECT_EQ(0, n1.countWestChampionshipsForTeam("Utah Jazz"));
}

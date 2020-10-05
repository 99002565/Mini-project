#include <iostream>
#include"NBA.h"
#include"result.h"
#include"NBA_db.h"
#include <gtest/gtest.h>

TEST(Result,DefaultConstructor) {
    Result r1;
    EXPECT_EQ(0,r1.getYear());
    EXPECT_EQ(0,r1.getWestScore());
    EXPECT_EQ(0,r1.getEastScore());

}

TEST(Result,ParameterizedConstructor) {
    Result r2("GSW","Cleveland","Steph","GSW",2019,4,0);
    EXPECT_EQ(2019,r2.getYear());
    EXPECT_EQ(4,r2.getWestScore());
    EXPECT_EQ(0,r2.getEastScore());
}

TEST(Result,GetChampion) {
    Result r4("GSW","Cleveland","Steph","GSW",2019,4,0);
    EXPECT_EQ("GSW",r4.getChampion(4,0));
}

TEST(Result,CheckSweep) {
    Result r3("GSW","Cleveland","Steph","GSW",2019,4,0);
    EXPECT_EQ(true,r3.checkSweep(4,0));
}


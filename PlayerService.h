#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Date
{
	int day;
	int month;
	int year;
}Date;
typedef struct Player
{
	char pName[20];
	Date dob;
	char country[20];
	int matchPlayed,odiMatch,TestMatch,t_20iMatch,jNo;
	int runs,odiRuns,testRuns,t_20iRuns;
	int hun,fif,testHun,testFif,odiHun,odiFif,t_20iHun,t_20ifif;
	int wickets,odiWik,TestWik,T_20iWik;
	int six,fours;
	int testBall,odiBall,t_20iBall,ballFaced;
	
}Player;
void getPlayerDetails(Player*,int);
void dispPlayerDetails(Player*,int);
void insertPlayer(Player*,int*);
void maxRun(Player*,int);
void maxWickets(Player*,int);
void minRun(Player*,int);
void minWik(Player*,int);
void dispRecordCard(Player*,int);
void searchByName(Player*,int);
void deleteData(Player*,int*);
void iccBatsRankings(Player*,int);
void testBatsRankings(Player*,int);
void ODIBatsRankings(Player*,int);
void t_20iBatsRankings(Player*,int);
void iccBallRankings(Player*,int);
void OdiBallRankings(Player*,int);
void TestBallRankings(Player*,int);
void T_20IBallRankings(Player*,int);
void ODITableformat(Player* ,int );
void testTableformat(Player*,int);
void T_20Tableformat(Player*,int);
void calcStrikeAvg();
void calEconomyRate();


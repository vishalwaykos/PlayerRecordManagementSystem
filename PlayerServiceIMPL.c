#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
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
void getPlayerDetails(Player* p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		printf("\nEnter details of Player No : %d",i+1);
		printf("\nEnter Player Name : ");
		gets(p[i].pName);// gets liya cause ye spaces allow krta he char me scanf nhi krta
		//if we use scanf the it will take (enter spaceas) as a char thats why will get logical error
		printf("Enter Date of Birth (dd/mm/yyyy): ");
		scanf("%d%d%d",&p[i].dob.day,&p[i].dob.month,&p[i].dob.year);
		fflush(stdin);
		printf("Enter Country : ");
		gets(p[i].country);
		printf("Enter the Jearsy Number: ");
		scanf("%d",&p[i].jNo);
		
//		Test Matches details
		printf("\nEnter The TestMatches Details\n");
		printf("Enter the Test Matches Played : ");
		scanf("%d",&p[i].TestMatch);
		printf("Enter the Total Test Runs : ");
		scanf("%d",&p[i].testRuns);
		printf("Ball played in Test: ");
		scanf("%d",&p[i].testBall);
		printf("Enter the Total TEST Wickets : ");
		scanf("%d",&p[i].TestWik);
		printf("Enter Hundred\tEnter Fifty");
		scanf("%d%d",&p[i].testHun,&p[i].testFif);
		
//		ODI Matches Details
		printf("\nEnter The ODI Matches Details\n");
		printf("Enter the ODI Matches Played : ");
		scanf("%d",&p[i].odiMatch);
		printf("Enter the Total ODI Runs : ");
		scanf("%d",&p[i].odiRuns);
		printf("Ball played in ODI: ");
		scanf("%d",&p[i].odiBall);
		printf("Enter the Total ODI Wickets : ");
		scanf("%d",&p[i].odiWik);
		printf("Enter Hundred\tEnter Fifty");
		scanf("%d%d",&p[i].odiHun,&p[i].odiFif);
		
//		T-20I Matches
		printf("\nEnter The T-20I Matches Details\n");
		printf("Enter the T-20I Matches Played : ");
		scanf("%d",&p[i].t_20iMatch);
		printf("Enter the Total T-20 Runs : ");
		scanf("%d",&p[i].t_20iRuns);
		printf("Ball played in T-20: ");
		scanf("%d",&p[i].t_20iBall);
		printf("Enter the Total T-20I Wickets : ");
		scanf("%d",&p[i].T_20iWik);
		printf("Enter Hundred\tEnter Fifty");
		scanf("%d %d",&p[i].t_20iHun,&p[i].t_20ifif);
		
		fflush(stdin);
	}
}
void dispPlayerDetails(Player* p,int n)
{
	int cyear=2022;//Age calculate ke liye Current Year
	int i;

	for(i=0;i<n;i++)
	{
	//	p[i].runs = p[i].odiRuns+p[i].testRuns+p[i].t_20rRuns;	
		printf("\n________________________________________");
		printf("\n******Player Details******\n");
		printf("\nPlayer Name                   : %s",p[i].pName);
		printf("\nDate of Birth(dd/mm/yyyy)     : %d/%d/%d",p[i].dob.day,p[i].dob.month,p[i].dob.year);
		printf("\nAge                           : %d",cyear-p[i].dob.year);
		printf("\nCountry Name                  : %s",p[i].country);
		printf("\nJearsy Number                 : %d",p[i].jNo);
//		printf("\nTEST Matches Played           : %d",p[i].TestMatch);
//		printf("\nTest Runs                     : %d",p[i].testRuns);
//		printf("\nTEST Wickets                  : %d",p[i].TestWik);
//		printf("\nODI Matches Played            : %d",p[i].odiMatch);
//		printf("\nODI Runs                      : %d",p[i].odiRuns);
//		printf("\nODI Wickets                   : %d",p[i].TestWik);
//		printf("\nT-20I Matches Played          : %d",p[i].t_20iMatch);
//		printf("\nT-20 Runs                     : %d",p[i].t_20rRuns);
//		printf("\nT-20I Wickets                 : %d",p[i].T_20iWik);	


		p[i].runs = p[i].testRuns+p[i].odiRuns+p[i].t_20iRuns;
		
		p[i].matchPlayed = p[i].TestMatch+p[i].odiMatch+p[i].t_20iMatch;
		
		p[i].wickets = p[i].TestWik+p[i].odiWik+p[i].T_20iWik;
		
		p[i].hun = p[i].odiHun+p[i].testHun+p[i].t_20iHun;
		
		p[i].fif = p[i].odiFif+p[i].testFif+p[i].t_20ifif;
		
		p[i].ballFaced = p[i].odiBall+p[i].testBall+p[i].t_20iBall;
		
		
		printf("\nMatches Played(TEST/ODI/T20I) : %d",p[i].matchPlayed);
		printf("\nTotal InterNatinal Runs       : %d",p[i].runs);
		printf("\nTotal International wickets   : %d",p[i].wickets);
		printf("\nInternational Hundred/100     : %d",p[i].hun);
		printf("\nInternational Fifties/50      : %d",p[i].fif);
//		printf("\nToal Sixes                    : %d",p[i].six);
//		printf("\nTotal Fours                   : %d",p[i].fours);
		//Avg runs Calculation per Matchrun/match
		printf("\nCareerAverage                 : %.2f",(float)p[i].runs/p[i].matchPlayed);
		printf("\nCareer Strike Rate            : %.1f",(float)p[i].runs/p[i].ballFaced*(100));
		
		printf("\n----------------------------------------------------------------");
	}
}

void insertPlayer(Player* p, int *n1){
	int nSize,i,oSize,ino;
//	Player * p1;
	oSize = *n1;
	printf("\nEnter how many Player want to Add");
	scanf("%d",&nSize);
	*n1 = *n1 + nSize;
	p = (Player*)realloc(p ,*n1*sizeof(Player));
	for(i=oSize;i<*n1;i++)
	{
		fflush(stdin);
		printf("\nEnter details of Player No : %d",i+1);
		printf("\nEnter Player Name : ");
		gets(p[i].pName);// gets liya cause ye spaces allow krta he char me scanf nhi krta
		//if we use scanf the it will take (enter spaceas) as a char thats why will get logical error
		printf("Enter Date of Birth (dd/mm/yyyy): ");
		scanf("%d%d%d",&p[i].dob.day,&p[i].dob.month,&p[i].dob.year);
		fflush(stdin);
		printf("Enter Country : ");
		gets(p[i].country);
		printf("\nEnter the Jearsy Number");
		scanf("%d",&p[i].jNo);
		
//		Test Matches 
		printf("\nEnter The TestMatches Details\n");
		printf("Enter the Test Matches Played : ");
		scanf("%d",&p[i].TestMatch);
		printf("Enter the Total Test Runs : ");
		scanf("%d",&p[i].testRuns);
		printf("Ball played in Test: ");
		scanf("%d",&p[i].testBall);
		printf("Enter the Total TEST Wickets : ");
		scanf("%d",&p[i].TestWik);
		printf("Enter Hundred\tEnter Fifty");
		scanf("%d%d",&p[i].testHun,&p[i].testFif);
		
//		ODI Matches
		printf("\nEnter The ODI Matches Details\n");
		printf("Enter the ODI Matches Played : ");
		scanf("%d",&p[i].odiMatch);
		printf("Enter the Total ODI Runs : ");
		scanf("%d",&p[i].odiRuns);
		printf("Ball played in ODI: ");
		scanf("%d",&p[i].odiBall);
		printf("Enter the Total ODI Wickets : ");
		scanf("%d",&p[i].odiWik);
		printf("Enter Hundred\tEnter Fifty");
		scanf("%d%d",&p[i].odiHun,&p[i].odiFif);
		
//		T-20I Matches
		printf("\nEnter The T-20I Matches Details\n");
		printf("Enter the T-20I Matches Played : ");
		scanf("%d",&p[i].t_20iMatch);
		printf("Enter the Total T-20 Runs : ");
		scanf("%d",&p[i].t_20iRuns);
		printf("Ball played in T-20: ");
		scanf("%d",&p[i].t_20iBall);
		printf("Enter the Total T-20I Wickets : ");
		scanf("%d",&p[i].T_20iWik);
		printf("Enter Hundred\tEnter Fifty");
		scanf("%d %d",&p[i].t_20iHun,&p[i].t_20ifif);

	}
	printf("\nRecord Added Successfully");

}
void deleteData(Player* p, int* n)
{
	char pnme[15];

	int k=0,i,j,del;
	do{
		printf("\nEnter a Player name which record you want to delete : ");
		scanf("%s",&pnme);
		for(i=0;i<*n;i++)
			if(strcmp(p[i].pName, pnme)==0){
				k++;
				printf("%s record Successfully deleted",pnme);
				for(j=i;j<(*n-k);j++)
					*(p+j)=p[j+1];
			}
			if(k==0){
				printf("\n%s record not found",pnme);
				printf("\n(If you want to delete Player record then it should be available in the Record Book)");
			}
		printf("\n Coninue in Delete\n(Press 1 -> yes/Press 2 -> No)");
		scanf("%d",&del);
	}while(del != 2);
	*n=*n-k;
//	free(p);
}
void dispRecordCard(Player* p, int n)
{
	int i;
	int max=0;
	int maxWik=0;
	int pos = 0;
	for(i=0;i<n;i++)
	{
		if(p[i].runs>max){
			max=p[i].runs;
			pos=i;
		}	
		if(p[i].wickets>maxWik){
			maxWik = p[i].wickets;
			pos = i;
		}
	}
	printf("\n********Players Records********");
	printf("\n--------------------------------------------------------------");
	printf("\nMaximum runs : %d  \nName of player : %s \nCountry : %s",max,p[pos].pName,p[pos].country);
	printf("\n--------------------------------------------------------------");
	printf("\nMaximum wickets : %d  \nName of player : %s\nCountry : %s",maxWik,p[pos].pName,p[pos].country);
	printf("\n-----------------------------------------------------------------");	
}
void searchByName(Player* p ,int n)
{
	int i=0,w=0;
	char s1[10];
	int cyr=2022;
	int flag=0;
	do{
		fflush(stdin);
		printf("\nEnter the name search : ");
		gets(s1);
		for(i=0;i<n;i++)
		{
			if(strcmp(p[i].pName,s1)==0)
			{
				flag=1;
				printf("\n==============================================================");
				printf("\nName : %s",s1);
				printf("\n******Player Details******\n");
				printf("\nPlayer Name                  : %s",p[i].pName);
				printf("\nDate of Birth(dd/mm/yyyy)    : %d/%d/%d",p[i].dob.day,p[i].dob.month,p[i].dob.year);
				printf("\nAge                          : %d",cyr-p[i].dob.year);
				printf("\nCountry Name                 : %s",p[i].country);
				printf("\nMatches Played               : %d",p[i].matchPlayed);
				printf("\nTotal InterNatinal Runs      : %d",p[i].runs);
				printf("\nTotal International wickets  : %d",p[i].wickets);
	//			printf("\nToal Sixes                   : %d",p[i].six);
	//			printf("\nTotal Fours                  : %d",p[i].fours);
				//Avg runs Calculation per Matchrun/match
				printf("\nCareerAverage                 : %.2f",(float)p[i].runs/p[i].matchPlayed);
				printf("\nCareer Strike Rate            : %.1f",(float)p[i].runs/p[i].ballFaced*(100));
				printf("\n____________________________________________________________________");
			}
		}
		if(flag==0){
			printf("sorry! %s is not in the record ",s1);
		}
		printf("\nwant to continue in search\n(Press 1 -> yes/Press 2 -> No)");
		scanf("%d",&w);
		if(w<=0 || w>2){
			printf("\nWrong Input");
		}
	}while(w != 2);
}
void maxRun(Player* p,int n)
{
	int i;
	int run=p[0].runs;
	int ps=0;
	for(i=0;i<n;i++)
	{
		if(p[i].runs>run)
		{
			run=p[i].runs;
			ps=i;
		}
	}
	printf("\n-------------------------------------------------\n");
	printf("\n_____________Maximum Runs Details_________________");
	printf("\nMaximum runs : %d \nName of player : %s \nCountry : %s",run,p[ps].pName,p[ps].country);
		printf("\n\n______________________________________________________\n");
    
}
void minRun(Player* p,int n)
{
	int i;
	int run=p[0].runs;
	int ps=0;
	for(i=0;i<n;i++)
	{
		if(p[i].runs<run)
		{
			run=p[i].runs;
			ps=i;
		}
	}
	printf("\n-------------------------------------------------\n");
	printf("\n_____________Minimum Runs Details_________________");
	printf("\nMinimum runs : %d \nName of player : %s \nCountry : %s",run,p[ps].pName,p[ps].country);
	printf("\n\n______________________________________________________\n");
    
}
void maxWickets(Player* p, int n)
{
	int i;
	int wik=0;
	int ps=0;
	for(i=0;i<n;i++)
	{
		if(p[i].wickets>wik){
			wik=p[i].wickets;
			ps=i;
		}
	}
	printf("\n-------------------------------------------------\n");;
	printf("\n_____________Maximum Wikets Details_________________");
	printf("\nMaximum Wickets : %d  \nName of player : %s \nCountry : %s",wik,p[ps].pName,p[ps].country);
	printf("\n\n______________________________________________________\n");
}
void minWik(Player* p, int n)
{
	int i;
	int wik1=p[0].wickets;
	int ps1=0;
	for(i=0;i<n;i++)
	{
		if(p[i].wickets<wik1){
			wik1=p[i].wickets;
			ps1=i;
		}
	}
	printf("\n-------------------------------------------------\n");
	printf("\n_____________Minimum Wikets Details_________________");
	printf("\nMinimum Wickets : %d  \nName of player : %s\nCountry : %s",wik1,p[ps1].pName,p[ps1].country);
	printf("\n\n______________________________________________________\n");
}
void iccBatsRankings(Player* p,int n)
{
	int i,j,l;
	Player s;
	 for(i=0;i<n;i++)
     {
          for(j=i+1;j<n;j++)
          {
               if(p[i].runs<p[j].runs)
               {
                    s=p[i];
                    p[i]=p[j];
                    p[j]=s;
               }
          }
    }
    printf("\n-------------------------------------------\n");
    printf("ICC All Rankings(BATSMAN based on runs)\n");
  	printf("\n________________________________________________________________\n");

    printf("\nName\t\t:Ranks\t\t: Runs");
    for(i=0;i<n;i++)
    {
    	printf("\n%s\t\t%d\t\t%d",p[i].pName,i+1,p[i].runs);
	}
	printf("\n---------------------------------------------------------------\n");
}
void testBatsRankings(Player* p,int n)
{
	int i,j,l;
	Player s;
	 for(i=0;i<n;i++)
     {
          for(j=i+1;j<n;j++)
          {
               if(p[i].testRuns<p[j].testRuns)
               {
                    s=p[i];
                    p[i]=p[j];
                    p[j]=s;
               }
          }
    }
    printf("\t\t\n-------------------------------------------\n");
    printf("\tICC TEST Rankings(based on runs)");
  	printf("\n________________________________________________________________\n");
    printf("\n\t\tName\t\t:Ranks\t\t: Runs");
    for(i=0;i<n;i++)
    {
    	printf("\n\t\t%s\t\t%d\t\t%d",p[i].pName,i+1,p[i].runs);
	}
	printf("\n-------------------------------------------------\n");
}
void ODIBatsRankings(Player* p,int n)
{
	int i,j,l;
	Player s;
	 for(i=0;i<n;i++)
     {
          for(j=i+1;j<n;j++)
          {
               if(p[i].odiRuns<p[j].odiRuns)
               {
                    s=p[i];
                    p[i]=p[j];
                    p[j]=s;
               }
          }
    }
    printf("\t\t\n-------------------------------------------\n");
    printf("\tICC ODI Rankings(based on runs)");
  	printf("\n________________________________________________________________\n");
    printf("\n\t\tName\t\t:Ranks\t\t: Runs");
    for(i=0;i<n;i++)
    {
    	printf("\n\t\t%s\t\t%d\t\t%d",p[i].pName,i+1,p[i].odiRuns);
	}
	printf("\n-------------------------------------------------\n");
}
void t_20iBatsRankings(Player* p,int n)
{
	int i,j,l;
	Player s;
	 for(i=0;i<n;i++)
     {
          for(j=i+1;j<n;j++)
          {
               if(p[i].t_20iRuns<p[j].t_20iRuns)
               {
                    s=p[i];
                    p[i]=p[j];
                    p[j]=s;
               }
          }
    }
    printf("\t\t\n-------------------------------------------\n");
    printf("\tICC T-20I Rankings(based on runs)");
	printf("\n________________________________________________________________\n");

    printf("\n\t\tName\t\t:Ranks\t\t: Runs");
    for(i=0;i<n;i++)
    {
    	printf("\n\t\t%s\t\t%d\t\t%d",p[i].pName,i+1,p[i].t_20iRuns);
	}
	printf("\n-------------------------------------------------\n");
}
void iccBallRankings(Player* p,int n)
{
	int i,j;
//	int w;//Incompatiable type assign player to int
//	we need to take player
	Player w;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].wickets<p[j].wickets)
			{
				w = p[i];
				p[i]=p[j];
				p[j]=w;
			}
		}
	}
    printf("\n-----------------------------------------------------\n");	
	printf("\tICC Rankings(Baller based on wickets)");
    printf("\n_____________________________________________________\n");
    printf("\n\t\tName\t\t:Ranks\t\t: Wickets");
    for(i=0;i<n;i++)
    {
    	printf("\n\t\t%s\t\t%d\t\t%d",p[i].pName,i+1,p[i].wickets);
	}
	printf("\n-------------------------------------------------\n");	
}
void T_20IBallRankings(Player* p,int n)
{
	int i,j;
//	int w;//Incompatiable type assign player to int
//	we need to take player
	Player w;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].T_20iWik<p[j].T_20iWik)
			{
				w = p[i];
				p[i]=p[j];
				p[j]=w;
			}
		}
	}
    printf("\n-----------------------------------------------------\n");	
	printf("ICC Rankings(Baller based on wickets)\n");
    printf("\n_____________________________________________________\n");
    printf("\nName\t\t:Ranks\t\t: Wickets");
    for(i=0;i<n;i++)
    {
    	printf("\n%s\t\t%d\t\t%d",p[i].pName,i+1,p[i].T_20iWik);
	}
	printf("\n-------------------------------------------------\n");	
}
void OdiBallRankings(Player* p,int n)
{
	int i,j;
//	int w;//Incompatiable type assign player to int
//	we need to take player
	Player w;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].odiWik<p[j].odiWik)
			{
				w = p[i];
				p[i]=p[j];
				p[j]=w;
			}
		}
	}
    printf("\n-----------------------------------------------------\n");	
	printf("ICC Rankings(Baller based on wickets)\n");
    printf("\n_____________________________________________________\n");
    printf("\nName\t\t:Ranks\t\t: Wickets");
    for(i=0;i<n;i++)
    {
    	printf("\n%s\t\t%d\t\t%d",p[i].pName,i+1,p[i].odiWik);
	}
	printf("\n-------------------------------------------------\n");	
}
void TestBallRankings(Player* p,int n)
{
	int i,j;
//	int w;//Incompatiable type assign player to int
//	we need to take player
	Player w;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].TestWik<p[j].TestWik)
			{
				w = p[i];
				p[i]=p[j];
				p[j]=w;
			}
		}
	}
    printf("\n-----------------------------------------------------\n");	
	printf("ICC Rankings(Baller based on wickets)\n");
    printf("\n_____________________________________________________\n");
    printf("\nName\t\t:Ranks\t\t: Wickets");
    for(i=0;i<n;i++)
    {
    	printf("\n%s\t\t%d\t\t%d",p[i].pName,i+1,p[i].TestWik);
	}
	printf("\n-------------------------------------------------\n");
	
}
void testTableformat(Player* p,int n)
{
	int i;
	printf("\nName\t\t Country\tMatch\t\tRuns\t\thundreds\tfifties\t\tWikets\t\tAvg\n");
	printf("\n_________________________________________________________________________________________________________________________________________________________");
	for(i=0;i<n;i++)
	{
		printf("\n%s\t\t %s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.2f",p[i].pName,p[i].country,p[i].TestMatch,p[i].testRuns,p[i].testHun,p[i].testFif,p[i].TestWik,(float)p[i].testRuns/p[i].TestMatch);
	}
	printf("\n_________________________________________________________________________________________________________________________________________________________");
}
void ODITableformat(Player* p,int n)
{
	int i;
	printf("\nName\t\t Country\tMatch\t\tRuns\t\thundreds\tfifties\t\tWikets\t\tAvg\n");
	printf("\n_________________________________________________________________________________________________________________________________________________________");
	for(i=0;i<n;i++)
	{
		printf("\n%s\t\t %s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.2f",p[i].pName,p[i].country,p[i].odiMatch,p[i].odiRuns,p[i].odiHun,p[i].odiFif,p[i].odiWik,(float)p[i].odiRuns/p[i].odiMatch);
	}
	printf("\n_________________________________________________________________________________________________________________________________________________________");
}
void T_20Tableformat(Player* p,int n)
{
	int i;
	printf("\nName\t\t Country\tMatch\t\tRuns\t\thundreds\tfifties\t\tWikets\t\tAvg\n");
	printf("\n__________________________________________________________________________________________________________________________________________________________");
	for(i=0;i<n;i++)
	{
		printf("\n%s\t\t %s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.2f",p[i].pName,p[i].country,p[i].t_20iMatch,p[i].t_20iRuns,p[i].t_20iHun,p[i].t_20ifif,p[i].T_20iWik,(float)p[i].t_20iRuns/p[i].t_20iMatch);
	}
	printf("\n_________________________________________________________________________________________________________________________________________________________");
}
void calcStrikeAvg()
{
	float sRate,avg;
	char name[100],tName2[30];
	int match,run,ball;
	fflush(stdin);
		printf("\nEnter Player Name :");
		gets(name);
		printf("Enter the Country Name : ");
		gets(tName2);
		printf("Enter total matches played in this format :");
		scanf("%d",&match);
		printf("Enter total Runs in  this format: ");
		scanf("%d",&run);
		printf("Enter Ball Played in this format : ");
		scanf("%d",&ball);
		sRate = (float)run/ball*100;//Type casting  using float
		avg= (float)(run/match);
	printf("\n________________StrikeRate/Avg ________________________");
	printf("\nName\t\t  Country\t  Match\t\t  Strke Rate\t  Average");
	printf("\n_________________________________________________________________________________");
	printf("\n%s\t\t  %s\t\t  %d\t\t  %.2f\t\t  %.2f",name,tName2,match,sRate,avg);
	printf("\n---------------------------------------------------------------------------------");
}
void calEconomyRate(char* p){
	int run,ovr,wik;
	char name[20],tName[20];
	printf("\nEnter the Player Name : ");
	gets(name);
	printf("Enter the Country Name : ");
	gets(tName);
	printf("run conceded in International Career :");
	scanf("%d",&run);
	printf("Over Bowlled in International Career: ");
	scanf("%d",&ovr);
	printf("Wikets Taken in International Career:");
	scanf("%d",&wik);
	float eco =(float) run/ovr;
//economy Based on runs conceded by a bowler by the number of overs bowled.
	float av = (float) run/wik;
// bowling average is calculated by dividing the 	
//numbers of runs they have conceded by the number of wickets they have taken.

	printf("\n %s format Table",p);
	printf("\n________________EconomyRateRate/Avg ________________________");
	printf("\nName\t\t Country\tOverBoweld\tRun Conceded\tEconomy\tBalling Average");
	printf("\n__________________________________________________________________________");
	printf("\n%s\t\t  %s\t\t%d\t\t%d\t\t%.2f\t\t%.2f",name,tName,ovr,run,eco,av);
}
void storedRecordInBook(Player* p, int n)
{
	int i,count=0;
	for(i=0;i<n;i++)
	{
		count++;
	}
	printf("\nTotal Number Of Player Record in Book is : %d",count);
}



/*
void getPlayerDetails(Player* p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		printf("\nEnter details of Player No : %d",i+1);
		printf("\nEnter Player Name : ");
		gets(p[i].pName);// gets liya cause ye spaces allow krta he char me scanf nhi krta
		//if we use scanf the it will take (enter spaceas) as a char thats why will get logical error
		printf("Enter Date of Birth (dd/mm/yyyy): ");
		scanf("%d%d%d",&p[i].dob.day,&p[i].dob.month,&p[i].dob.year);
		fflush(stdin);
		printf("Enter Country : ");
		gets(p[i].country);
		printf("\nEnter the Jearsy Number");
		scanf("%d",&p[i].jNo);
		
//		Test Matches 
		printf("\nEnter The TestMatches Details\n");
		printf("Enter the Test Matches Played : ");
		scanf("%d",&p[i].TestMatch);
		printf("Enter the Total Test Runs : ");
		scanf("%d",&p[i].testRuns);
//		printf("Ball played in Test: ");
//		scanf("%d",&p[i].testBall);
		printf("Enter the Total TEST Wickets : ");
		scanf("%d",&p[i].TestWik);
//		printf("Enter Hundred\tEnter Fifty");
//		scanf("%d%d",&p[i].testHun,&p[i].testFif);
//		ODI Matches
		printf("\nEnter The ODI Matches Details\n");
		printf("Enter the ODI Matches Played : ");
		scanf("%d",&p[i].odiMatch);
		printf("Enter the Total ODI Runs : ");
		scanf("%d",&p[i].odiRuns);
//		printf("Ball played in ODI: ");
//		scanf("%d",&p[i].odiBall);
		printf("Enter the Total ODI Wickets : ");
		scanf("%d",&p[i].odiWik);
//		printf("Enter Hundred\tEnter Fifty");
//		scanf("%d%d",&p[i].odiHun,&p[i].odiFif);
//		T-20I Matches
		printf("Enter The T-20I Matches Details\n");
		printf("Enter the T-20I Matches Played : ");
		scanf("%d",&p[i].t_20iMatch);
		printf("Enter the Total T-20 Runs : ");
		scanf("%d",&p[i].t_20iRuns);
//		printf("Ball played in T-20: ");
//		scanf("%d",&p[i].t_20iBall);
		printf("Enter the Total T-20I Wickets : ");
		scanf("%d",&p[i].T_20iWik);
//		printf("Enter Hundred\tEnter Fifty");
//		scanf("%d %d",&p[i].t_20iHun,&p[i].t_20ifif);
//		printf("Enter the Total International Runs : ");
//		scanf("%d",&p[i].runs);
		fflush(stdin);
	}
}
void dispPlayerDetails(Player* p,int n)
{
	int cyear=2022;//Age calculate ke liye Current Year
	int i;

	for(i=0;i<n;i++)
	{
	//	p[i].runs = p[i].odiRuns+p[i].testRuns+p[i].t_20rRuns;	
		printf("\n________________________________________");
		printf("\n******Player Details******\n");
		printf("\nPlayer Name                  : %s",p[i].pName);
		printf("\nDate of Birth(dd/mm/yyyy)    : %d/%d/%d",p[i].dob.day,p[i].dob.month,p[i].dob.year);
		printf("\nAge                          : %d",cyear-p[i].dob.year);
		printf("\nCountry Name                 : %s",p[i].country);
		printf("\nJearsy Number                : %d",p[i].jNo);
		printf("\nTEST Matches Played          : %d",p[i].TestMatch);
//		printf("\nTest Runs                    : %d",p[i].testRuns);
//		printf("\nTEST Wickets                  : %d",p[i].TestWik);
//		printf("\nODI Matches Played           : %d",p[i].odiMatch);
//		printf("\nODI Runs                     : %d",p[i].odiRuns);
//		printf("\nODI Wickets                   : %d",p[i].TestWik);
//		printf("\nT-20I Matches Played         : %d",p[i].t_20iMatch);
//		printf("\nT-20 Runs                    : %d",p[i].t_20rRuns);
//		printf("\nT-20I Wickets                 : %d",p[i].T_20iWik);	


		p[i].runs = p[i].testRuns+p[i].odiRuns+p[i].t_20iRuns;
		
		p[i].matchPlayed = p[i].TestMatch+p[i].odiMatch+p[i].t_20iMatch;
		
		p[i].wickets = p[i].TestWik+p[i].odiWik+p[i].T_20iWik;
		
		p[i].hun = p[i].odiHun+p[i].testHun+p[i].t_20iHun;
		
		p[i].fif = p[i].odiFif+p[i].testFif+p[i].t_20ifif;
		
		p[i].ballFaced = p[i].odiBall+p[i].testBall+p[i].t_20iBall;
		
		
		printf("\nMatches Played               : %d",p[i].matchPlayed);
		printf("\nTotal InterNatinal Runs      : %d",p[i].runs);
		printf("\nTotal International wickets  : %d",p[i].wickets);
		printf("\nInternational Hundred/100    : %d",p[i].hun);
		printf("\nInternational Fifties/50     : %d",p[i].fif);
//		printf("\nToal Sixes                   : %d",p[i].six);
//		printf("\nTotal Fours                  : %d",p[i].fours);
		//Avg runs Calculation per Matchrun/match
//		printf("\nCareerAverage                : %.2f",(float)p[i].runs/p[i].matchPlayed);
//		printf("\nCareer Strike Rate           : %.1f",(float)p[i].runs/p[i].ballFaced*(100));
		
		printf("\n----------------------------------------------------------------");
	}
}
void deleteData(Player* p, int* n)
{
	char pnme[15];

	int k=0,i,j;
	char del[5];
	printf("\nEnter a Player name which record you want to delete : ");
	scanf("%s",&pnme);
	for(i=0;i<*n;i++)
		if(strcmp(p[i].pName, pnme)==0){
			k++;
			printf("%s record Successfully deleted",pnme);
			for(j=i;j<(*n-k);j++)
				*(p+j)=p[j+1];
		}
		if(k==0){
			printf("\n%s record not found",pnme);
			printf("\n(If you want to delete Player record then it should be available in the Record Book)");
		}
	
	//		scanf("%c",&del);
	*n=*n-k;
//	free(p);
}
void insertPlayer(Player* p, int *n1){
	int nSize,i,oSize;
//	Player * p1;
	oSize = *n1;
	printf("\nEnter how many Player want to Add");
	scanf("%d",&nSize);
	*n1 = *n1 + nSize;
	p = (Player*)realloc(p ,*n1*sizeof(Player));
	for(i=oSize;i<*n1;i++)
	{
			fflush(stdin);
		printf("\nEnter details of Player No : %d",i+1);
		printf("\nEnter Player Name : ");
		gets(p[i].pName);// gets liya cause ye spaces allow krta he char me scanf nhi krta
		//if we use scanf the it will take (enter spaceas) as a char thats why will get logical error
		printf("Enter Date of Birth (dd/mm/yyyy): ");
		scanf("%d%d%d",&p[i].dob.day,&p[i].dob.month,&p[i].dob.year);
		fflush(stdin);
		printf("Enter Country : ");
		gets(p[i].country);
		printf("\nEnter the Jearsy Number");
		scanf("%d",&p[i].jNo);
		
//		Test Matches 
		printf("\nEnter The TestMatches Details\n");
		printf("Enter the Test Matches Played : ");
		scanf("%d",&p[i].TestMatch);
		printf("Enter the Total Test Runs : ");
		scanf("%d",&p[i].testRuns);
//		printf("Ball played in Test: ");
//		scanf("%d",&p[i].testBall);
		printf("Enter the Total TEST Wickets : ");
		scanf("%d",&p[i].TestWik);
//		printf("Enter Hundred\tEnter Fifty");
//		scanf("%d%d",&p[i].testHun,&p[i].testFif);
//		ODI Matches
		printf("\nEnter The ODI Matches Details\n");
		printf("Enter the ODI Matches Played : ");
		scanf("%d",&p[i].odiMatch);
		printf("Enter the Total ODI Runs : ");
		scanf("%d",&p[i].odiRuns);
//		printf("Ball played in ODI: ");
//		scanf("%d",&p[i].odiBall);
		printf("Enter the Total ODI Wickets : ");
		scanf("%d",&p[i].odiWik);
//		printf("Enter Hundred\tEnter Fifty");
//		scanf("%d%d",&p[i].odiHun,&p[i].odiFif);
//		T-20I Matches
		printf("Enter The T-20I Matches Details\n");
		printf("Enter the T-20I Matches Played : ");
		scanf("%d",&p[i].t_20iMatch);
		printf("Enter the Total T-20 Runs : ");
		scanf("%d",&p[i].t_20iRuns);
//		printf("Ball played in T-20: ");
//		scanf("%d",&p[i].t_20iBall);
		printf("Enter the Total T-20I Wickets : ");
		scanf("%d",&p[i].T_20iWik);
//		printf("Enter Hundred\tEnter Fifty");
//		scanf("%d %d",&p[i].t_20iHun,&p[i].t_20ifif);
//		printf("Enter the Total International Runs : ");
//		scanf("%d",&p[i].runs);
	}

	
}
void dispRecordCard(Player* p, int n)
{
	int i;
	int max=0;
	int maxWik=0;
	int pos = 0;
	for(i=0;i<n;i++)
	{
		if(p[i].runs>max){
			max=p[i].runs;
			pos=i;
		}	
		if(p[i].wickets>maxWik){
			maxWik = p[i].wickets;
			pos = i;
		}
	}
	printf("\n********Players Records********");
	printf("\n_____");
	printf("\nMaximum runs : %d & \nName of player : %s",max,p[pos].pName);
	printf("\n_____");
	printf("\nMaximum wickets : %d & \nName of player : %s",maxWik,p[pos].pName);	
}
void searchByName(Player* p ,int n)
{
	int i=0;
	char s1[10];
	int cyr=2022;
	int flag=0;
	printf("\nEnter the name search : ");
	gets(s1);
	for(i=0;i<n;i++)
	{
		if(strcmp(p[i].pName,s1)==0)
		{
			flag=1;
			printf("\nName : %s",s1);
			printf("\n******Player Details******\n");
			printf("\nPlayer Name                  : %s",p[i].pName);
			printf("\nDate of Birth(dd/mm/yyyy)    : %d/%d/%d",p[i].dob.day,p[i].dob.month,p[i].dob.year);
			printf("\nAge                          : %d",cyr-p[i].dob.year);
			printf("\nCountry Name                 : %s",p[i].country);
			printf("\nMatches Played               : %d",p[i].matchPlayed);
			printf("\nTotal InterNatinal Runs      : %d",p[i].runs);
			printf("\nTotal International wickets  : %d",p[i].wickets);
//			printf("\nToal Sixes                   : %d",p[i].six);
//			printf("\nTotal Fours                  : %d",p[i].fours);
			//Avg runs Calculation per Matchrun/match
			printf("\nAverage per match            : %d",p[i].runs/p[i].matchPlayed);
			printf("\nCarrer Strike Rate           : %.1f",p[i].runs/p[i].ballFaced*(100));
		}
	}
	if(flag==0){
		printf("sorry! %s is not in the record ",s1);
	}
}
void maxRun(Player* p,int n)
{
	int i;
	int run=p[0].runs;
	int ps=0;
	for(i=0;i<n;i++)
	{
		if(p[i].runs>run)
		{
			run=p[i].runs;
			ps=i;
		}
	}
	printf("\n______________________________________________________\n");
	printf("\n_____________Maximum Runs Details_________________");
	printf("\nMaximum runs : %d \nName of player : %s",run,p[ps].pName);
	printf("\n______________________________________________________\n");
    
}
void minRun(Player* p,int n)
{
	int i;
	int run=p[0].runs;
	int ps=0;
	for(i=0;i<n;i++)
	{
		if(p[i].runs<run)
		{
			run=p[i].runs;
			ps=i;
		}
	}
	printf("\n______________________________________________________\n");
	printf("\n_____________Minimum Runs Details_________________");
	printf("\nMinimum runs : %d \nName of player : %s",run,p[ps].pName);
	printf("\n______________________________________________________\n");
    
}
void maxWickets(Player* p, int n)
{
	int i;
	int wik=0;
	int ps=0;
	for(i=0;i<n;i++)
	{
		if(p[i].wickets>wik){
			wik=p[i].wickets;
			ps=i;
		}
	}
	printf("\n____________________________________________________\n");
	printf("\n_____________Maximum Wikets Details_________________");
	printf("\nMaximum Wickets : %d  \nName of player : %s",wik,p[ps].pName);
	printf("\n______________________________________________________\n");
}
void minWik(Player* p, int n)
{
	int i;
	int wik1=p[0].wickets;
	int ps1=0;
	for(i=0;i<n;i++)
	{
		if(p[i].wickets<wik1){
			wik1=p[i].wickets;
			ps1=i;
		}
	}
	printf("\n____________________________________________________\n");
	printf("\n_____________Minimum Wikets Details_________________");
	printf("\nMinimum Wickets : %d  \nName of player : %s",wik1,p[ps1].pName);
	printf("\n______________________________________________________\n");
}
void iccBatsRankings(Player* p,int n)
{
	int i,j,l;
	Player s;
	 for(i=0;i<n;i++)
     {
          for(j=i+1;j<n;j++)
          {
               if(p[i].runs<p[j].runs)
               {
                    s=p[i];
                    p[i]=p[j];
                    p[j]=s;
               }
          }
    }
    printf("\n-------------------------------------------\n");
    printf("ICC All Rankings(BATSMAN based on runs)\n");
  	printf("\n_____________________________________________\n");

    printf("\nName\t\t:Ranks\t\t: Runs");
    for(i=0;i<n;i++)
    {
    	printf("\n%s\t\t%d\t\t%d",p[i].pName,i+1,p[i].runs);
	}
}
void testBatsRankings(Player* p,int n)
{
	int i,j,l;
	Player s;
	 for(i=0;i<n;i++)
     {
          for(j=i+1;j<n;j++)
          {
               if(p[i].testRuns<p[j].testRuns)
               {
                    s=p[i];
                    p[i]=p[j];
                    p[j]=s;
               }
          }
    }
    printf("\t\t\n-------------------------------------------\n");
    printf("\t\tICC TEST Rankings(based on runs)\n");
  	printf("\t\t\n_____________________________________________\n");

    printf("\nName\t\t:Ranks\t\t: Runs");
    for(i=0;i<n;i++)
    {
    	printf("\n%s\t\t%d\t\t%d",p[i].pName,i+1,p[i].runs);
	}
}
void ODIBatsRankings(Player* p,int n)
{
	int i,j,l;
	Player s;
	 for(i=0;i<n;i++)
     {
          for(j=i+1;j<n;j++)
          {
               if(p[i].odiRuns<p[j].odiRuns)
               {
                    s=p[i];
                    p[i]=p[j];
                    p[j]=s;
               }
          }
    }
    printf("\t\t\n-------------------------------------------\n");
    printf("\t\tICC ODI Rankings(based on runs)\n");
  	printf("\t\t\n_____________________________________________\n");

    printf("\nName\t\t:Ranks\t\t: Runs");
    for(i=0;i<n;i++)
    {
    	printf("\n%s\t\t%d\t\t%d",p[i].pName,i+1,p[i].odiRuns);
	}
}
void t_20iBatsRankings(Player* p,int n)
{
	int i,j,l;
	Player s;
	 for(i=0;i<n;i++)
     {
          for(j=i+1;j<n;j++)
          {
               if(p[i].t_20iRuns<p[j].t_20iRuns)
               {
                    s=p[i];
                    p[i]=p[j];
                    p[j]=s;
               }
          }
    }
    printf("\t\t\n-------------------------------------------\n");
    printf("\t\tICC T-20I Rankings(based on runs)\n");
  	printf("\t\t\n_____________________________________________\n");

    printf("\nName\t\t:Ranks\t\t: Runs");
    for(i=0;i<n;i++)
    {
    	printf("\n%s\t\t%d\t\t%d",p[i].pName,i+1,p[i].t_20iRuns);
	}
}
void iccBallRankings(Player* p,int n)
{
	int i,j;
//	int w;//Incompatiable type assign player to int
//	we need to take player
	Player w;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].wickets<p[j].wickets)
			{
				w = p[i];
				p[i]=p[j];
				p[j]=w;
			}
		}
	}
    printf("\n-----------------------------------------------------\n");	
	printf("ICC Rankings(Baller based on wickets)\n");
    printf("\n_____________________________________________________\n");
    printf("\nName\t\t:Ranks\t\t: Wickets");
    for(i=0;i<n;i++)
    {
    	printf("\n%s\t\t%d\t\t%d",p[i].pName,i+1,p[i].wickets);
	}
	
}
void T_20IBallRankings(Player* p,int n)
{
	int i,j;
//	int w;//Incompatiable type assign player to int
//	we need to take player
	Player w;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].T_20iWik<p[j].T_20iWik)
			{
				w = p[i];
				p[i]=p[j];
				p[j]=w;
			}
		}
	}
    printf("\n-----------------------------------------------------\n");	
	printf("ICC Rankings(Baller based on wickets)\n");
    printf("\n_____________________________________________________\n");
    printf("\nName\t\t:Ranks\t\t: Wickets");
    for(i=0;i<n;i++)
    {
    	printf("\n%s\t\t%d\t\t%d",p[i].pName,i+1,p[i].T_20iWik);
	}
	
}
void OdiBallRankings(Player* p,int n)
{
	int i,j;
//	int w;//Incompatiable type assign player to int
//	we need to take player
	Player w;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].odiWik<p[j].odiWik)
			{
				w = p[i];
				p[i]=p[j];
				p[j]=w;
			}
		}
	}
    printf("\n-----------------------------------------------------\n");	
	printf("ICC Rankings(Baller based on wickets)\n");
    printf("\n_____________________________________________________\n");
    printf("\nName\t\t:Ranks\t\t: Wickets");
    for(i=0;i<n;i++)
    {
    	printf("\n%s\t\t%d\t\t%d",p[i].pName,i+1,p[i].odiWik);
	}
	
}
void TestBallRankings(Player* p,int n)
{
	int i,j;
//	int w;//Incompatiable type assign player to int
//	we need to take player
	Player w;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].TestWik<p[j].TestWik)
			{
				w = p[i];
				p[i]=p[j];
				p[j]=w;
			}
		}
	}
    printf("\n-----------------------------------------------------\n");	
	printf("ICC Rankings(Baller based on wickets)\n");
    printf("\n_____________________________________________________\n");
    printf("\nName\t\t:Ranks\t\t: Wickets");
    for(i=0;i<n;i++)
    {
    	printf("\n%s\t\t%d\t\t%d",p[i].pName,i+1,p[i].TestWik);
	}
	
}
void testTableformat(Player* p,int n)
{
	int i;
	printf("\nName\t\t Country\tMatch\t\tRuns\t\thundreds\tfifties\t\tWikets\t\tAvg\n");
	printf("\n_________________________________________________________________________________________________________________________________________________________");
	for(i=0;i<n;i++)
	{
		printf("\n%s\t\t %s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.2f",p[i].pName,p[i].country,p[i].TestMatch,p[i].testRuns,p[i].testHun,p[i].testFif,p[i].TestWik,(float)p[i].testRuns/p[i].TestMatch);
	}
	printf("\n_________________________________________________________________________________________________________________________________________________________");
}
void ODITableformat(Player* p,int n)
{
	int i;
	printf("\nName\t\t Country\tMatch\t\tRuns\t\thundreds\tfifties\t\tWikets\t\tAvg\n");
	printf("\n_________________________________________________________________________________________________________________________________________________________");
	for(i=0;i<n;i++)
	{
		printf("\n%s\t\t %s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.2f",p[i].pName,p[i].country,p[i].odiMatch,p[i].odiRuns,p[i].odiHun,p[i].odiFif,p[i].odiWik,(float)p[i].odiRuns/p[i].odiMatch);
	}
	printf("\n_________________________________________________________________________________________________________________________________________________________");
}
void T_20Tableformat(Player* p,int n)
{
	int i;
	printf("\nName\t\t Country\tMatch\t\tRuns\t\thundreds\tfifties\t\tWikets\t\tAvg\n");
	printf("\n__________________________________________________________________________________________________________________________________________________________");
	for(i=0;i<n;i++)
	{
		printf("\n%s\t\t %s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.2f",p[i].pName,p[i].country,p[i].t_20iMatch,p[i].t_20iRuns,p[i].t_20iHun,p[i].t_20ifif,p[i].T_20iWik,(float)p[i].t_20iRuns/p[i].t_20iMatch);
	}
	printf("\n_________________________________________________________________________________________________________________________________________________________");
}
void calcStrikeAvg()
{
	float sRate,avg;
	char name[100],tName2[30];
	int match,run,ball;
	fflush(stdin);
		printf("\nEnter Player Name :");
		gets(name);
		printf("Enter the Country Name : ");
		gets(tName2);
		printf("Enter total matches played in this format :");
		scanf("%d",&match);
		printf("Enter total Runs in  this format: ");
		scanf("%d",&run);
		printf("Enter Ball Played in this format : ");
		scanf("%d",&ball);
		sRate = (float)run/ball*100;//Type casting  using float
		avg= (float)(run/match);
	printf("\n________________StrikeRate/Avg ________________________");
	printf("\nName\t\t  Country\t  Match\t\t  Strke Rate\t  Average");
	printf("\n_________________________________________________________________________________");
	printf("\n%s\t\t  %s\t\t  %d\t\t  %.2f\t\t  %.2f",name,tName2,match,sRate,avg);
}
void calEconomyRate(char* p){
	int run,ovr,wik;
	char name[20],tName[20];
	printf("\nEnter the Player Name : ");
	gets(name);
	printf("Enter the Country Name : ");
	gets(tName);
	printf("run conceded in International Career :");
	scanf("%d",&run);
	printf("Over Bowlled in International Career: ");
	scanf("%d",&ovr);
	printf("Wikets Taken in International Career:");
	scanf("%d",&wik);
	float eco =(float) run/ovr;
//economy Based on runs conceded by a bowler by the number of overs bowled.
	float av = (float) run/wik;
// bowling average is calculated by dividing the 	
//numbers of runs they have conceded by the number of wickets they have taken.

	printf("\n %s format Table",p);
	printf("\n________________EconomyRateRate/Avg ________________________");
	printf("\nName\t\t Country\tOverBoweld\tRun Conceded\tEconomy\tBalling Average");
	printf("\n__________________________________________________________________________");
	printf("\n%s\t\t  %s\t\t%d\t\t%d\t\t%.2f\t\t%.2f",name,tName,ovr,run,eco,av);
}


*/

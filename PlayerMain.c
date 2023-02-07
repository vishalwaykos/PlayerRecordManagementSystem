#include<stdio.h>
#include"PlayerService.h"
void main()
{
	int n, ch;
	char ch1;
	printf("\n_____Welcome to Record Book_____");
	printf("\nEnter how Many Player details Want to Add ");
	scanf("%d",&n);
	Player *p;
	int* n1;
	p = (Player*)malloc(sizeof(Player)*n);
	getPlayerDetails(p,n);
	do{
	printf("\n-------------------------------------------------------------------------");
	printf("\nEnter  your Choice");
	printf("\nPress 1 -> Display  Player Details");
	printf("\nPress 2 ->  Add new Player");
	printf("\nPress 3 -> Maximum Interational Runs in All Format(TEST/ODI/T-20)");
	printf("\nPress 4 -> Maximum Interational Wickets in All Format(TEST/ODI/T-20)");
	printf("\nPress 5 -> Display Record Book");
	printf("\nPress 6 -> Search By name ");
	printf("\nPress 7 -> Delete the Record");
	printf("\nPress 8 -> ICC Ranking");
	printf("\nPress 9 -> Display individual Format Details in Table Format ");
	printf("\nPress 10 -> how many record added");
	printf("\nPress 11 -> Calculate Batsman Strike Rate and Avg Individual Format(ODI/TEST/T-20)");
	printf("\nPress 12 -> Calculate Baller Economy Rate and Avg Individual Format(ODI/TEST/T-20) ");

	printf("\n------------------------------------------------------------------------\n");
	scanf("%d",&ch);
	fflush(stdin);
	//switch cases use kraycha
	
		if(ch==1)
		{
			dispPlayerDetails(p,n);		
		}
		if(ch==2){
			insertPlayer(p,&n);
		//	dispPlayerDetails(p,n);
		}
		if(ch==3)
		{
			maxRun(p,n);	
		}
		if(ch==4)
		{
			maxWickets(p,n);	
		}
		if(ch==5)
		{
			int r;
			do{
				printf("\n________________________________________________________________");
				printf("\nEnter 1 Max Run record \nEnter 2 Max wicket Record \nEnter 3 Both maxRun and maxWickets record");
				printf("\nEnter 4 Min Run record \nEnter 5 Min wicket Record\nEnter 6 Both Minimum Record \nEnter 7 Main Menu");
				printf("\n________________________________________________________________");	
				scanf("%d",&r);
				if(r==1){
					maxRun(p,n);
				}
				if(r==2){
					maxWickets(p,n);
				}
				if(r==3){
					dispRecordCard(p,n);
				}
				if(r==4){
					minRun(p,n);
				}
				if(r==5){
					minWik(p,n);
				}
				if(r==6){
					printf("\n---------------------------------------------------------------");
					minRun(p,n);
					minWik(p,n);
					printf("\n________________________________________________________________");
				}
				if(r>7)
				{
					printf("\nWrong Input");
				}
			}while(r!=7);
		}
		if(ch==6){
			searchByName(p,n);
		}
		if(ch==7){
			deleteData(p,&n);
			//dispPlayerDetails(p,n);
		}
		if(ch==8){
			int s,rn;
			do{
					printf("\n________________________________________________________________");
				printf("\nEnter 1 BatsMan Rangkings\nEnter 2 Baller Rangkings\nEnter 3 Exit/MainMenu");
				printf("\n________________________________________________________________");
				scanf("%d",&s);
				if(s==1)
				{
					
					do{
						printf("\n________________________________________________________________");
						printf("\nEnter 1.Test Rankings\nEnter 2.ODI Rankings\nEnter n3.T-20i Rangkings\nEnter 4.AllFormat Rangkings\nEnter 5.Back(N=5)");
						printf("\n________________________________________________________________");
						scanf("%d",&rn);
						if(rn == 1){
						testBatsRankings(p,n);}		
						if(rn==2){
							ODIBatsRankings(p,n);
						}
						if(rn==3){
							t_20iBatsRankings(p,n);
						}
						if(rn==4){
							iccBatsRankings(p,n);
						}
						if(rn>5){
							printf("\nWrong Input");
						}
					}while(rn !=5);
				}
				if(s==2){
					do{
						printf("\n________________________________________________________________");
						printf("\nEnter 1.Test Rankings\nEnter 2.ODI Rankings \nEnter 3.T20i Rangkings\nEnter 4.AllFormat Rangkings\nEnter 5.continue in Rankings");
						printf("\n________________________________________________________________");
						scanf("%d",&rn);
						if(rn==1){
							TestBallRankings(p,n);
						}
						if(rn==2){
							OdiBallRankings(p,n);
						}
						if(rn==3){
							T_20IBallRankings(p,n);
						}
						if(rn==4){
						iccBallRankings(p,n);
						}
						if(rn>5)
						{
							printf("\nWrong Input");
						}
					}while(rn!=5);
				}
				if(s>3)
				{
					printf("\nWrong Input");
				}
			}while(s!=3);
		}
		if(ch==9){
			int f1;
			do{
				printf("\n________________________________________________________________");
				printf("\nEnter 1.Test Format\nEnter 2.ODI Format\nEnter 3.T-20I Format\n4.Main Menu");
				printf("\n________________________________________________________________");
				scanf("%d",&f1);
				if(f1==1){
					printf("\n\t\t\t*********TEST FORMAT*********\n");
					testTableformat(p,n);
				}
				if(f1==2){
					printf("\n\t\t\t*********ODI FORMAT*********\n");
					ODITableformat(p,n);
				}
				if(f1==3){
					printf("\n\t\t\t*********T-20I FORMAT*********\n");
					T_20Tableformat(p,n);
				}
				if(f1>4){
					printf("\nWrong Input");
					printf("\n________________________________________________________________");
				}
			}while(f1!=4);
		}
		if(ch==10){
			storedRecordInBook(p,n);
		}
		if(ch==11){
			char format[20];
			int c;
			do{
				printf("\nEnter the Name of Format");
				printf("\nEnter 1.ICC TEST format\nEnter 2.ICC T-20 format\nEnter 3.ICC ODI format\nEnter 4 ");
				printf("\n===============================================\n");
				gets(format);
				printf("\nEnter Details of %s Format : ",format);
				calcStrikeAvg();
			}while(c!=4);
		}
		if(ch==12)
		{
			char format[20];
			int c;
			do{
				printf("\nEnter 1.ICC TEST format\nEnter 2.ICC T-20 format\nEnter 3.ICC ODI format\n");
				printf("\n===============================================");
				gets(format);
				printf("\nEnter Details of %s Format : ",format);
				calEconomyRate(&format);
			}while(c!=4);
		}
	
	
		if(ch>12){
			printf("\nEnter the proper Details");
		}
		fflush(stdin);
		printf("\n---------------------------------------------------------------------------------");
		printf("\nDo you Want to Continue with Main Menu(Press ""y"" for yes/ press ""n"" for No)\n");
	
		scanf("%c",&ch1);
//		if(ch1!='y'||ch1!='n'){printf("\nEnter proper Details");}
		
	}while(ch1!='n');
}


/*
void main()
{
	int n, ch;
	char ch1;
	printf("\n_____Welcome to Record Book_____");
	printf("\nEnter how Many Player details Want to Add ");  
	scanf("%d",&n);
	Player *p;
	int* n1;
	p = (Player*)malloc(sizeof(Player)*n);
	getPlayerDetails(p,n);
	do{
	printf("\n-------------------------------------------------------------------------");
	printf("\nEnter  your Choice");
	printf("\nPress 1 -> Display  Player Details");
	printf("\nPress 2 -> Maximum Interational Runs in All Format(TEST/ODI/T-20)");
	printf("\nPress 3 -> Maximum Interational Wickets in All Format(TEST/ODI/T-20)");
	printf("\nPress 4 -> Display Record Book");
	printf("\nPress 5 -> Search By name");
	printf("\nPress 6 -> ICC Ranking ");
	printf("\nPress 7 -> Display indDetails in Table Format");
	printf("\nPress 8 -> Calculate Batsman Strike Rate and Avg Individual Format(ODI/TEST/T-20) ");
	printf("\nPress 9 -> Calculate Baller Economy Rate and Avg Individual Format(ODI/TEST/T-20) ");
	printf("\nPress 10 -> Delete the Record");
	printf("\nPress 11 -> Add new Player");
	printf("\n------------------------------------------------------------------------");
	scanf("%d",&ch);
	fflush(stdin);
		if(ch==1)
		{
			dispPlayerDetails(p,n);		
		}
		if(ch==2)
		{
			maxRun(p,n);	
		}
		if(ch==3)
		{
			maxWickets(p,n);	
		}
		if(ch==4)
		{
			int r;
			do{
				printf("\nEnter 1.Max Run record \nEnter 2.Max wicket Record \nEnter 3.Both maxRun and maxWickets record");
				printf("\nEnter 4.Min Run record \nEnter 5.Min wicket Record\nEnter 6.Both Minimum Record \n7.Exit");
				scanf("%d",&r);
				if(r==1){
					maxRun(p,n);
				}
				if(r==2){
					maxWickets(p,n);
				}
				if(r==3){
					dispRecordCard(p,n);
				}
				if(r==4){
					minRun(p,n);
				}
				if(r==5){
					minWik(p,n);
				}
				if(r==6){
					printf("\n---------------------------------------------------------------");
					minRun(p,n);
					minWik(p,n);
					printf("\n________________________________________________________________");
				}
			}while(r!=7);
		}
		if(ch==5){
			searchByName(p,n);
		}
		if(ch==6){
			int s,rn;
			do{
				printf("\nEnter 1.BatsMan Rangkings\nEnter 2.Baller Rangkings\nEnter 3.Exit");
				scanf("%d",&s);
				if(s==1)
				{
					
					do{
						printf("\nEnter 1.Test Rankings\nEnter 2.ODI Rankings\Enter n3.T-20i Rangkings\nEnter 4.AllFormat Rangkings\nEnter 5.continue in Rankings(N=5)");
						scanf("%d",&rn);
						if(rn == 1){
						testBatsRankings(p,n);}		
						if(rn==2){
							ODIBatsRankings(p,n);
						}
						if(rn==3){
							t_20iBatsRankings(p,n);
						}
						if(rn==4){
							iccBatsRankings(p,n);
						}
					}while(rn !=5);
				}
				if(s==2){
					do{
						printf("\nEnter 1.Test Rankings\nEnter 2.ODI Rankings \nEnter 3.T20i Rangkings\nEnter 4.AllFormat Rangkings\nEnter 5.continue in Rankings");
						scanf("%d",&rn);
						if(rn==1){
							TestBallRankings(p,n);
						}
						if(rn==2){
							OdiBallRankings(p,n);
						}
						if(rn==3){
							T_20IBallRankings(p,n);
						}
						if(rn==4){
						iccBallRankings(p,n);
						}
					}while(rn!=5);
				}
			}while(s!=3);
		}
		if(ch==7){
			int f1;
			do{
				
				printf("\nEnter 1.Test Format\nEnter 2.ODI Format\nEnter 3.T-20I Format\n4.exit");
				scanf("%d",&f1);
				if(f1==1){
					printf("\n\t\t\t*********TEST FORMAT*********\n");
					testTableformat(p,n);
				}
				if(f1==2){
					printf("\n\t\t\t*********ODI FORMAT*********\n");
					ODITableformat(p,n);
				}
				if(f1==3){
					printf("\n\t\t\t*********T-20I FORMAT*********\n");
					T_20Tableformat(p,n);
				}
			}while(f1!=4);
		}
		if(ch==8){
			char format[20];
			int c;
				printf("\nEnter the Name of Format");
				printf("\nEnter 1.ICC TEST format\nEnter 2.ICC T-20 format\nEnter 3.ICC ODI format");
				printf("\n===============================================");
				gets(format);
				printf("\nEnter Details of %s Format : ",format);
				calcStrikeAvg();
		}
		if(ch==9)
		{
			char format[20];
			printf("\nEnter 1.ICC TEST format\nEnter 2.ICC T-20 format\nEnter 3.ICC ODI format");
			printf("\n===============================================");
			gets(format);
			printf("\nEnter Details of %s Format : ",format);
			calEconomyRate(&format);
		}
		if(ch==10){
			deleteData(p,&n);
			//dispPlayerDetails(p,n);
		}
		if(ch==11){
			insertPlayer(p,&n);
		//	dispPlayerDetails(p,n);
		}
		if(ch>12){
			printf("\nEnter the proper Details");
		}
		fflush(stdin);
		printf("\nDo you Want to Continue(Press ""y"" for yes/ press ""n"" for No)");
		scanf("%c",&ch1);
//		if(ch1!='y'||ch1!='n'){printf("\nEnter proper Details");}
		
	}while(ch1!='n');
}*/

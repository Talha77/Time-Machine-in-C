#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#include<time.h>
int CheckTime(char []);
void GMT(void);
void display(void);
void displayset(void);
void printmenu();
void reset();
void effect();
void gotoxy (int ,int );
void color(int,int);

struct diff {
	int hour;
	int minute;
};
struct diff GMTtime;

int main()
{
	char ch;
	 int fore= 10, back = 5;

color(fore,back);
  

	
do{
	reset();
	printmenu();
	fflush(stdin);
	printf("\n\n\t\tEnter any key : ");
	ch = getche();
	effect();
	switch(ch)
	{
		case 'a':
			display();
			break;
		case 'b':
			displayset();
			break;
		case 'e':
			exit(0);
		default:
			printf("\n\t**invalid key**");
}
	reset();
	
}while(ch!='e');
}

// Getting GMT time

void GMT(void)
{	
	int pkhrs=0,pkmin=0;
		// Saving time web in file
	printf("Now Fetching GMT Time\n");
	system("curl http://time.is/Pakistan > GMT.txt");
	system("cls");
	
	FILE * pFile;
    char buffer [100];
    char time[9];
	int count=0;
    pFile = fopen ("GMT.txt" , "r");
    if (pFile == NULL) perror ("Error opening file");
    else
    
    {
     
	 // Reaching at position where time exists
	 while ( ! feof (pFile) )
     {
     	if (count>298)break;
     	count++;
      if ( fgets (buffer , 100 , pFile) == NULL ) break;
       
     }
     fgets (buffer , 99 , pFile);
     fgets (time , 9 , pFile);
     fclose (pFile);
    } 
    
    // Got time in Char time
    
    //Delete temp
    system("del GMT.txt");
   
   	 for(int i=0;i<=1;i++)
 		pkhrs=pkhrs*10+(time[i]-48);
 	
	 for(int i=3;i<=4;i++)
 		pkmin=pkmin*10+(time[i]-48);
	 
      
      GMTtime.hour=pkhrs-5;
      GMTtime.minute=pkmin;
}

int CheckTime(char _time[]){
	
	int chars=0;
	int digits=0;
	
	for(int i=0;i<strlen(_time);i++){
		
		if(isdigit(_time[i])!=0)
			digits++;
		else
			chars++;
		
	}
	
	if(digits==6 && chars==2)
		return 1;
	else
		return 0;
}

// Display time of country and set it as default
void displayset(void)
{
	
	system("cls");
	char cpy[20];
	int hrs=0,min=0,sec=0,mindiff,hrsdiff;
	char cname[20];
	fflush(stdin);
	printf("Enter country name : ");
	gets(cname);
	if(cname[0]>=97 || cname[0]<=122)
	cname[0]-=32;
	char linkend[12]=" > time.txt";
	char link[100]="curl http://time.is/";
	strcat(link,cname);
	strcat(link,linkend);
		
	// Saving time web in file
	printf("Fetching current Time in %s\n",cname);
	system(link);
	effect();
	system("cls");
		
	FILE * pFile;
    char buffer [100];
    char time[9];
	int count=0;
    pFile = fopen ("time.txt" , "r");
    if (pFile == NULL) perror ("Error opening file");
    else
    
    {
     
	 // Reaching at position where time exists
	 while ( ! feof (pFile) )
     {
     	if (count>298)break;
     	count++;
      if ( fgets (buffer , 100 , pFile) == NULL ) break;
       
     }
     fgets (buffer , 99 , pFile);
     fgets (time , 9 , pFile);
     fclose (pFile);
    } 
    
    // Got time in Char time
    
    //Delete temp
    system("del time.txt");
    
 	if(CheckTime(time)!=1){
 		printf("\n\n\n\n\n\n\n\n\n\n\t\t***Invalid country name Or Network problem***");
 	}
 	
 	else{
 		GMT();
 	
	 printf("Current time in %s is : ",cname);
 	printf("%s\n",time);
	 
	  for(int i=0;i<=1;i++)
 		hrs=hrs*10+(time[i]-48);
 	
	 for(int i=3;i<=4;i++)
 		min=min*10+(time[i]-48);
	 
	 for(int i=6;i<=7;i++)
 		sec=sec*10+(time[i]-48);
 		
 		if(GMTtime.minute<=min)
 		{
 			mindiff = min-GMTtime.minute;
 			hrsdiff = hrs-GMTtime.hour;
		 }
		 else
		 {
		 	mindiff = min+60-GMTtime.minute;
		 	hrsdiff = hrs-1-GMTtime.hour;
		 }
	if(mindiff<=9 && mindiff>=0)
	printf("GMT (%d:0%d)",hrsdiff,mindiff);
	else
	printf("GMT (%d:%d)",hrsdiff,mindiff);
	
}
		 SYSTEMTIME str_t;
	GetSystemTime(&str_t);
   
	   //changing system time
	   
	SYSTEMTIME st;
	st.wYear = str_t.wYear;
	st.wMonth = str_t.wMonth;
	st.wDay = str_t.wDay;
	st.wHour = hrs;
	st.wMinute = min;
	st.wSecond = sec;
	st.wMilliseconds = 0;
 	SetLocalTime (&st);
   		getch();
   
}
     
	 // Display time of country

void display(void)
{
	effect();
	system("cls");
	char cpy[20];
	int hrs=0,min=0,sec=0,mindiff,hrsdiff;
	char cname[20];
	fflush(stdin);
	printf("Enter country name : ");
	gets(cname);
	if(cname[0]>=97 || cname[0]<=122)
	cname[0]-=32;
	char linkend[12]=" > time.txt";
	char link[100]="curl http://time.is/";
	strcat(link,cname);
	strcat(link,linkend);
		
	// Saving time web in file
	printf("Fetching current Time in %s\n",cname);
	system(link);
	effect();
	system("cls");
		
	FILE * pFile;
    char buffer [100];
    char time[9];
	int count=0;
    pFile = fopen ("time.txt" , "r");
    if (pFile == NULL) perror ("Error opening file");
    else
    
    {
     
	 // Reaching at position where time exists
	 while ( ! feof (pFile) )
     {
     	if (count>298)break;
     	count++;
      if ( fgets (buffer , 100 , pFile) == NULL ) break;
       
     }
     fgets (buffer , 99 , pFile);
     fgets (time , 9 , pFile);
     fclose (pFile);
    } 
    
    // Got time in Char time
    
    //Delete temp
    system("del time.txt");
    
 	if(CheckTime(time)!=1){
 		printf("\n\n\n\n\n\n\n\n\n\n\t\t***Invalid country name Or Network problem***");
 		exit(0);
 	}
 	
 	else{
 		GMT();
 	
	 printf("Current time in %s is : ",cname);
 	printf("%s\n",time);
	 
	  for(int i=0;i<=1;i++)
 		hrs=hrs*10+(time[i]-48);
 	
	 for(int i=3;i<=4;i++)
 		min=min*10+(time[i]-48);
	 
	 for(int i=6;i<=7;i++)
 		sec=sec*10+(time[i]-48);
 		
 		if(GMTtime.minute<=min)
 		{
 			mindiff = min-GMTtime.minute;
 			hrsdiff = hrs-GMTtime.hour;
		 }
		 else
		 {
		 	mindiff = min+60-GMTtime.minute;
		 	hrsdiff = hrs-1-GMTtime.hour;
		 }
	if(mindiff<=9 && mindiff>=0)
	printf("GMT (%d:0%d)",hrsdiff,mindiff);
	else
	printf("GMT (%d:%d)",hrsdiff,mindiff);
	
}
			getch();
		}

void PrintLine(int j){

	for(int i=0;i<j;i++)
	{
			Sleep(10);
		printf("%c",205);
	}
}
void PrintTopRight(){
	printf("%c",185);
}

void PrintTopLeft(){
	printf("%c",204);
}
void PrintBottomLeft(){
	printf("%c",200);
}

void PrintBottomRight(){
	printf("%c",188);
}

void printmenu(void)
{		effect();
	system("cls");

	printf("%-10s"," ");
	printf("%c",201);
	PrintLine(67);
	printf("%c",187);
	printf("\n%11c %25s %-39s %c",186," ","***MENU***",186);
	printf("\n%10s"," ");
	PrintTopLeft();
	PrintLine(67);
	PrintTopRight();
	
	printf("\n%11c %s %-63s %c",186," ","Watch Current times of different countries and set default",186);
	printf("\n%11c %s %-63s %c",186," ","Note : Run program as administrator for setting time as default",186);
	printf("\n%11c %s %-63s %c",186," ","press (a) for display time",186);
	printf("\n%11c %s %-63s %c",186," ","press (b) for setting time as default",186);
	printf("\n%11c %s %-63s %c\n",186," "," press (e) for exit",186);
	printf("%10s"," ");
	
	PrintBottomLeft();
	PrintLine(67);
	PrintBottomRight();
	
}
void effect()
{   int i,j;
    gotoxy(0,0);
    for (i=0;i<24;i++)
    {   for(j=0;j<79;j++)
        printf("%c",220);Sleep(6);
        printf("\n");}
    gotoxy(0,0);
    for (i=0;i<24;i++)
    { printf("\t\t\t\t\t\t\t\t               \n");Sleep(6);}
}
void gotoxy (int x,int y)
{COORD cur={x,y}; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cur);}


void reset(void)
{
	GMTtime.minute = 0;
	GMTtime.hour = 0;
}
void color(int F,int B)
{

     WORD wColor = ((B & 0x0F) << 4) + (F & 0x0F);;

     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);

     return;


	
}



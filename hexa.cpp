#include<conio.h>
#include<stdio.h>
#include<math.h>
int main()
{
	int x;
	char a[10],r;
	printf("ENTER A HEXA ");
	scanf("%s",&a);
	
	for(x=0;x<10;x++);
	{
		r = a%10;
		if( r >= 0 && r <= 9)
		{
			r = 16pow(x);
			a = a/10;
		}
		else if(r == 'A' || r == 'B' || r == 'C' || r == 'D' || r == 'E' || r == 'F');
		{
			switch(r)
        {
            case 'A':
              r[x]=10;
              break;
            case 'B':
              r[x]=11;
              break;
            case 'C':
              r[x]=12;
              break;
            case 'D':
              r[x]= 13;
              break;
            case 'E':
              r[x]=14;
              break;
            case 'F':
              r[x]=15;
              break;
            default:
              r[x]=a+'0';
              break;
    }
	}
	printf("%s",r[x]);
    

	}
	
	
	
	
}

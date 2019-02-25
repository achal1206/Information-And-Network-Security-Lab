#include<stdio.h>
#define MAX 25
int min(int x,int y)
{
	return(x<y)?x:y;
}
int main()
{
	int drop=0,a,size,oprt,nsec,count,i=0,inp[MAX];
	printf("Enter the bucket size:\n");
	scanf("%d",&size);
	printf("Enter Operation rate:\n");
	scanf("%d",&oprt);
	printf("Enter Simulation rate:\n");
	scanf("%d",&nsec);
	for(i=0;i<nsec;i++)
	{
		printf("Enter Packet Entering At %d second\t",i+1);
	        scanf("%d",&inp[i]);
	}
	printf("(Second):(Packet Received):(Packet Sent):(Packet Left):(Packet dropped)\n");
	count=0;
	for(i=0;i<nsec;i++)
	{
		count+=inp[i];
		if(count>size)
		{
			drop=count-size;
			count=size;
		}
		printf("%d",i+1);
		printf("\t\t %d",inp[i]);
		a=min(count,oprt);
		printf("\t\t %d",a);
		count=count-a;
		printf("\t\t %d",count);
		printf("\t\t %d\n",drop);
		drop=0;
	}
	for(;count!=0;i++)
	{
		if(count>size)
		{
			drop=count-size;
			count=size;
		}
		printf("%d",i+1);
		printf("\t\t0");
		a=min(count,oprt);
		printf("\t\t %d",a);
		count=count-a;
		printf("\t\t %d",count);
		printf("\t\t %d\n",drop);
	}
}
	
	

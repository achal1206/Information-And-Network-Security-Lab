#include<stdio.h>
#define MAX 10
int main()
{
	struct rtable
	{
		unsigned distance[MAX];
		unsigned from[MAX];
		
	}rt[10];
	int dmatrix[MAX][MAX];
	int n=0,i=0,j=0,k=0,count=0;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	printf("Enter the matrix--0 for self loop and 999 for no path");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&dmatrix[i][j]);
			if(i==j)
			 dmatrix[i][j]=0;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			rt[i].distance[j]=dmatrix[i][j];
			rt[i].from[j]=j;
		}
	}
	do
	{
		count=0;
		for(i=0;i<n;i++)
		{	
			for(j=0;j<n;j++)
			{
			
				for(k=0;k<n;k++)
				{
					if(rt[i].distance[j]>dmatrix[i][k]+rt[k].distance[j])
					{
						rt[i].distance[j]=rt[i].distance[k]+rt[k].distance[j];
						rt[i].from[j]=k;
						count++;
					}
				}
			}
		}
	}while(count!=0);
	for(i=0;i<n;i++)
	{
		printf("The state values for router is: %d\n",i);
		for(j=0;j<n;j++)
		{
			printf("From node %d via %d distance %d\n",j,rt[i].from[j],rt[i].distance[j]);
		}
	}
	return 0;
}


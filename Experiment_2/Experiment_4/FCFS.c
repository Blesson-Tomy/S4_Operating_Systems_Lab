#include <stdio.h>

int main()
{
	int num, i;
	printf("Enter the number of processes: ");
	scanf("%d", &num);
	int btime[num];
	int wtime[num];
	int ttime[num];
	int wsum=0, wavg;
	int tsum=0, tavg;
	for(i=1;i<=num;i++)
	{
		printf("\nP[%d]: ",i);
		scanf("%d", &btime[i]);
	}
	
	wtime[1]=0;
	//printf("The waiting time of process 1 is: 0 \n");
	for(i=2;i<=num;i++)
	{
		wtime[i]=wtime[i-1]+btime[i-1];
		//printf("The waiting time of process %d is: %d \n",i,wtime[i]);
		wsum=wsum+wtime[i];
	}
	
	for(i=1;i<=num;i++)
	{
		ttime[i]=btime[i]+wtime[i];
		//printf("The turnaround time of process %d is: %d \n",i,ttime[i]);
		tsum=tsum+ttime[i];
	}
	
	wavg = wsum/num;
	tavg = tsum/num;
	
	printf("The average wavg is: %d", wavg);
	printf("\nThe average tavg is: %d", tavg);
	
	printf("\n Process_ID Burst_Time Waiting_Time Turnaround_Time");
	printf("\n___________________________________________________");
	
    for(i=1;i<=num;i++)
	{
	    printf("\nP[%d]\t\t%d\t\t%d\t\t%d\n", i,btime[i],wtime[i],ttime[i]);
	}
	
    printf("\nGANTT CHART\n");
	int temp=0;
	printf("======================================\n");
	
    for(i=0;i<num;i++)
	{
		printf(" P%d ", i+1);
	}

	printf("\n======================================\n");
	
    for(i=1;i<=num;i++)
	{
		printf("%d ", temp);
		temp+=btime[i];
	}
}
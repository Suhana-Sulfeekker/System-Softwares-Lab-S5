#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int pid,at,bt,tt,wt;
}Process;

int sort(Process Pro[],int n){
	int i=0;
	for( i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(Pro[j].at>Pro[j+1].at){
				Process temp=Pro[j];
				Pro[j]=Pro[j+1];
				Pro[j+1]=temp;
			}
		}
	}
	printf("Sorted Processes (according to AT):\nProcess ID\tArrival Time\tBurst Time\n");
	for(i=0;i<n;i++){
		printf("%d\t\t%d\t\t%d\n",Pro[i].pid,Pro[i].at,Pro[i].bt);
	}
	return 0;
}

int sortpid(Process Pro[],int n){
	int i=0;
	for( i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(Pro[j].pid>Pro[j+1].pid){
				Process temp=Pro[j];
				Pro[j]=Pro[j+1];
				Pro[j+1]=temp;
			}
		}
	}
	return 0;
}

int display(Process Pro[],int n){
	printf("\nFCFS\n\n");
	printf("Process  AT  BT  WT  TT\n");
	float w=0,t=0;
	for(int i=0;i<n;i++){
		printf("P%d      %3d %3d %3d %3d\n",Pro[i].pid,Pro[i].at,Pro[i].bt,Pro[i].wt,Pro[i].tt);
		t +=Pro[i].tt;
		w +=Pro[i].wt;
	}
	w = w/n; t=t/n;
	printf("Average waiting time = %f\n", w);
	printf("Average turn around time = %f\n", t);
	return 0;
}

void main(){
	int n;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	Process Pro[n];
	printf("Enter Arrival Time & Burst Time:\n");
	for (int i=0;i<n;i++){
		scanf("%d %d",&Pro[i].at,&Pro[i].bt);
		Pro[i].pid=i+1;	
	}
	sort(Pro,n);
	int t=0;
	printf("\nGantt Chart\n");
	for(int i=0;i<n;i++){
		if (Pro[i].at>t){
			printf("%d|**|%d|P%d|",t,Pro[i].at,Pro[i].pid);
			t=Pro[i].at+Pro[i].bt;
		}
		else{
			printf("%d|P%d|",t,Pro[i].pid);
			t=t+Pro[i].bt;		
		}
		Pro[i].tt=t-Pro[i].at;
		Pro[i].wt=Pro[i].tt-Pro[i].bt;	
	}
	printf("%d\n",t);
	sortpid(Pro,n);
	display(Pro,n);
}

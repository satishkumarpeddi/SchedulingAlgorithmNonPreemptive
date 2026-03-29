#include <stdio.h>
#include <stdlib.h>
struct process{
    int pid;
    int btime;
    int tatime;
    int wtime;
    int priority;
    int ctime;
    int rtime;
    int atime;
    int complete;
};
typedef struct process *PROCESS;
void main(){
    int n,completed = 0,t=0;
    printf("Enter number of process: ");
    scanf("%d",&n);
    PROCESS p = (PROCESS)malloc(n*sizeof(struct process));
    for(int i=0;i<n;i++){
        p[i].pid = i+1;
        printf("Enter burst time of the Process P%d\n",i);
        scanf("%d",&p[i].btime);
        printf("Enter arrival time of the Process P%d\n",i);
        scanf("%d",&p[i].atime);
        printf("Enter priority time of the Process P%d\n",i);
        scanf("%d",&p[i].priority);
        p[i].rtime = p[i].btime;
        p[i].ctime = p[i].wtime = p[i].tatime = p[i].complete = 0;
    }
    while(completed!=n){
        int highest_priority = 100000;
        int idx = -1;
        for(int i=0;i<n;i++){
            if(p[i].atime<=t&&p[i].complete==0){
                    if(p[i].priority<highest_priority){
                    highest_priority = p[i].priority;
                    idx = i;
                }
            }
        }
        if(idx==-1){
            t++;
            continue;
        } 
            t+=p[idx].btime; 
            p[idx].ctime = t;
            p[idx].tatime = p[idx].ctime - p[idx].atime;
            p[idx].wtime = p[idx].tatime - p[idx].btime;
            completed++; 
            p[idx].complete=1;

    }
    float awtime = 0.0,atatime=0.0;
    printf("\nProcess\tBurst Time\tTurn Around Time\tWaiting Time\n");
    for(int i=0;i<n;i++){
        printf("\n%d\t%d\t\t%d\t\t\t%d\n",p[i].pid,p[i].btime,p[i].tatime,p[i].wtime);
        awtime += p[i].wtime;
        atatime += p[i].tatime;
    }
    printf("The Average Waiting Time : %.2f\n",awtime/n);
    printf("The Average Turn Around Time : %.2f\n",atatime/n);
}
#include <stdio.h>
#include <stdlib.h>
struct process{
    int pid;
    int btime;
    int wtime;
    int tatime;
    int priority;
    int atime;
    int ctime;
    int rtime;
    int complete;
};
typedef struct process *PROCESS;
void main(){
    int n;
    printf("Enter number of process : ");
    scanf("%d",&n);
    PROCESS p = (PROCESS)malloc(n*sizeof(struct process));
    for(int i=0;i<n;i++){
        p[i].pid= i;
        printf("Enter burst time for the process P%d: ",i);
        scanf("%d",&p[i].btime);
        printf("Enter arrival time for the process P%d: ",i);
        scanf("%d",&p[i].atime);
        printf("Enter priorty for the process P%d: ",i);
        scanf("%d",&p[i].priority);
        p[i].rtime = p[i].btime;
        p[i].ctime = p[i].tatime = p[i].wtime = p[i].complete = 0;
    }
    int completed=0,t=0;
    float awtime = 0.0;
    float awtatime = 0.0; 
    while(completed!=n){
        int highest_priority = 1000000;
        int idx = -1;
        for(int i=0;i<n;i++){
            if(p[i].atime<=t&&p[i].complete==0){
                if(p[i].priority<highest_priority){
                    highest_priority=p[i].priority;
                    idx =i;
                }
            }
        }
            if(idx == -1){
                t++;
                continue;
            }
            printf("P%d --> ",p[idx].pid); 
            t+=p[idx].btime; 
                completed++;
                p[idx].ctime = t;
                p[idx].tatime = p[idx].ctime - p[idx].atime;
                p[idx].wtime = p[idx].tatime - p[idx].btime;
                p[idx].complete = 1; 
    }
    printf("\nProcess\tBurst Time\tTurn Around Time\tWaiting Time\tArrival Time\tCompletion Time\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t\t%d\t\t\t%d\t\t%d\t\t\n",p[i].pid,p[i].btime,p[i].tatime,p[i].wtime,p[i].atime,p[i].ctime);
        awtime +=  p[i].wtime;
        awtatime += p[i].tatime;
    }
    printf("Average waiting time : %.2f\n",awtime/n);
    printf("Average turn around time : %.2f\n",awtatime/n);
}
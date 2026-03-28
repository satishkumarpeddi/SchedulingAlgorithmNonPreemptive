#include <stdio.h>
#include <stdlib.h>
struct process{
    int pid;
    int btime;
    int wtime;
    int tatime; 
    int atime;
    int ctime;
    int rtime;
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
        p[i].rtime = p[i].btime;
        p[i].ctime = p[i].tatime = p[i].wtime = 0;
    }
    int completed=0,t=0;
    float awtime = 0.0;
    float awtatime = 0.0; 
    int tq;
    printf("Enter time quantum: ");
    scanf("%d",&tq);
    while(completed!=n){
        int done=1;
        for(int i=0;i<n;i++){
            if(p[i].atime<=t&&p[i].rtime>0){
                done = 0;
                printf("P%d ",p[i].pid);
                if(p[i].rtime > tq){
                    t+=tq;
                    p[i].rtime -=tq;
                }else{
                    tq+=p[i].rtime;
                    p[i].rtime = 0;
                    completed++;
                    p[i].tatime = p[i].ctime - p[i].atime;
                    p[i].wtime = p[i].tatime - p[i].btime;
                }
            }
        }
        if(done)
            t++;
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

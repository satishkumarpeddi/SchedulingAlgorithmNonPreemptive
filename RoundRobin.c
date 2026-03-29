#include <stdio.h>
#include <stdlib.h>
struct process{
    int pid;
    int btime;
    int tatime;
    int wtime;
    int ctime;
    int rtime;
    int atime;
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
        p[i].rtime = p[i].btime;
        p[i].ctime = p[i].wtime = p[i].tatime = 0;
    }
    int tq=0;
    printf("Enter time quantum for the problem: ");
    scanf("%d",&tq);
    while(completed!=n){
        int done=1;
        for(int i=0;i<n;i++){
            if(p[i].atime<=t&&p[i].rtime>0){
                done=0;
                if(p[i].rtime>tq){
                    t+=tq;
                    p[i].rtime-=tq;
                }else{
                    t+=p[i].rtime;
                    p[i].rtime = 0;
                    p[i].ctime=t;
                    p[i].tatime = p[i].ctime - p[i].atime;
                    p[i].wtime = p[i].tatime - p[i].btime;
                    completed++;
            }
            }
        }
    if(done) t++;
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
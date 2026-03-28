#include <stdio.h>
#include <stdlib.h>
struct process{
    int pid;
    int btime;
    int wtime;
    int tatime;
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
    }
    p[0].wtime = 0;
    p[0].tatime = p[0].btime;
    float awtime = 0.0;
    float awtatime = 0.0;
    for(int i=1;i<n;i++){
        p[i].wtime = p[i-1].wtime + p[i-1].btime;
        p[i].tatime = p[i].wtime + p[i].btime;
    }
    printf("\nProcess\tBurst Time\tTurn Around Time\tWaiting Time\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t\t%d\t\t%d\t\n",p[i].pid,p[i].btime,p[i].tatime,p[i].wtime);
        awtime +=  p[i].wtime;
        awtatime += p[i].tatime;
    }
    printf("Average waiting time : %.2f\n",awtime/n);
    printf("Average turn around time : %.2f\n",awtatime/n);
}
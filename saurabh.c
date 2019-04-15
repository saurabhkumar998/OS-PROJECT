#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

struct process{
int name;
float burstTime;
float arrivalTime;
float status;

float waitingTime;
float turnAroundTime;
};
int main(){
int m,n;
float arrival;
float burst;
float sum=0;
static int num;
struct process p[10];
printf( "===================================================  WELCOME  ========================================================\n");
printf("\n");
printf("\n");
printf("Enter  Number of processes:");
scanf("%d",&num);
printf("\n");
printf(" \n");
printf("\n");

for(m=0;m<num;m++){
p[m].name=m+1;
printf("------ FOR PROCESS P%d ------\n",p[m].name);
printf("\n");

printf("Arrival Time:");
scanf("%f",&arrival);
p[m].arrivalTime=arrival;

printf("Burst Time:");
scanf("%f",&burst);
p[m].burstTime=burst;

p[m].status=0;
sum+=p[m].burstTime;
printf("\n");
}
printf("\n");
printf("\n");
printf("==============*==================*===================*====================*====================*===========\n");
printf("\n");
printf("\n");

printf("Entered Details Are : \n");
printf("\n");
printf(" PROCESS NAME\t BURST TIME\t ARRIVAL TIME\t\n");
printf("\n");
for(m=0;m<num;m++){
printf("| p%d\t |\t%f\t|\t%f\t|\n",p[m].name,p[m].burstTime,p[m].arrivalTime);
}
printf("\n");
printf("\n");
printf("==================*==============*=====================*======================*=====================*========\n");
printf("\n");
printf("\n");
struct process temp;
for(m=0;m<num-1;m++)
{
for(n=m+1;n<num;n++)
{
if(p[m].arrivalTime>p[n].arrivalTime){

temp=p[m];
p[m]=p[n];
p[n]=temp;
}
}
}
printf("\n");
printf("==========*===========*===============*=================*=============*=============*================*==========");
printf("\n");
printf("\n");
printf(" ========= EXECUTION ACCORDING TO THE GIVEN PRIORITY =========\n");
printf("\n");
float f,avgWaitingTime=0,avgTurnaroundTime=0;
printf("\n | PROCESS | BURST TIME | ARRIVAL TIME | WAITING TIME | TURN AROUND TIME | \n");
printf("\n");
for(f=p[0].arrivalTime;f<(float)sum;){
float pr=-12345;
int nxt;
float temp;
for(m=0;m<num;m++){

if(p[m].arrivalTime<=f && p[m].status!=1){
temp=1 + (f - p[m].arrivalTime) / p[m].burstTime;
if(pr<temp){

pr=temp;
nxt=m;
}
}
}

f=p[nxt].burstTime+f;

p[nxt].waitingTime=f-(p[nxt].arrivalTime)-(p[nxt].burstTime);

p[nxt].turnAroundTime=f-p[nxt].arrivalTime;

avgWaitingTime+=p[nxt].waitingTime;

avgTurnaroundTime+=p[nxt].turnAroundTime;

p[nxt].status=1;
printf("|    %d     |    %f    |     %f   | ",p[nxt].name,p[nxt].burstTime,p[nxt].arrivalTime);
printf("| %f | %f |\n",p[nxt].waitingTime,p[nxt].turnAroundTime);
}
printf("\n");
printf("=========*=============*=============*=================*===================*===================*===============*=======\n");
printf("\n");


printf("\n");

printf("Average Turn Around Time=%f\n",avgTurnaroundTime/num);

printf("\n");

printf("Average Waiting Time=%f\n",avgWaitingTime/num);

printf("\n");

printf("=============*============*====================*=================*=================*=============*===============\n");
}


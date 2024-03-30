//Round Robin with arrival_order
#include<stdio.h>
struct process{
    int num, exec_t, wait_t, turn_arnd_t, lst, prev_exec;
}p[20],temp;

void main(){
    int n, slice_t, i,j,rem,arr_o[20],g[100],lst, exec_t[20];
    float avg_wait_t, avg_turn_arnd_t;
    
    printf("Enter no.of processes: ");
    scanf("%d",&n);
    rem=n;
    for(i=0;i<n;i++)
    {
        p[i].num=i+1;
        printf("Execution time of P[%d]: ",i+1);
        scanf("%d",&p[i].exec_t);
    }
    printf("Enter arrival order:");
    for(i=0;i<n;i++){
        scanf("%d",&arr_o[i]);
        for(j=i;j<n;j++){
            if(arr_o[i]==p[j].num){
                temp=p[i], p[i]=p[j], p[j]=temp;
                exec_t[i]=p[i].exec_t;
                break;
            }
        }
    }
    printf("\nEnter slice time: ");
    scanf("%d",&slice_t);

    printf("\nArrival order:");
    for(i=0;i<n;i++){
        printf("%d\t",p[i].num);
    }
    for(i=0,j=0; rem!=0;){
        if(p[i].exec_t>slice_t){
            g[j++]=p[i].num;
            p[i].prev_exec+=slice_t;
            p[i].lst=lst;
            lst+=slice_t;
            p[i].exec_t-=slice_t;
        } 
        else if(p[i].exec_t<=slice_t && p[i].exec_t>0){
            g[j++]=p[i].num;
            p[i].lst=lst;
            p[i].wait_t= p[i].lst-p[i].prev_exec; //(lst-prev_exec)-arr_time
            p[i].turn_arnd_t=exec_t[i]+p[i].wait_t;
            lst+=p[i].exec_t;
            p[i].exec_t=0;
            rem--;
        }
        if(i==n-1)
            i=0;
        else
            i++;
    }
    
    printf("\n\nGantt Chart for the given,\n");
    for(i=0;i<j;i++)
        printf("%d -> ",g[i]);
    printf("end");
    printf("\n\nProcess\tExecution time\tWaiting time\tTurn_arnd time\n");
    for(i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\n",p[i].num,exec_t[i], p[i].wait_t, p[i].turn_arnd_t);
        avg_wait_t+=p[i].wait_t;
        avg_turn_arnd_t+=p[i].turn_arnd_t;
    }    
    avg_wait_t/=n;
    avg_turn_arnd_t/=n;
    printf("\nAverage Waiting time: %.2f\n,Average Turn Around Time: %.2f",avg_wait_t,avg_turn_arnd_t);
}

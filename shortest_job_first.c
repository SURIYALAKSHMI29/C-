 #include<stdio.h>
void main()
{
    int i,j, n=4,temp;
    float avg_wait_t, avg_turn_arnd_t;
    int p[]={1,2,3,4,}, arr_t[]={0,1,2,3}, exec_t[]={4,1,10,7}, wait_t[n], turn_arnd_t[n], comp_t[n];
    printf("The given Information is,\n");
    printf("Process\tArrival_Time\tloads\n");
    for(i=0;i<n;i++)
        printf("  P%d\t\t%d\t  %d\n",p[i],arr_t[i], exec_t[i]);
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(exec_t[j]>exec_t[j+1])
            {
                temp=exec_t[j], exec_t[j]=exec_t[j+1], exec_t[j+1]=temp;
                temp=arr_t[j], arr_t[j]=arr_t[j+1], arr_t[j+1]=temp;
                temp=p[j], p[j]=p[j+1], p[j+1]=temp;
            }
        }
    }
    
    wait_t[0]=0;
    printf("The order of process execution is,\n");
    for(i=0;i<n-1;i++)
    {
        printf("P%d->",p[i]);
        wait_t[i+1]=wait_t[i]+exec_t[i];
    }
    printf("P%d\n",p[i]);
    
    for(i=0;i<n;i++)
    {
        turn_arnd_t[i]=wait_t[i]+exec_t[i];
        comp_t[i]=turn_arnd_t[i]+arr_t[i];
        
        avg_turn_arnd_t+=turn_arnd_t[i];
        avg_wait_t+=wait_t[i];
    }
    avg_wait_t/=n;
    avg_turn_arnd_t/=n;
    
    printf("\nConclusion by SJF scheduling algorithm,\n");
    printf("Process\tArrival_time\tExecution_time\tWaiting_time\tCompletion_time\tTurn_around_Time\n");
    for(i=0;i<n;i++)
    {
        printf("  P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],arr_t[i],exec_t[i],wait_t[i],comp_t[i],turn_arnd_t[i]);
    }
    printf("\nAverage Turn around time: %.2f\nAverage Waiting time: %.2f",avg_turn_arnd_t,avg_wait_t);
}

#include<stdio.h>
void main()
{
    int i,j, n=5, temp;
    int p[5] = {1,2,3,4,5}, arr_t[5]={0,2,3,4,5};
    int wait_t[n], turn_arnd_t[n], exec_t[n], comp_t[n];
    float avg_wait_t, avg_turn_arnd_t;
    printf("The Information given,\n");
    for(i=0;i<n;i++)
        printf("P%d is arrived at %ds\n",p[i],arr_t[i]);
    printf("\nEnter the Execution time for 5 processes:\n");
    for(i=0;i<n;i++)
        scanf("%d",&exec_t[i]);
        
    //sorting thr processes based on the arriving time
    for(i=0;i<n;i++) 
    {
        for(j=0;j<n-1;j++)
        {
            if(arr_t[j]>arr_t[j+1])
            {
                temp=arr_t[j], arr_t[j]=arr_t[j+1], arr_t[j+1]=temp;
                temp=p[j], p[j]=p[j+1], p[j+1]=temp;
                temp=exec_t[j], exec_t[j]=exec_t[j+1], exec_t[j+1]=temp;
            }
        }
    }
    wait_t[0]=0;
    for(i=1;i<n;i++)
    {
       wait_t[i]=wait_t[i-1]+exec_t[i-1];
    }
  
    printf("\nThe order of process execution is,\n");
    for(i=0;i<n;i++)
    {
        turn_arnd_t[i]=wait_t[i]+exec_t[i];
        comp_t[i]=turn_arnd_t[i]+arr_t[i];
        avg_turn_arnd_t+=turn_arnd_t[i];
        avg_wait_t+=wait_t[i];
        printf("P%d\t",p[i]);
    }
    avg_wait_t/=n;
    avg_turn_arnd_t/=n;
    printf("\n\nConclusion by FCFS Algorithm,\n");
    printf("Process\t  Execution Time\tWaiting time\tCompletion time\tTurn Around time\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n",p[i],exec_t[i],wait_t[i],comp_t[i], turn_arnd_t[i]);
    }    
    printf("\nAverage Waiting Time: %.2f\n Average Turn around time: %.2f",avg_wait_t,avg_turn_arnd_t);
}

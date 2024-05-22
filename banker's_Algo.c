//Deadlock avoidance
//Bankers' algorithm

#include <stdio.h>

void main(){
    int avail_r[5], r_total[5], finish[5]; 
    int alloc[5][5], need[5][5], max[5][5];
    int p,r,i,j, seq[5], s=-1;
    
    printf("Enter no.of process: ");
    scanf("%d",&p);
    for(i=0; i<p;i++)
            finish[i]=0;
    printf("Enter no.of Resources: ");
    scanf("%d",&r);
    for(i=0; i<r;i++){
        printf("Resource %d Instances:",i+1);
        scanf("%d",&r_total[i]);
    }
    printf("\nEnter allocation matrix:\n");
    for(i=0;i<p;i++){
        for(j=0;j<r;j++){
            scanf("%d",&alloc[i][j]);
        }
        printf("\n");
    }
    
    printf("Enter maximum need matrix:\n");
    for(i=0;i<p;i++){
        for(j=0;j<r;j++)
            scanf("%d",&max[i][j]);
    }
    for(i=0;i<p;i++){
        for(j=0;j<r;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    
    printf("\nEnter resources availability...\n");
    for(i=0;i<r;i++){
        printf("Resource %d: ",i+1);
        scanf("%d",&avail_r[i]);
    }
    // if resources available value is not given, avail_r= r_total- sum(allocated)
    int flag=0;
    for(int k=0;k<20;k++){
        for(i=0;i<p;i++){
            if(finish[i]==0){
                int ref=1;
                for(j=0;j<r;j++){
                    if(need[i][j]>avail_r[j])
                    {
                        ref=0;
                        break;
                    }
                }
                if(ref==1){
                    seq[++s]=i+1;
                    finish[i]=1;
                    for(j=0;j<r;j++)
                        avail_r[j]+=alloc[i][j];
                }
            }
        }
    }

    for(i=0;i<p;i++){
        if(finish[i]==0){
            printf("The system may undergo deadlock situation");
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("\nThe system executes all the process safely!\nSafe Sequence: ");
        for(i=0;i<p-1;i++)
            printf("%d ->",seq[i]);
        printf("%d\n",seq[i]);
        printf("Resources availability\n");
        for(j=0;j<r;j++)
        printf("Resource %d: %d\n",j+1,avail_r[j]);
    }
}

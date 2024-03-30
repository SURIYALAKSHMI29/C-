#include<stdio.h>
#include<stdlib.h>

int i,j,temp,max=0, c[3]={0,0,0};

void line();
void sort(int a[], int b[], int m);
void first_fit(int p[], int size[], int n, int m);
void best_fit(int p[], int size[], int ord[], int n, int m);
void worst_fit(int p[], int size[], int ord[], int n, int m);

void main(){
    int n,m;
    printf("Enter no.of process:");
    scanf("%d",&n);
    printf("Enter no.of memory partitions:");
    scanf("%d",&m); 
    int p[n],ord[m], size[m];
    printf("\nEnter the process(in KBs)..\n");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    printf("\nEnter memory sizes (in KBs)..\n");
    for(i=0;i<m;i++){
        scanf("%d",&size[i]);
        ord[i]=(i+1);
    }
    line();
    first_fit(p, size,n,m);
    
    line();
    worst_fit(p,size, ord,n,m);
    
    line();
    best_fit(p, size, ord, n,m);
    
    line();
    if(c[0]==c[1] && c[1]==c[2])
        printf("\nIn this case, all the algorithms are efficient!As they allocated equal no.of processes.\n");
    else if(c[0]==c[1])   
        printf("\n In this case, both first & best-fit algorithm are efficient! As they allocated equal no.of processes.\n");
    else
        printf("\nIn this case and ");
    printf("in general, Best-Fit Algorithm is the most efficient algorithm.");
}

void line(){
    printf("\n");
    for(i=0;i<20;i++)
        printf("*****");
    printf("\n");
}
void first_fit(int p[], int s[], int n, int m){
    int f=0;
    int size[m];
    
    for(i=0;i<m;i++)
        size[i]=s[i];

    printf("\nFIRST FIT ALGORITHM\n\n");
    printf(" Process_No.\t Process_Size\t   Allocated_at(mem)   \tRemaining_memory\n\n");
    for(i=0;i<n;i++){
        f=0;
        for(j=0;j<m;j++){
            if(p[i]<=size[j])
            {
                f=1;
                printf("\t%d\t\t%d KB\t\t%d - %d KB \t\t%d\n",(i+1),p[i],(j+1),size[j],size[j]-p[i]);
                size[j]-=p[i];
                c[0]++;
                break;
            }
        }
        if(f==0){
            printf("\t%d\t\t%d KB\t\tNOT ALLOCATED\n",(i+1),p[i]);
        }
    }
}

void best_fit(int p[], int s[],  int ord[], int n, int m){
    int f=0,num;
    int size[m];
    for(i=0;i<m;i++)
        size[i]=s[i];
    
    printf("\nBEST FIT ALGORITHM\n\n");
    printf(" Process_No.\t Process_Size\t   Allocated_at(mem)   \tRemaining_memory\n\n");
    for(i=0;i<n;i++){
        f=0;
        sort(size,ord,m);
        for(j=0;j<m;j++){
            if(p[i]<=size[j])
            {
                f=1;
                printf("\t%d\t\t%d KB\t \t%d - %d KB\t\t %d\n",(i+1),p[i],ord[j],size[j],size[j]-p[i]);
                size[j]-=p[i];
                c[1]++;
                break;
            }
        }
        if(f==0){
            printf("\t%d\t\t%d KB\t\tNOT ALLOCATED\n",(i+1),p[i]);
         }
    }
}


void worst_fit(int p[], int s[],  int ord[], int n, int m){
    int f=0,k;
    int size[m];
    for(i=0;i<m;i++)
        size[i]=s[i];
    printf("\nWORST FIT ALGORITHM\n\n");
    printf(" Process_No.\t Process_Size\t   Allocated_at(mem)   \tRemaining_memory\n\n");
    for(i=0;i<n;i++){
        f=0, max=0;
        for(j=0;j<=m;j++){
            if(max<size[j]){
                max=size[j];
                k=j;
            }
        }
        if(p[i]<=size[k]){
                f=1;
                printf("\t%d\t\t%d KB\t \t%d - %d KB\t\t %d\n",(i+1),p[i],ord[k],size[k],size[k]-p[i]);
                size[k]-=p[i];
                c[2]++;
        }
        if(f==0){
            printf("\t%d\t\t%d KB\t\tNOT ALLOCATED\n",(i+1),p[i]);
         }
    }
}

void sort(int size[], int ord[], int m){
    for(int x=0;x<m;x++){
        for(int y=x+1;y<m;y++){
            if(size[y]<size[x]){
                temp=size[x], size[x]=size[y], size[y]=temp;
                temp=ord[x], ord[x]=ord[y], ord[y]=temp;
            }
        }
    }
}

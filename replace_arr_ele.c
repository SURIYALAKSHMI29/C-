/* Given an array arr[] of N integers and replace every element with the
least greater element on its right side in the array. 
If there are no greater elements on the right side, replace it with -1. 
*/

#include <stdio.h>
void main()
{
    int arr[]={7,15,9,17,36,49,37}, n=7, i,j,k,min,cpy;
    for(i=0;i<n;i++){
        min=arr[i], cpy=arr[i];
        for(j=i+1;j<n;j++){
            if(min<arr[j]){
                min=arr[j];
                break;
            }
        }
        
        for(k=j;k<n;k++){
            if(min>arr[k] && arr[i]<arr[k])
                min=arr[k];
        }
        
        arr[i]=min;
        if(arr[i]==cpy)
            arr[i]= -1;
    }
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
}

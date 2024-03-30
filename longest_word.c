/*
In this program, we need to find the largest word present in the string and it's length of the word.
(Hackerrank problem)
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char str[200],word[20],big[20];
    int i,j=-1,count=0;
    scanf("%[^\n]",str);
    for(i=0;i<=strlen(str);i++)
    {   
        if(!isspace(str[i]) && str[i]!='\0'){
                word[++j]=str[i];
        }
        else{
            word[++j]='\0';
            if(count<strlen(word)){
                count=strlen(word);
                strcpy(big,word);
            }
            j=-1;
        }
    }
    printf("%s\n",big);
    printf("%d",count);
    return 0;
}

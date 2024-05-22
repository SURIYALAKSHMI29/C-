// fcfs disk scheduling

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, totalSeekTime = 0;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int requests[n];

    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("The head position moves as,\n%d",head);
    // Calculate total seek time
    for (int i = 0; i < n; i++) {
        totalSeekTime += abs(head - requests[i]);
        head = requests[i];
        printf("->%d",head);
    }
    
    printf("\nTotal seek time: %d\n", totalSeekTime);
    
    return 0;
}

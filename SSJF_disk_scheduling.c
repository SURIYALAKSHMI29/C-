//Disk management-ssjf

#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, head, sstf_seek_count = 0;

    printf("Enter the number of requests: ");
    scanf("%d", &size);

    int requests[size];

    printf("Enter the request sequence: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &requests[i]);

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    int visited[size];
    for (int i = 0; i < size; i++)
        visited[i] = 0;
    
    printf("The head position moves as,\n%d",head);
    
    // Calculate total seek operations for SSTF
    int current = head;
    for (int i = 0; i < size; i++) {
        int min_distance = 10000;
        int min_index;

        for (int j = 0; j < size; j++) {
            if (!visited[j] && abs(requests[j] - current) < min_distance) {
                min_index = j;
                min_distance = abs(requests[j] - current);
            }
        }

        visited[min_index] = 1;
        sstf_seek_count += min_distance;
        current = requests[min_index];
        printf("-> %d",current);
    }

    // Output result
    printf("\nTotal number of seek operations for SSTF: %d\n", sstf_seek_count);

    return 0;
}

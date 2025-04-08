#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[20], n, head, i, j, seek = 0, max, diff;
    int queue1[20], queue2[20], temp, temp1 = 0, temp2 = 0;
    float avg;

    printf("Enter the max range of disk: ");
    scanf("%d", &max);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk positions to be read:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (temp >= head) {
            queue1[temp1++] = temp;
        } else {
            queue2[temp2++] = temp;
        }
    }

    
    for (i = 0; i < temp1 - 1; i++) {
        for (j = i + 1; j < temp1; j++) {
            if (queue1[i] > queue1[j]) {
                temp = queue1[i];
                queue1[i] = queue1[j];
                queue1[j] = temp;
            }
        }
    }

    
    for (i = 0; i < temp2 - 1; i++) {
        for (j = i + 1; j < temp2; j++) {
            if (queue2[i] > queue2[j]) {
                temp = queue2[i];
                queue2[i] = queue2[j];
                queue2[j] = temp;
            }
        }
    }

    
    int index = 0;
    queue[index++] = head;

    for (i = 0; i < temp1; i++)
        queue[index++] = queue1[i];
    queue[index++] = max - 1;  
    queue[index++] = 0;        

    for (i = 0; i < temp2; i++)
        queue[index++] = queue2[i];

    for (i = 0; i < index - 1; i++) {
        diff = abs(queue[i + 1] - queue[i]);
        seek += diff;
        printf("Disk head moves from %d to %d with seek %d\n", queue[i], queue[i + 1], diff);
    }

    printf("Total seek time is %d\n", seek);
    avg = (float)seek / n;
    printf("Average seek time is %.2f\n", avg);

    return 0;
}

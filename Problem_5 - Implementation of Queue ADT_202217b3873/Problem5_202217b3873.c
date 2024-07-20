#include <stdio.h>

#define n 5

int main() {
    int queue[n], ch = 1, front = 0, rear = 0, i, j = 1;

    printf("Queue using Array");
    printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Exit");

    while (ch) {
        printf("\nEnter the Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (rear == n) {
                    printf("\nQueue is Full");
                } else {
                    printf("\nEnter no %d: ", j++);
                    scanf("%d", &queue[rear++]);
                }
                break;
            case 2:
                if (front == rear) {
                    printf("\nQueue is Empty");
                } else {
                    printf("\nDeleted Element is %d", queue[front++]);
                }
                break;
            case 3:
                if (front == rear) {
                    printf("\nQueue is Empty");
                } else {
                    printf("\nQueue Elements are:\n");
                    for (i = front; i < rear; i++) {
                        printf("%d ", queue[i]);
                    }
                    printf("\n");
                }
                break;
            case 4:
                printf("\nExiting...");
                return 0;
            default:
                printf("\nWrong Choice: Please see the options");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define MS 10

int Queue[MS];
int FRONT = 0;
int REAR = -1;

void ENQUEUE() {
    int ele;
    if ((FRONT == (REAR + 1) % MS) && REAR > -1) {
        printf("\nQueue is full");
    } else {
        printf("\nEnter element to add in the queue: ");
        scanf("%d", &ele);
        REAR = (REAR + 1) % MS;
        Queue[REAR] = ele;
        printf("%d inserted successfully\n", ele);
    }
}

void DEQUEUE() {
    if (FRONT == 0 && REAR == -1) {
        printf("\nQueue is empty");
    } else {
        printf("\n%d is removed from Queue", Queue[FRONT]);
        FRONT = (FRONT + 1) % MS;

        // Reset when queue becomes empty
        if (FRONT == (REAR + 1) % MS) {
            FRONT = 0;
            REAR = -1;
        }
    }
}

void is_empty() {
    if (FRONT == 0 && REAR == -1) {
        printf("\nQueue is empty");
    } else {
        printf("\nQueue is not empty");
    }
}

void is_full() {
    if ((FRONT == (REAR + 1) % MS) && REAR > -1) {
        printf("\nQueue is full");
    } else {
        printf("\nQueue is not full");
    }
}

int main() {
    int ch;
    while (1) {
        printf("\n-----MENU-----");
        printf("\n1 - ENQUEUE OPERATION");
        printf("\n2 - DEQUEUE OPERATION");
        printf("\n3 - is_empty");
        printf("\n4 - is_full");
        printf("\n5 - Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: ENQUEUE(); break;
            case 2: DEQUEUE(); break;
            case 3: is_empty(); break;
            case 4: is_full(); break;
            case 5: exit(0);
            default: printf("\nInvalid choice");
        }
    }
}

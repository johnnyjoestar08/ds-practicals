#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;

};
struct node *last = NULL;


void insert(int value){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    if(last==NULL){
        last = newNode;
        newNode->next = last;}

    else{
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;

        }
printf("%d inserted\n", value);}

void deleteNode(){
    struct node *temp;
    if(last==NULL){
        printf("List is empty\n");
        return;
    }

    temp = last->next;
    if(temp == last){
        last = NULL;
    }
    else{
        temp->next = last->next;
    }
    printf("%d deleted\n", temp->data);
    free(temp);
    }
void display() {
    struct node *temp;

    if (last == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = last->next;  

    printf("Circular Linked List: ");

    do{
        printf("%d -> ", temp ->data);
        temp = temp->next;
    } 
    while (temp != last->next);
    printf("first node\n");
}

int main() {
    int choice, value;

    while (1){
        printf("\n Circular Linked List \n");

        printf("1. Insert\n");

        printf("2. Delete\n");

        printf("3. Display\n");

        printf("4. Exit\n");

        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                deleteNode();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct queue
{
    struct node* front, *rear;
};

void initialize(struct queue *q){
    q->front = NULL;
    q->rear = NULL;
}

int is_empty(struct queue *q){
    return (q->front == NULL && q->rear==NULL);
}

void insertq(struct queue *q, int x){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;
    if(q->rear==NULL){
        q->front = p;
        q->rear = p;
    }
    else{
        q->rear->next = p;
        q->rear = p;
    }
}

int deleteq(struct queue *q){
    if(is_empty(q)){
        printf("Queue is empty\n");
        return __INT_MAX__;
    }
    int x = q->front->data;
    struct node* p = q->front;
    q->front = q->front->next;
    if(q->front==NULL) q->rear = NULL;
    free(p);
    return x;
}

void printq(struct queue *q){
    struct node* p = q->front;
    while(p!=NULL){
        printf("%4d", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    struct queue q;
    initialize(&q);
    while(1){
        printf("1. Insert\n2. Delete\n3. Display All\n4.Exit\n");
        printf("Enter choice: ");
        int x;
        scanf("%d",&x);
        if(x==1){
            int y;
            scanf("%d", &y);
            insertq(&q, y);
        }
        else if(x==2){
            int y = deleteq(&q);
            if(y!=__INT_MAX__){
                printf("Element at front %4d, is deleted\n", y);
            }
        }
        else if(x==3){
            printq(&q);
        }
        else if(x==4){
            break;
        }
        else{
            printf("Invalid Input\n");
        }
    }
}

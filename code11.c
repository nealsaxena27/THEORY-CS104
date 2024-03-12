# include <stdio.h>
# define MAX_SIZE 1000

struct queue
{
    int a[MAX_SIZE];
    int front, rear;
};

void initialize(struct queue *q){
    q->front = 0;
    q->rear = 0;
}

int is_full(struct queue *q){
    return ((q->rear + 1)%MAX_SIZE == q->front);
}

int is_empty(struct queue *q){
    return (q->front == q->rear);
}

void insertq(struct queue *q, int x){
    if(is_full(q)){
        printf("Queue is full\n");
        return;
    }
    q->a[q->rear] = x;
    q->rear = (q->rear + 1)%MAX_SIZE;
}

int deleteq(struct queue *q){
    if(is_empty(q)){
        printf("Queue is empty\n");
        return __INT_MAX__;
    }
    int x = q->a[q->front];
    q->front = (q->front + 1)%MAX_SIZE;
    return x;
}

void printq(struct queue *q){
    int start = q->front, end = q->rear;
    for (int i = start; i < end; i++)
    {
        printf("%4d", q->a[i]);
    }
    printf("\n");
}

int main(){
    struct queue *q;
    initialize(q);
    while(1){
        printf("1. Insert\n2. Delete\n3. Display All\n 4.Exit\n");
        printf("Enter choice: ");
        int x;
        scanf("%d",&x);
        if(x==1){
            int y;
            scanf("%d", &y);
            insertq(q, y);
        }
        else if(x==2){
            int y = deleteq(q);
            if(y!=__INT_MAX__){
                printf("Element at front %4d, is deleted\n", y);
            }
        }
        else if(x==3){
            printq(q);
        }
        else if(x==4){
            break;
        }
        else{
            printf("Invalid Input\n");
        }
    }
}

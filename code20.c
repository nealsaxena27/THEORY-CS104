# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct stack
{
    struct node* top;
};

void initialize(struct stack *st){
    st->top = NULL;
}

int is_empty(struct stack *st){
    return (st->top == NULL);
}

void push(struct stack *st, int x){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data = x;
    p->next = st->top;
    st->top = p;
}

int pop(struct stack *st){
    if(is_empty(st)){
        printf("Stack is empty, Underflow\n");
        return __INT_MAX__;
    }
    int x = st->top->data;
    struct node* p = st->top;
    st->top = st->top->next;
    free(p);
    return x;
}

void printst(struct stack *st){
    struct node* p = st->top;
    while(p!=NULL)
    {
        printf("%4d", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    struct stack st;
    initialize(&st);
    while(1){
        printf("1. Push\n2. Pop\n3. Display All\n4.Exit\n");
        printf("Enter choice: ");
        int x;
        scanf("%d",&x);
        if(x==1){
            int y;
            scanf("%d", &y);
            push(&st, y);
        }
        else if(x==2){
            int y = pop(&st);
            if(y!=__INT_MAX__){
                printf("Element at front %4d, is deleted\n", y);
            }
        }
        else if(x==3){
            printst(&st);
        }
        else if(x==4){
            break;
        }
        else{
            printf("Invalid Input\n");
        }
    }
}

# include <stdio.h>
# define MAX_SIZE 1000

struct stack
{
    int a[MAX_SIZE];
    int top;
};

void initialize(struct stack *st){
    st->top = -1;
}

int is_full(struct stack *st){
    return (st->top == (MAX_SIZE - 1));
}

int is_empty(struct stack *st){
    return (st->top == -1);
}

void push(struct stack *st, int x){
    if(is_full(st)){
        printf("Stack is full, Overflow\n");
        return;
    }
    st->top++;
    st->a[st->top] = x;
}

int pop(struct stack *st){
    if(is_empty(st)){
        printf("Stack is empty, Underflow\n");
        return __INT_MAX__;
    }
    int x = st->a[st->top];
    st->top--;
    return x;
}

void printst(struct stack *st){
    int start = st->top;
    for (int i = start; i >= 0; i--)
    {
        printf("%4d", st->a[i]);
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

# include <stdio.h>
# include <string.h>
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

float valueof(char c){
    switch (c)
    {
    case 'a':
        return 5.2;
    case 'b':
        return 6.4;
    case 'c':
        return 1.5;
    case 'd':
        return 2.8;
    case 'e':
        return 4.0;
    }
}

float compute(float op1, float op2, char operator){
    switch (operator)
    {
    case '+':
        return op1 + op2;    
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    }
}

int is_operand(char c){
    return (c >= 'a' && c <= 'z');
}

int is_operator(char c){
    return (c=='+' || c=='-' || c=='*' || c =='/');
}

float evaluate_postfix(char postfix[]){
    struct stack s;
    initialize(&s);
    int i = 0;
    while(postfix[i]!='\0'){
        if(is_operand(postfix[i])){
            push(&s,valueof(postfix[i]));
        }
        else if(is_operator(postfix[i])){
            if(is_empty(&s)) return __INT_MAX__;
            float op2 = pop(&s);
            if(is_empty(&s)) return __INT_MAX__;
            float op1 = pop(&s);
            float result = compute(op1, op2, postfix[i]);
            push(&s, result);
        }
        else return __INT_MAX__;
        i++;
    }
    if(s.top!=0) return __INT_MAX__;
    return (pop(&s));
}

int main(){
    char postfix[MAX_SIZE];
    printf("Enter postfix expression:\n");
    scanf("%s", &postfix);
    float ans = evaluate_postfix(postfix);
    if(ans==__INT_MAX__){
        printf("Invalid Postfix Expression\n");
    }
    else{
        printf("Result of given postfix expression is %5.4f\n", ans);
    }
}
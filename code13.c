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

int stacktop(struct stack *st){
    if(!is_empty(st)) return st->a[st->top];
}

int is_operand(char c){
    return (c >= 'a' && c <= 'z');
}

int is_operator(char c){
    return (c=='+' || c=='-' || c=='*' || c =='/');
}

int priority(char x){
    switch (x)
    {
    case '\0':
        return -1;
    case '(':
        return 0;
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    }
}

void convert_infix_to_postfix(char infix[], char postfix[]){
    struct stack s;
    initialize(&s);
    int i = 0, j = 0;
    push(&s, '\0');
    while(infix[i]!='\0'){
        if(is_operand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else if(is_operator(infix[i])){
            while(priority(stacktop(&s)) >= priority(infix[i])){
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i++]);
        }
        else if(infix[i]=='('){
            push(&s, infix[i++]);
        }
        else if(infix[i]==')'){
            char x;
            do{
                x = pop(&s);
                if(x!='(') postfix[j++] = x;
            } while(x!='(');
            i++;
        }
    }

    while(!is_empty(&s)){
        postfix[j++] = pop(&s);
    }
}

void print_expression(char s[]){
    int i = 0;
    while(s[i]!='\0'){
        printf("%c", s[i++]);
    }
    printf("\n");
}

int main(){
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter infix expression:\n");
    scanf("%s", &infix);
    convert_infix_to_postfix(infix, postfix);
    printf("Postfix expression is:\n");
    print_expression(postfix);
}
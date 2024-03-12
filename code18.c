# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void insert_x(struct node **s, int x){
    struct node * p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;
    if(*s==NULL){
        *s = p;
    }
    else if((*s)->data >= x){
        p->next = (*s);
        *s = p;
    }
    else{
        struct node* q = *s;
        while(q->next!=NULL && q->next->data < x){
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
    }
}

void delete_x(struct node **s, int x){
    if(*s==NULL) return;
    if((*s)->data==x){
        struct node* p = *s;
        *s = (*s)->next;
        free(p);
        return;
    }
    struct node *q = *s;
    while(q->next != NULL && q->next->data != x){
        q = q->next;
    }
    if(q->next==NULL) return;
    struct node* p = q->next;
    q->next = q->next->next;
    free(p);
}

struct node* search_x(struct node *s, int x){
    struct node *q = s;
    while(q!=NULL){
        if(q->data==x){
            return q;
        }
        q = q->next;
    }
    return NULL;
}

void display_all(struct node* s){
    struct node *q = s;
    while(q!=NULL){
        printf("%4d", q->data);
        q = q->next;
    } 
    printf("\n");  
}

int main(){
    struct node* start = NULL;
    while(1){
        printf("1. Insert x\n2. Delete x\n3. Search x\n4. Display All\n5. Exit\n");
        printf("Enter choice: ");
        int ch;
        scanf("%d",&ch);
        if(ch==1){
            int x;
            printf("Enter x: ");
            scanf("%d", &x);
            insert_x(&start, x);
        }
        else if(ch==2){
            int x;
            printf("Enter x: ");
            scanf("%d", &x);
            delete_x(&start, x);
        }
        else if(ch==3){
            int x;
            printf("Enter x: ");
            scanf("%d", &x);
            struct node* address = search_x(start, x);
            if(address==NULL){
                printf("x not found in linked list\n");
            }
            else{
                printf("x found at %p\n", address);
            }
        }
        else if(ch==4){
            display_all(start);
        }
        else if(ch==5){
            break;
        }
        else{
            printf("Invalid Input\n");
        }
    }
}

# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void insert_at_beginning(struct node **s, int x){
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    if(p==NULL){
        printf("Memory Full\n");
        return;
    }
    p->data = x;
    p->next = *s;
    *s = p;
}

void insert_at_end(struct node **s, int x){
    struct node *p, *q;
    p = (struct node*)malloc(sizeof(struct node));
    if(p==NULL){
        printf("Memory Full\n");
        return;
    }
    p->data = x;
    p->next = NULL;
    if(*s == NULL){
        // empty linked list
        *s = p;
    }
    else{
        q = *s;
        while(q->next!=NULL){
            q = q->next;
        }
        q->next = p;
    }
}

void display(struct node *q){
    while(q!=NULL){
        printf("%6d", q->data);
        q = q->next;
    }
    printf("\n");
}

struct node* search(struct node *start, int x){
    struct node* q = start;
    while(q!=NULL){
        if(q->data==x) return q;
        q = q->next;
    }
    return NULL;
}

void deletex(struct node **s, int x){
    if(*s==NULL) return;
    struct node* q;
    if((*s)->data==x){
        q = *s;
        *s = (*s)->next;
        free(q);
        return;
    }
    q = *s;
    while(q->next!=NULL && q->next->data!=x){
        q = q->next;
    }
    if(q->next!=NULL){
        struct node* p;
        p = q->next;
        q->next = q->next->next;
        free(p);
    }
}

void insert_x_after_y(struct node *s, int x, int y){
    struct node* q = search(s, y);
    if(q==NULL) return;
    struct node* p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = x;
    p->next = q->next;
    q->next = p;
}

int main(){
    struct node* start = NULL;
    while(1){
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert x after y\n");
        printf("4. Display All\n 5.Search 6.Delete x\n 7.Exit\n");
        printf("Enter choice: ");
        int ch;
        scanf("%d",&ch);
        if(ch==1){
            int x;
            printf("Enter x: ");
            scanf("%d", &x);
            insert_at_beginning(&start, x);
        }
        else if(ch==2){
            int x;
            printf("Enter x: ");
            scanf("%d", &x);
            insert_at_end(&start, x);
        }
        else if(ch==3){
            int x, y;            
            printf("Enter x, y: ");
            scanf("%d %d", &x, &y);
            insert_x_after_y(start, x, y);
        }
        else if(ch==4){
            display(start);
        }
        else if(ch==5){
            int x;
            printf("Enter x: ");
            scanf("%d", &x);
            struct node* address = search(start, x);
            if(address==NULL){
                printf("x not found in linked list\n");
            }
            else{
                printf("x found at %p", address);
            }
        }
        else if(ch==6){
            int x;
            printf("Enter x: ");
            scanf("%d", &x);
            deletex(&start, x);
        }
        else if(ch==7){
            break;
        }
        else{
            printf("Invalid Input\n");
        }
    }
}

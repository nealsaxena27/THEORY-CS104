# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct headnode{
    struct node* start;
    struct node* end;
    int count;
};

void initialize(struct headnode *h1){
    h1->start = NULL;
    h1->end = NULL;
    h1->count = 0;
}

void insert_at_beginning(struct headnode *s, int x){
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    if(p==NULL){
        printf("Memory Full\n");
        return;
    }
    p->data = x;
    p->next = s->start;
    s->start = p;
    s->count++;
    if(s->end == NULL) s->end = p;
}

void insert_at_end(struct headnode *s, int x){
    struct node *p, *q;
    p = (struct node*)malloc(sizeof(struct node));
    if(p==NULL){
        printf("Memory Full\n");
        return;
    }
    p->data = x;
    p->next = NULL;
    s->count++;
    if(s->end==NULL){
        s->start = p;
        s->end = p;
    }
    else{
        s->end->next = p;
        s->end = p;
    }
}

void display(struct headnode s){
    struct node *q = s.start; 
    while(q!=NULL){
        printf("%6d", q->data);
        q = q->next;
    }
    printf("\n");
}

struct node* search(struct headnode s, int x){
    struct node* q = s.start;
    while(q!=NULL){
        if(q->data==x) return q;
        q = q->next;
    }
    return NULL;
}

void deletex(struct headnode *s, int x){
    if(s->start==NULL) return;
    struct node* q;
    if(s->start->data==x){
        q = s->start;
        s->start = s->start->next;
        free(q);
        s->count--;
        return;
    }
    q = s->start;
    while(q->next!=NULL && q->next->data!=x){
        q = q->next;
    }
    if(q->next!=NULL){
        struct node* p;
        p = q->next;
        q->next = q->next->next;
        s->count--;
        free(p);
    }
}

void insert_x_after_y(struct headnode *s, int x, int y){
    struct node* q = search(*s, y);
    if(q==NULL) return;
    struct node* p;
    p = (struct node*)malloc(sizeof(struct node));
    s->count++;
    p->data = x;
    p->next = q->next;
    q->next = p;
    if(p->next==NULL){
        s->end = p;
    }
}

int main(){
    struct headnode head;
    initialize(&head);
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
            insert_at_beginning(&head, x);
        }
        else if(ch==2){
            int x;
            printf("Enter x: ");
            scanf("%d", &x);
            insert_at_end(&head, x);
        }
        else if(ch==3){
            int x, y;            
            printf("Enter x, y: ");
            scanf("%d %d", &x, &y);
            insert_x_after_y(&head, x, y);
        }
        else if(ch==4){
            display(head);
        }
        else if(ch==5){
            int x;
            printf("Enter x: ");
            scanf("%d", &x);
            struct node* address = search(head, x);
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
            deletex(&head, x);
        }
        else if(ch==7){
            break;
        }
        else{
            printf("Invalid Input\n");
        }
    }
}

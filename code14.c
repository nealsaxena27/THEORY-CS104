# include <stdio.h>
# define MAX_SIZE 1000

void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void insert(int a[], int *s, int x){
    int n = *s;
    if(n==MAX_SIZE){
        printf("Heap is full\n");
        return;
    }
    a[n] = x;
    n++;
    *s = n;
    int i = n - 1;
    int parentindex = (i - 1)/2;
    while(parentindex >= 0 && a[parentindex] < a[i]){
        swap(a, parentindex, i);
        i = parentindex;
        parentindex = (i - 1)/2;
    }
}

int deletemax(int a[], int *s){
    if(*s==0){
        printf("Heap is empty\n");
        return __INT_MAX__;
    }
    int x = a[0];
    a[0] = a[*s - 1];
    *s = *s - 1;
    int i = 0;
    do
    {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int li = i;
        if(left < *s && a[left] > a[li]) li = left;
        if(right < *s && a[right] > a[li]) li = right;
        if(li != i){
            swap(a, li, i);
            i = li;
        }
    } while (1);
    return x;
}

int main(){
    int priority_queue[MAX_SIZE];
    int size = 0;
    while(1){
        printf("1. Insert\n2. Delete Max\n3.Exit\n");
        printf("Enter choice: ");
        int x;
        scanf("%d",&x);
        if(x==1){
            int y;
            scanf("%d", &y);
            insert(priority_queue, &size, y);
        }
        else if(x==2){
            int y = deletemax(priority_queue, &size);
            if(y!=__INT_MAX__){
                printf("Max element %4d, is deleted\n", y);
            }
        }
        else if(x==3){
            break;
        }
        else{
            printf("Invalid Input\n");
        }
    }
}

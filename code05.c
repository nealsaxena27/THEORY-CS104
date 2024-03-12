# include <stdio.h>
# define MAX_SIZE 100


int insertpos(int arr[], int size, int x){
    int pos = size, l = 0, r = size - 1;
    while(l<=r){
        int m = l + (r-l)/2;
        if(arr[m] > x){
            pos = m;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    return pos;
}

void insert(int arr[], int *size, int x){
    if(*size == MAX_SIZE){
        return;
    }
    int index = insertpos(arr, *size, x);
    for (int i = index + 1; i <= *size; i++)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = x;
    (*size)++;
}

int search(int arr[], int size, int x){
    int l = 0, r = size - 1;
    while(l<=r){
        int m = l + (r-l)/2;
        if(arr[m]==x){
            return m;
        }
        else if(arr[m]<x){
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    return -1;
}

int delete(int arr[], int *size, int x){
    int index = search(arr, *size, x);
    if(index==-1){
        return -1;
    }
    for (int i = index; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    return 0;
}

void update(int arr[], int *size, int x, int y){
    int found = delete(arr, size, x);
    if(found==-1){
        return;
    }
    insert(arr, size, y);
}

void printarray(int arr[], int n){
    printf("Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int choice, n = 0;
    int arr[MAX_SIZE];
    while (1)
    {   
        printf("1. Insert\n2. Delete\n3. Search\n4. Update\n5. Print All\n6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        if(choice==1){
            int x;
            scanf("%d", &x);
            insert(arr, &n, x);
        }   
        else if(choice==2){
            int x;
            scanf("%d", &x);
            delete(arr, &n, x);
        }
        else if(choice==3){
            int x;
            scanf("%d", &x);
            printf("%d\n",search(arr, n, x));
        }
        else if(choice==4){
            int x, y;
            scanf("%d %d", &x, &y);
            update(arr, &n, x, y);
        }
        else if(choice==5){
            printarray(arr, n);
        }
        else if(choice==6){
            break;
        }
        else{
            printf("Invalid Input\n");
        }
    }
}
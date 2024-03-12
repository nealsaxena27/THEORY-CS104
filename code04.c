# include <stdio.h>
# define MAX_SIZE 100

void insert(int arr[], int *size, int x){
    if(*size < MAX_SIZE){
        arr[*size] = x;
        (*size)++;
    }
}

int search(int arr[], int size, int x){
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==x){
            index = i;
            break;
        }
    }
    return index;
}

void delete(int arr[], int *size, int x){
    int index = search(arr, *size, x);
    if(index==-1){
        return;
    }
    for (int i = index; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void update(int arr[], int size, int x, int y){
    int index = search(arr, size, x);
    if(index==-1){
        return;
    }
    arr[index] = y;
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
            update(arr, n, x, y);
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
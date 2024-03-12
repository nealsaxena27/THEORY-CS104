# include <stdio.h>

void inputarray(int arr[], int n){
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
}

void printarray(int arr[], int n){
    printf("Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heapify(int arr[], int n, int i){
    int li = i, left = 2*i + 1, right = 2*i + 2;
    if(left < n && arr[left] > arr[li]){
        li = left;
    }
    if(right < n && arr[right] > arr[li]){
        li = right;
    } 
    if(li!=i){
        swap(arr, li, i);
        heapify(arr, n, li);
    }
}

void make_heap(int arr[], int n){
    for (int i = n/2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void delete_max(int arr[], int n){
    swap(arr, 0, n - 1);
    heapify(arr,n-1, 0);
}

void heapsort(int arr[], int n){
    make_heap(arr,n);
    for (int i = n; i > 1; i--)
    {
        delete_max(arr,i);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    inputarray(arr,n);
    heapsort(arr,n);
    printarray(arr,n);
}
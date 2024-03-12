# include <stdio.h>

void swap(int *a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

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

int partition(int arr[], int low, int high){
    int i = low, j = high, pivot = arr[low];
    while (i < j)
    { 
        while (arr[i]<=pivot && i<high)
        {
            i++;
        }
        while (arr[j]>pivot && j>low)
        {
            j--;
        }
        if(i<j){
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quicksort(int arr[], int low, int high){
    if(low<high){
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot-1);
        quicksort(arr, pivot+1, high);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    inputarray(arr,n);
    quicksort(arr,0,n-1);
    printarray(arr,n);
}
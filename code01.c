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

void shellsort(int arr[], int n){
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;
            while(j>=gap && arr[j-gap]>temp){
                arr[j] = arr[j-gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    inputarray(arr,n);
    shellsort(arr,n);
    printarray(arr,n);
}
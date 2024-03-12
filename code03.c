# include <stdio.h>
# include <string.h>

struct student
{
    int rollno;
    char name[10];
    int marks;
};

typedef struct student student;

void swap(student *a, student *b){
    student temp = *a;
    *a = *b;
    *b = temp;
}

void inputarray(student arr[], int n){
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s %d",&arr[i].rollno, arr[i].name, &arr[i].marks);
    }
}

void printarray(student arr[], int n, int mode){
    if(mode==1){
        printf("List of Students Sorted By Marks:\n");
    }
    else if(mode==2){
        printf("List of Students Sorted By Name:\n");
    }
    for (int i = 0; i < n; i++)
    {
        printf("%3d %10s %3d\n", arr[i].rollno, arr[i].name, arr[i].marks);
    }
}

int partition_marks(student arr[], int low, int high){
    int i = low, j = high, pivot = arr[low].marks;
    while (i < j)
    { 
        while (arr[i].marks<=pivot && i<high)
        {
            i++;
        }
        while (arr[j].marks>pivot && j>low)
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

int partition_name(student arr[], int low, int high){
    int i = low, j = high;
    char* pivot = arr[low].name;
    while (i < j)
    { 
        while (strcmp(arr[i].name,pivot)<=0 && i<high)
        {
            i++;
        }
        while (strcmp(arr[j].name,pivot)>0 && j>low)
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

void sortstudents(student arr[], int low, int high, int mode){
    if(mode==1){
        if(low<high){
            int pivot = partition_marks(arr, low, high);
            sortstudents(arr, low, pivot-1, mode);
            sortstudents(arr, pivot+1, high, mode);
        }
    }
    else if(mode==2){
        if(low<high){
            int pivot = partition_name(arr, low, high);
            sortstudents(arr, low, pivot-1, mode);
            sortstudents(arr, pivot+1, high, mode);
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    student arr[n];
    inputarray(arr,n);
    sortstudents(arr,0,n-1,1); // sort by marks
    printarray(arr,n,1);
    sortstudents(arr,0,n-1,2); // sort by name
    printarray(arr,n,2);
}
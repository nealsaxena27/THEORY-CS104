# include <stdio.h>
# define MAX_SIZE 100

struct sparse_matrix
{
    int rno;
    int cno;
    int val;
};

typedef struct sparse_matrix sparse_matrix;

void read_sparse_matrix(sparse_matrix mat[]){
    int m, n;
    printf("Enter m, n : ");
    scanf("%d %d", &m, &n);
    mat[0].rno = m; mat[0].cno = n;
    int k = 1;
    printf("Enter the matrix:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            scanf("%d", &x);
            if(x!=0){
                mat[k].rno = i;
                mat[k].cno = j;
                mat[k].val = x;
                k++;
            }
        }
    }
    mat[0].val = k - 1;
}

void print_sparse_matrix(sparse_matrix mat[]){
    int rows = mat[0].rno;
    int cols = mat[0].cno;
    int size = mat[0].val;
    int k = 1;
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(k <= size && i==mat[k].rno && j==mat[k].cno){
                printf("%6d",mat[k++].val);
            }
            else{
                printf("%6d",0);
            }
        }
        printf("\n");
    }
}

void add_sparse_matrix(sparse_matrix mat1[], sparse_matrix mat2[], sparse_matrix mat3[]){
    int size1 = mat1[0].val, size2 = mat2[0].val;
    int l = 1, r = 1, k = 1;
    while(l <= size1 && r <= size2){
        if(mat1[l].rno==mat2[r].rno && mat1[l].cno==mat2[r].cno){
            if(mat1[l].val + mat2[r].val != 0){
                mat3[k].rno = mat1[l].rno;
                mat3[k].cno = mat1[l].cno;
                mat3[k].val = mat1[l].val + mat2[r].val;
                k++;
            }
            l++; r++;
        }
        else if((mat1[l].rno < mat2[r].rno) || (mat1[l].rno==mat2[r].rno && mat1[l].cno < mat2[r].cno)){
            mat3[k].rno = mat1[l].rno;
            mat3[k].cno = mat1[l].cno;
            mat3[k].val = mat1[l].val;
            k++; l++;
        }
        else{
            mat3[k].rno = mat2[r].rno;
            mat3[k].cno = mat2[r].cno;
            mat3[k].val = mat2[r].val;
            k++; r++;
        }
    }
    while(l <= size1){
        mat3[k].rno = mat1[l].rno;
        mat3[k].cno = mat1[l].cno;
        mat3[k].val = mat1[l].val;
        k++; l++;
    }
    while(l <= size2){
        mat3[k].rno = mat2[r].rno;
        mat3[k].cno = mat2[r].cno;
        mat3[k].val = mat2[r].val;
        k++; r++;
    }
    mat3[0].rno = mat1[0].rno;
    mat3[0].cno = mat1[0].cno;
    mat3[0].val = k - 1;
}


int main(){
    sparse_matrix mat1[MAX_SIZE];
    sparse_matrix mat2[MAX_SIZE];
    read_sparse_matrix(mat1);
    read_sparse_matrix(mat2);
    print_sparse_matrix(mat1);
    print_sparse_matrix(mat2);
    sparse_matrix mat3[MAX_SIZE];
    add_sparse_matrix(mat1,mat2,mat3);
    print_sparse_matrix(mat3);
}
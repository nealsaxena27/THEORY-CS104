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

void transpose_sparse_matrix(sparse_matrix s[], sparse_matrix t[]){
    int k = s[0].cno, n = s[0].val;
    int c[k], m[k];
    for (int i = 0; i < k; i++)
    {
        c[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        c[s[i].cno]++;
    }
    m[0] = 1;
    for (int i = 1; i < k; i++)
    {
        m[i] = m[i-1] + c[i-1];
    }
    for (int i = 1; i <= n; i++)
    {
        int j = m[s[i].cno];
        t[j].rno = s[i].cno;
        t[j].cno = s[i].rno;
        t[j].val = s[i].val;
        m[s[i].cno]++;
    }
    t[0].rno = s[0].cno;
    t[0].cno = s[0].rno;
    t[0].val = s[0].val;
}


int main(){
    sparse_matrix mat1[MAX_SIZE];
    sparse_matrix mat2[MAX_SIZE];
    read_sparse_matrix(mat1);
    print_sparse_matrix(mat1);
    transpose_sparse_matrix(mat1, mat2);
    print_sparse_matrix(mat2);
}
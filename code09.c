# include <stdio.h>
# define MAX_SIZE 100

struct poly
{
    float coef;
    int expo;
};

void read_poly(struct poly p[], int *size){
    int n;
    printf("Enter n : ");
    scanf("%d", &n);
    *size = n;
    printf("Enter the polynomial (coef, expo) in decreasing order of powers:\n");
    for (int i = 0; i < n; i++)
    {
        float c;
        int e;
        scanf("%f %d", &c, &e);
        p[i].coef = c;
        p[i].expo = e;
    }
}

void print_poly(struct poly p[], int n){
    printf("Polynomial is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%4.2f * (x ^ %2d)", p[i].coef, p[i].expo);
        if(i < n - 1) printf(" + ");
    }
    printf("\n");
}

void add_poly(struct poly p1[], struct poly p2[], struct poly p3[], int s1, int s2, int *s3){
    int i = 0, j = 0, k = 0;
    while(i < s1 && j < s2){
        if(p1[i].expo==p2[j].expo){
            float sum_coef = p1[i].coef + p2[j].coef;
            if(sum_coef!=0){
                p3[k].coef = sum_coef;
                p3[k].expo = p1[i].expo;
                k++; i++; j++;
            }
            else{
                i++; j++;
            }
        }
        else if(p1[i].expo > p2[j].expo){
            p3[k].coef = p1[i].coef;
            p3[k].expo = p1[i].expo;
            k++; i++;
        }
        else{
            p3[k].coef = p2[j].coef;
            p3[k].expo = p2[j].expo;
            k++; j++;
        }
    }

    while(i < s1){
        p3[k].coef = p1[i].coef;
        p3[k].expo = p1[i].expo;
        k++; i++;
    }
    while(j < s2){
        p3[k].coef = p2[j].coef;
        p3[k].expo = p2[j].expo;
        k++; j++;
    }
    *s3 = k;
}

void mult_term(struct poly p1[], struct poly term, struct poly p2[], int s1){
    for (int i = 0; i < s1; i++)
    {
        p2[i].coef = term.coef * p1[i].coef;
        p2[i].expo = term.expo + p1[i].expo;
    }
}

void multiply_poly(struct poly p1[], struct poly p2[], struct poly p4[], int s1, int s2, int *s4){
    int s5 = s2, *s4 = 0, s6;
    struct poly p5[MAX_SIZE];
    struct poly p6[MAX_SIZE];
    for (int i = 0; i < s1; i++)
    {
        mult_term(p2, p1[i], p5, s2);
        add_poly(p4,p5,p6,*s4, s5, &s6);

        for (int j = 0; j < s6; j++)
        {
            p4[j].coef = p6[j].coef;
            p4[j].expo = p6[j].expo;
        }
        *s4 = s6;
    }
}

int main(){
    struct poly p1[MAX_SIZE];
    struct poly p2[MAX_SIZE];
    struct poly p3[MAX_SIZE];
    struct poly p4[MAX_SIZE];
    int size1, size2, size3, size4;
    read_poly(p1, &size1);
    read_poly(p2, &size2);
    add_poly(p1, p2, p3, size1, size2, &size3);
    print_poly(p3, size3);
    multiply_poly(p1, p2, p4, size1, size2, &size4);
    print_poly(p4, size4);
}
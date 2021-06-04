//前面是c代码，后面注释掉的部分是使用我们定义的文法写的代码
#include<stdio.h>
int main()
{
    int M_A, N_A;
    int M_B, N_B;
    int matrix_A[400], matrix_B[400];
    int size_A,size_B;
    int i,j,k;

    scanf ("%d %d",&M_A,&N_A);
    size_A = M_A * N_A;
    for (i = 0; i < size_A; i++)
        scanf("%d",&matrix_A[i]);

    

    scanf ("%d %d",&M_B,&N_B);
    size_B = M_B * N_B;
    for (i = 0; i < size_B; i++)
        scanf("%d",&matrix_B[i]);
    
    if(N_A != M_B)
    {
        printf("Incompatible Dimensions\n");
        return 0;
    }
    int temp = 0;
    for (i = 0; i < M_A; i++)
    {
        for (j = 0; j < N_B; j++)
        {
            temp = 0;
            for (k = 0; k < N_A; k++)
                temp = temp + matrix_A[i * N_A + k] * matrix_B[k * N_B + j];
            printf("%d ", temp);
        }
        printf("\n");
    }
        return 0;
}

/*================================================================
main ()
{
    Int M_A;
    Int N_A;
    Int M_B;
    Int N_B;
    Int matrix_A[400];
    Int matrix_B[400];
    Int i;
    Int j;
    Int k;


    scan(M_A);
    scan(N_A);
    Int size_A = M_A * N_A;
    for (i = 0; i < size_A; i = i+1)
    {
        scan(matrix_A[i]);
    }

    scan(M_B);
    scan(N_B);
    Int size_B = M_B * N_B;
    for(i = 0; i< size_B; i = i+1)
    {
        scan(matrix_B[i]);
    }

    if(N_A <> M_B)
    {
        print("Incompatible Dimensions\n");
        return;
    }
    
    Int temp = 0;
    for(i = 0; i < M_A; i = i+1)
    {
        for(j = 0; j < N_B; j = j+1)
        {
            temp = 0;
            for(k = 0; k < N_A; k = k+1)
            {
                temp = temp + matrix_A[i * N_A + k] * matrix_B[k * N_B + j];
            }
            print("%d ", temp);
        }
        print("\n");
    }

    return;
}


*/
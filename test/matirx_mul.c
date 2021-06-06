main ()
{
    int M_A;
    int N_A;
    int M_B;
    int N_B;
    int matrix_A[400];
    int matrix_B[400];
    int i;
    int j;
    int k;
    read(M_A);
    read(N_A);
    int size_A = M_A * N_A;
    for (i = 0; i < size_A; i = i+1)
    {
        read(matrix_A[i]);
    }
    read(M_B);
    read(N_B);
    int size_B = M_B * N_B;
    for(i = 0; i< size_B; i = i+1)
    {
        read(matrix_B[i]);
    }
    if(N_A <> M_B)
    {
        println("Incompatible Dimensions");
        return;
    }

    int temp = 0;
    for(i = 0; i < M_A; i = i+1)
    {
        for(j = 0; j < N_B; j = j+1)
        {
            temp = 0;
            for(k = 0; k < N_A; k = k+1)
            {
                temp = temp + matrix_A[i * N_A + k] * matrix_B[k * N_B + j];
            }
            print(temp," ");
        }
        println();
    }
    return;
}
main ()
{
    int M;
    int N;
    int i;
    int matrix_A[400];
    read("%d%d",M,N);
    int size_A = M * N;

    for (i = 0; i < size_A; i = i+1)
    {
        print("%4d:",i);
        read("%d",matrix_A[i]);
    }

    for (i = 0; i < size_A; i = i+1)
    {
        print("%4d",matrix_A[i]);
    }
    return;
}
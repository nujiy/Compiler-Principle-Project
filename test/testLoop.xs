main ()
{
    int i;
    for(i=1;i<5;i=i+1){
        int j = 5;
        while(j>1){
            print("%d ", j);
            j = j - 1;
        }
    }
    return 0;
}
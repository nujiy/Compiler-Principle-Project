int test(int a[],int i);
main ()
{
    int i;
    int a[10];
    for(i=0;i<10;i=i+1){
        test(a,i);
    }

    for(i=0;i<10;i=i+1){
        print("%d ",a[i]);
    }

    return;
}

int test(int a[],int i){
    int b = a[i];
    a[i] = i;
    return 0;
}
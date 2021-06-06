int a[10];
int test(int i);
main ()
{
    int i;

    for(i=0;i<10;i=i+1){
        test(i);
    }

    for(i=0;i<10;i=i+1){
        print("%d ",a[i]);
    }

    return;
}

int test(int i){
    print("%d ",i);
    a[i] = i;
    return 0;
}
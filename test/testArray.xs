main(){
    int i;
    int a[10];
    for(i = 0;i<10;i=i+1){
        a[i] = i;
    }
    for(i=0;i<10;i=i+2){
        print("%d ",a[i]);
    }
    return;
}
int testFunc(int a[]);
main(){
    int i;
    int a[10];
    for(i=0;i<10;i=i+1){
    	read("%d",a[i]);
    }
 
    testFunc(a);
    return 0;
}

int testFunc(int a[]){
    int i;
    for(i=0;i<10;i=i+1){
    	print("%d",a[i]);
    }
    return 0;
}
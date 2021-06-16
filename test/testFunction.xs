int testFunc(int a[],int low,int high);
main(){
    int i;
    int a[10];
    int low = 0;
    int high = 0;
    a[0] =10;
    for(i=0;i<10;i=i+1){
    	read("%d",a[i]);
    }
 
    testFunc(a,low,high);
    return 0;
}

int testFunc(int a[],int low,int high){
    int b = a[0];
    int i;
    for(i=0;i<10;i=i+1){
    	print("%d",a[i]);
    }
    return 0;
}
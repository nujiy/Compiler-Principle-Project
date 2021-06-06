int testFunc(int i);
main(){
    int i;
    for(i=0;i<5;i=i+1){
        testFunc(i);
    }
}

int testFunc(int i){
    print(i);
    return 0;
}
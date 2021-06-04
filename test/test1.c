int N = 10001;
int partition(int arr[], int low, int high);
void quickSort(int arr[], int start, int end);

main(){
    int i,j;
    int n;

    printf("QuickSort Test\n");
    int arr[N];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("排序前 \n");

    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }

    quickSort(arr,0,n-1);

    printf("\n 排序后 \n");
    for(i=0; i<n; i++){
        printf("%d\n", arr[i]);
    }

    printf("QuickSort Test End\n");
    return 0;
}

int partition(int arr[], int low, int high){
    int key;
    key = arr[low];
    while(low<high){
        while(low <high && arr[high]>= key ){
            high = high-1;
        }
        if(low<high)
        {
            arr[low] = arr[high];
            low = low+1;
        }
        while( low<high && arr[low]<=key ){
            low=low+1;
        }
        if(low<high){
            arr[high] = arr[low];
            high = high -1;
        }
    }
    arr[low] = key;

    return low;
}

void quickSort(int arr[], int start, int end){
    int pos;
    if (start<end){
        pos = partition(arr, start, end);
        quick_sort(arr,start,pos-1);
        quick_sort(arr,pos+1,end);
    }
}
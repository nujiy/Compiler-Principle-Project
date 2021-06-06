int N = 10001;
int arr[N];
int partition(int arr[], int low, int high);
void quickSort(int arr[], int start, int end);

main()
{
    int i;
    int j;
    int n;
    read("%d",n);
    if(n == 0)
    {
        println();
        return;
    }
    for (i = 0; i < n; i = i+1)
    {
        read("%d",arr[i]);
    }
    quickSort(arr[], 0, n - 1);
    for(i=0 ; i<n; i = i+1)
    {
        println("%d",arr[i]);
    }
    return;
}

int partition(int arr[], int low, int high)
{
    int key = arr[low];
    while (low < high)
    {
        while ((low < high) && (arr[high] >= key))
        {
            high = high - 1;
        }
        if (low < high)
        {
            arr[low] = arr[high];
            low = low + 1;
        }
        while ((low < high) && (arr[low] <= key))
        {
            low = low + 1;
        }
        if (low < high)
        {
            arr[high] = arr[low];
            high = high - 1;
        }
    }
    arr[low] = key;
    return low;
}

void quickSort(int arr[], int start, int end)
{
    int pos;
    if (start < end)
    {
        pos = partition(arr, start, end);
        quickSort(arr, start, pos - 1);
        quickSort(arr, pos + 1, end);
    }
}

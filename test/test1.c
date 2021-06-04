int Partition(int arr[],int low,int high)
{
    if(arr == NULL || low < 0 || low > high)
    {
        return -1;
    }
    int datum = arr[low];
    while(low < high)
    {
		while((low<high) && arr[high]>=datum)
			high--;
		arr[low] = arr[high];
		while((low<high) && arr[low]<=datum)
			low++;
		arr[high] = arr[low];
    }
    arr[low] = datum;
    return low;
}
 
static void Quick(int arr[],int start,int end)
{
    int par = Partition(arr,start,end);
    if(start < par-1)
    {
	Quick(arr,start,par-1);
    }
    if(par < end-1)
    {
	Quick(arr,par+1,end);
    }
 
}
 
void QuickSort(int arr[],int len)
{
    Quick(arr,0,len-1);
 
}
 
 
void Show(int arr[],int len)
{
    for(int i=0;i<len;i++)
    {
	printf("%d ",arr[i]);
    }
    printf("\n");
}
 
int main()
{
    int i;
    int n;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++) scanf("%d",arr[i]);
    QuickSort(arr,n);
    Show(arr,n);
 
    return 0;
}
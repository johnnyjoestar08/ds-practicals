#include <stdio.h>


void bubbleSort(int arr[], int n)
{
    int i, j, temp;

    for (i=0; i<n-1; i++)
    {
        for (j=0; j<n-i-1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int temp[100];

    while (i<=mid && j<=high)
    {
        if (arr[i]<arr[j])
        {
            temp[k]=arr[i];
            i++;
        }
        else
        {
            temp[k]=arr[j];
            j++;
        }
        k++;
    }

    while (i<=mid)
    {
        temp[k]=arr[i];
        i++;
        k++;
    }

    while (j<=high)
    {
        temp[k]=arr[j];
        j++;
        k++;
    }

    for (i=low, k=0; i<=high; i++, k++)
    {
        arr[i]=temp[k];
    }
}


void mergeSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;

        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);

        merge(arr,low,mid,high);
    }
}

int main()
{
    int arr[100],n,i,choice;

    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    
    printf("\nChoose Sorting Method:\n");
    printf("1)Bubble Sort\n");
    printf("2)Merge Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    
    switch(choice)
    {
        case 1:
            bubbleSort(arr,n);
            printf("\nArray sorted using Bubble Sort.\n");
            break;

        case 2:
            mergeSort(arr,0,n-1);
            printf("\nArray sorted using Merge Sort.\n");
            break;

        default:
            printf("\nInvalid choice!\n");
            return 0;
    }

    
    printf("Sorted Array: ");
    for (i=0; i<n; i++)
    {
        printf("%d",arr[i]);
    }

    printf("\n");

    return 0;
}

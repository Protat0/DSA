#include <stdio.h>




// Write the code of the function that will accept an array of integers and its size. The function will 
// find the smallest integer and swap/exchange with the element at index 0 via function exchange.
// Create code snippet that will declare and initialize an array of integers, call findsmallest() 
// as many times as needed in order for the array to be sorted in ascending order.



void findSmallestExchange(int arr[], int size)
{
    int i, x = 0;

    for(i = 1; i < size; i++)
    {
        if(arr[x] > arr[i])
        {
            x = i;
        }
    }

    exchange(arr+x, arr);
}

void exchange(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void findSmallestShifting(int arr[], int size)
{
    int i, low = 0;

    for(i = 1; i < size; i++)
    {
        if(arr[low] > arr[i])
        {
            low = i;
        }
    }

        int temp = arr[low];
        for(i = low; i > -1; i--)
        {
            arr[i] = arr[i-1];
        }

        arr[0] = temp;
}

void display(int arr[], int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{

    int size = 6;

    int arr[] = {5, 10, 12, 1, 3, 2};

    display(arr, size);
    // findSmallestExchange(arr, size);
    findSmallestShifting(arr, size);
    display(arr, size);





    return 0;
}
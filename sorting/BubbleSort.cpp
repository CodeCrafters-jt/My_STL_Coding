#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n)
{
    int temp = 0;
    bool IsSwap = false;
    for(int j = n-1; j > 0; j--)
    {
        IsSwap = false;
        for (int i = 0; i < j; i++)
        {
            if(arr[i] > arr[i+1])
            {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                IsSwap = true;
            }
        }
        if(IsSwap == false)
        {
            return;
        }
    }
}

void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array[] = {10,15,8,7,6,25,4,9,2,1};
    int n = sizeof(array) / sizeof(array[0]);
    BubbleSort(array,n);
    printArray(array,n);
}


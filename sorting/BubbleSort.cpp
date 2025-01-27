#include <iostream>
using namespace std;
/*冒泡排序的原理是：
从左到右，相邻元素进行比较,两两交互，每次比较一轮，就会找到序列中最大的一个或最小的一个。这个数就会从序列的最右边冒出来，即：沉底
以从小到大排序为例，第一轮比较后，所有数中最大的那个数就会浮到最右边；第二轮比较后，所有数中第二大的那个数就会浮到倒数第二个位置……
就这样一轮一轮地比较，最后实现从小到大排序。
*/
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


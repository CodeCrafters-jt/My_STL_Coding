#include <iostream>
using namespace std;
/*快速排序算法通过多次比较和交换来实现排序，其排序流程如下：
1、首先设定一个分界值，通过该分界值将数组分成左右两部分。
2、将大于或等于分界值的数据集中到数组右边，小于分界值的数据集中到数组的左边。此时，左边部分中各元素都小于或等于分界值，而右边部分中各元素都大于或等于分界值。
3、然后，左边和右边的数据可以独立排序。对于左侧的数组数据，又可以取一个分界值，将该部分数据分成左右两部分，同样在左边放置较小值，右边放置较大值。右侧的数组数据也可以做类似处理。
4、重复上述过程，可以看出，这是一个递归定义。通过递归将左侧部分排好序后，再递归排好右侧部分的顺序。当左、右两个部分各数据排序完成后，整个数组的排序也就完成了。
概括来说为 挖坑填数 + 分治法。
*/

/*快排，最后一次将基准值换到中间位置是因为j最后找到了小于基准值的数，但是i因为i<j这个条件，终止了，最后即i==j，
所以i没有找到大于基准值的数*/

void QuickSort(int array[], int low, int high) 
{
    int i = low; 
    int j = high;
    if(i >= j) {
        return;
    }
 
    int temp = array[low];
    while(i < j) 
    {
        while(array[j] >= temp && i < j) 
        {
            j--;
        }
        while(array[i] <= temp && i < j) 
        {
            i++;
        }
        if(i < j) 
        {
            swap(array[i], array[j]);
        }
    }
 
    //将基准temp放于自己的位置，（第i个位置）
    swap(array[low], array[i]);
    QuickSort(array, low, i - 1);
    QuickSort(array, i + 1, high);
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
    QuickSort(array,0,n-1);
    printArray(array,n);
}


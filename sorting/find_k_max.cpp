// 215. 数组中的第K个最大元素
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int quickselect(vector<int>& nums, int l, int r, int k) 
{
    if (l == r)
        return nums[k]; // 返回元素

    int partition = nums[l], i = l - 1, j = r + 1;
    
    // 快速选择中的划分
    while (i < j) 
    {
        do i++; while (nums[i] < partition);  // 找到大于等于pivot的元素
        do j--; while (nums[j] > partition);  // 找到小于等于pivot的元素

        if (i < j)
            swap(nums[i], nums[j]);  // 交换元素
    }

    // 根据k值所在的位置选择递归查找的范围
    if (k <= j)
        return quickselect(nums, l, j, k); // 在左侧子数组中继续查找
    else 
        return quickselect(nums, j + 1, r, k); // 在右侧子数组中继续查找
}

int findKthLargest(vector<int>& nums, int k) 
{
    int n = nums.size();
    return quickselect(nums, 0, n - 1, n - k); // 调用quickselect查找第k大元素
}

int main() 
{
    // 输入数组和k值
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    // 输出结果
    cout << "The " << k << "th largest element is: " << findKthLargest(nums, k) << endl;

    return 0;
}

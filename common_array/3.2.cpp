//189. 轮转数组
//空间复杂度为 O(1) 原地翻转
/*
首先反转整个数组
反转前 k 个元素
反转剩余的 n-k 个元素
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;  // 防止k大于n的情况
    if (k == 0) return; // 如果旋转步数为0，直接返回

    // 1. 反转整个数组
    reverse(nums.begin(), nums.end());

    // 2. 反转前k个元素
    reverse(nums.begin(), nums.begin() + k);

    // 3. 反转后n-k个元素
    reverse(nums.begin() + k, nums.end());
}


int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums,3);
    for(auto num : nums)
    {
        cout << num <<" ";
    }
    cout << endl;

    return 0;
}





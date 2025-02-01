// 15. 三数之和
// 排序 + 双指针
/*
算法流程：
特判，对于数组长度 n，如果数组为 null 或者数组长度小于 3，返回 []。
对数组进行排序。
遍历排序后数组：
若 nums[i]>0：因为已经排序好，所以后面不可能有三个数加和等于 0，直接返回结果。
对于重复元素：跳过，避免出现重复解
令左指针 L=i+1，右指针 R=n−1，当 L<R 时，执行循环：
当 nums[i]+nums[L]+nums[R]==0，执行循环，判断左界和右界是否和下一位置重复，去除重复解。并同时将 L,R 移到下一位置，寻找新的解
若和大于 0，说明 nums[R] 太大，R 左移
若和小于 0，说明 nums[L] 太小，L 右移
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) 
{
    int n = nums.size();
    vector<vector<int>> res;
    
    if (n < 3) 
    {
        return res;
    }
    
    sort(nums.begin(), nums.end());  // 排序数组
    
    for (int i = 0; i < n; i++) 
    {
        if (nums[i] > 0) 
        {
            return res;  // 如果当前数大于0，后续不可能有解，提前返回
        }
        if (i > 0 && nums[i] == nums[i - 1]) 
        {
            continue;  // 去重，跳过重复的元素
        }
        
        int L = i + 1, R = n - 1;  // 双指针
        while (L < R) 
        {
            int sum = nums[i] + nums[L] + nums[R];
            if (sum == 0) 
            {
                res.push_back({nums[i], nums[L], nums[R]});
                // 去重：跳过重复的L值
                while (L < R && nums[L] == nums[L + 1]) 
                {
                    L++;
                }
                // 去重：跳过重复的R值
                while (L < R && nums[R] == nums[R - 1]) 
                {
                    R--;
                }
                L++;
                R--;
            }
            else if (sum > 0) 
            {
                R--;
            }
            else 
            {
                L++;
            }
        }
    }
    
    return res;
}

int main() 
{
    vector<int> nums = {-1, 0, 1, -2, 1, 3};  // 示例输入
    
    vector<vector<int>> result = threeSum(nums);
    
    for (auto triplet : result) 
    {
        for (int num : triplet) 
        {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}

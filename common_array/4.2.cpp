//238. 除自身以外数组的乘积
//时间复杂度为 O(n) 
//前积和*后积和
//前积和的意思就是 除了当前这个数把前面的所以数的乘积算出来
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) 
{
    int n = nums.size();  // 获取数组的大小
    vector<int> pre(n, 1); // pre[i] 存储 nums[0...i-1] 的积
    vector<int> later(n, 1); // later[i] 存储 nums[i+1...n-1] 的积
    
    // 计算 pre 数组
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] * nums[i - 1];
    }

    // 计算 later 数组
    for (int i = n - 2; i >= 0; i--) {
        later[i] = later[i + 1] * nums[i + 1];
    }

    // 计算结果数组 pre[i] * later[i]，即除去 nums[i] 的积
    for (int i = 0; i < n; i++) {
        pre[i] = pre[i] * later[i];
    }

    return pre;  // 返回计算后的数组
}


int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    vector<int>results = productExceptSelf(nums);
    for(auto result : results)
    {
        cout << result <<" ";
    }
    cout << endl;

    return 0;
}





//53. 最大子数组和
//动态规划

#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) 
{
    int max_tmp = INT_MIN;
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    max_tmp = dp[0];
    for(int i=1;i < nums.size();i++)
    {
        dp[i] = max(dp[i-1] + nums[i], nums[i]);
        max_tmp = max(max_tmp,dp[i]);
    }
    return max_tmp;
}

int main()
{
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    int result = maxSubArray(v);
    cout << result <<endl;
}
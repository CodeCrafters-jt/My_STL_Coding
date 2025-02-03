//53. 最大子数组和
//暴力，先把包含1的子串找出来，然后包含2的 3的。。。。。
#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums)
{
    int max =INT_MIN;
    for(int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for(int j = i; j < nums.size(); j++)
        {
            sum = sum + nums[j];
            if(sum > max)
            {
                max = sum;
            }
        }
    }
    return max;
}

int main()
{
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    int result = maxSubArray(v);
    cout << result <<endl;
}
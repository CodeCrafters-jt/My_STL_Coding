//238. 除自身以外数组的乘积
//暴力解法 时间复杂度为 O(n*n) 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) 
{
    int n = nums.size();
    vector<int> answer(n,1);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j)
            {
                answer[i] *= nums[j];
            }
        }
    }

    return answer;
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





//1. 两数之和
// 暴力解法
#include <iostream>
using namespace std;
#include <vector>

vector<int> twoSum(vector<int>& nums, int target) 
{
    int n =nums.size();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                if(i != j)
                    return {i,j};
            }

        }
    }
    return {};
}

int main()
{
    int n, target;
    // 输入数组的大小和目标值
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> nums[i];
    }

    cout << "Enter the target value: ";
    cin >> target;

    vector<int> result = twoSum(nums,target);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] <<endl;
    }
}

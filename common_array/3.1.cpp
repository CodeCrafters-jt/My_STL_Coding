//189. 轮转数组
//空间复杂度为 O(n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<int>& nums, int k) 
{
    int n = nums.size();
    vector<int> newArr(n); //初始化n个值为0的元素
    for(int i = 0; i < n; i++)
    {
        newArr[(i+k)%10] = nums[i];
    }
    nums = newArr;
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





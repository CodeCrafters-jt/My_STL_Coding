//283. 移动零
//冒泡法：每一趟将一个为0的放到最后
#include <iostream>
#include <vector>
using namespace std;
    
void moveZeroes(vector<int>& nums) 
{
    bool IsSwap = false;
    for(int j = nums.size()-1; j > 0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            if(nums[i] == 0)
            {
                swap(nums[i], nums[i+1]);
                IsSwap = true;
            }

        }
        if(IsSwap == false)
        {
            return;
        }
    }
}

int main()
{
    vector<int> nums = {0,2,0,4,5,6,0,7,9};
    moveZeroes(nums);
    for(auto num : nums)
    {
        cout << num <<" ";
    }
    cout << endl;
}
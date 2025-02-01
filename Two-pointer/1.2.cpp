//283. 移动零
/*使用双指针，左指针指向当前已经处理好的序列的尾部，右指针指向待处理序列的头部。

右指针不断向右移动，每次右指针指向非零数，则将左右指针对应的数交换，同时左指针右移。

注意到以下性质：

左指针左边均为非零数；

右指针左边直到左指针处均为零。

*/
#include <iostream>
#include <vector>
using namespace std;
    
void moveZeroes(vector<int>& nums) 
{
    int left = 0;  // 用来指示下一个非零元素的位置
    for (int right = 0; right < nums.size(); right++) 
    {
        if (nums[right] != 0) 
        {
            // 如果是非零元素，交换位置
            swap(nums[left], nums[right]);
            left++;
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
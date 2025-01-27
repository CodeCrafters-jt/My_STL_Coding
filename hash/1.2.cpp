//1. 两数之和
//两遍 哈希 修改！！！,更新查找
//hashtable.end() 是一个 特殊的迭代器，它指向哈希表中最后一个元素之后的位置。它是一个标志，表示查找未成功。
#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

 vector<int> twoSum(vector<int>& nums, int target) 
 {
    unordered_map<int, int> hashtable;
    
    // 第一步：将数组中的所有元素存入哈希表
    for (int i = 0; i < nums.size(); ++i) 
    {
        hashtable[nums[i]] = i;
    }
    
    // 第二步：遍历数组，查找每个元素的配对值
    for (int i = 0; i < nums.size(); ++i) 
    {
        int complement = target - nums[i];
        // unordered_map<int, int>::iterator it = hashtable.find(2); 
        // 如果哈希表中找到了配对值，并且索引不相同（避免自己和自己配对）
        
        auto it = hashtable.find(complement); 
        // if (hashtable.find(complement) != hashtable.end() && hashtable[complement] != i) 
        //使用 it->second 来访问 unordered_map 中找到的值，而不是 hashtable[temp]，因为 it 已经是一个有效的迭代器，指向 unordered_map 中的对应元素
        if (it != hashtable.end() && it->second != i)
        {
            return {i, hashtable[complement]};
        }
    }
    
    // 如果没有找到，返回空数组
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

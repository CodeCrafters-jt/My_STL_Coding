//128. 最长连续序列
/*
核心思路：对于 nums 中的元素 x，以 x 为起点，不断查找下一个数 x+1,x+2,⋯ 是否在 nums 中，并统计序列的长度。

为了做到 O(n) 的时间复杂度，需要两个关键优化：
把 nums 中的数都放入一个哈希集合中，这样可以 O(1) 判断数字是否在 nums 中。
如果 x−1 在哈希集合中，则不以 x 为起点。为什么？因为以 x−1 为起点计算出的序列长度，一定比以 x 为起点计算出的序列长度要长！
这样可以避免大量重复计算。比如 nums=[3,2,4,5]，从 3 开始，我们可以找到 3,4,5 这个连续序列；而从 2 开始，
我们可以找到 2,3,4,5 这个连续序列，一定比从 3 开始的序列更长。

num_set.count() 是 C++ 中 unordered_set（以及其他 STL 集合类型，如 set 和 unordered_map）的一个成员函数，
count 函数返回的是一个 整数，它表示指定元素在集合中出现的次数。在哈希表中只会返回0或1 因为哈希表的性质决定了每个元素在集合中只出现一次
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) 
{
    //首先，本题是不能排序的，因为排序的时间复杂度是 O(nlogn)，不符合题目 O(n) 的要求
    // 1. 使用 unordered_set 去重，避免重复元素
    unordered_set<int> num_set;
    for (const int& num : nums) 
    {
        num_set.insert(num);
    }

    int longestStreak = 0;  // 记录最长连续序列的长度

    // 2. 遍历 num_set 中的每一个元素
    for (const int& num : num_set) 
    {
        // 3. 只有在 num - 1 不存在时，num 才可能是一个连续序列的起点
        if (!num_set.count(num - 1)) 
        {
            int currentNum = num;  // 当前元素
            int currentStreak = 1; // 当前序列的长度（至少有当前元素）

            // 4. 找到当前元素的下一个连续元素（num + 1, num + 2, ...）
            while (num_set.count(currentNum + 1)) 
            {
                currentNum += 1;  // 更新到下一个数字
                currentStreak += 1;  // 增加连续序列的长度
            }

            // 5. 更新最长序列长度
            longestStreak = max(longestStreak, currentStreak);
        }
    }

    // 6. 返回最长连续序列的长度
    return longestStreak;           
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,10,7,9};
    int length = longestConsecutive(v);
    cout << length << endl;
}
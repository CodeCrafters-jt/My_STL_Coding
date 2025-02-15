//3. 无重复字符的最长子串

//暴力
/*
我们需要两层循环，第一层循环遍历字符串、并且记录第二层循环开始的位置。
①创建一个新的数组；
②从第一个字符开始遍历，不重复的字符就将它放到新的数组中，遇到重复的就停止，计算该子串的长度；
③开始下一次循环，直到遍历到字符串结束。
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // 用于max函数
using namespace std;

int lengthOfLongestSubstring(string s) 
{
    int max_len = 0;
    const int n = s.length();
    
    // 外层循环：遍历所有可能的子串起始位置
    for (int i = 0; i < n; ++i) 
    {
        vector<char> current_chars; // 存储当前子串的字符
        int current_len = 0;
        
        // 内层循环：从i位置开始扩展子串
        for (int j = i; j < n; ++j) 
        {
            // 查找当前字符是否已存在（时间复杂度O(k)，k为当前子串长度）
            auto it = find(current_chars.begin(), current_chars.end(), s[j]);
            
            if (it != current_chars.end()) 
            {
                // 发现重复字符，停止扩展
                break;
            } 
            else 
            {
                // 无重复，继续扩展子串
                current_chars.push_back(s[j]);
                current_len++;
                max_len = max(max_len, current_len); // 更新最大值
            }
        }
    }
    return max_len;
}

int main() 
{
    string str = "abcabcbb";
    cout << "The length of the longest substring without repeating characters is: "
              << lengthOfLongestSubstring(str) << endl;
    return 0;
}

//49. 字母异位词分组
// 通过对每个字符串排序，然后将排序后的字符串作为一个 "key" 来分组。所有具有相同 "key" 的字符串，就是异位词
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>  // 用于 sort
using namespace std;

// vector<vector<string>> groupAnagrams(vector<string>& strs) 
// {
//     unordered_map<string, vector<string>> mp;

//     // 遍历每个字符串
//     for (string& str : strs) 
//     {
//         // 对字符串进行排序，得到标准化的键
//         string key = str;
//         sort(key.begin(), key.end());  // 将字符串按字母顺序排序
//         mp[key].emplace_back(str);  // 将原字符串放入哈希表中，按排序后的键分组
//     }

//     // 将哈希表中的所有分组存入结果向量
//     vector<vector<string>> ans;
//     for (auto it = mp.begin(); it != mp.end(); ++it) 
//     {
//         ans.emplace_back(it->second);  // 将每个分组加入答案中
//     }

//     return ans;  // 返回分组结果
// }

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map <string,vector<string>> mp;
    for(auto& str : strs)
    {
        string key = str;
        sort(key.begin(), key.end());
        mp[key].push_back(str);
    }

    vector<vector<string>> ans;
    for(auto& pair : mp)
    {
        ans.push_back(pair.second);
    }

    return ans;  // 返回分组结果
}


int main() 
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    // 获取异位词分组
    vector<vector<string>> result = groupAnagrams(strs);
    
    // 打印结果
    for (const auto& group : result) 
    {
        for (const string& word : group) 
        {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}

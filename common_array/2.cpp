//56. 合并区间
/*
按照左端点从小到大排序
如果当前区间的左端点小于等于结果中最后一个区间的右端点，说明两个区间有重叠，可以合并。
如果不能合并，直接将当前区间加入结果。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
    sort(intervals.begin(),intervals.end()); // 按照左端点从小到大排序
    vector<vector<int>> merge;
    for (auto& p : intervals) 
    {
        if (!merge.empty() && p[0] <= merge.back()[1]) 
        { // 可以合并
            merge.back()[1] = max(merge.back()[1], p[1]); // 更新右端点最大值
        } 
        else 
        { // 不相交，无法合并
            merge.push_back (p); // 新的合并区间
        }
    }
    return merge;
}
    
int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 4}, {5, 7}, {6, 8}};
    vector<vector<int>> result = merge(intervals);
    for(auto& interval : result)
    {
        for(auto& pair : interval)
        {
            cout << pair << " ";
        }
        cout << endl;
    }

    // // 输出合并后的区间
    // for (const auto& interval : result) 
    // {
    //     cout << "[" << interval[0] << ", " << interval[1] << "] ";
    // }
    // cout << endl;

    return 0;
}





//11. 盛最多水的容器
// 双指针
#include <vector>
#include <algorithm>  // 包含 std::min 和 std::max
#include <iostream>
using namespace std;

int maxArea(vector<int>& height) 
{
    int l = 0, r = height.size() - 1;  // 左右指针
    int ans = 0;  // 用于保存最大的面积
    while (l < r) 
    {
        int area = min(height[l], height[r]) * (r - l);  // 计算当前面积
        ans = max(ans, area);  // 更新最大面积
        if (height[l] <= height[r]) 
        {  // 如果左边的高度小，移动左指针
            ++l;
        }
        else 
        {  // 如果右边的高度小，移动右指针
            --r;
        }
    }
    return ans;  // 返回最大面积
}

int main() 
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};  // 示例输入
    
    int result = maxArea(height);  // 调用函数
    
    cout << "The maximum area is: " << result << endl;  // 输出结果
    return 0;
}

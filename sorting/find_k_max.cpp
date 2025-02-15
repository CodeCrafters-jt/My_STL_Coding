// 215. �����еĵ�K�����Ԫ��
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int quickselect(vector<int>& nums, int l, int r, int k) 
{
    if (l == r)
        return nums[k]; // ����Ԫ��

    int partition = nums[l], i = l - 1, j = r + 1;
    
    // ����ѡ���еĻ���
    while (i < j) 
    {
        do i++; while (nums[i] < partition);  // �ҵ����ڵ���pivot��Ԫ��
        do j--; while (nums[j] > partition);  // �ҵ�С�ڵ���pivot��Ԫ��

        if (i < j)
            swap(nums[i], nums[j]);  // ����Ԫ��
    }

    // ����kֵ���ڵ�λ��ѡ��ݹ���ҵķ�Χ
    if (k <= j)
        return quickselect(nums, l, j, k); // ������������м�������
    else 
        return quickselect(nums, j + 1, r, k); // ���Ҳ��������м�������
}

int findKthLargest(vector<int>& nums, int k) 
{
    int n = nums.size();
    return quickselect(nums, 0, n - 1, n - k); // ����quickselect���ҵ�k��Ԫ��
}

int main() 
{
    // ���������kֵ
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    // ������
    cout << "The " << k << "th largest element is: " << findKthLargest(nums, k) << endl;

    return 0;
}

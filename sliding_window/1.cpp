//3. ���ظ��ַ�����Ӵ�

//����
/*
������Ҫ����ѭ������һ��ѭ�������ַ��������Ҽ�¼�ڶ���ѭ����ʼ��λ�á�
�ٴ���һ���µ����飻
�ڴӵ�һ���ַ���ʼ���������ظ����ַ��ͽ����ŵ��µ������У������ظ��ľ�ֹͣ��������Ӵ��ĳ��ȣ�
�ۿ�ʼ��һ��ѭ����ֱ���������ַ���������
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // ����max����
using namespace std;

int lengthOfLongestSubstring(string s) 
{
    int max_len = 0;
    const int n = s.length();
    
    // ���ѭ�����������п��ܵ��Ӵ���ʼλ��
    for (int i = 0; i < n; ++i) 
    {
        vector<char> current_chars; // �洢��ǰ�Ӵ����ַ�
        int current_len = 0;
        
        // �ڲ�ѭ������iλ�ÿ�ʼ��չ�Ӵ�
        for (int j = i; j < n; ++j) 
        {
            // ���ҵ�ǰ�ַ��Ƿ��Ѵ��ڣ�ʱ�临�Ӷ�O(k)��kΪ��ǰ�Ӵ����ȣ�
            auto it = find(current_chars.begin(), current_chars.end(), s[j]);
            
            if (it != current_chars.end()) 
            {
                // �����ظ��ַ���ֹͣ��չ
                break;
            } 
            else 
            {
                // ���ظ���������չ�Ӵ�
                current_chars.push_back(s[j]);
                current_len++;
                max_len = max(max_len, current_len); // �������ֵ
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

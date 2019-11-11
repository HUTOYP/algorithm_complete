class Solution {
public:
    bool isAnagram(string s, string t) {
        // 排序，使用快排 O(nlogn)
        // 附加一个hashmap，O(2*n)，额外空间复杂度 O(n)
        /*
        std::map<char, int> helper;
        for (char c : s) {
            helper[c]++;
        }
        for (char c : t) {
            helper[c]--;
        }
        for (std::map<char, int>::iterator iter = helper.begin(); iter != helper.end(); ++iter) {
            if (iter->second != 0) {
                return false;
            }
        }
        return true;
        */
        
        // 优化的话，可以直接使用 size=26 的数组存储
        int helper[26] = {0};
        for (char c : s) {
            helper[c-'a']++;
        }
        for (char c : t) {
            helper[c-'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (helper[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
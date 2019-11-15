class Solution {
public:
    int numJewelsInStones(string J, string S) {
//         int res = 0;
//         for (int j : J) {
//             for (int s : S) {
//                 if (j == s) {
//                     ++res;
//                 }
//             }
//         }
//         return res;
    
        int res = 0;
        std::map<char, int> smap;
        for (int s : S) {
            ++smap[s];
        }
        for (int j : J) {
            if (smap.find(j) != smap.end()) {
                res += smap[j];
            }
        }
        return res;
    }
};

// 执行用时 :4 ms, 在所有 cpp 提交中击败了81.84%的用户
// 内存消耗 :8.5 MB, 在所有 cpp 提交中击败了76.53%的用户

// 和暴力法相差不多，可能主要是因为testcase样本少

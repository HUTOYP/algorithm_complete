// 不太理解LCP编号的题目是什么含义

class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int res = 0;
        for (int i = 0; i < guess.size() && i < answer.size(); ++i) {
            if (guess[i] == answer[i]) {
                ++res;
            }
        }
        return res;
    }
};

// 执行用时 :0 ms, 在所有 cpp 提交中击败了100.00%的用户
// 内存消耗 :8.3 MB, 在所有 cpp 提交中击败了100.00%的用户

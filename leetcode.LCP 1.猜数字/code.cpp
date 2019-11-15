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

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        // 使用栈来进行状态的记录，存储的是元素下标，而不是元素值
        stack<int> st;

        vector<int> res(T.size());
        for (int i = 0; i < T.size(); ++i) {
            if (st.empty() || T[st.top()] > T[i]) {
                st.push(i);
                continue;
            } 

            while (!st.empty() && T[st.top()] < T[i]) {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) {
            res[st.top()] = 0;
            st.pop();
        }

        return res;
    }
};

// 执行用时 :228 ms, 在所有 cpp 提交中击败了92.48%的用户
// 内存消耗 :16.2 MB, 在所有 cpp 提交中击败了63.76%的用户

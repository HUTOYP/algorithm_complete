class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        // 优化技巧，如何去掉if/else排比
        map<char, char> helper = {{')','('}, {']','['}, {'}','{'}};
        for (char c : s) {
            if (helper.find(c) == helper.end()) {
                st.push(c);
            } else if (st.size() != 0 && st.top() == helper[c]) {
                st.pop();
            } else {
                return false;
            }
        }
        return st.empty() ? true : false;

/*
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else if (c == ')') {
                if (st.size() != 0 && st.top() == '(') {
                    st.pop();
                } else {
                    return false;
                }
            } else if (c == ']') {
                if (st.size() != 0 && st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            } else if (c == '}') {
                if (st.size() != 0 && st.top() == '{') {
                    st.pop();
                } else {
                    return false;
                }
            } 
        } 
        return st.empty() ? true : false;
*/
    }
};

// 执行用时 :4 ms, 在所有 cpp 提交中击败了75.55%的用户
// 内存消耗 :8.5 MB, 在所有 cpp 提交中击败了76.24%的用户

class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        string invalid = "[.]";
        for (char c : address) {
            c == '.' ? res.append(invalid) : res += c;
        }
        return res;
    }
};

// 执行用时 :0 ms, 在所有 cpp 提交中击败了100.00%的用户
// 内存消耗 :8.2 MB, 在所有 cpp 提交中击败了100.00%的用户

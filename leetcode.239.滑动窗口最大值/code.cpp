class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 滑动窗口问题一般都是使用双端队列来解决
        std::deque<int> q;

        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (q.empty()) {
                q.push_back(i);
            } else {
                if (i - q.front() >= k) {
                    q.pop_front();
                }
                while (!q.empty() && nums[q.front()] < nums[i]) {
                    q.pop_front();
                }
                while (!q.empty() && nums[q.back()] < nums[i]) {
                    q.pop_back();
                }
                q.push_back(i);
            }
            
            if (i >= k - 1) {
                res.push_back(nums[q.front()]);
            }
        }
        return res;
    }
};

// 执行用时 :68 ms, 在所有 cpp 提交中击败了87.29%的用户
// 内存消耗 :13.2 MB, 在所有 cpp 提交中击败了39.48%的用户

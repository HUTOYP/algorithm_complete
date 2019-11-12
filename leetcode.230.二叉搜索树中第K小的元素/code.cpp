/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // 中序遍历存数组
        vector<int> vec;
        kth(root, vec);
        
        return vec[k-1];
    }
    
    void kth(TreeNode* root, vector<int>& vec) {
        if (root == NULL) return;
        
        kth(root->left, vec);
        vec.push_back(root->val);
        kth(root->right, vec);
    }
};

// 执行用时 :20 ms, 在所有 cpp 提交中击败了95.01%的用户
// 内存消耗 :21.8 MB, 在所有 cpp 提交中击败了22.45%的用户

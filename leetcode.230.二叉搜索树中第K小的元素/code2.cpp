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
    int res = 0;
    int kthSmallest(TreeNode* root, int k) {
        int n = 1;
        kth(root, k, n);
        return res;
    }

    void kth(TreeNode* root, int k, int& n) {
        if (root == NULL) return;

        kth(root->left, k, n);
        if (n++ == k) {
            res = root->val;
            return;     // 能够提前终止么？
        }
        kth(root->right, k, n);
    }
};

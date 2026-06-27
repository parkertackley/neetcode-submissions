/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> p1;
        queue<TreeNode*> q1;
        p1.push(p);
        q1.push(q);

        while (!p1.empty() && !q1.empty()) {
            TreeNode* pt = p1.front();
            p1.pop();
            TreeNode* qt = q1.front();
            q1.pop();

            if (!qt && !pt) {
                continue;
            }

            if (!qt || !pt || pt->val != qt->val) {
                return false;
            }

            p1.push(pt->left);
            p1.push(pt->right);
            q1.push(qt->left);
            q1.push(qt->right);

        }
        return true;
    }
};

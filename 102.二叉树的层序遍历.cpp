/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (64.20%)
 * Likes:    1006
 * Dislikes: 0
 * Total Accepted:    387K
 * Total Submissions: 602.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 *
 *
 *
 * 示例：
 * 二叉树：[3,9,20,null,null,15,7],
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 * 返回其层序遍历结果：
 *
 *
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 *
 *
 */

// @lc code=start
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
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> res;
        if (!root)
        {
            return res;
        }
        q.emplace(root);
        while (!q.empty())
        {
            int s = q.size();
            vector<int> path;
            while (s--)
            {
                TreeNode *tmp = q.front();
                q.pop();
                path.emplace_back(tmp->val);
                if (tmp->left)
                {
                    q.emplace(tmp->left);
                }
                if (tmp->right)
                {
                    q.emplace(tmp->right);
                }
            }
            res.emplace_back(path);
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=110 lang=golang
 *
 * [110] 平衡二叉树
 *
 * https://leetcode-cn.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (56.25%)
 * Likes:    763
 * Dislikes: 0
 * Total Accepted:    248.9K
 * Total Submissions: 442.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 *
 * 本题中，一棵高度平衡二叉树定义为：
 *
 *
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,2,3,3,null,null,4,4]
 * 输出：false
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = []
 * 输出：true
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中的节点数在范围 [0, 5000] 内
 * -10^4
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}
	var check func(*TreeNode) int
	check = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		l := check(root.Left)
		r := check(root.Right)
		if l < 0 || r < 0 || abs(l-r) > 1 {
			return -1
		}
		return max(l, r) + 1
	}
	return check(root) >= 0
}
func abs(a int) int {
	if a > 0 {
		return a
	}
	return -a
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// @lc code=end


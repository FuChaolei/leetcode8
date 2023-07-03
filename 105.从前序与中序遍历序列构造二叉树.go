/*
 * @lc app=leetcode.cn id=105 lang=golang
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (71.40%)
 * Likes:    1894
 * Dislikes: 0
 * Total Accepted:    469K
 * Total Submissions: 656.8K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder
 * 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * 输出: [3,9,20,null,null,15,7]
 *
 *
 * 示例 2:
 *
 *
 * 输入: preorder = [-1], inorder = [-1]
 * 输出: [-1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder 和 inorder 均 无重复 元素
 * inorder 均出现在 preorder
 * preorder 保证 为二叉树的前序遍历序列
 * inorder 保证 为二叉树的中序遍历序列
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
func buildTree(preorder []int, inorder []int) *TreeNode {
	n := len(preorder)
	mp := map[int]int{}
	for i := 0; i < n; i++ {
		mp[inorder[i]] = i
	}
	var build func(int, int, int, int) *TreeNode
	build = func(l1, r1, l2, r2 int) *TreeNode {
		if l1 > r1 || l2 > r2 {
			return nil
		}
		root := &TreeNode{
			Val: preorder[l1],
		}
		k := mp[preorder[l1]] - l2
		root.Left = build(l1+1, l1+k, l2, l2+k-1)
		root.Right = build(l1+k+1, r1, l2+k+1, r2)
		return root
	}
	return build(0, n-1, 0, n-1)
}

// @lc code=end


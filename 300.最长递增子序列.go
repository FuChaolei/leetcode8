/*
 * @lc app=leetcode.cn id=300 lang=golang
 *
 * [300] 最长递增子序列
 *
 * https://leetcode.cn/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (54.39%)
 * Likes:    2933
 * Dislikes: 0
 * Total Accepted:    660.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 *
 * 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7]
 * 的子序列。
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [10,9,2,5,3,7,101,18]
 * 输出：4
 * 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,1,0,3,2,3]
 * 输出：4
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [7,7,7,7,7,7,7]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 你能将算法的时间复杂度降低到 O(n log(n)) 吗?
 *
 *
 */

// @lc code=start
func lengthOfLIS(nums []int) int {
	res := []int{}
	lower_bound := func(t int) int {
		l, r := 0, len(res)-1
		for l <= r {
			mid := (r-l)/2 + l
			if res[mid] == t {
				return mid
			} else if res[mid] < t {
				l = mid + 1
			} else {
				r = mid - 1
			}
		}
		return l
	}
	for i := 0; i < len(nums); i++ {
		it := lower_bound(nums[i])
		if it == len(res) {
			res = append(res, nums[i])
		} else {
			res[it] = nums[i]
		}
	}
	return len(res)
}

// @lc code=end


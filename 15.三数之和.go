/*
 * @lc app=leetcode.cn id=15 lang=golang
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (33.42%)
 * Likes:    3738
 * Dislikes: 0
 * Total Accepted:    638.8K
 * Total Submissions: 1.9M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0
 * 且不重复的三元组。
 *
 * 注意：答案中不可以包含重复的三元组。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [0]
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * -10^5
 *
 *
 */

// @lc code=start
func threeSum(nums []int) [][]int {
	sort.Ints(nums)
	l, r := 0, len(nums)-1
	res := [][]int{}
	for l < r {
		if l != 0 && nums[l] == nums[l-1] {
			l++
			continue
		}
		t := -nums[l]
		x, y := l+1, r
		for x < y {
			if x < y && nums[x]+nums[y] == t {
				tmp := []int{-t, nums[x], nums[y]}
				res = append(res, tmp)
				for x < y && nums[x] == nums[x+1] {
					x++
				}
				for x < y && nums[y] == nums[y-1] {
					y--
				}
				x++
				y--
			} else if x < y && nums[x]+nums[y] < t {
				x++
			} else if x < y && nums[x]+nums[y] > t {
				y--
			}
		}
		l++
	}
	return res
}

// @lc code=end


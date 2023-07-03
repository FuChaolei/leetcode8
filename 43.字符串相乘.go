/*
 * @lc app=leetcode.cn id=43 lang=golang
 *
 * [43] 字符串相乘
 *
 * https://leetcode.cn/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (44.71%)
 * Likes:    1078
 * Dislikes: 0
 * Total Accepted:    266.8K
 * Total Submissions: 597.2K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 *
 * 注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 *
 * 示例 2:
 *
 *
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= num1.length, num2.length <= 200
 * num1 和 num2 只能由数字组成。
 * num1 和 num2 都不包含任何前导零，除了数字0本身。
 *
 *
 */

// @lc code=start
func multiply(num1 string, num2 string) string {
	if num1 == "0" || num2 == "0" {
		return "0"
	}
	m, n := len(num1), len(num2)
	dp := make([]int, m+n)
	for i := m - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			dp[i+j+1] += int((num1[i] - '0') * (num2[j] - '0'))
		}
	}
	add := 0
	for i := m + n - 1; i >= 0; i-- {
		sum := dp[i] + add
		add = sum / 10
		dp[i] = sum % 10
	}
	res := ""
	for i := 0; i < m+n; i++ {
		res += strconv.Itoa(dp[i])
	}
	if res[0] == '0' {
		res = res[1:]
	}
	return res
}

// @lc code=end


/*
 * @lc app=leetcode.cn id=415 lang=golang
 *
 * [415] 字符串相加
 *
 * https://leetcode.cn/problems/add-strings/description/
 *
 * algorithms
 * Easy (54.94%)
 * Likes:    598
 * Dislikes: 0
 * Total Accepted:    219.4K
 * Total Submissions: 399K
 * Testcase Example:  '"11"\n"123"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
 *
 * 你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：num1 = "11", num2 = "123"
 * 输出："134"
 *
 *
 * 示例 2：
 *
 *
 * 输入：num1 = "456", num2 = "77"
 * 输出："533"
 *
 *
 * 示例 3：
 *
 *
 * 输入：num1 = "0", num2 = "0"
 * 输出："0"
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= num1.length, num2.length <= 10^4
 * num1 和num2 都只包含数字 0-9
 * num1 和num2 都不包含任何前导零
 *
 *
 */

// @lc code=start
func addStrings(num1 string, num2 string) string {
	l, r := len(num1)-1, len(num2)-1
	add := 0
	res := ""
	for l >= 0 || r >= 0 || add > 0 {
		a, b := 0, 0
		if l >= 0 {
			a = int(num1[l]) - '0'
			l--
		}
		if r >= 0 {
			b = int(num2[r]) - '0'
			r--
		}
		sum := a + b + add
		res = strconv.Itoa(sum%10) + res
		add = sum / 10
	}
	return res
}

// @lc code=end


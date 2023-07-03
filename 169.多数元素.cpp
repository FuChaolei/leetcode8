/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 *
 * https://leetcode.cn/problems/majority-element/description/
 *
 * algorithms
 * Easy (66.95%)
 * Likes:    1537
 * Dislikes: 0
 * Total Accepted:    578K
 * Total Submissions: 863.5K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
 *
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [3,2,3]
 * 输出：3
 *
 * 示例 2：
 *
 *
 * 输入：nums = [2,2,1,1,1,2,2]
 * 输出：2
 *
 *
 *
 * 提示：
 *
 *
 * n == nums.length
 * 1 <= n <= 5 * 10^4
 * -10^9 <= nums[i] <= 10^9
 *
 *
 *
 *
 * 进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
 *
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int res = nums[0];
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == res)
            {
                count++;
                if (count > nums.size() / 2)
                {
                    return res;
                }
            }
            else
            {
                count--;
                if (count < 0)
                {
                    count = 1;
                    res = nums[i];
                }
            }
        }
        return res;
    }
};
// @lc code=end

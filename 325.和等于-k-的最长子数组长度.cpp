/*
 * @lc app=leetcode.cn id=325 lang=cpp
 *
 * [325] 和等于 k 的最长子数组长度
 *
 * https://leetcode.cn/problems/maximum-size-subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (51.89%)
 * Likes:    197
 * Dislikes: 0
 * Total Accepted:    16.3K
 * Total Submissions: 31.4K
 * Testcase Example:  '[1,-1,5,-2,3]\n3'
 *
 * 给定一个数组 nums 和一个目标值 k，找到和等于 k 的最长连续子数组长度。如果不存在任意一个符合要求的子数组，则返回 0。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [1,-1,5,-2,3], k = 3
 * 输出: 4
 * 解释: 子数组 [1, -1, 5, -2] 和等于 3，且长度最长。
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [-2,-1,2,1], k = 1
 * 输出: 2
 * 解释: 子数组 [-1, 2] 和等于 1，且长度最长。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 2 * 10^5
 * -10^4 <= nums[i] <= 10^4
 * -10^9 <= k <= 10^9
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int maxSubArrayLen(vector<int> &nums, int k)
    {
        long res = 0, sum = 0;
        unordered_map<long, long> mp{{0, 0}};
        for (int i = 0; i < nums.szie(); i++)
        {
            sum += nums[i];
            if (!mp.count(sum))
            {
                mp[sum] = i + 1;
            }
            if (mp.count(sum - k))
            {
                res = max(res, i - mp[sum - k] + 1);
            }
        }
        return res;
    }
};
// @lc code=end

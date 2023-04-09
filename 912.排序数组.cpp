/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 *
 * https://leetcode-cn.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (56.57%)
 * Likes:    361
 * Dislikes: 0
 * Total Accepted:    211.9K
 * Total Submissions: 375.1K
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给你一个整数数组 nums，请你将该数组升序排列。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 50000
 * -50000 <= nums[i] <= 50000
 *
 *
 */

// @lc code=start
/* 堆排序：
 * 数组下标从从零开始
 * 下标为i的节点的父节点下标:(i-1)/2【整数除法】
 * 下标为i的节点的左孩子下标：i*2+1
 * 下标为i的节点的右孩子的下标：i*2+2
 *
 * https://www.bilibili.com/video/BV1fp4y1D7cj/?spm_id_from=333.337.search-card.all.click&vd_source=b528fb16c8de754b7d88e0bc8622709c
 * https://github.com/imxtx/algorithms/blob/main/01-sort/05-heap/heap.c
 *
 * 维护堆的性质
 * @param arr 存储堆的数组
 * @param len 数组长度
 * @param i 待维护节点的下标
 */
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        function<void(int, int)> heapify = [&](int n, int i)
        {
            int largest = i;
            int lson = i * 2 + 1;
            int rson = i * 2 + 2;
            if (lson < n && nums[lson] > nums[largest])
            {
                largest = lson;
            }
            if (rson < n && nums[rson] > nums[largest])
            {
                largest = rson;
            }
            if (i != largest)
            {
                swap(nums[i], nums[largest]);
                heapify(n, largest);
            }
        };
        // 建堆
        for (int i = (n - 1 - 1) / 2; i >= 0; i--)
        {
            heapify(n, i);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            swap(nums[i], nums[0]);
            heapify(i, 0);
        }
        return nums;
    }
};
// @lc code=end

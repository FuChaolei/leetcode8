/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode.cn/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (63.51%)
 * Likes:    1558
 * Dislikes: 0
 * Total Accepted:    425.9K
 * Total Submissions: 670.6K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [1], k = 1
 * 输出: [1]
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * k 的取值范围是 [1, 数组中不相同的元素的个数]
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 *
 *
 *
 *
 * 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<pair<int, int>> vec_stat;
        vector<pair<int, int>> heap;
        function<void(int, int)> heapify = [&](int n, int i)
        {
            int lson = i * 2 + 1;
            int rson = i * 2 + 2;
            int largest = i;
            if (lson < n && heap[lson].second < heap[largest].second)
            {
                largest = lson;
            }
            if (rson < n && heap[rson].second < heap[largest].second)
            {
                largest = rson;
            }
            if (largest != i)
            {
                swap(heap[largest], heap[i]);
                heapify(n, largest);
            }
        };
        unordered_map<int, int> stat;
        for (auto &num : nums)
            stat[num]++;
        for (auto &item : stat)
            vec_stat.push_back({item.first, item.second});

        for (int i = 0; i < k; i++)
        {
            heap.push_back(vec_stat[i]);
        }
        // 建堆
        for (int i = (k - 1 - 1) / 2; i >= 0; i--)
        {
            heapify(k, i);
        }
        for (int i = k; i < vec_stat.size(); i++)
        {
            if (vec_stat[i].second > heap[0].second)
            {
                heap[0] = vec_stat[i];
                heapify(k, 0);
            }
        }

        vector<int> result;
        for (int i = 0; i < k; i++)
            result.push_back(heap[i].first);
        return result;
    }
};
// @lc code=end

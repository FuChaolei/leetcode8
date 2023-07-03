/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 *
 * https://leetcode.cn/problems/rotate-list/description/
 *
 * algorithms
 * Medium (41.47%)
 * Likes:    924
 * Dislikes: 0
 * Total Accepted:    313.1K
 * Total Submissions: 755.1K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4,5], k = 2
 * 输出：[4,5,1,2,3]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [0,1,2], k = 4
 * 输出：[2,0,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目在范围 [0, 500] 内
 * -100 <= Node.val <= 100
 * 0 <= k <= 2 * 10^9
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr)
        {
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *cur = pre;
        int l = 0;
        while (cur->next)
        {
            cur = cur->next;
            l++;
        }
        int t = l - (k % l);
        if (t == 0)
        {
            return head;
        }
        cur->next = head;
        pre = head;
        while (t > 1)
        {
            pre = pre->next;
            t--;
        }
        ListNode *res = pre->next;
        pre->next = nullptr;
        return res;
    }
};
// @lc code=end

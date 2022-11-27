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
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        deque<int> nums;
        ListNode* ret = new ListNode;
        
        while(head){
            while(nums.size() && nums.back() < head->val)
                nums.pop_back();
            nums.push_back(head->val);
            head = head->next;
        }
        
        ListNode* it = ret;
        while(nums.size()){
            it->val = nums.front();
            if(nums.size() > 1){
                ListNode* next = new ListNode;
                it->next = next;
                it = it->next;
            }
            nums.pop_front();
        }
        
        return ret;
    }
};
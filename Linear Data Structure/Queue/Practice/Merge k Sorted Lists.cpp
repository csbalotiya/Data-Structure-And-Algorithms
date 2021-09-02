//https://leetcode.com/problems/merge-k-sorted-lists/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < lists.size(); ++i) {
            ListNode* temp = lists[i];
            while(temp) {
                pq.push(temp->val);
                temp = temp->next;
            }
        }
        if(pq.empty()) return nullptr;
        ListNode* head = new ListNode(pq.top());
        pq.pop();
        ListNode* temp = head;
        while(!pq.empty()) {
            temp->next = new ListNode(pq.top());
            pq.pop();
            temp = temp->next;
        }
        return head;
    }
};

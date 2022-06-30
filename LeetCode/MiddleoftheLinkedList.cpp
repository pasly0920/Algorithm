class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* now = head;
        vector<int> NodeList;
        while(now){
            NodeList.push_back(now->val);
            now = now -> next;
        }
        int size = NodeList.size();
        int target = size/2;
        
        int index = 0;
        now = head;
        while(now){
            if (index == target)
                break;
            now = now -> next;
            index ++;
        }
        return now;
    }
};
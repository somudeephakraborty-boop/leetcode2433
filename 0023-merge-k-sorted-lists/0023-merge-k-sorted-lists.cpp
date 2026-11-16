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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        ListNode* temp = NULL;

        while (true) {
            int minValue = 100001;
            int index = -1;

            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != NULL && lists[i]->val < minValue) {
                    minValue = lists[i]->val;
                    index = i;
                }
            }

            if (index == -1) {
                break;
            }

            ListNode* newNode = new ListNode(minValue);

            if (head == NULL) {
                head = newNode;
                temp = newNode;
            }
            else {
                temp->next = newNode;
                temp = newNode;
            }

            lists[index] = lists[index]->next;
        }

        return head;
    }
};

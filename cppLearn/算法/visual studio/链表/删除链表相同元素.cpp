//#include <iostream>
//using namespace std;
//
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode(int m_val) {
//        val = m_val;
//        next = NULL;
//    }
//};
//
//ListNode* test01(ListNode* head) {
//    ListNode* dummy = new ListNode(-1);
//    dummy->next = head;
//    ListNode* fast = head;
//    ListNode* slow = dummy;
//    while (fast) {
//        while (fast->next != NULL && fast->next->val == fast->val) fast = fast->next;
//        if (slow->next != fast) {
//            slow->next = fast->next;
//        } else {
//            slow = fast;
//        }
//        fast = fast->next;
//    }
//    return dummy;
//}
//
//int main() {
//    ListNode* ys1 = new ListNode(1);
//    ListNode* ys2 = new ListNode(2);
//    ListNode* ys3 = new ListNode(3);
//    ListNode* ys4 = new ListNode(3);
//    ListNode* ys5 = new ListNode(4);
//    ListNode* ys6 = new ListNode(4);
//    ListNode* ys7 = new ListNode(5);
//    ys1->next = ys2;
//    ys2->next = ys3;
//    ys3->next = ys4;
//    ys4->next = ys5;
//    ys5->next = ys6;
//    ys6->next = ys7;
//    ListNode* head = test01(ys1);
//    while (head) {
//        head = head->next;
//        if(head) cout << head->val << endl;
//    }
//    return 0;
//}
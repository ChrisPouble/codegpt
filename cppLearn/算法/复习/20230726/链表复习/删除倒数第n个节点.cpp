#include <iostream>
using namespace std;

struct ListNode
{
    int val; //节点存储的值
    ListNode* next; //指向下一个节点的指针
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;

    ListNode* fast = dummyHead;
    ListNode* slow = dummyHead;

    n++;
    while (n-- && fast != NULL)
    {
        fast = fast->next;
    }

    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return dummyHead->next;
}

//int main()
//{
//    int target = 0;
//
//    ListNode* head1 = new ListNode(1);
//    ListNode* head2 = new ListNode(2);
//    ListNode* head3 = new ListNode(4);
//    ListNode* head4 = new ListNode(7);
//    ListNode* head5 = new ListNode(10);
//    ListNode* head6 = new ListNode(15);
//    head1->next = head2;
//    head2->next = head3;
//    head3->next = head4;
//    head4->next = head5;
//    head5->next = head6;
//
//    ListNode* ret = removeNthFromEnd(head1, target);
//    while (ret != NULL)
//    {
//        cout << ret->val << " ";
//        ret = ret->next;
//    }
//
//    cout << endl;
//    system("pause");
//    return 0;
//}
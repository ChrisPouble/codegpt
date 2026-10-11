#include <iostream>
using namespace std;

struct ListNode
{
    int val; //节点存储的值
    ListNode* next; //指向下一个节点的指针
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* tempremove(ListNode* head)
{
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* cur = dummyHead;

    while (cur->next != NULL && cur->next->next != NULL)
    {
        ListNode* temp1 = cur->next;
        ListNode* temp2 = cur->next->next->next;

        cur->next = cur->next->next;
        cur->next->next = temp1;
        temp1->next = temp2;

        cur = cur->next->next;
    }

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
//    ListNode* ret = tempremove(head1);
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
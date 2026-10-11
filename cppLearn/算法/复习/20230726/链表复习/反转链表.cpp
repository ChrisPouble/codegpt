#include <iostream>
using namespace std;

struct ListNode
{
    int val; //节点存储的值
    ListNode* next; //指向下一个节点的指针
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList1(ListNode* head)
{
    ListNode* pre = NULL;
    ListNode* cur = head;

    while (cur != NULL)
    {
        ListNode* temp = cur->next;
        cur->next = pre;

        pre = cur;
        cur = temp;
    }
    return pre;
}

ListNode* reverse(ListNode* pre, ListNode* cur)
{
    if (cur == NULL) return pre;
    ListNode* temp = cur->next;
    cur->next = pre;

    return reverse(cur, temp);
}

ListNode* reverseList2(ListNode* head)
{
    return reverse(NULL, head);
}

//int main()
//{
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
//    ListNode* ret = reverseList2(head1);
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
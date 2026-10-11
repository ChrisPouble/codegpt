#include <iostream>
using namespace std;

struct ListNode 
{
    int val; //节点存储的值
    ListNode* next; //指向下一个节点的指针
    ListNode(int x) : val(x), next(nullptr){}
};

ListNode* removeElements1(ListNode* head, int val)
{
    //删除头节点
    while (head != NULL && head->val == val)
    {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    //删除非头节点
    ListNode* cur = head;
    while (cur != NULL && cur->next != NULL)
    {
        if (cur->next->val == val)
        {
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
        else
        {
            cur = cur->next; //没找到就继续往下找
        }
    }
    return head;
}

ListNode* removeElements2(ListNode* head, int val)
{
    ListNode* dummyHead = new ListNode(0); //设置一个虚拟头节点
    dummyHead->next = head;

    ListNode* cur = dummyHead;
    while (cur->next != NULL)
    {
        if (cur->next->val == val)
        {
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
        else
        {
            cur = cur->next; //没找到就继续往下找
        }
    }
    cur = dummyHead->next;
    delete dummyHead;
    return cur;
}

//int main()
//{
//    int target = 7;
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
//    ListNode* ret = removeElements2(head1, target);
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
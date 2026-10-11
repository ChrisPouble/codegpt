#include <iostream>
using namespace std;

struct ListNode
{
    int val; //节点存储的值
    ListNode* next; //指向下一个节点的指针
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* detectCycle(ListNode* head)
{
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != NULL && fast ->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        
        if (slow == fast)
        {
            ListNode* index1 = fast;
            ListNode* index2 = head;

            while (index1 != index2)
            {
                index1 = index1->next;
                index2 = index2->next;
            }
            return index1;
        }
    }
    return NULL;
}

int main()
{
    int target = 0;

    ListNode* head1 = new ListNode(1);
    ListNode* head2 = new ListNode(2);
    ListNode* head3 = new ListNode(4);
    ListNode* head4 = new ListNode(7);
    ListNode* head5 = new ListNode(10);
    ListNode* head6 = new ListNode(15);
    head1->next = head2;
    head2->next = head3;
    head3->next = head4;
    head4->next = head5;
    head5->next = head6;
    head6->next = head4;

    ListNode* ret = detectCycle(head1);
    if (ret != NULL)
    {
        cout << ret->val << endl;
    }

    system("pause");
    return 0;
}
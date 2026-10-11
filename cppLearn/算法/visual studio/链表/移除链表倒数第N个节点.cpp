//#include <iostream>
//using namespace std;
//
//struct ListNode
//{
//    int val;  //节点上存储的元素
//    ListNode* next;  //指向下一个节点的指针
//    ListNode(int x) : val(x), next(nullptr) {}  //节点的构造函数
//};
//
//ListNode* test01(ListNode* head, int n)
//{
//    ListNode* dummyHead = new ListNode(0);
//    dummyHead->next = head;
//    ListNode* fast = dummyHead;
//    ListNode* slow = dummyHead;
//
//    n++; //不用fast = fast->next;的原因是因为fast有可能是空指针
//    while(n-- && fast != NULL)
//    {
//        fast = fast->next;
//    }
//    while(fast != NULL)
//    {
//        fast = fast->next;
//        slow = slow->next;
//    }
//    ListNode* temp = slow->next;
//    slow->next = slow->next->next;
//    delete temp;
//    return dummyHead->next;
//}
//
//int main()
//{
//    ListNode* head1 = new ListNode(1);
//    ListNode* head2 = new ListNode(4);
//    ListNode* head3 = new ListNode(2);
//    ListNode* head4 = new ListNode(4);
//    ListNode* head5 = new ListNode(7);
//    head1->next = head2;
//    head2->next = head3;
//    head3->next = head4;
//    head4->next = head5;
//
//    ListNode* head_return = test01(head1, 2);
//
//    while (head_return != NULL)
//    {
//        cout << head_return->val << " ";
//        head_return = head_return->next;
//    }
//    cout << endl;
//    system("pause");
//    return 0;
//}

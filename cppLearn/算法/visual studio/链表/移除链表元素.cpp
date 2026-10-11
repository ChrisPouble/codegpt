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
//ListNode* test01(ListNode* head, int  val)
//{
//    // 删除头节点
//    while (head != NULL && head->val == val)
//    {
//        ListNode* tmp = head;
//        head = head->next;
//        delete tmp;
//    }
//
//    // 删除非头节点
//
//    //要设置一个临时指针指向当前的节点,不能直接操作head指针,
//    //否则操作完成后,head指向了链表尾部nullptr,就找不到整个链表了,因为是单向链表;
//    ListNode* cur = head; //临时指针
//    while (cur != NULL && cur->next != NULL)
//    {
//        if (cur->next->val == val)
//        {
//            ListNode* tmp = cur->next;
//            cur->next = cur->next->next;
//            delete tmp;
//        }
//        else
//        {
//            cur = cur->next; //没找到就向下继续找
//        }
//    }
//    return head;
//}
//
//ListNode* test02(ListNode* head, int  val)
//{
//    ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头节点
//    dummyHead->next = head; //将虚拟头节点指向head
//    ListNode* cur = dummyHead;
//    while (cur->next != NULL)
//    {
//        if (cur->next->val == val)
//        {
//            ListNode* tmp = cur->next;
//            cur->next = cur->next->next;
//            delete tmp;
//        }
//        else
//        {
//            cur = cur->next;
//        }
//    }
//    head = dummyHead->next;
//    delete dummyHead;
//    return head;
//}

//int main()
//{
//    ListNode* head1 = new ListNode(1);
//    ListNode* head2 = new ListNode(4);
//    ListNode* head3 = new ListNode(2);
//    ListNode* head4 = new ListNode(4);
//    head1->next = head2;
//    head2->next = head3;
//    head3->next = head4;
//
//    ListNode*  head_return=test02(head1,4);
//
//    while (head_return) 
//    {
//        cout << head_return->val << " ";
//        head_return = head_return->next;
//    }
//
//
//    system("pause");
//    return 0;
//}

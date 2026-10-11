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
//ListNode* test01(ListNode* head)
//{
//    ListNode* temp; //保存cur下一个节点
//    ListNode* cur = head;
//    ListNode* pre = NULL;
//    while(cur != NULL)
//    { 
//        temp = cur->next;
//        cur->next = pre; //反转操作
//        //更新pre 和 cur 指针
//        pre = cur;
//        cur = temp;
//    }
//    return pre;
//}
//
//ListNode* test02func(ListNode* pre, ListNode* cur)
//{
//    if (cur == NULL) return pre;
//    ListNode* temp = cur->next;
//    cur->next = pre;
//    //比较双指针和递归的代码
//    //pre = cur;
//    //cur = temp;
//    return test02func(cur, temp);
//}
//
//ListNode* test02(ListNode* head)
//{
//    //比较双指针和递归的初始化代码
//    //ListNode* cur = head;
//    //ListNode* pre = NULL;
//    return test02func(NULL, head);
//}
//
//int main()
//{
//    ListNode* head1 = new ListNode(1);
//    ListNode* head2 = new ListNode(4);
//    ListNode* head3 = new ListNode(2);
//    ListNode* head4 = new ListNode(4);
//    ListNode* head5 = new ListNode(7);
//    ListNode* head6 = new ListNode(5);
//    head1->next = head2;
//    head2->next = head3;
//    head3->next = head4;
//    head4->next = head5;
//    head5->next = head6;
//
//    ListNode* head_return = test02(head1);
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
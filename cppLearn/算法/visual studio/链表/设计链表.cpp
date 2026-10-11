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
//class MyListNode
//{
//public:
//    //初始化链表
//    MyListNode()
//    {
//        _dummyHead = new ListNode(0);
//        _size = 0;
//    }
//    
//    //查找第n个节点的值
//    int get(int index)
//    {
//        if (index > (_size - 1) || index < 0)
//        {
//            return -1;
//        }
//        ListNode* cur = _dummyHead->next;
//        while (index)
//        {
//            cur = cur->next;
//            index--;
//        }
//        return cur->val;
//    }
//
//    //头部插入节点
//    void addAtHead(int val)
//    {
//        ListNode* newNode = new ListNode(val);
//        newNode->next = _dummyHead->next;
//        _dummyHead->next = newNode;
//        _size++;
//    }
//
//    //尾部插入节点
//    void addAtTail(int val)
//    {
//        ListNode* newNode = new ListNode(val);
//        ListNode* cur = _dummyHead;
//        while(cur->next != NULL)
//        {
//            cur = cur->next;
//        }
//        newNode->next = cur->next;
//        cur->next = newNode;
//        _size++;
//    }
//
//    //第n个节点前插入节点
//    void addAtindex(int val)
//    {
//        ListNode* newNode = new ListNode(val);
//        ListNode* cur = _dummyHead;
//        while (val)
//        {
//            cur = cur->next;
//            val--;
//        }
//        cur->next = newNode;
//        _size++;
//    }
//
//    //删除第n个节点
//    void addAtindex(int val)
//    {
//        ListNode* newNode = new ListNode(val);
//        ListNode* cur = _dummyHead;
//        while (val)
//        {
//            cur = cur->next;
//            val--;
//        }
//        cur->next = cur->next->next;
//        _size--;
//    }
//
//public:
//    int _size;
//    ListNode* _dummyHead;
//};
//
//int main()
//{
//    system("pause");
//    return 0;
//}                                           
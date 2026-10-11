#include <iostream>

using namespace std;

//空指针访问成员函数

class person
{
public:

    void showclassname()
    {
        cout<<"this is person class" <<endl;//这是人类
    }

    void showpersonage()
    {
        //报错原因是因为传入的指针是为NULL

        if(this==NULL)
        {
            return;
        }

        cout<<"age = "<<m_age<<endl;
    }

    int m_age;
};

void test01()
{
    person * p=NULL;

    p->showclassname();

    p->showpersonage();
}

int main()
{
    test01();
    return 0;
}

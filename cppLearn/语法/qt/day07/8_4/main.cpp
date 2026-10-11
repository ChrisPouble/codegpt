#include <iostream>

using namespace std;
#include <string>
//结构体定义
struct student
{
    //成员列表
    string name; //姓名
    int age; //年龄
    int score; //分数
};
int main() {
    struct student s1{"chris",11,95};
    struct student *p=&s1;
    p->age=12;
    cout << "name " << p->name
         << " age " << p->age
         << " score " << p->score <<endl;

    return 0;
}

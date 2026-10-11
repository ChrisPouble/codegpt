#include <iostream>

using namespace std;
#include <string>
struct student{
    string name;
    int age;
    int score;
};

int main()
{
    struct student s1;
    s1.name="chris";
    s1.age=11;
    s1.score=95;
    cout << "name " << s1.name << " age " << s1.age << " score " <<
    s1.score << endl;
    //结构体变量创建方式2
    struct student stu2 = { "李四",19,60 };
    cout << "姓名：" << stu2.name << " 年龄：" << stu2.age << " 分数：" <<
    stu2.score << endl;
    return 0;
}

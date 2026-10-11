#include <iostream>

using namespace std;
#include<string>
struct student{
    string name;
    int age;
    int score;
};
struct teacher{
    string name;
    int age;
    struct student stu;
};
int main()
{
    struct teacher t1;
    t1.name="dabao";
    t1.age=11;

    t1.stu.name="xiaobao";
    t1.stu.age=9;
    t1.stu.score=69;
    cout << "t1.name " << t1.name << " t1.age " << t1.age << endl;

    cout << "t1.stu.name " << t1.stu.name << " t1.stu.age " << t1.stu.age
    << " t1.stu.score  " << t1.stu.score << endl;
    return 0;
}

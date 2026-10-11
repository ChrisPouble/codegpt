#include <iostream>

using namespace std;
#include<string>

class student{
public:

    string name;
    string xuehao;

    void xinxi(string name,string xuehao){
        cout<<"name: "<< name<<" xuehao: "<< xuehao << endl;
        cout<< endl;
    }
};

int main()
{
    student s1;
    s1.name="s1";
    s1.xuehao="25";
    s1.xinxi("s1","25");
    return 0;
}

#include <iostream>

using namespace std;

#include<string>
struct hero{
    string name;
    int age;
    string gender;
};
void bubble(hero sanguo[],int len){

    for(int i=0;i<len-1;i++) {
        for(int j=0;j<len-1-i;j++) {
            if(sanguo[j].age>sanguo[j+1].age){
                hero temp=sanguo[j];
                sanguo[j]=sanguo[j+1];
                sanguo[j+1]=temp;
            }
        }
    }


}
void printhero(hero sanguo[],int len){
    for(int i=0;i<len;i++) {
        cout<<"name "<<sanguo[i].name
        << " age " << sanguo[i].age
        << " gender " <<sanguo[i].gender<< endl;
    }
}
int main()
{
    hero sanguo[5]={
        {"liu bei",23,"man"},
        {"guan yu",22,"man"},
        {"zhang fei",20,"man"},
        {"zhao yun",21,"man"},
        {"diao chan",19,"woman"},
    };
    int len=sizeof(sanguo)/sizeof (sanguo[0]);
    bubble(sanguo,len);
    printhero(sanguo,len);
    return 0;
}

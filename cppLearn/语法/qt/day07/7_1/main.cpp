#include <iostream>

using namespace std;

void func(int &a){
    cout<<"this is func"<<endl;
}

void func(const int &a){
    cout<<"this is func!"<<endl;
}
int main(){
    int a=10;
    func(a);

    return 0;
}
//int a[10000];
//int main()
//{
//    int n,temp;
//    cin>>n;
//    for(int i=0;i<n;i++) {
//        cin>>a[i];
//    }

//    int count=0;
//    bool is_ordered=false;
//    for(int i=0;i<n-1;i++) {
//        if (is_ordered){
//            break;
//        }
//        is_ordered=true;

//        for(int j=0;j<n-1-i;j++) {
//            count++;
//            if(a[j]>a[j+1]){
//                temp=a[j];
//                a[j]=a[j+1];
//                a[j+1]=temp;
//                is_ordered=false;
//            }
//        }
//    }
//    cout<<count<<endl;
//    for(int i=0;i<n;i++) {
//        cout<<a[i]<<" ";
//    }
//    return 0;
//}

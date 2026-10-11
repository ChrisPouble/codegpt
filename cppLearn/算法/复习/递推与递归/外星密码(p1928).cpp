//#include <iostream>
//using namespace std;
//
//string p1928()
//{
//    string s = "", x;
//    char c; int d;
//    while (cin >> c) { //持续读完字符, 直到全部读完
//        if (c == '[') { //发现一个“压缩区”
//            cin >> d; //读入d
//            x = p1928(); //递归地读入x
//            for (int i = 1; i <= d; i++) //从复d次拼接
//                s += x;
//        }
//        else if(c == ']') return s; //压缩区结束, 返回已经处理好的s
//        else s += c; //如果不是'['和']', 那还是s的字符, 加进去既可
//    }
//    return s;
//}
//
//int main()
//{
//    cout << p1928() << endl;
//    system("pause");
//    return 0;
//}
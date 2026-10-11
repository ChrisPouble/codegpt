#include <iostream>

using namespace std;

class cube{
public:

    //设置长
    void setl(int l){
        m_l=l;
    }

    //获取长
    int getl(){
        return m_l;
    }

    //设置宽
    void setw(int w){
        m_w=w;
    }

    //获取宽
    int getw(){
        return m_w;
    }

    //设置高
    void seth(int h){
        m_h=h;
    }

    //获取宽
    int geth(){
        return m_h;
    }

    //获取立方体的面积
    int gets(){
        return 2*m_l*m_w+2*m_l*m_h+2*m_h*m_w;
    }

    //获取立方体的体积
    int getv(){
        return m_l*m_w*m_h;
    }

//    bool issame(cube &c1,cube &c2){
//        if(c1.getl() == c2.getl() && c1.getw() == c2.getw() && c1.geth() == c2.geth()){
//            return true;
//        }
//        return false;
//    }

    bool issamebyclass(cube &c){
        if(m_l == c.getl() && m_w == c.getw() && m_h == c.geth()){
            return true;
        }
        return false;
    }

private:

    int m_l;//长
    int m_w;//宽
    int m_h;//高
};

bool issame(cube &c1,cube &c2   ){
    if(c1.getl() == c2.getl() && c1.getw() == c2.getw() && c1.geth() == c2.geth()){
        return true;
    }
    return false;
}


int main()
{
    cube c1;
    c1.setl(10);
    c1.setw(10);
    c1.seth(10);
    cout<<"c1 s wei: "<<c1.gets()<<endl;
    cout<<"c1 v wei: "<<c1.getv()<<endl;

    cube c2;
    c2.setl(10);
    c2.setw(10);
    c2.seth(10);

    bool ret=issame(c1,c2);
    if(ret){
        cout<<"c1 same c2 "<<endl;
    }
    else{
        cout<<"c1 diffrent c2 "<<endl;
    }
    ret=c1.issamebyclass(c2);
    if(ret){
        cout<<"c1 same c2 "<<endl;
    }
    else{
        cout<<"c1 diffrent c2 "<<endl;
    }

    return 0;
}

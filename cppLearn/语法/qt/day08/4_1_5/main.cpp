#include <iostream>

using namespace std;
//点类
class point{
public:
    //设置x
    void setx(int x){
        m_x=x;
    }
    //获取x
    int getx(){
        return m_x;
    }
    //设置y
    void sety(int y){
        m_y=y;
    }
    //获取y
    int gety(){
        return m_y;
    }
private:
    int m_x;
    int m_y;

};



//圆类
class yuan{
public:

    //设置半径
    void setr(int r){
        m_r=r;
    }
    //获取半径
    int getr(){
        return m_r;
    }
    //设置圆心
    void setcenter(point center){
        m_center=center;
    }
    //获取半径
    point getcenter(){
        return m_center;
    }
private:
    int m_r;//半径
    point m_center;
};

//判断点和圆的关系
void isinyuan(yuan &c,point &p){
    //计算两点之间距离的平方
    int distance=
    (c.getcenter().getx()-p.getx())*(c.getcenter().getx()-p.getx())+
    (c.getcenter().gety()-p.gety())*(c.getcenter().gety()-p.gety());

    //计算半径的平方
    int rdistanc=c.getr()*c.getr();

    //判断关系
    if(distance==rdistanc){
        cout<<"dian zai yuan shang!"<<endl;
    }
    else if (distance>rdistanc) {
        cout<<"dian zai yuan wai!"<<endl;
    }
    else {
        cout<<"dian zai yuan nei!"<<endl;
    }
}

int main()
{
    //创建圆
    yuan c;
    c.setr(10);
    point center;
    center.setx(10);
    center.sety(0);
    c.setcenter(center);

    //创建点
    point p;
    p.setx(10);
    p.sety(9);

    //判断关系
    isinyuan(c,p);

    return 0;
}

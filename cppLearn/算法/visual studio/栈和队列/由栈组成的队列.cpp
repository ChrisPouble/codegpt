#include <iostream>
#include <stack>
using namespace std;

class myQueue
{
public:
    stack<int> out;
    stack<int> in;
    myQueue()
    {

    }

    void push(int x)
    {
        in.push(x);
    }

    int pop()
    {
        while (!in.empty())
        {
            out.push(in.top());
            in.pop();
        }
        int temp = out.top();
        out.pop();
        return temp;
    }

    int peek()
    {
        int ret = this->pop();
        out.push(ret);
        return ret;
    }

    bool empty()
    {
        return in.empty() && out.empty() ? true : false;
    }
};

    //int main()
    //{
    //myQueue st;
    //bool ret = st.empty();

    //if (ret)
    //{
    //    cout << "ret = true" << endl;
    //}
    //else
    //{
    //    cout << "ret = false" << endl;
    //}


    //st.push(12);
    //bool rex = st.empty();

    //if (rex)
    //{
    //    cout << "rex = true" << endl;
    //}
    //else
    //{
    //    cout << "rex = false" << endl;
    //}

    //cout << st.peek() << endl;
    //cout << st.pop() << endl;
    //
    //bool rey = st.empty();

    //if (rey)
    //{
    //    cout << "rey = true" << endl;
    //}
    //else
    //{
    //    cout << "rey = false" << endl;
    //}
    //system("pause");
    //return 0;
    //}
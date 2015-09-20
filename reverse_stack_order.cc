#include <iostream>
#include <stack>
using namespace std;

int getrmlastelement(stack<int>& s) {
    int result = 0;
    if(!s.empty()) {
        result = s.top();
        s.pop();
    }
    if(s.empty()) {
        return result;
    }
    else {
        int last = getrmlastelement(s);
        s.push(result);
        return last;
    }

}

void reversestackorder(stack<int>& q) {
    if(q.empty())
        return;
    int i = getrmlastelement(q);
    reversestackorder(q);
    q.push(i);
}

int main() {
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);

    reversestackorder(s);

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;

    return 0;
}

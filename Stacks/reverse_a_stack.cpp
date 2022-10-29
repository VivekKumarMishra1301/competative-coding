#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    int count =0;
    int x;
    while(!input.empty()){
        extra.push(input.top());
        input.pop();
        count++;
    }
    while(count--){
        
        int x=extra.top();
        extra.pop();
        int counter=0;
        while(!input.empty()){
            extra.push(input.top());
            input.pop();
            counter++;
        }
        input.push(x);
        while(counter--){
            input.push(extra.top());
            extra.pop();
        }
        
    }
}

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}
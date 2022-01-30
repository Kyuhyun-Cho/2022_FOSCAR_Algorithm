#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    stack<char> my_stack;
    queue<char> my_queue;
    
    string flag = "stack_mode";

    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '<') {
            while (!my_stack.empty()) {
                cout << my_stack.top();
                my_stack.pop();
            }
            flag = "queue_mode";
        }

        if (flag == "queue_mode") {
            my_queue.push(s[i]);
        }

        if (flag == "stack_mode" && s[i] == ' ') {
            while (!my_stack.empty()) {
                cout << my_stack.top();
                my_stack.pop();
            }
            cout << " ";
            continue;
        }

        if (flag == "stack_mode") {
            my_stack.push(s[i]);
        }

        if (s[i] == '>') {
            while (!my_queue.empty()) {
                cout << my_queue.front();
                my_queue.pop();
            }
            flag = "stack_mode";
        }
    }
    
    while (!my_stack.empty()) {
        cout << my_stack.top();
        my_stack.pop();
    }

    cout << endl;
} 
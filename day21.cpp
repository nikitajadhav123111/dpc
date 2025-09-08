#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int>& st, int item) {
    if (st.empty()) {
        st.push(item);
        return;
    }

    int top = st.top();
    st.pop();
    insertAtBottom(st, item);
    st.push(top);
}

// Function to reverse the stack using recursion
void reverseStack(stack<int>& st) {
    if (st.empty()) return;

    int top = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, top);
}

// Utility function to print stack (from top to bottom)
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Original Stack (top to bottom): ";
    printStack(st);

    // Push again since printStack consumes the stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    reverseStack(st);

    cout << "Reversed Stack (top to bottom): ";
    printStack(st);

    return 0;
}


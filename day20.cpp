#include <bits/stdc++.h>
using namespace std;

// Function to insert an element into the sorted stack
void insertSorted(stack<int>& st, int element) {
    if (st.empty() || st.top() <= element) {
        st.push(element);
        return;
    }
    
    int topElement = st.top();
    st.pop();
    insertSorted(st, element);
    st.push(topElement);
}

// Function to sort the stack using recursion
void sortStack(stack<int>& st) {
    if (st.empty()) return;
    
    int topElement = st.top();
    st.pop();
    sortStack(st);          // Sort remaining stack
    insertSorted(st, topElement); // Insert topElement in correct position
}

// Utility function to print the stack
void printStack(stack<int> st) {
    vector<int> result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    reverse(result.begin(), result.end()); // To print bottom → top
    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);
    
    cout << "Original stack: ";
    printStack(st);
    
    sortStack(st);
    
    cout << "Sorted stack: ";
    printStack(st);
    
    return 0;
}

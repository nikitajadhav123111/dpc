#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(const string& expression) {
    stack<int> st;
    stringstream ss(expression);
    string token;
    
    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/") st.push(a / b);  
        } else {
            st.push(stoi(token));
        }
    }
    
    return st.top();
}

int main() {
    cout << evaluatePostfix("2 1 + 3 *") << endl;          
    cout << evaluatePostfix("4 13 5 / +") << endl;         
    cout << evaluatePostfix("10 6 9 3 + -11 * / * 17 + 5 +") << endl; 
    return 0;
}

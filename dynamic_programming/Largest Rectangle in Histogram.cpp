int Solution::largestRectangleArea(vector<int> &A) {
    
    int n = A.size();
    int ans = 0;
    stack<int> st;
    int i = 0;
    while(i < n) {
        if(st.empty() || A[st.top()] <= A[i]) {
            st.push(i);
            i++;
        } else {
            int base = A[st.top()];
            st.pop();
            int area ;
            if (st.empty()) {
                area = base*(i );
            } else {
                area = base*(i - st.top() - 1);
            }
            
            ans = max(ans, area);
        }
    }
    while(st.empty() == false) {
        int base = A[st.top()];
        int area ;
        st.pop();
            if (st.empty()) {
                area = base*(i);
            } else {
                area = base*(i - st.top() - 1);
            } 
            ans = max(ans, area);
    }
    return ans;
}

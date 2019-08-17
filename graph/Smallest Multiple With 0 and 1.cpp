string Solution::multiple(int A) {
    
    if(A==0)
        return "0";
        
    queue<int> q;
    vector<int> visit(A + 1, 0);
    vector<int> parent(A + 1, -1);
    vector<int> val(A + 1, -1);
    
    q.push(1%A);    
    parent[1%A] = -1;
    val[1%A] = 1;
    visit[1%A] = 1;
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        if (temp == 0) 
        {
            string ans = "";
            while(temp != -1) {
                ans += val[temp] + '0';
                temp = parent[temp];
            }
        
            string result = "";
            for (int i = ans.length() - 1; i >=0; i--) {
                result += ans[i];
            }   
            
        return result;
        }
            
        int n0 = (temp*10) % A;
        int n1 = (temp * 10 + 1) % A;
        
        if(visit[n0] == 0) {
            visit[n0] = 1;
            q.push(n0);
            val[n0] = 0;
            parent[n0] = temp;
        }
        if(visit[n1] == 0) {
            visit[n1] = 1;
            q.push(n1);
            val[n1] = 1;
            parent[n1] = temp;
        }
}
}
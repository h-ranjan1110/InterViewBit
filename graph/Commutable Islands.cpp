

    int Solution::solve(int A, vector<vector<int> > &B) {
        
        // vector<vector<pair<int, int>> > adj(A + 1, vector<pair<int, int>>(A + 1));
        vector<pair<int, int>> adj[A + 1];
        for (int i = 0; i < B.size(); i++) {
            adj[B[i][0]].push_back(make_pair(B[i][1], B[i][2]));
            adj[B[i][1]].push_back(make_pair(B[i][0], B[i][2]));
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > q;
        int cost = 0;
        q.push(make_pair(0, 1));
        vector<int> visit(A + 1, 0);
        
        while(!q.empty()) {
            pair<int, int> p = q.top();
            q.pop();
            int x = p.second;
            if(visit[x] == 1) continue;
            cost += p.first;
            visit[x] = 1;
            for (int i = 0; i < adj[x].size(); i++) {
                int y = adj[x][i].first;
                if(visit[y] == 0) {
                    q.push(make_pair(adj[x][i].second, y));
                }
            }
            
        }
        return cost;
    }


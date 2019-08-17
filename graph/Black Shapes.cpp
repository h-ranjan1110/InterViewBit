

    void dfs(int i, int j, vector<string> &A, vector<vector<int>> &visit) {
        
        int n = A.size(), m = A[0].length();
        
        if(i > 0 && visit[i - 1][j] == 0 && A[i - 1][j] == 'X') {
            visit[i - 1][j] = 1;
            dfs(i - 1, j, A, visit);
        }
        if(j > 0 && visit[i][j - 1] == 0 && A[i][j - 1] == 'X') {
            visit[i][j - 1] = 1;
            dfs(i, j - 1, A, visit);
        }
        // if(i < n - 1 && j > 0 && visit[i + 1][j - 1] == 0 && A[i + 1][j - 1] == 'X') {
        //     visit[i + 1][j - 1] = 1;
        //     dfs(i + 1, j - 1, A, visit);
        // }
        // if(i > 0 && j < m - 1 && visit[i - 1][j + 1] == 0 && A[i - 1][j + 1] == 'X') {
        //     visit[i - 1][j + 1] = 1;
        //     dfs(i - 1, j + 1, A, visit);
        // }
        if(j < m - 1 && visit[i][j + 1] == 0 && A[i][j + 1] == 'X') {
            visit[i][j + 1] = 1;
            dfs(i, j + 1, A, visit);
        }
        if(i < n - 1 && visit[i + 1][j] == 0 && A[i + 1][j] == 'X') {
            visit[i + 1][j] = 1;
            dfs(i + 1, j, A, visit);
        }
    }
     
     
    int Solution::black(vector<string> &A) {
        
        int ans = 0;
        vector<vector<int>> visit(A.size(), vector<int>(A[0].length(), 0));
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].length(); j++) {
                if (visit[i][j] == 0 && A[i][j] == 'X') {
                    dfs(i, j, A, visit);
                    ans++;
                }
                
            }
        }
        return ans;
    }


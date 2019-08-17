

    void dfs(int i, int j, vector<vector<char> > &A, vector<vector<int>> &visit) {
        int n = A.size(), m = A[0].size();
        if(i > 0 && visit[i - 1][j] == 0 && A[i - 1][j] == 'O'){
            visit[i - 1][j] = 1;
            dfs(i - 1, j, A, visit);
        }
        if(j > 0 && visit[i][j - 1] == 0 && A[i][j - 1] == 'O'){
            visit[i][j - 1] = 1;
            dfs(i, j - 1, A, visit);
        }
        if(i < n - 1 && visit[i + 1][j] == 0 && A[i + 1][j] == 'O'){
            visit[i + 1][j] = 1;
            dfs(i + 1, j, A, visit);
        }
        if(j < m - 1 && visit[i][j + 1] == 0 && A[i][j + 1] == 'O'){
            visit[i][j + 1] = 1;
            dfs(i, j + 1, A, visit);
        }
    }
     
    void Solution::solve(vector<vector<char> > &A) {
        // Do not write main() function.
        // Do not read input, instead use the arguments to the function.
        // Do not print the output, instead return values as specified
        // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
        vector<vector<int>> visit(A.size(), vector<int>(A[0].size(), 0));
        int n = A.size(), m = A[0].size();
        if (n != 1 && m != 1) {
            // Base cases
        // if (A[0][0] == 'O') {
        //     visit[0][0] = 1;
        // }
        // if (A[n - 1][0] == 'O') visit[n - 1][0] = 1;
        // if (A[0][m - 1] == 'O') visit[0][m - 1] = 1;
        // if (A[n - 1][m - 1] == 'O') visit[n - 1][m - 1] = 1;
            
        for (int i = 0; i < A.size(); i++) {
            if(A[i][0] == 'O' && visit[i][0] == 0) {
                visit[i][0] = 1;
                dfs(i, 0, A, visit);
            }
            if(A[i][m - 1] == 'O' && visit[i][m - 1] == 0) {
                visit[i][m - 1] = 1;
                dfs(i, m - 1, A, visit);
            }
        }
        for (int j = 0; j < m; j++) {
            if (A[0][j] == 'O' && visit[0][j] == 0) {
                visit[0][j] = 1;
                dfs(0, j, A, visit);
            }
            if (A[n - 1][j] == 'O' && visit[n - 1][j] == 0) {
                visit[n - 1][j] = 1;
                dfs(n - 1, j, A, visit);
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(A[i][j] == 'O' && visit[i][j] == 0) {
                    A[i][j] = 'X';
                }
            }
        }
        } 
        
        
        
    }


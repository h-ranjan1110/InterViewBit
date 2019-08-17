string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<int> > rec(A + 1, vector<int>(B + 1, 0));
    
    
    if(A == 0 || B == 0) {
        if(C>0) return "NO";
    }
    
    for (int i = 0; i < C; i++) {
        for (int j = 0; j <= A; j++) {
            for (int k = 0; k <= B; k++) {
                if(sqrt(pow(E[i] - j , 2) + pow(F[i] - k, 2)) <= D ) {
                    rec[j][k] = -1;
                }
            }
        }
    }
    queue<pair<int, int> > q;
    rec[0][0] = 1;
    if(rec[0][0] == -1 || rec[A][B] == -1) return "NO";
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        
        int x0 = q.front().first;
        int y0 = q.front().second;
        q.pop();
        if (x0 > 0 && y0 > 0 && rec[x0 - 1][y0 - 1] == 0) {
            rec[x0 - 1][y0 - 1] = 1;
            q.push(make_pair(x0 - 1, y0 - 1));
        }
        if (y0 > 0 && rec[x0][y0 - 1] == 0) {
            rec[x0][y0 - 1] = 1;
            q.push(make_pair(x0, y0 - 1));
        }
        if (x0 > 0 && rec[x0 - 1][y0] == 0) {
            rec[x0 - 1][y0] = 1;
            q.push(make_pair(x0 - 1, y0));
        }
        if (x0 < A && y0 < B && rec[x0 + 1][y0 + 1] == 0) {
            rec[x0 + 1][y0 + 1] = 1;
            q.push(make_pair(x0 + 1, y0 + 1));
        }
        if (x0 < A && rec[x0 + 1][y0] == 0) {
            rec[x0 + 1][y0] = 1;
            q.push(make_pair(x0 + 1, y0));
        }
        if (y0 < B && rec[x0][y0 + 1] == 0) {
            rec[x0][y0 + 1] = 1;
            q.push(make_pair(x0, y0 + 1));
        }
        if (x0 > 0 && y0 < B && rec[x0 - 1][y0 + 1] == 0) {
            rec[x0 - 1][y0 + 1] = 1;
            q.push(make_pair(x0 - 1, y0 + 1));
        }
        if (x0 < A && y0 > 0 && rec[x0 + 1][y0 - 1] == 0) {
            rec[x0 + 1][y0 - 1] = 1;
            q.push(make_pair(x0 + 1, y0 - 1));
        }
        
    }
    if (rec[A - 1][B - 1] == 1) return "YES";
    else return "NO";
    
}

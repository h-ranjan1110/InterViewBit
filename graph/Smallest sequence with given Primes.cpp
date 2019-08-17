

    vector<int> Solution::solve(int A, int B, int C, int D) {
        
        vector<int > ans;
        ans.push_back(1);
        int i1 = 0, i2 = 0, i3 = 0;
        while (ans.size() <= D) {
            
        
            int entry = min(ans[i1] * A, min(ans[i2] * B, ans[i3] * C));
            
            if (entry == ans[i1] * A) {
                    i1++;
                    if (ans[ans.size() - 1] != entry) {
                        ans.push_back(entry);   
                    }
            } else if (entry == ans[i2] * B) {
                if (ans[i2] == A || ans[i2] == C) {
                    i2++;
                } else {
                    i2++;
                    if (ans[ans.size() - 1] != entry) {
                        ans.push_back(entry);   
                    }
                }
                
            } else if (entry == ans[i3] * C) {
                if (ans[i3] == A) {
                    i3++;
                } else {
                    i3++;
                    if (ans[ans.size() - 1] != entry) {
                        ans.push_back(entry);   
                    }
                }
            }
            
        }
        ans.erase(ans.begin(), ans.begin() + 1);
        return ans;
    }


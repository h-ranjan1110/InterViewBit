vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    
    vector<vector<int> > level;
    queue<TreeNode* > q;
    q.push(A);
    // level.push_back(vector<int> (1, A->val));
    while(!q.empty()) {
        vector<int > temp;
        int count = q.size();
        
        while(count--) {
            TreeNode* t = q.front();
            temp.push_back(t->val);
            
            if(t->left != NULL) {
                q.push(t->left);
            }
            if (t->right != NULL) {
                q.push(t->right);
            }
            q.pop();
        }
        
        if(temp.size() > 0) {
            level.push_back(temp);
        }
        
    }
    return level;
}
bool tree(string s1, string s2) {
    
    int l = s1.length();
    int m = s2.length();
    if(l != m) return false;
    if (l == 1) {
        return s1[0] == s2[0];
    }
    if (s1 == s2 ) return true;
    string t1 = s1;
    string t2 = s2;
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    if (t1 != t2) return false;
    
    for (int i = 1; i < l; i++) {
        
        if (tree(s1.substr(0, i), s2.substr(0, i)) && tree(s1.substr(i), s2.substr(i))) {
            return true;
        }
        
        if (tree(s1.substr(0, i), s2.substr(l - i)) && tree(s1.substr(i), s2.substr(0, i))) {
            return true;
        }
    }
}

int Solution::isScramble(const string A, const string B) {
    if (tree(A, B)) {
        return 1;
        cout<< "sdfdsf";
    } else {
        return 0;
    }
}

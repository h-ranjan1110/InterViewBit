void tree(int n, int k, std::vector< vector<int> > &ans, std::vector<int> &current_ans)
{
	if(k == 0)
	{
		std::vector<int> temp = current_ans;
		sort(temp.begin(), temp.end());
		ans.push_back(temp);
		return;
	}

	if (n == 0 || k > n)
	{
		return;
	}

	tree(n - 1, k, ans, current_ans);
	current_ans.push_back(n);
	tree(n - 1, k - 1, ans, current_ans);
	current_ans.pop_back();
	return;
}

vector<vector<int> > Solution::combine(int A, int B) 
{
	std::vector<int> current_ans;
	std::vector<std::vector<int> > ans;
	tree(A, B, ans, current_ans);
	sort(ans.begin(), ans.end());
	return ans;
	
};
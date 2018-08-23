
//字符串分割
bool wordBreak(string s, unordered_set<string> &dict){
	if (s.empty() || dict.empty()){
		return false;
	}
	int n = s.size();
	vector<bool> can_break(n + 1, false);

	//初始化
	can_break[0] = true;

	//递推
	for (int i = 1; i <= n; ++i){
		//F[i]=j<i && F(j)&&substr(j+1,i)
		for (int j = 0; j < i; j++){
			if (can_break[j] && dict.find(s.substr(j, i - j)) != dict.end()){
				can_break[i] = true;
				break;
			}
		}
	}
	//结果
	return can_break[n];
}

//动态规划
int Find(vector<int> v){
	if (v.empty())
		return -1;
	int n = v.size();
	vector<int> great_sum(n, 0);
	great_sum[0] = v[0];
	int maxsum = 0;
	for (int i = 1; i < n; ++i){
		//F(i)=max{F(i-1)+array[i],array[i]}
		great_sum[i] = max(great_sum[i - 1] + v[i], v[i]);
		maxsum = great_sum[i];
	}
	int result = great_sum[0];
	for (int i = 1; i < n; ++i){
		//max(F(i))
		result = max( result, great_sum[i] );
	}
	return result;
}

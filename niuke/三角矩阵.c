
//三角矩阵
//从上往下定义
//状态：双序列动归    F(i,j):从(0,0)走到(i,j)的最短路径和
//递推：中间位置：F(i,j)=min{F(i-1,j-1),F(i-1,j)+F(i,j)}
//      左边界位置：F(i,j)=F(i-1,j)+F(i,j)
//      右边界位置：F(i,j)=F(i-1,j-1)+F(i,j)
//初始化：  F(0,0)=(0,0)
//返回结果： min(F(n-1,j))

int minimumTotal(vector<vector<int>> &triangle){
	if (triangle.empty())
		return 0;
	vector<vector<int>> min_sum(triangle);
	int line = triangle.size();
	min_sum[0][0] = triangle[0][0];
	for (int i = 0; i < line; ++i){
		for (int j = 0; j <= i; ++j){
			if (j == 0){//left
				min_sum[i][j] = min_sum[i - 1][j] + triangle[i][j];
			}
			else if (j == i){//right
				min_sum[i][j] = min_sum[i - 1][j - 1] + triangle[i][j];
			}
			else{//mid
				min_sum[i][j] = min(min_sum[i - 1][j], min_sum[i - 1][j - 1]);
				min_sum[i][j] = min_sum[i][j] + triangle[i][j];
			}
		}
	}
	int result = min_sum[line - 1][0];
	for (int i = 1; i < line; ++i){
		result = min(result, min_sum[line - 1][i]);
	}
	return result;
}

//从下往上定义
//状态：   F(i,j):  从(i,j)到最后一行的最短路径和
//递推：   F(i,j)=min{F(i+1,j),F(i+1,j+1)}+(i,j)
//初始化： F(n-1,j)=(n-1,j)
//返回值： F(0,0)
//不用考虑左右边界

int minimumTotal1(vector<vector<int>> &triangle){
	if (triangle.empty())
		return 0;
	vector<vector<int>> min_sum(triangle);
	int line = triangle.size();
	//初始化
	for (int i = 0; i < line; ++i){
		min_sum[line - 1][i] = triangle[line - 1][i];
	}
	//递推
	for (int i = line - 2; i >= 0; --i){
		for (int j = 0; j <= i; ++j){
			//F(i,j)=min{F(i+1,j),F(i+1,j+1)}+(i,j)
			min_sum[i][j] = min(min_sum[i + 1][j], min_sum[i + 1][j + 1]) + triangle[i][j];
		}
	}
	//返回值
	return min_sum[0][0];
}

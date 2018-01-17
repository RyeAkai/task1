#include<iostream>
#include<vector>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>

using namespace std;
//递推实现
class Plan_1 {
public:
	/**
	* @param triangle: a list of lists of integers.
	* @return: An integer, minimum path sum.
	*/
	int minimumTotal_1(vector<vector<int> > &triangle) 
	{
		if (triangle.empty()) {
			return -1;
		}

		int result = INT_MAX;
		dfs(0, 0, 0, triangle, result);

		return result;
	}

private:
	void dfs(int x, int y, int sum, vector<vector<int> > &triangle, int &result) 
	{
		const int n = triangle.size();
		if (x == n) {
			if (sum < result) {
				result = sum;
			}
			return;
		}

		dfs(x + 1, y, (sum + triangle[x][y]), triangle, result);
		dfs(x + 1, y + 1, (sum + triangle[x][y]), triangle, result);
	}
};
//递归实现
class Plan_2 {
public:
	/**
	* @param triangle: a list of lists of integers.
	* @return: An integer, minimum path sum.
	*/
	int minimumTotal_2(vector<vector<int> > &triangle) {
		if (triangle.empty()) {
			return -1;
		}

		int result = dfs(0, 0, triangle);

		return result;
	}

private:
	int dfs(int x, int y, vector<vector<int> > &triangle) {
		const int n = triangle.size();
		if (x == n) {
			return 0;
		}

		return min(dfs(x + 1, y, triangle), dfs(x + 1, y + 1, triangle)) + triangle[x][y];
	}
};
class Solution :public Plan_1, public Plan_2
{
public:
	Solution(int size)
	{
		Nums_out.clear();
		Nums_in.clear();
		size_ = size;
	}
	void Init_Vector_1()
	{
		int i = 0;
		srand((unsigned)time(NULL));
		for (i = 1; i <= size_; i++)
		{
			Nums_in = Init_Vector_2();
			Nums_out.push_back(Nums_in);
		}
	}
	vector<int> Init_Vector_2()
	{
		int Random = 0;
		vector<int> arr;
		int i = 1;
		for (i = 1; i <= size_; i++)
		{
			Random = rand() % 10 + 1;
			arr.push_back(Random);
		}
		return arr;
	}
	void Print_Vec()
	{
		for (int i = 0; i < size_; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				cout << Nums_out[i][j] << " ";
			}
			cout << endl;
		}
	}
	vector<vector<int> >& Get_Vec_numsout()
	{
		return Nums_out;
	}
private :
	vector<vector<int> > Nums_out;
	vector<int> Nums_in;
	int size_;
};

int main()
{
	Solution My_Vec(15);
	int Dis_min1 = 0, Dis_min2 = 0;
	clock_t start_1 = 0, start_2 = 0, end_1 = 0, end_2 = 0;
	cout << "15*15的三角矩阵:>" << endl;
	My_Vec.Init_Vector_1();
	My_Vec.Print_Vec();

	start_1 = clock();

	Dis_min1 = My_Vec.minimumTotal_1(My_Vec.Get_Vec_numsout());
	cout << "最短距离为:" << Dis_min1 << endl;

	end_1 = clock();

	start_2 = clock();

	Dis_min2 = My_Vec.minimumTotal_2(My_Vec.Get_Vec_numsout());
	cout << "最短距离为:" << Dis_min2 << endl;

	end_2 = clock();

	printf("递推实现time=%f\n", (double)(end_1 - start_1) / CLK_TCK);

	printf("递归实现time=%f\n", (double)(end_2 - start_2) / CLK_TCK);
	system("pause");
	return 0;
}
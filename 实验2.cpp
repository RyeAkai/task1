#include <iostream>  
#include <vector>  
#include <algorithm> 
#include<time.h>

using namespace std;

class Binary_Search_1 {
	/**
	* param A : an integer sorted array
	* param target :  an integer to be inserted
	* return : an integer
	*/
public:
	/////////////////////////////////////循环处理
	int searchInsert(vector<int> &A, int target) {
		// write your code here
		if (A.empty()) return 0;

		int n = A.size();
		int lb = -1, ub = n;
		while (lb + 1 < ub) {
			int mid = lb + (ub - lb) / 2;
			if (A[mid] < target) {
				lb = mid;
			}
			else {
				ub = mid;
			}
		}
		return ub;
	}
};


class Binary_Search_2
{
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result = { -1, -1 };
		if (nums.empty())
			return result;

		int lb = -1, ub = nums.size();
		while (lb + 1 < ub) {
			int mid = lb + (ub - lb) / 2;
			if (nums[mid] < target)
				lb = mid;
			else
				ub = mid;
		}

		if ((ub < nums.size()) && (nums[ub] == target))
			result[0] = ub;
		else
			return result;

		ub = nums.size();
		while (lb + 1 < ub) {
			int mid = lb + (ub - lb) / 2;
			if (nums[mid] > target) ub = mid;
			else lb = mid;
		}
		result[1] = ub - 1;
		return result;
	}
};


class Solution :public Binary_Search_1, public Binary_Search_2
{
public:
	void generate_nums()
	{
		srand(time(NULL));
		for (auto &r : nums_)
			r = rand();
	}

	vector<int> Get_Vector()
	{
		return nums_;
	}

	void sort_nums()
	{
		sort(nums_.begin(), nums_.end());
	}
private:
	vector<int> nums_ = vector<int>(1000000);
};

int main()
{
	Solution Mynums_;
	clock_t start_1 = 0, start_2 = 0, start_3 = 0, end_1 = 0, end_2 = 0, end_3 = 0;
	vector<int> addr;
	double Time_1 = 0, Time_2 = 0, Time_3 = 0;
	int i = 0, tmp = -1, src_1 = -1;
	bool src_2 = false;
	Mynums_.generate_nums();
	Mynums_.sort_nums();		  //排序 
	while (i < 100)
	{
		start_1 = clock();
		tmp = rand();
		addr = Mynums_.searchRange(Mynums_.Get_Vector(), tmp);
		end_1 = clock();
		Time_1 += (double)(end_1 - start_1) / CLK_TCK;
		start_2 = clock();
		src_1 = Mynums_.searchInsert(Mynums_.Get_Vector(), tmp);
		end_2 = clock();
		Time_2 += (double)(end_2 - start_2) / CLK_TCK;
		i++;
		cout << endl;
	}
	printf("矩阵搜索所用时间=%f\n", Time_1);
	printf("循环二分搜索所用时间=%f\n", Time_2);
	system("pause");
	return 0;
}
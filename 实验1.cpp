#include<iostream>
#include<time.h>
#include<string>
using namespace std;
const int maxn = 10000;
int Next[maxn];
class KMP
{
public:
	void getNext(string needle){
		int i = 0, j = -1, len = needle.size();
		while (i < len){
			if (j == -1 || needle[i] == needle[j]) Next[++i] = ++j;
			else j = Next[j];
		}
	}
	int strStr(string haystack, string needle){
		int i = 0, j = 0, length1 = haystack.size(), length2 = needle.size();
		int ans = 0;
		while (i < length1){
			if (j == -1 || needle[j] == haystack[i]) i++, j++;
			else j = Next[j];
			if (j == length2) return i - length2 + 1;
		}
	}
};
class FORFOR {
public:
	int strStr(string haystack, string needle) {
		if (haystack.empty() && needle.empty()) return 0;
		if (haystack.empty()) return -1;
		if (needle.empty()) return 0;
		// in case of overflow for negative
		if (haystack.size() < needle.size()) return -1;

		for (int i = 0; i < haystack.size() - needle.size() + 1; i++) {
			string::size_type j = 0;
			for (; j < needle.size(); j++) {
				if (haystack[i + j] != needle[j]) break;
			}
			if (j == needle.size()) return i;
		}
		return -1;
	}
};
/*	string rand_num(int size)//生成随机数
	 {
		 string str="a";
		 srand(time(NULL));
		 for (int i = 0; i < size; i++)
			 str.push_back ('a'+rand() % 26);
		 return str;
 }*/
int main()
{
	Next[0] = -1;
	FORFOR S1;		
	KMP S2;
	//string STR;
	//string str;
	//STR = rand_num(50);
	//str = rand_num(5);
	clock_t start1 = 0, start2 = 0, end2 = 0,end1 = 0;
	printf("以下为仅运行一千次的结果。\n");
	printf("-----------------------------\n");
	printf("以下为暴力算法：\n");
	start1 = clock();
	int i = 0;
	while (i < 1000)
	{
		//S1.strStr(STR, str);
		S1.strStr("fawebvewbtbwbttrwbyegrebabrwbwethtwrthjwrhjywrjrwqrhyrywrnywnqegwrhyetjut", "ywrnyw");
		i++;
	}
	end1 = clock();
	cout<< (double)(end1 - start1) / CLK_TCK<<endl;
	printf("以下为KMP算法：\n");
	start2 = clock();
	int j = 0;
	S2.getNext("ywrnyw");
	while (j < 1000)
	{
		//S2.getNext(str);
		//S2.strStr(STR, str);
		S2.strStr("fawebvewbtbwbttrwbyegrebabrwbwethtwrthjwrhjywrjrwqrhyrywrnywnqegwrhyetjut", "ywrnyw");
		j++;
	}
	end2 = clock();
	cout<<(double)(end2 - start2) / CLK_TCK<<endl;
	system("pause");
	return 0;
}
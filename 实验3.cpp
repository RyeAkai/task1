#include<iostream>
#include<math.h>
#include<Windows.h>
#include<time.h>

using namespace std;


//Definition of TreeNode:���������ĳ�ʼ��
class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};


///////////////////////////////////////�ݹ�����
class BinTree_Search_1
{
public:
	/**
	* @param root: The root of the binary search tree.
	* @param node: insert this node into the binary search tree
	* @return: The root of the new binary search tree.
	*/
	TreeNode* insertNode_1(TreeNode* root, TreeNode* node) {
		if (!root)
		{
			return node;
		}

		if ((node->val) < (root->val)) {
			root = insertNode_1(root->left, node);
		}
		else if ((node->val) > (root->val))
		{
			root = insertNode_1(root->right, node);
		}
		else if ((node->val) == (root->val))
		{
			return root;
		}

		return root;
	}
};
///////////////////////////////////////��������
class BinTree_Search_2
{
public:
	/**
	* @param root: The root of the binary search tree.
	* @param node: insert this node into the binary search tree
	* @return: The root of the new binary search tree.
	*/
	TreeNode* insertNode_2(TreeNode* root, TreeNode* node) {
		if (NULL == root) {
			return node;
		}

		TreeNode* tempNode = root;
		while (NULL != tempNode) {
			if (node->val < tempNode->val) {
				if (NULL == tempNode->left) {
					tempNode = NULL;
					return tempNode;
				}
				tempNode = tempNode->left;
			}
			else if (node->val > tempNode->val)
			{
				if (NULL == tempNode->right) {
					tempNode = NULL;;
					return tempNode;
				}
				tempNode = tempNode->right;
			}
			else if (node->val == tempNode->val)
			{
				return tempNode;
			}
		}
	}
};


class Solution :public BinTree_Search_1, public BinTree_Search_2 //�����������
{
public:
	Solution(int tier)
	{
		Tree_nums = (int)pow(2, tier);
	}
	~Solution()
	{
		cout << "�����ͷţ���δ���ټǵ����١�" << endl;
	}
	int Get_Tree_nums()
	{
		return Tree_nums;
	}
	TreeNode* Init_BinTree(int value_sub, int value_var)
	{
		TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
		if (tmp == NULL)
		{
			cout << "malloc failed!" << endl;
			exit(1);
		}
		tmp->val = value_var;
		if (value_var % 2 == 1)
		{
			tmp->left = NULL;
			tmp->right = NULL;
			return tmp;
		}
		tmp->left = Init_BinTree(value_sub / 2, value_var - value_sub);
		tmp->right = Init_BinTree(value_sub / 2, value_var + value_sub);
		return tmp;
	}
	/*void Destory_BInTree(TreeNode*& BinTree)
	{
	if (BinTree!=NULL)
	{
	Destory_BInTree(BinTree->left);
	Destory_BInTree(BinTree->right);
	free(BinTree);
	}
	}*/
private:
	int Tree_nums;
};

int main()
{
	Solution gym(20);//�ܵ�
	clock_t start_1 = 0, start_2 = 0, end_1 = 0, end_2 = 0;//��ʱ����
	int i = 0, Random = -1;//ѭ������
	double Time_1 = 0, Time_2 = 0;//��ʱ��

	//��ʼ���ܵ���������Ҫ���ܵ�������һ����������
	TreeNode* src = gym.Init_BinTree(gym.Get_Tree_nums() / 2, gym.Get_Tree_nums());
	if (src != NULL)
		cout << "�������Ѿ����ɣ���������" << endl;
	srand(time(NULL));//�ı����������

	////////////////////////////////////��ʱ
	while (i < 1000)
	{
		////////////////////////////////////////Ŀ���������
		Random = rand();
		TreeNode BT(Random);
		TreeNode* dst = &BT;
		TreeNode* Address = NULL;
		////////////////////////////////////////�ݹ�
		start_1 = clock();

		Address = gym.insertNode_1(src, dst);
		if (Address == dst)
			cout << "ֵ�����ܵ���" << endl;
		else
			printf("Ŀ��ֵΪ %d ,��ַΪ %p \n", Address->val, Address);

		end_1 = clock();
		Time_1 += (double)(end_1 - start_1) / CLK_TCK;
		////////////////////////////////////////����
		start_2 = clock();

		Address = gym.insertNode_2(src, dst);
		if (Address == NULL)
			cout << "ֵ�����ܵ���" << endl;
		else
			printf("Ŀ��ֵΪ %d ,��ַΪ %p \n", Address->val, Address);

		end_2 = clock();
		Time_2 += (double)(end_2 - start_2) / CLK_TCK;

		i++;
		cout << endl;
	}

	printf("�ݹ����������Time_1=%f\n", Time_1);
	printf("��������������Time_2=%f\n", Time_2);
	/*gym.Destory_BInTree(src);*/
	system("pause");
	return 0;
}
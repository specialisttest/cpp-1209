#ifndef _TREE_H_
#define _TREE_H_

class BinaryTreeNode{
	public:
		BinaryTreeNode* left;
		BinaryTreeNode* right;
		
		int value;
		
		BinaryTreeNode(int _value, BinaryTreeNode* _left, BinaryTreeNode* _right)
			: value(_value), left(_left), right(_right)
		{}
		
		BinaryTreeNode(int _value)
			: BinaryTreeNode(_value, nullptr, nullptr)
		{}
		
		int summaTree()
		{
			int summa = this->value;
			if (this->left)
				summa += this->left->summaTree();
			if (this->right)
				summa += this->right->summaTree();
				
			return summa;
		}
		
		bool find(int key) // O(log n) if balanced
		{
			BinaryTreeNode* curr = this;
			while (curr && curr->value != key) 
			{
				if (curr->value > key)
					curr = curr->left;
				else
					curr = curr->right;
			}
			
			return curr != nullptr;
			
		}
		

		~BinaryTreeNode()
		{
			delete left;
			delete right;
		}

};

#endif

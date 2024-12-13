#include <iostream>

#include "Tree.h"




int main(int argc, char** argv) {
	
	BinaryTreeNode* root = new BinaryTreeNode(13,
		new BinaryTreeNode(8, new BinaryTreeNode(6),new BinaryTreeNode(10)), 
		new BinaryTreeNode(25, new BinaryTreeNode(17),new BinaryTreeNode(28))
			);
	
	std::cout << root->summaTree() << std::endl;
	std::cout << root->find(10) << std::endl;
	std::cout << root->find(11) << std::endl;
	
	
	delete root;
	
	
	return 0;
}

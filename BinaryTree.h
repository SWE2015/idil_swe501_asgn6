#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

struct TreeNode;

class BinaryTree
{
    public:
        BinaryTree();
        ~BinaryTree();

        void MakeEmpty();
        bool IsEmpty() const;
        bool IsFull() const;
        void RetrieveItem(int& item, bool& found) const;
        void InsertItem(int item);
        void DeleteItem(int item);
        void Print() const;

    private:
        TreeNode* root;
};

struct TreeNode
{
  int info;
  TreeNode* left;
  TreeNode* right;
};

#endif // BINARYTREE_H

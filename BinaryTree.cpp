#include "BinaryTree.h"
#include <iostream>

using namespace std;

//helper function signatures
void Retrieve(TreeNode* tree, int & item, bool& found);
void Insert(TreeNode*& tree, int item);
void DeleteNode(TreeNode*& tree);
void Delete(TreeNode*& tree, int item);
void GetPredecessor(TreeNode* tree, int& data);
void PrintTree(TreeNode* tree);
void Destroy(TreeNode*& tree);

BinaryTree::BinaryTree()
{
    root = NULL;
}

BinaryTree::~BinaryTree()
{
    Destroy(root);
}

void Destroy(TreeNode*& tree)
{
  if (tree != NULL)
  {
    Destroy(tree->left);
    Destroy(tree->right);
    delete tree;
   }
}

bool BinaryTree::IsFull() const
{
  TreeNode* location;
  //try to allocate a new location, if possible memmory is not full, if not possible, memmory is full
  try
  {
    location = new TreeNode;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}

bool BinaryTree::IsEmpty() const
{
  // tree is empty if root is NULL
  return root == NULL;
}

void BinaryTree::RetrieveItem(int& item, bool& found) const
{
  Retrieve(root, item, found);
}

void Retrieve(TreeNode* tree, int & item, bool& found)
// Recursive function to search tree for item.
{
  if (tree == NULL)
    found = false;                     // item is not found.
  else if (item < tree->info)
    Retrieve(tree->left, item, found); // Search left subtree.
  else if (item > tree->info)
    Retrieve(tree->right, item, found);// Search right subtree.

  else {
    item = tree->info;
    found = true;
   }
}

void BinaryTree::InsertItem(int item)
{
  Insert(root, item);
}

void Insert(TreeNode*& tree, int item)
// Recursive function to insert item to tree
{
  if (tree == NULL) // insert if tree is null
  {
    tree = new TreeNode;
    tree->right = NULL;
    tree->left = NULL;
    tree->info = item;
  }
  else if (item < tree->info)
    Insert(tree->left, item);
  else
    Insert(tree->right, item);
}

void BinaryTree::DeleteItem(int item)
{
  Delete(root, item);
}

void Delete(TreeNode*& tree, int item)
// Recursive function to delete item from tree
{
  if (item < tree->info)
    Delete(tree->left, item);
  else if (item > tree->info)
    Delete(tree->right, item);  // Look in right subtree.
  else
    DeleteNode(tree);
}

void DeleteNode(TreeNode*& tree)
{
  int data;
  TreeNode* tempPtr;
  tempPtr = tree;
  if (tree->left == NULL)
  {
    tree = tree->right;
    delete tempPtr;
  }
  else if (tree->right == NULL)
  {
    tree = tree->left;
    delete tempPtr;
  }
  else {
    GetPredecessor(tree->left, data);
    tree->info = data;
    Delete(tree->left, data);
   }
}

void GetPredecessor(TreeNode* tree, int& data)
{
  while (tree->right != NULL)
    tree = tree->right;
    data = tree->info;
}

void BinaryTree::Print() const
{
  PrintTree(root);
}

void PrintTree(TreeNode* tree)
// inorder traversal (left - node - right)
{
  if (tree != NULL)
  {
    PrintTree(tree->left);   // Print left subtree.
    cout << tree->info << " ";
    PrintTree(tree->right);  // Print right subtree.
  }
}


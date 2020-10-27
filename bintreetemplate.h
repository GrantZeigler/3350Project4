// FILE: bintreetemplate.h
// IMPLEMENTS: The nine template functions of the second version of the binary
// tree toolkit (see bintree.h for documentation). Note that this file is not
// compiled on its own. Instead, this file is included by an include directive
// at the bottom of bintree.h.

#include <cassert>    // Provides assert
#include <iomanip>   // Provides setw
#include <iostream>  // Provides cout
#include <cstdlib>    // Provides NULL, size_t

using namespace std;

// Programming note: Some compilers require that the default argument is
// listed in the implementation as well as the prototype, so we have
// include the default arguments for create_node.
template <class Item>
BinaryTreeNode<Item>* create_node(
    const Item& entry,
    BinaryTreeNode<Item>* l_ptr,
    BinaryTreeNode<Item>* r_ptr
)
{
    BinaryTreeNode<Item>* result_ptr;

    result_ptr = new BinaryTreeNode<Item>;
    result_ptr->data  = entry;
    result_ptr->left  = l_ptr;
    result_ptr->right = r_ptr;

    return result_ptr;
}

template <class Item>
BinaryTreeNode<Item>* tree_copy(const BinaryTreeNode<Item>* root_ptr)
// Library facilities used: stdlib.h
{
    BinaryTreeNode<Item> *l_ptr;
    BinaryTreeNode<Item> *r_ptr;

    if (root_ptr == NULL)
        return NULL;
    else
    {
        l_ptr = tree_copy(root_ptr->left);
        r_ptr = tree_copy(root_ptr->right);
        return create_node(root_ptr->data, l_ptr, r_ptr);
    }
}

template <class Item>
void tree_clear(BinaryTreeNode<Item>*& root_ptr)
{
    if (root_ptr != NULL)
    {
        tree_clear(root_ptr->left);
        tree_clear(root_ptr->right);
        delete root_ptr;
        root_ptr = NULL;
    }
}

template <class Item>
bool is_leaf(const BinaryTreeNode<Item>& node)
{
    return (node.left == NULL) && (node.right == NULL);
}

template <class Process, class Item>
void inorder(Process f, BinaryTreeNode<Item>* node_ptr)
{
    if (node_ptr != NULL)
    {
		
        inorder(f, node_ptr->left);
        f(node_ptr->data);
        inorder(f, node_ptr->right);
    }
}

template <class Process, class Item>
void postorder(Process f, BinaryTreeNode<Item>* node_ptr)
{
    if (node_ptr != NULL)
    {
        postorder(f, node_ptr->left);
        postorder(f, node_ptr->right);
        f(node_ptr->data);
    }
}

template <class Process, class Item>
void preorder(Process f, BinaryTreeNode<Item>* node_ptr)
{
    if (node_ptr != NULL)
    {
        f(node_ptr->data);
        preorder(f, node_ptr->left);
        preorder(f, node_ptr->right);
    }
}

template <class Item>
size_t tree_size(const BinaryTreeNode<Item>* node_ptr)
// Library facilities used: stdlib.h
{
    if (node_ptr == NULL)
        return 0;
    else
        return 1 + tree_size(node_ptr->left) + tree_size(node_ptr->right);
}

//
//   template <class Item, class SizeType>
//   void printTreeAtDepth (BinaryTreeNode<Item>* node_ptr, SizeType depth)
//     Precondition: node_ptr is a pointer to a node in a binary
//     tree (or node_ptr may be NULL to indicate the empty tree).
//     If the pointer is NULL, then depth is expected to be 0.
//     If the pointer is not NULL, then depth is the depth of
//     the node pointed to by node_ptr.
//     Postcondition: If node_ptr is non-NULL, then the contents
//     of *node_ptr and all its descendants have been written
//     to cout with the << operator, using a backward in-order
//     traversal. Each node is indented 4 times its depth.
template <class Item, class SizeType>
void printTreeAtDepth (BinaryTreeNode<Item>* node_ptr, SizeType depth)
// Library facilities used: iomanip.h, iostream.h, stdlib.h
{
    if (node_ptr != NULL)
    {
        printTreeAtDepth (node_ptr->right, depth+1);
        cout << setw(4*depth) << ""; // Indent 4*depth spaces
        cout << node_ptr->data << endl;
        printTreeAtDepth (node_ptr->left, depth+1);
    }
}

template <class Item>
void printTree(BinaryTreeNode<Item>* node_ptr)
{
    printTreeAtDepth (node_ptr, 0);
}

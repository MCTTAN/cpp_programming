#include <iostream>
#include <vector>
#include <climits>
#include <deque>
using namespace std;

struct Tree
{
  char data;
  Tree *left;
  Tree *right;
  Tree *parent;
};

Tree* look_up(struct Tree *node, char key)
{
  if(node == NULL)
  {
    return node;
  }
  
  if(node->data == key)
  {
    return node;
  }

  else
  {
    if(node->data < key)
    {
      return look_up(node->right, key);
    }

    else
    {
      return look_up(node->left, key);
    }
  }
}

Tree* left_most(struct Tree *node)
{
  if(node == NULL)
  {
    return NULL;
  }

  while(node->left != NULL)
  {
    node = node->left;
  }

  return node;
}

struct Tree *newTreeNode(int data)
{
  Tree *node = new Tree;

  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;

  return node;
}

struct Tree* insertTreeNode(struct Tree *node, int data)
{
  static Tree *p;
  Tree *retNode;

  if(node == NULL)
  {
    retNode = newTreeNode(data);
    retNode->parent = p;
    return retNode;
  }

  if(data <= node->data)
  {
    p = node;
    node->left = insertTreeNode(node->left, data);
  }

  else
  {
    p = node;
    node->right = insertTreeNode(node->right, data);
  }

  return node;
}

void isBST(struct Tree *node)
{
  static int last_data = INT_MIN;
  if(node == NULL)
  {
    return;
  }

  isBST(node->left);

  // check to see if the given tree is a isBST
  if(last_data < node->data)
  {
    last_data = node->data;
  }

  else
  {
    cout << "Not a BST" << endl;

    return;
  }

  isBST(node-right);

  return;
}

int tree_size(struct Tree *node)
{
  if(node == NULL)
  {
    return 0;
  }

  else
  {
    return tree_size(node->left) + 1 + tree_size(node->right);
  }
}

int max_depth(struct Tree *node)
{
  if(node == NULL || (node->left == NULL && node->right == NULL))
  {
    return 0;
  }

  int left_depth = max_depth(node->left);
  int right_depth = max_depth(node->right);

  return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
}

int min_depth(struct Tree *node)
{
  if(node == NULL || (node->left == NULL && node->right == NULL))
  {
    return 0;
  }

  int left_depth = min_depth(node->left);
  int right_depth = min_depth(node->right);

  return left_depth < right_depth ? left_depth + 1 : right_depth + 1;
}

bool is_balanced(struct Tree *node)
{
  if(max_depth(node) - min_depth(node)) <= 1)
  {
    return(true);
  }

  else
  {
    return(false);
  }
}

Tree* min_tree(struct Tree *node)
{
  if(node == NULL)
  {
    return NULL;
  }

  while(node->left)
  {
    node = node->left;
  }

  return node;
}

Tree* max_tree(struct Tree *node)
{
  while(node->right)
  {
    node = node->right;
  }

  return node;
}

Tree *successor_in_order(struct Tree *node)
{
  // if the node has a right child, then the
  // successor is the tree's minimum
  
  Tree *x = node->parent;
  
  while(x != NULL && node == x->right)
  {
    node = x;
    x = x->parent;
  }

  return x;
}

Tree *in_order_predecessor(struct Tree *node)
{
  // if the node has a left child, then the
  // predecessor is the tree's maximum

  Tree *x = node->parent;

  // if it does not have a left child, then the
  // predecessor is its first left ancestor

  while(x != NULL && node == x->left)
  {
    node = x;
    x = x->parent;
  }

  return x;
}

void reverse_order_print(struct Tree *node)
{
  if(node == NULL)
  {
    return;
  }

  if(node->left == NULL && node->right == NULL)
  {
    cout << node->data << " ";

    return;
  }

  reverse_order_print(node->right);
  
  cout << node->data << " ";

  reverse_order_print(node->left);
}

Tree *lowest_common_ancestor(Tree *node, Tree *p, Tree *q)
{
  Tree *left, *right;

  if(node == NULL)
  {
    return NULL;
  }

  if(node->left == p || node->left == q || node->right == p || node->right == q)
  {
    return(node);
  }

  left = lowest_common_ancestor(node->left,p,q);
  right = lowest_common_ancestor(node->right,p,q);
  
  if(left && right)
  {
    return node;
  }

  else
  {
    return(left) ? left : right;
  }
}

void clear(struct Tree *node)
{
  if(node != NULL)
  {
    clear(node->let);
    clear(node->right);

    delete node;
  }
}

void print_tree_in_order(struct Tree *node)
{
  // 1.) Traverse the left subtree.
  // 2.) Visit the root.
  // 3.) Traverse the right subtree.

  if(node == NULL)
  {
    return;
  }

  print_tree_in_prder(node->left);
  
  cout << node->data << " ";

  print_tree_in_order(node->right);
}

void print_tree_post_order(struct Tree *node)
{
  // 1.) Traverse the left subtree.
  // 2.) Traverse the right subtree.
  // 3.) Visit the root.

  if(node == NULL)
  {
    return;
  }

  printTreePostOrder(node->left);
  printTreePostOrder(node->right);

  cout << node->data << " ";
}

void print_tree_pre_order(struct Tree *node)
{
  // 1.) Visit the root.
  // 2.) Traverse the left subtree.
  // 3.) Traverse the right subtree.

  if(node == NULL)
  {
    return;
  }

  cout << node->data << " ";

  print_tree_pre_order(node->left);
  print_tree_pre_order(node->right);
}

void print_tree_reverse_order(struct Tree *node)
{
  if(node == NULL)
  {
    return;
  }

  if(node->left == NULL && node->right == NULL)
  {
    cout << node->data << " ";
    
    return;
  }

  print_tree_reverse_order(node->right);

  cout << node->data << " ";

  print_tree_reverse_order(node->left);
}

void path_finder(struct tree *node, int path[], int level)
{
  if(node == NULL)
  {
    return;
  }

  if(node->left == NULL && node->right == NULL)
  {
    path[level] = node->data;
    for(int i = 0; i <= level; ++i)
    {
      cout << (char)path[i];
    }
    cout << endl;
    return;
  }

  path[level] = node->data;

  path_finder(node->left, path, level + 1);
  path_finder(node->right, path, level + 1);
}

bool match_tree(Tree *r1, Tree *r2)
{
  // nothing left in the subtree
  if(r1 == NULL && r2 == NULL)
  {
    return true;
  }

  // the big tree is empty while the subtree isn't
  if(r1 == NULL || r2 == NULL)
  {
    return false;
  }

  if(r1->data != r2->data)
  {
    return false;
  }

  return (match_tree(r1->left, r2->left) && match_tree(r1->right, r2->right));
}

bool sub_tree(Tree *r1, Tree *r2)
{
  // the big tree is empty while the subtree isn't
  // found
  if(r1 == NULL)
  {
    return(false);
  }
  
  if(r1->data == r2->data)
  {
    if(matchTree(r1, r2))
    {
      return(true);
    }
  }

  return(sub_tree(r1->left, r2) || sub_tree(r1->right, r2));
}

bool is_sub_tree(Tree *r1, Tree *r2)
{
  if(r2 == NULL)
  {
    return(true);
  }

  else
  {
    return sub_tree(r1, r2);
  }
}

void mirror(Tree *r)
{
  // change a tree so that the roles of the left and
  // right pointers are swapped at every node

  if(r == NULL)
  {
    return;
  }

  Tree *tmp;

  mirror(r->left);
  mirror(r->right);

  tmp = r->right;
  r->right = r->left;
  r->left = tmp;
}

Tree *add_to_BST(char arr[], int start, int end)
{
  // create a new tree from a sorted array

  if(end < start)
  {
    return NULL;
  }

  int mid = (start + end)/2;

  Tree *r = new Tree;

  r->data = arr[mid];
  r->left = add_to_BST(arr, start, mid - 1);
  r->right = add_to_BST(arr, mid + 1, end);

  return r;
}

Tree *create_minimal_BST(char arr[], int size)
{
  return add_to_BST(arr, 0, size - 1);
}

void breadth_first_traversal(Tree *root)
{
  if(root == NULL)
  {
    return;
  }

  deque <Tree *> que;
  queue.push_back(root);

  while(!queue.empty())
  {
    Tree *p = queue.front();

    cout << p->data << " ";
    
    queue.pop_front();

    if(p->left != NULL)
    {
      queue.push_back(p->left);
    }

    if(p->right != NULL)
    {
      queue.push_back(p->right);
    }
  }

  cout << endl;
}

int get_level(struct Tree *node, int elm, int level)
{
  if(node == NULL)
  {
    return 0;
  }

  if(elm == node->data)
    return level;
  }

  else if(elm < node->data)
  {
    return get_level(node->left, elm, level + 1);
  }

  else
  {
    return get_level(node->right, elm, level + 1);
  }
}

void nth_max(struct Tree* t)
{
  static int n_max = 5;
  static int num = 0;

  if(t == NULL)
  {
    return;
  }

  nth_max(t->right);

  ++num;

  if(num == n_max)
  {
    cout << n_max << "-th maximum data is " << t->data << endl;
    nth_max(t->left);
  }
}

void tree_to_array(struct Tree *node, int a[])
{
  static int pos = 0;

  if(node)
  {
    tree_to_array(node->left, a);
    a[++pos] = node->data;
    tree_to_array(node->right, a);
  }
}

void level_even_odd(struct Tree *node)
{
  vector<char> even_vec, odd_vec;
  if(node == NULL)
  {
    return;
  }
  deque<struct Tree*> que;
  que.push_back(node);

  while(!que.empty())
  {
    struct Tree *p = que.front();
    int level = get_level(node, p->data, 0);
    if(level % 2 == 0)
    {
      even_vec.push_back(p->data);
    }
    else
    {
      odd_vec.push_back(p->data);
    }
    que.pop_front();
    if(p->left)
    {
      que.push_back(p->left);
    }
    if(p->right)
    {
      que.push_back(p->right);
    }
  }

  cout << "even level elements: ";
  for(int i = 0; i < even_vec.size(); ++i)
  {
    cout << even_vec[i] << " ";
  }

  cout << end << "odd level elements: ";

  for(int i = 0; i < odd_vec.size(); ++i)
  {
    cout << odd_vec[i] << " ";
  }

  cout << endl;
}

int main(int argc, char **argv)
{
  char ch, ch1, ch2;
  Tree *found;
  Tree *succ;
  Tree *pred;
  Tree *ancestor;
  char charArr[9] = {'A','B','C','D','E','F','G','H','I'};

  Tree *root = new_tree_node('F');
	insert_tree_node(root,'B');
	insert_tree_node(root,'A');
	insert_tree_node(root,'D');
	insert_tree_node(root,'C');  
	insert_tree_node(root,'E');
	insert_tree_node(root,'G');
	insert_tree_node(root,'I');
	insert_tree_node(root,'H');

  is_BST(root);

  cout << "size = " << tree_size(root) << endl;
  cout << "max depth = " << max_depth(root) << endl;
  cout << "min depth = " << min_depth(root) << endl;
  if(is_balanced(root))
	{
    cout << "Balanced" << endl;
  }
	else
	{
    cout << "Unbalanced" << endl;
  }
  if(root) 
	{
    cout << "Min value = " << min_tree(root)->data << endl;
  }
  if(root) 
	{
    cout << "Max value = " << max_tree(root)->data << endl;
  }
  cout << "Node B is at level: " << get_level(root, 'B', 0) << endl;
	cout << "Node H is at level: " << get_level(root, 'H', 0) << endl;
	cout << "Node F is at level: " << get_level(root, 'F', 0) << endl;
}

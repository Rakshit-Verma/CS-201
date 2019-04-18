#include <iostream>
#include <string>
#include <queue>
#include "avl.hpp"
using namespace std;

int currentsize = 0;
int entries = 0;

Avl::Avl()
{
    root = NULL;
}

int Avl::height(node* t)
{
    return (t == NULL ? -1 : (max(height(t->left), height(t->right))+1));
}

void Avl::add(string wordin, string meaningin)
{
    root = insert(wordin, meaningin, root);
}

node* Avl::insert(string wordin, string meaningin, node *t)
{
    if(t == NULL)
    {
        currentsize++;
        t = new node;
        t->word = wordin;
        t->meaning = meaningin;
        t->height = 0;
        t->left = t->right = NULL;
    }
    else if(wordin.compare(t->word) > 0)
    {
        t->right = insert(wordin, meaningin, t->right);
        if(height(t->right) - height(t->left) == 2)
        {
            node *l = t->right;
            if(wordin.compare(l->word) > 0)
                t = singleLeftRotate(t);
            else
                t = doubleLeftRotate(t);
        }
    }
    else if(wordin.compare(t->word) < 0)
    {
        t->left = insert(wordin, meaningin, t->left);
        if(height(t->left) - height(t->right) == 2)
        {
            node *l = t->left;
            if(wordin.compare(l->word) < 0)
                t = singleRightRotate(t);
            else
                t = doubleRightRotate(t);
        }
    }
    else
    {
        t->meaning = meaningin;
    }
    t->height = max(height(t->left), height(t->right))+1;
    return t;
}
node* Avl::singleRightRotate(node* y)
{
    node *x = y->left; 
    node *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1; 
  
    // Return new root 
    return x; 
}

node* Avl::singleLeftRotate(node* x)
{
    node *y = x->right; 
    node *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
  
    // Return new root 
    return y; 
}

node* Avl::doubleLeftRotate(node* t)
{
    t->right = singleRightRotate(t->right);
    return singleLeftRotate(t);
}

node* Avl::doubleRightRotate(node* t)
{
    t->left = singleLeftRotate(t->left);
    return singleRightRotate(t);
}

void Avl::search(string wordin)
{
    node *temp = new node;
    temp = root;
    while(temp != NULL)
    {
        int x = wordin.compare(temp->word);
        if(x == 0)
        {
            cout<<"\nMEANING\n"<<temp->meaning<<endl<<endl;
            return;
        }
        else if(x > 0)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    cout<<"\nNOT FOUND!!!\n\n";
    return;
}

void Avl::remove_node(string wordin)
{
    root = deleteNode(root, wordin);
}

node* Avl::findMin(node* t)
{
    if(t == NULL)
        return NULL;
    else if(t->left == NULL)
        return t;
    else
        return findMin(t->left);
}

int Avl::getBalance(node *t)
{
    if(t == NULL)
        return 0;
    return height(t->left)-height(t->right);
}

node* Avl::deleteNode(node* root, string key)
{
    if (root == NULL) 
        return root; 
  
    // If the key to be deleted is smaller than the 
    // root's key, then it lies in left subtree 
    if ( key.compare(root->word) < 0 ) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the 
    // root's key, then it lies in right subtree 
    else if( key.compare(root->word) > 0 ) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is 
    // the node to be deleted 
    else
    { 
        // node with only one child or no child 
        if( (root->left == NULL) || (root->right == NULL) ) 
        { 
            node *temp = root->left ? root->left : root->right; 
  
            // No child case 
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else // One child case 
                *root = *temp; // Copy the contents of    
            delete(temp);      // the non-empty child
        } 
        else
        { 
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
            node* temp = findMin(root->right); 
  
            // Copy the inorder successor's data to this node 
            root->word = temp->word;
            root->meaning = temp->meaning; 
  
            // Delete the inorder successor 
            root->right = deleteNode(root->right, temp->word); 
        } 
    } 
  
    // If the tree had only one node then return 
    if (root == NULL) 
      return root; 
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
    root->height = 1 + max(height(root->left), height(root->right)); 
  
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to 
    // check whether this node became unbalanced) 
    int balance = getBalance(root); 
  
    // If this node becomes unbalanced, then there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && getBalance(root->left) >= 0) 
        return singleRightRotate(root); 
  
    // Left Right Case 
    if (balance > 1 && getBalance(root->left) < 0) 
    { 
        root->left =  singleLeftRotate(root->left); 
        return singleRightRotate(root); 
    } 
  
    // Right Right Case 
    if (balance < -1 && getBalance(root->right) <= 0) 
        return singleLeftRotate(root); 
  
    // Right Left Case 
    if (balance < -1 && getBalance(root->right) > 0) 
    { 
        root->right = singleRightRotate(root->right); 
        return singleLeftRotate(root); 
    } 
  
    return root; 
}

void Avl::range(string k1, string k2)
{
    entries = 0;
    count_in_range(root, k1, k2);
    cout<<"****************************\nTotal number of entries are\n"<<entries<<endl;
    entries = 0;
    return;
}

void Avl::count_in_range(node *t, string k1, string k2)
{
    if(t == NULL)
        return;
    if(k1.compare(t->word) < 0)
    {
        count_in_range(t->left, k1, k2);
    }
    if(k1.compare(t->word) <= 0 && k2.compare(t->word) >= 0)
    {
        cout<<t->word<<endl;
        entries++;
    }
    if(k2.compare(t->word) > 0)
    {
        count_in_range(t->right, k1, k2);
    }
}

void Avl::display()
{
    cout<<"\n****************************\n";
    displaytree(root);
    cout<<"\n****************************\n";
    return;
}

void Avl::displaytree(node *temp)
{
    if(temp == NULL)
    {
        return;
    }
    queue<node *> q;
    node *curr;
    q.push(temp);
    q.push(NULL);
    while(q.size() > 1)
    {
        curr =  q.front();
        q.pop();
        if(curr == NULL)
        {
            q.push(NULL);
            cout<<"\n****************************"<<endl;
        }
        else
        {
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
            cout<<curr->word<<" ";
        }
    }
}

int Avl::size()
{
    return currentsize;
}
//C++ Code to implement creation of a binary tree

#include <bits/stdc++.h>
using namespace std;

class TNode
//Node of Binary Search Tree
{
public:
    int data;
    TNode *lchild;
    TNode *rchild;
};

class Node
{
public:
    TNode *data;
    Node *next;
};

class Stack
{
    private:
        Node *top;
    public:
        Stack()
        {
            top=NULL;
        }

        void push(TNode *n)
        //To push element into Stack
        {
            Node *temp=new Node;
            temp->data=n;
            temp->next=NULL;
            if (top==NULL)
            {
                top=temp;
            }
            else if (this->isFull())
            {
                cout<<"Stack Overflow"<<endl;
                return;
            }
            else{
                temp->next=top;
                top=temp;
            }
        }

        TNode *StackTop()
        //To return element at top of stack
        {
            return top->data;
        }


        TNode *pop()
        //To pop element from Stack
        {
            TNode *x=0;
            if (top==NULL)
            {
                cout<<"Stack is Empty"<<endl;
            }
            else
            {
                Node *p=top;
                top=top->next;
                x=p->data;
                delete p;
            }
            return x;
        }

        bool isEmpty()
        //To check whether the stack is empty
        {
            if (top==NULL) return true;
            else return false;
        }

        bool isFull()
        //To check whether the stack is full
        {
            Node *y= new Node;
            if (y) return false; else return true;
        }
};

class BinarySearchTree
{
private:
    TNode *root;
public:
    BinarySearchTree()
    {
        root=NULL;
    }
    void insert(int elem)
    //Function to insert node in BST
    {
        if (root==NULL)
        {
            root= new TNode;
            root->data=elem;
            root->lchild=root->rchild=NULL;
        }
        else
        {
            TNode *p=root, *q;
            TNode *temp=new TNode;
            temp->data=elem;
            temp->lchild=temp->rchild=NULL;
            while (p)
            {
                if (p->data==elem)
                    return;
                else
                {
                    q=p;
                    if (elem<p->data)
                        p=p->lchild;
                    else   
                    {
                        p=p->rchild;
                    } 
                }
            }
            if (elem<q->data)
                q->lchild=temp;
            else
                q->rchild=temp;
        }
    }

    void createBSTfromPreorder(int pre[], int n)
    //To create BST if preorder traversal is given
    {
        TNode *p;
        int i=0;
        Stack S1;
        root=new TNode;
        root->lchild=root->rchild=NULL;
        root->data=pre[i++];
        p=root;
        while (i<n)
        {   
            TNode *temp=new TNode;
            temp->data=pre[i];
            temp->lchild=temp->rchild=NULL;
            if (pre[i]<p->data)
            {
                p->lchild=temp;
                S1.push(p);
                p=temp;
                i++;
            }
            else if (!S1.isEmpty())
            {
                if (pre[i]>p->data && pre[i]<S1.StackTop()->data)
                {
                    p->rchild=temp;
                    p=temp;
                    i++;
                }
                else if (pre[i]>p->data && pre[i]>S1.StackTop()->data)
                {
                    p=S1.pop();
                }
            }
            else
            {
                p->rchild=temp;
                p=temp;
                i++;
            }
              
        }
    }

    TNode *Search(int elem)
    //Function to return address of element if it exists in BST
    {
        TNode *p=root;
        while (p)
            {
                if (p->data==elem)
                    return p;
                else
                {
                    if (p->data<elem)
                        p=p->lchild;
                    else   
                    {
                        p=p->rchild;
                    } 
                }
            }
            return NULL;

    }

    int inorderpre(TNode *x)
    {
        TNode *p=x->lchild, *q;
        while (p && p->rchild)
        {
            p=p->rchild;
        }
        return p->data;
    }

    int inordersuc(TNode *x)
    {
        TNode *p=x->rchild;
        while (p && p->lchild)
        {
            p=p->lchild;
        }
        return p->data;
    }


    void preorder(TNode *p)
    //Function for preorder traversal
    {
        if (p!=NULL)
        {
            cout<<p->data<<" ";
            preorder(p->lchild);
            preorder(p->rchild);
        }
    }

    void inorder(TNode *p)
    //Function for inorder traversal
    {
        if (p!=NULL)
        {
            inorder(p->lchild);
            cout<<p->data<<" ";
            inorder(p->rchild);
        }
        return;
    }

    void postorder(TNode *p)
    //Function for postorder traversal
    {
        if (p!=NULL)
        {
            postorder(p->lchild);
            postorder(p->rchild);
            cout<<p->data<<" ";
        }
        return;
    }

    TNode *getRoot()
    //Function to get address of root
    {
        return root;
    }

    void setRoot(TNode *p)
    {
        root=p;
    }


    int CountNodes(TNode *p)
    //Function to count nodes
    {
        int x, y;
        if (p!=NULL)
        {
            x=CountNodes(p->lchild);
            y=CountNodes(p->rchild);
            return x+y+1;
        }
        return 0;
    }

    int height(TNode *p)
    //Function to calculate height of binary tree
    {
        int lheight, rheight;
        if (p!=NULL)
        {
            lheight=height(p->lchild);
            rheight=height(p->rchild);
            if (p->lchild || p->rchild)
            {
                if (lheight>=rheight) return lheight+1;
                else return rheight+1;
            }
            else
            {
                return 0;
            }
        }
        return 0;
    }

    TNode *remove(TNode *p, int elem)
    {
        if (p==NULL)
            return NULL;
        if (p->lchild==NULL && p->rchild==NULL &&p->data==elem)
        {
            if (p==root)
            {
                root=NULL;
            }
            delete p;
            return NULL;
        }
        if (elem<p->data)
            p->lchild=remove(p->lchild, elem);
        else if (elem>p->data)
        {
            p->rchild=remove(p->rchild, elem);
        }
        else if (p->lchild==NULL && p->rchild)
        {
            int x=inordersuc(p);
            p->data=x;
            p->rchild=remove(p->rchild,x);
        }
        else if (p->lchild && p->rchild==NULL)
        {
            int x=inorderpre(p);
            p->data=x;
            p->lchild=remove(p->lchild, x);
        }
        else 
        {
            if (height(p->lchild)>=height(p->rchild))
            {
                int x=inorderpre(p);
                p->data=x;
                p->lchild=remove(p->lchild, x);
            }
            else
            {
                int x=inordersuc(p);
                p->data=x;
                p->rchild=remove(p->rchild,x);
            }
        }
    return p;
    }

    int leafCount(TNode *p)
    //Function to count number of leaf nodes
    {
        int lcount, rcount;
        if (p)
        {
            lcount=leafCount(p->lchild);
            rcount=leafCount(p->rchild);
            if (!p->lchild && !p->rchild) return lcount+rcount+1;
            else return lcount+rcount;
        }
        return 0;
    }

    int nonleafCount(TNode *p)
    //Function to count number of non leaf nodes
    {
        int lcount, rcount;
        if (p)
        {
            lcount=nonleafCount(p->lchild);
            rcount=nonleafCount(p->rchild);
            if (p->lchild || p->rchild)
            {
                return lcount+rcount+1;
            }
            else
            {
                return lcount+rcount;
            }
        }
        return 0;
    }

};

int main()
{
    BinarySearchTree BST;
    BST.insert(50);
    BST.insert(20);
    BST.insert(100);
    BST.insert(11);
    BST.insert(42);
    BST.insert(75);
    BST.insert(89);
    BST.insert(27);
    cout<<"Inorder Traversal: ";
    BST.inorder(BST.getRoot());
    cout<<endl;
    cout<<"Preorder Traversal: ";
    BST.preorder(BST.getRoot());
    cout<<endl;
    cout<<"Height of BST: "<<BST.height(BST.getRoot())<<endl;
    cout<<"Number of nodes in BST: "<<BST.CountNodes(BST.getRoot())<<endl;
    cout<<"Number of leaf nodes in BST: "<<BST.leafCount(BST.getRoot())<<endl;
    cout<<"Number of non leaf nodes in BST: "<<BST.nonleafCount(BST.getRoot())<<endl;
    BST.setRoot(BST.remove(BST.getRoot(), 50));
    cout<<"Inorder Traversal: ";
    BST.inorder(BST.getRoot());
    cout<<endl;
    cout<<"Preorder Traversal: ";
    BST.preorder(BST.getRoot());
    cout<<endl;
    BinarySearchTree BST2;
    int pre[]={7,2,1,5,21, 16, 19, 25};
    BST2.createBSTfromPreorder(pre, sizeof(pre)/sizeof(pre[0]));
    cout<<"Inorder Traversal: ";
    BST2.inorder(BST2.getRoot());
    cout<<endl;
    cout<<"Preorder Traversal: ";
    BST2.preorder(BST2.getRoot());
    cout<<endl;
}
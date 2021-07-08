//C++ Code to implement creation of a binary tree

#include <bits/stdc++.h>
using namespace std;

class TNode
//Mode of Binary Tree
{
public:
    int data;
    TNode *lchild;
    TNode *rchild;
};

class Node
//Node of Queue
{
public:
    TNode* data;
    Node *next;
};


class Queue
{
    private:
        Node *front;
        Node *rear;
    public:
        Queue()
        {
            front=NULL;
            rear=NULL;
        }

        void enqueue(TNode* n)
        {
            Node *temp=new Node;
            temp->data=n;
            temp->next=NULL;
            if (!temp)
            {
                cout<<"Queue Overflow"<<endl;
            }
            else if (front==NULL)
            {
                front=rear=temp;
            }
            else
            {
                rear->next=temp;
                rear=temp;
            }
        }

        TNode * dequeue()
        {
            TNode *x=0;
            if (front==NULL)
            {
                cout<<"Queue is empty"<<endl;
            }
            else
            {
                Node *p=front;
                x=front->data;
                front=front->next;
                delete p;  
            }
            return x;
        }

        bool isEmpty()
        {
            if (front==NULL) return true;
            else return false;
        }
};

class BinaryTree
{
private:
    TNode *root;
    Queue Nodes;
public:
    BinaryTree()
    {
        root=NULL;
        
    }
    void createBinaryTree()
    //Function to create Binary Tree
    {
        cout<<"Enter the value of root"<<endl;
        root=new TNode;
        cin>>root->data;
        root->lchild=root->rchild=NULL;
        Nodes.enqueue(root);
        while (!Nodes.isEmpty())
        {
            TNode *p=Nodes.dequeue();
            int left, right;
            cout<<"Enter left child. If not enter -1"<<endl;
            cin>>left;
            if (left!=-1)
            {
                TNode *temp= new TNode;
                temp->data=left;
                temp->lchild=temp->rchild=NULL;
                p->lchild=temp;
                Nodes.enqueue(temp);
            }
            cout<<"Enter right child. If not enter -1"<<endl;
            cin>>right;
            if (right!=-1)
            {
                TNode *temp= new TNode;
                temp->data=right;
                temp->lchild=temp->rchild=NULL;
                p->rchild=temp;
                Nodes.enqueue(temp);
            }

        }
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

    void levelorder()
    //Function for levelorder traversal
    {
        TNode *p;
        Queue N;
        N.enqueue(root);
        while (!N.isEmpty())
        {
            p=N.dequeue();
            cout<<p->data<<" ";
            if (p->lchild)
            {
                N.enqueue(p->lchild);
            }
            if (p->rchild)
            {
                N.enqueue(p->rchild);
            }
        }
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
    BinaryTree BT1;
    BT1.createBinaryTree();
    cout<<"PreOrder Traversal: ";
    BT1.preorder(BT1.getRoot());
    cout<<endl;
    cout<<"InOrder Traversal: ";
    BT1.inorder(BT1.getRoot());
    cout<<endl;
    cout<<"PostOrder Traversal: ";
    BT1.postorder(BT1.getRoot());
    cout<<endl;
    cout<<"PreOrder Traversal: ";
    BT1.postorder(BT1.getRoot());
    cout<<endl;
    cout<<"LevelOrder Traversal: ";
    BT1.levelorder();
    cout<<endl;
    cout<<"Count of Nodes: "<<BT1.CountNodes(BT1.getRoot())<<endl;
    cout<<"Height of Tree: "<<BT1.height(BT1.getRoot())<<endl;
    cout<<"Number of Leaf nodes: "<<BT1.leafCount(BT1.getRoot())<<endl;
    cout<<"Number of Non Leaf nodes: "<<BT1.nonleafCount(BT1.getRoot())<<endl;

}
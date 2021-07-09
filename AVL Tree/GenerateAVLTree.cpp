//C++ Code to implement creation of a AVL tree

#include <bits/stdc++.h>
using namespace std;

class Node
//Node of AVL Tree
{
public:
    int data;
    Node *lchild;
    Node *rchild;
    int Height;
};

class AVLTree
{
public:
    Node *root;
    AVLTree()
    {
        root=NULL;
    }

    int NodeHeight(Node *p)
    {
        int lheight, rheight;
        if (p!=NULL)
        {
            lheight=NodeHeight(p->lchild);
            rheight=NodeHeight(p->rchild);
            if (p->lchild || p->rchild)
                if (lheight>=rheight) return lheight+1;
                else return rheight+1;
            else
                return 0;
        }
        return 0;
    }

    int balancefactor(Node *p)
    {
        if (p)
        {
        int lh,rh;
        lh=NodeHeight(p->lchild);
        rh=NodeHeight(p->rchild);
        if (p->lchild)  lh++;
        if (p->rchild) rh++;
        return lh-rh;
        }
        return -10;
    }

    Node *LLRotation(Node *p)
    {
        Node *p1=p->lchild;
        Node *pl1=p1->rchild;
        p1->rchild=p;
        p->lchild=pl1;

        if (p==root)
        {
            root=p1;
        }
        p1->Height=NodeHeight(p1);
        p->Height=NodeHeight(p);

        return p1;
    }

    Node *RRRotation(Node *p)
    {
        Node *p1=p->rchild;
        Node *pl1=p1->lchild;
        p1->lchild=p;
        p->rchild=pl1;
        if (p==root)
        {
            root=p1;
        }
        p1->Height=NodeHeight(p1);
        p->Height=NodeHeight(p);
        return p1;
    }

    Node *LRRotation(Node *p)
    {
        Node *p1=p->lchild;
        Node *p2=p1->rchild;
        p->lchild=p2->rchild;
        p1->rchild=p2->lchild;
        p2->lchild=p1;
        p2->rchild=p;
        p1->Height=NodeHeight(p1);
        p->Height=NodeHeight(p);
        p2->Height=NodeHeight(p2);

        if (p==root) root=p2;
        return p2;
    }

    Node *RLRotation(Node *p)
    {
        Node *p1=p->rchild;
        Node *p2=p1->lchild;
        p->rchild=p2->lchild;
        p1->lchild=p2->rchild;
        p2->lchild=p;
        p2->rchild=p1;
        p1->Height=NodeHeight(p1);
        p->Height=NodeHeight(p);
        p2->Height=NodeHeight(p2);

        if (p==root) root=p2;
        return p2;
    }

    int inorderpre(Node *x)
    {
        Node *p=x->lchild, *q;
        while (p && p->rchild)
        {
            p=p->rchild;
        }
        return p->data;
    }

    int inordersuc(Node *x)
    {
        Node *p=x->rchild;
        while (p && p->lchild)
        {
            p=p->lchild;
        }
        return p->data;
    }


    Node *insert(Node *p,int elem)
    //To insert in AVL Tree
    {
        if (p==NULL)
        {
            Node *temp=new Node;
            temp->lchild=temp->rchild=NULL;
            temp->data=elem;
            temp->Height=0;
            return temp;
        }

        if (elem<p->data)
        {
            p->lchild=insert(p->lchild, elem);
        }
        else if (elem>p->data)
        {
            p->rchild=insert(p->rchild, elem);
        }

        p->Height=NodeHeight(p);

        if (balancefactor(p)==2 && balancefactor(p->lchild)==1)
        {
            p=LLRotation(p);
        }
        else if (balancefactor(p)==2 && balancefactor(p->lchild)==-1)
        {
            p=LRRotation(p);
        }
        else if (balancefactor(p)==-2 && balancefactor(p->rchild)==-1)
        {
            p=RRRotation(p);
        }
        else if (balancefactor(p)==-2 && balancefactor(p->rchild)==1)
        {
            p=RLRotation(p);
        }
        return p;
    }

    Node *remove(Node *p, int elem)
    //To remove element in AVL Tree
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
            if (NodeHeight(p->lchild)>=NodeHeight(p->rchild))
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
        p->Height=NodeHeight(p);

        if (balancefactor(p)==2 && balancefactor(p->lchild)==1)  //L1 Rotation
        {
            p=LLRotation(p);
        }
        else if (balancefactor(p)==2 && balancefactor(p->lchild)==0)   //L0 Rotation
        {
            p=LLRotation(p);
        }
        else if (balancefactor(p)==2 && balancefactor(p->lchild)==-1)   //L-1 Rotation
        {
            p=LRRotation(p);
        }
        else if (balancefactor(p)==-2 && balancefactor(p->rchild)==-1)   //R-1 Rotation
        {
            p=RRRotation(p);
        }
        else if (balancefactor(p)==-2 && balancefactor(p->rchild)==1)   //R1 Rotation
        {
            p=RLRotation(p);
        }
        else if (balancefactor(p)==-2 && balancefactor(p->rchild)==0)   //R0 Rotation
        {
            p=RRRotation(p);
        }

    return p;
    }


    void preorder(Node *p)
    //Function for preorder traversal
    {
        if (p!=NULL)
        {
            cout<<p->data<<" ";
            preorder(p->lchild);
            preorder(p->rchild);
        }
    }

    void inorder(Node *p)
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

    void postorder(Node *p)
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

};

int main()
{
    AVLTree AV;
    AV.root=AV.insert(AV.root, 10);
    AV.root=AV.insert(AV.root, 20);
    AV.root=AV.insert(AV.root, 30);
    AV.root=AV.insert(AV.root, 25);
    AV.root=AV.insert(AV.root, 28);
    AV.root=AV.insert(AV.root, 27);
    AV.root=AV.insert(AV.root, 5);
    cout<<"Inorder Traversal: ";
    AV.inorder(AV.root);
    cout<<endl;
    cout<<"Preorder Traversal: ";
    AV.preorder(AV.root);
    cout<<endl;
    AV.root=AV.remove(AV.root, 25);
    cout<<"Inorder Traversal: ";
    AV.inorder(AV.root);
    cout<<endl;
    cout<<"Preorder Traversal: ";
    AV.preorder(AV.root);
    cout<<endl;
    

}




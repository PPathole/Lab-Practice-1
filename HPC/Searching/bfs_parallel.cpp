#include <iostream>
#include <omp.h>
#include <queue>
using namespace std;

class node
{
    public:
    node *left;
    int data;
    node *right;
};

class BST
{
    node *root;
    public:
    BST()
    {
        root=NULL;
    }
    int isEmpty()
    {
        if (root==NULL)
            return 1;
        return 0;
    }
    node* insert(int item)
    {
        node *p=new node;
        node *parent;
        p->data=item;
        p->left=NULL;
        p->right=NULL;
        parent=NULL;
        if(isEmpty())
            root=p;
        else
        {
            node *t;
            t=root;
            while(t!=NULL)
            {
                parent=t;
                if(item>t->data)
                    t=t->right;
                else
                    t=t->left;
            }
            if(item<parent->data)
                parent->left=p;
            else
                parent->right=p;
        }
        return root;
    }
    int bfs_parallel(node *root,int key)
    {
        int flag=0;
        node *t;
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            #pragma omp parallel for
            for(int i=0;i<q.size();i++)
            {
                #pragma omp critical
                {
                    t=q.front();
                    q.pop();
                    if(t->data==key)
                        flag=1;
                }
                #pragma omp critical
                {
                    if(t->left)
                        q.push(t->left);
                    if(t->right)
                        q.push(t->right);
                }
            }
        }
        return flag;
    }
};

int main()
{
    BST b;
    int data,key,flag;
    char ch;
    node *root;
    do
    {
        cout<<"Enter Data : ";
        cin>>data;
        root=b.insert(data);
        cout<<"Do you want to add more?(Y/N)"<<endl;
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    do
    {
        cout<<"Enter Key Element : ";
        cin>>key;
        flag=b.bfs_parallel(root,key);
        if(flag)
            cout<<"Found"<<endl;
        else
            cout<<"Not Found"<<endl;
        cout<<"Do you want to search more?(Y/N)"<<endl;
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    return 0;
}
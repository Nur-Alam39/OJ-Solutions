#include<bits/stdc++.h>
using namespace std;
struct node
{
    bool endmark;
    node* next[10+1];
    node()
    {
        endmark=false;
        for(int i=0; i<10; i++)
        {
            next[i]=NULL;
        }
    }
} *root;

void insert(char str[],int len)
{
    node* curr=root;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'0';
        printf("id=%d ",id);
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
    }
    curr->endmark=1;
}

bool search(char str[],int len)
{
    node* curr=root;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'0';
        if(curr->next[id]==NULL)
            return false;
        curr=curr->next[id];
    }
    return curr->endmark;
}
void del(node* cur)
{
    for(int i=0; i<26; i++)
        if(cur->next[i])
            del(cur->next[i]);
    delete(cur);
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        root =new node();
        int n;
        scanf("%d",&n);
        while(n--)
        {
            for(int i=0; i<n; i++)
            {
                char str[100];
                scanf("%s",&str);
                insert(str,strlen(str));
                printf("%s inserted\n",str);
            }
        }
        int query;
    printf("Enter number of query:");
    cin>>query;
    for(int i=0;i<query;i++)
    {
        char str[100];
        scanf("%s",&str);
        if(search(str,strlen(str)))printf("Found\n");
        else printf("Not Found\n");
    }
    }
    return 0;
}


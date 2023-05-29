#include<bits/stdc++.h>
using namespace std;

  /* The function bfs_rec takes several parameters: vec[] is an array of vectors representing an adjacency list, visit is a vector to track visited vertices, q is a queue used for BFS traversal, and ans is a vector to store the BFS traversal result.
    The base case of the recursive function is when the queue q is empty. In that case, there are no more vertices to visit, so the function simply returns.
    The first step inside the function is to retrieve the front element ele from the queue using q.front(), and then remove it from the queue using q.pop().
    The element ele is then appended to the ans vector, which represents the BFS traversal order.
    Next, the function retrieves the adjacency list for the current vertex ele from the vec[] array and stores it in the vector a.
    It then iterates over each element in a using a for loop.
    For each unvisited vertex a[i], the function sets visit[a[i]] to 1 to mark it as visited and inserts it into the queue q for further exploration in the BFS traversal. Additionally, it prints a message indicating the vertex being visited and inserted into the queue.
    Finally, the function makes a recursive call to itself bfs_rec(vec, visit, q, ans). This step ensures that the BFS traversal continues with the next vertex in the queue until all vertices are visited.

In summary, this recursive function performs a breadth-first search traversal on a graph represented by an adjacency list vec[]. It starts from a given vertex and explores its adjacent vertices in a level-by-level manner, using a queue for tracking and visiting vertices. The visited vertices are stored in the ans vector, representing the BFS traversal order.*/

void bfs_rec(vector<int>vec[],vector<int> &visit, queue<int> & q,vector<int> & ans) 
{
    if(q.empty())
    {
        return ;
    }
    int ele=q.front();
    q.pop();
    ans.push_back(ele);
    vector<int>a=vec[ele];
    for(int i=0;i<a.size();i++)
    {
        if(!visit[a[i]])
        {
            visit[a[i]]=1;
            cout<<"Visiting "<<a[i]<<" Vertex and inserting it into queue\n";
            q.push(a[i]);
        }
    }
    bfs_rec(vec,visit,q,ans);
}
void BFS(vector<int>vec[],int n)
{
    vector<int>visit(n+1,0);
    queue<int>q;
    vector<int>ans;
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==0)
        {

            visit[i]=1;
            cout<<"Visiting "<<i<<" Vertex and inserting it into stack\n";
            q.push(i);
             bfs_rec(vec,visit,q,ans);
        }
    }
    cout<<"\nBFS Traversal is : ";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";

}
void bfs_rec_search(vector<int>vec[],vector<int> &visit, queue<int> & q,vector<int> & ans,int & find,int target)
{
    if(q.empty())
    {
        return ;
    }
    int ele=q.front();
    q.pop();
    ans.push_back(ele);
    if(ele==target)
    {
        find=1;
        return ;
    }

    vector<int>a=vec[ele];
    for(int i=0;i<a.size();i++)
    {
        if(!visit[a[i]])
        {
            visit[a[i]]=1;

            q.push(a[i]);
        }
        if(find==1)
        {
            break;
        }
    }
    if(find!=1)
    {
        bfs_rec_search(vec,visit,q,ans,find,target);
    }
}
void BFS_Search(vector<int>vec[],int n,int target)
{
     vector<int>visit(n+1,0);
    queue<int>q;
    vector<int>ans;
    int find=0;
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==0)
        {
            visit[i]=1;
            q.push(i);
            bfs_rec_search(vec,visit,q,ans,find,target);
        }
        if(find==1)
        {
            break;
        }
    }
    if(find==1)
    {
        cout<<"\nVertex Found \n";
        cout<<"\nBFS Traversal for vertex "<< target <<" is : ";
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    else
    {
        cout<<"\nVertex Not Found \n";
    }

}
void dfs_rec(vector<int>vec[],vector<int> &visit,stack<int>st,vector<int> &ans)
{
    int n=st.top();
    st.pop();
     vector<int>a=vec[n];
     ans.push_back(n);
    // cout<<n<<" ";
     for(int i=0;i<a.size();i++)
     {
         int ele=a[i];
         if(visit[a[i]]==0)
         {
             visit[a[i]]=1;
             cout<<"Visiting "<<a[i]<<" Vertex and inserting it into stack\n";
            st.push(a[i]);
             dfs_rec(vec,visit,st,ans);
         }
     }
}
void dfs_rec_search(vector<int>vec[],vector<int> &visit,stack<int>st,vector<int> &ans,int & find,int target)
 {
      int n=st.top();
    st.pop();
     vector<int>a=vec[n];
     ans.push_back(n);
     if(n==target)
     {
         find=1;
         return;
     }

     for(int i=0;i<a.size();i++)
     {
         int ele=a[i];
         if(visit[a[i]]==0)
         {
             visit[a[i]]=1;

             st.push(a[i]);
             dfs_rec_search(vec,visit,st,ans,find,target);
             if(find==1)
             {
                 break;
             }
         }
     }
 }
void DFS_Search(vector<int>vec[],int n,int target)
{
    vector<int>ans;
    vector<int>visit(n+1,0);
    stack<int>st;
      int find=0;
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==0)
        {
            visit[i]=1;

            st.push(i);
            dfs_rec_search(vec,visit,st,ans,find,target);
        }
        if(find==1)
        {
            break;
        }
    }
     if(find==1)
    {
        cout<<"\nVertex Found \n";
        cout<<"\nDFS Traversal for vertex is : ";
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    else
    {
        cout<<"\nVertex Not Found \n";
    }
}
void DFS(vector<int>vec[],int n)
{
    vector<int>ans;
    vector<int>visit(n+1,0);
    stack<int>st;
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==0)
        {
            visit[i]=1;
            cout<<"Visiting "<<i<<" Vertex and inserting it into stack\n";
            st.push(i);
            dfs_rec(vec,visit,st,ans);
        }
    }

     cout<<"\nDFS Traversal is : ";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";


}

int main()
{
    int n,edge,u,v;
    cout<<"Enter Number of vertices : ";
    cin>>n;
    vector<int>vec[n+1];
    cout<<"Enter Number of Edges : ";
    cin>>edge;
    
    for(int i=0;i<edge;i++)
    {
        cout<<"Enter source index : ";
        cin>>u;
        cout<<"Enter destination vertex : ";
        cin>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    cout<<"\nGraph\n";

    for(int i=1;i<n+1;i++)
    {
        cout<<i<<" -> ";
        vector<int>a=vec[i];
        for(int j=0;j<vec[i].size();j++)
         {
             cout<<a[j]<<" ";
         } 
    cout<<"\n"; z

    }

    cout<<"\n\nBFS Treversal \n\n";
    BFS(vec,n);

    cout<<"\n\nDFS Treversal \n\n";
    DFS(vec,n);

    while(1)
    {
        cout<<"\n\nEnter the node to search : ";
        int node;
        cin>>node;
        cout<<"\n1. BFS";
        cout<<"\n 2.DFS";
        cout<<"\n 3.Exit";
        cout<<"\nChoice : ";
        int ch;
        cin>>ch;
        switch(ch)
        {
            case 0:
                exit(1);
                break;
            case 1:
                BFS_Search(vec,n,node);
                break;
            case 2:
                DFS_Search(vec,n,node);
                break;
            default:
            cout<<"Invalid choice\n";
        }
    }
}

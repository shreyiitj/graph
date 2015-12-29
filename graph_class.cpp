#include "graph.h"
#define MAXINT 99999

Graph::Graph(int v1)
{
v=v1;
e=0;
vec.resize(v1);
int i,j;
for(i=0;i<v1;i++)
    {
    vec[i].push_back(i);
    }
w=new int*[v1];              //to store weights
for(i=0;i<v1;i++)
{
    w[i]=new int[v1];
    for(j=0;j<v1;j++)
    {
        w[i][j]=MAXINT;
    }
    w[i][i]=0;
}
}

Graph(int v1,int **weigh,vector<vector<int> > vect)
{
    v=v1;
    w=weigh;
    vec=vect;
}

void Graph::addEdge(int v1,int v2,int wt)
{
    if(v1>=v || v2>=v) cout<<v1<<"and"<<v2<<" are not allowed"<<endl;

    else
    {
        int i,j=0;
        for(i=0;i<vec[v1].size();i++)
        {
            if((vec[v1])[i]==v2) j=1;      //v1 v2 are already present
        }
        if(j!=1)
        {
    vec[v1].push_back(v2);
    //vec[v2].push_back(v1);
    w[v1][v2]=wt;
    //w[v2][v1]=wt;
    e++;
        }
        //else cout<<"edge ("<<v1<<","<<v2<<") are already present";

    }
}

void Graph::printGraph()
{
    int i,j;
    cout<<"Adjacency List:"<<endl;
    for(i=0;i<v;i++)
    {
        for(j=0;j< vec[i].size();j++)
        {
            cout<<(vec[i])[j];
            if(j<vec[i].size()-1) cout<<"---->";
        }
        cout<<endl;
    }
    cout<<"\nWeights:"<<endl;

    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if (w[i][j]==MAXINT) cout<<"- ";
            else cout<<w[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

ostream& operator<<(ostream& stream,Graph g)
{
    stream<<g.v;
    //stream<<\n;
    int i,j;
    for(i=0;i<g.v;i++)
    {
        for(j=0;j<(g.vec[i]).size();j++)
        {
           stream<<(g.vec[i])[j];
        }
        stream<<'n';
    }
    return stream;
}

void Graph::BFS(int v1)
{
    cout<<"BFS("<<v1<<"): \n";
    bool *visited = new bool[v]();
    int *parent =new int[v];
    visited[v1]=1;
    parent[v1]=-10;
    list<int> q;              //queue
    q.push_back(v1);
    vector<int>::iterator i;
    while(!q.empty())
    {
        v1=q.front();
        cout<<v1<<" ";
        q.pop_front();
        for(i=vec[v1].begin();i!=vec[v1].end();i++)
        {
            if(visited[*i]!=1)
            {
                visited[*i]=1;
                parent[*i]=v1;
                q.push_back(*i);
            }
        }
    }
    cout<<endl;
}

void Graph::DFS(int v1)
{
    cout<<"DFS("<<v1<<"): \n";
    bool* visited=new bool[v]();
    DFSmain(v1,visited);
}

void Graph::DFSmain(int v1,bool* visited)
{



      vector<int>::iterator i;
      visited[v1]=1;
      cout<<v1<<" ";
      for(i=vec[v1].begin();i!=vec[v1].end();i++)
      {
          if(visited[*i]!=1)
          {
            DFSmain(*i,visited);
          }

      }


}

void Graph::dijkstra(int src)
{
    int d,n;
    vector<int>::iterator j;
    int *dist=new int[v];
    bool* taken=new bool[v]();
    int* parent=new int[v];
    for(int i=0;i<v;i++) dist[i]=MAXINT;
    dist[src]=0;
    parent[src]=0;
    priority_queue<T> q;
    q.push(T(0,dist[0]));
    while(!q.empty())
    {
      T u=q.top();
      q.pop();                                //remove one-by-one from min-heap until it gets empt
      d=u.dist;
      n=u.node;
      if(taken[n]==0)
      {
       taken[n]=1;
      for(j=vec[n].begin()+1;j!=vec[n].end();j++)          //for every adjacent node to u
      {
          if(taken[*j]!=1 && dist[*j]>d+w[n][*j])
          {
              dist[*j]=d+w[n][*j];
              parent[*j]=n;
              q.push(T(*j,dist[*j]));
          }
      }
      }
      else continue;
    }
    cout<<"Dijkstra:"<<endl;
    cout<<"node  distance    parent"<<endl;
    for(int i=0;i<v;i++)
    {
        cout<<i<<"      "<<dist[i]<<"           "<<parent[i]<<endl;
    }
}

void Graph::floyd_warshal()
{
    cout<<"floyd-warshal:"<<endl;
    int i,j,k;
  int **w1;
  w1=new int*[v];
  for( i=0;i<v;i++)
  {
      w1[i]=new int[v];
      for( j=0;j<v;j++)
      {
          w1[i][j]=w[i][j];
      }
  }
  for(k=0;k<v;k++)
  {
      for(i=0;i<v;i++)
      {
          for(j=0;j<v;j++)
          {
              if(w1[i][k]+w1[k][j]<w1[i][j]) w1[i][j]=w1[i][k]+w1[k][j];
          }
      }
  }
  for( i=0;i<v;i++)
  {
      for( j=0;j<v;j++)
      {
          cout<<w1[i][j]<<" ";
      }
      cout<<endl;
  }
  cout<<endl;

}

void Graph::mstPrim()
{
int d,n;
    vector<int>::iterator j;
    int *dist=new int[v];
    bool* taken=new bool[v]();
    int* parent=new int[v];
    for(int i=0;i<v;i++) dist[i]=MAXINT;
    dist[0]=0;
    parent[0]=0;
    priority_queue<T> q;
    q.push(T(0,dist[0]));
    while(!q.empty())
    {
      T u=q.top();
      q.pop();                                //remove one-by-one from min-heap until it gets empt
      d=u.dist;
      n=u.node;
      if(taken[n]==0)
      {
       taken[n]=1;
      for(j=vec[n].begin()+1;j!=vec[n].end();j++)          //for every adjacent node to u
      {
          if(taken[*j]!=1 && dist[*j]>w[n][*j])
          {
              dist[*j]=w[n][*j];
              parent[*j]=n;
              q.push(T(*j,dist[*j]));
          }
      }
      }
      else continue;
    }
    cout<<"mstPrim:"<<endl;
    //cout<<"node      parent"<<endl;
    for(int i=1;i<v;i++)
    {
        cout<<i<<"--"<<parent[i]<<endl;
    }


}

void Graph::mstKruskal()
{
    cout<<"mstKruskal"<<endl;
    priority_queue<K> q;           //1.sort edges
    int i;
    vector<int>::iterator j;
    for(i=0;i<v;i++)
    {
        for(j=vec[i].begin()+1;j!=vec[i].end();j++)
        {
            if(*j>i) q.push(K(i,*j,w[i][*j]));                          //for every edge there will be 2 copies stored(resolved by if)
        }
    }

    list<pairs> mst_edges;
    subSet* ss=new subSet[v];
    for(i=0;i<v;i++)
    {
        ss[i].parent=i;
        ss[i].rank=0;
    }
    while(!q.empty())
    {
        K obj;
        obj=q.top();
        q.pop();
        int src_set=findSet(obj.src,ss);
        int des_set=findSet(obj.des,ss);
        if(src_set==des_set) continue ;    //there exists a cycle
        else
        {
            mst_edges.push_back(pairs(obj.src,obj.des));
            union2(obj.src,obj.des,ss);
        }
    }
    list<pairs> ::iterator p;
    p=mst_edges.begin();
    while(p!=mst_edges.end())
    {

        cout<<(*p).a<<"--"<<(*p).b<<endl;
        p++;
    }
}

int Graph::findSet(int s,subSet *ss)
{
    if(ss[s].parent==s) return s;
    else ss[s].parent=findSet(ss[s].parent,ss);
}

void Graph::union2(int a,int b,subSet *ss)
{
    int a_set=findSet(a,ss);
    int a_rank=ss[a_set].rank;
    int b_set=findSet(b,ss);
    int b_rank=ss[b_set].rank;
    if(a_rank>b_rank)
    {
        ss[b_set].parent=a_set;
    }
    else if(b_rank>a_rank)
    {
        ss[a_set].parent=b_set;
    }
    else
    {
         ss[b_set].parent=a_set;
         ss[a_set].rank++;
    }

}

void Graph::topoSort()
{
    cout<<"Topological Sort()"<<endl;
    int i;
    stack<int> Stack;
    bool* visited=new bool[v]();
    for(i=0;i<v;i++)
    {
        if(visited[i]==0)
        {
        topoUtil(i,visited,Stack);

        }
    }
    while(!Stack.empty())
    {
        cout<<Stack.top()<<" ";
        Stack.pop();
    }
    cout<<endl;
}

void Graph::topoUtil(int i,bool* visited,stack<int>& Stack)
{
    visited[i]=1;
    vector<int>::iterator p;
    int j;
    for(p=vec[i].begin()+1;p!=vec[i].end();p++)
    {
        if(visited[*p]==0) topoUtil(*p,visited,Stack);
    }
    Stack.push(i);
}

void Graph::bellman_ford(int v1)
{
    //cout<<"enter"<<endl;
    int i;
    int src,des,weigh;
    vector<int>::iterator j;
    int *dist=new int[v];
    for(i=0;i<v;i++)
    {
        dist[i]=MAXINT;
    }
    dist[v1]=0;
    for(i=0;i<v;i++)
    {
        src=i;
        for(j=vec[i].begin()+1;j!=vec[i].end();j++)
        {
                des=*j;
                weigh=w[i][*j];
                if(dist[src]!=MAXINT && dist[des]>dist[src]+weigh)
                    dist[des]=dist[src]+weigh;
        }
    }
    //cout<<"here"<<endl;
            //check all edges once again to detect negative weight cycle
     for(i=0;i<v;i++)
    {
        src=i;
        for(j=vec[i].begin()+1;j!=vec[i].end();j++)
        {
                des=*j;
                weigh=w[i][*j];
                if(dist[src]!=MAXINT && dist[des]>dist[src]+weigh)
                   {
                     cout<<"there is negative weight cycle present"<<endl;
                    return ;

                   }
        }

    }
    cout<<"node     distance"<<endl;
    for(i=0;i<v;i++)
    {
        cout<<i<<"  "<<dist[i]<<endl;
    }
    cout<<endl;
}

void Graph::johnson()
{
    vector<int> p;          //1.create a new vertex and connect to every other vertex with edge weight 0
    p.push_back(v);
    int i,j;
    for(i=0;i<v;i++)
    {
        p.push_back(i);

    }
    vec.push_back(p);
    Graph g(v+1);
    int *dist=new int[v]();          //all 0

}
/*istream& operator>>(istream& stream,Graph g)
{
    stream>>g.v;
     int i,j;
    for(i=0;i<v;i++)
    {
        for(j=0;j<vec[i].size();j++)       //problematic!!!!!!!!!!!!!!!!!!!!!
        {
           stream<<(vec[i])[j];
        }
    }
    return stream;
}
*/


bool operator<(T a,T b)
{
     return (a.dist>b.dist);
}

bool operator>(T a,T b)
{
     return (a.dist<b.dist);
}

ostream& operator<<(ostream& stream,T a)
{
    stream<<a.dist;
    return stream;
}

 bool operator<(K a,K b)
{
    return(a.w>b.w);
}

 bool operator>(K a,K b)
{
    return(a.w<b.w);
}

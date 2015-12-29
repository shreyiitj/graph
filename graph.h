//graph.h
#include<iostream>
#include<fstream>
#include<vector>
#include<list>
#include<queue>
#include<stack>

using namespace std;
class subSet;
class Graph
{
int v;                               // no. of vertices
int e;                               //no of edges
vector<vector<int> > vec;            // adjacency vectors
int **w;                             //to store weights

public:

friend class K;
friend class pairs;
friend class subSet;
Graph(int v1);
Graph(int v1,int **weigh,vector<vector<int> > vect);
void addEdge(int v1,int v2,int wt);
void printGraph();
void BFS(int v1);
void DFS(int v1);
void DFSmain(int v1,bool* visited);
void dijkstra(int src);
void floyd_warshal();
void mstPrim();
void mstKruskal();
int findSet(int,subSet*);
void union2(int a,int b,subSet *ss);
void topoSort();
void topoUtil(int i,bool* visited,stack<int>& Stack);
void bellman_ford(int v1);
void johnson();
friend ostream& operator<<(ostream& stream,Graph g);
//friend istream& operator>>(istream& stream,Graph g);
};


class T
{
    public:                 //so that in dijkstra they can be accessed easily when extracted from min-heap
    int node;
    int dist;
    T(int n,int d)
    {
        node=n;
        dist=d;
    }

    friend bool operator<(T a,T b);
    friend bool operator>(T a,T b);
    friend ostream& operator<<(ostream& stream,T a);
};

class K                // for kruskal
{

    int src;
    int des;
    int w;
    public:
        friend class Graph;
    K(){};
    K(int a,int b,int c){src=a;des=b;w=c;}
    friend bool operator<(K a,K b);
    friend bool operator>(K a,K b);
};

class pairs
{
    int a;
    int b;
public:
    friend class Graph;
    pairs(){};
    pairs(int p,int q) {a=p; b=q;}

};

class subSet
{
    int parent;
    int rank;
public:
    friend class Graph;
    subSet(){};
    subSet(int p,int r){parent=p; rank=r;}

};





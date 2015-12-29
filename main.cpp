#include "graph_class.cpp"


int main()
{

Graph g(3);
g.addEdge(0,1,5);
g.addEdge(0,2,9);
g.addEdge(1,2,5);
/*

Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(2, 0);
    g2.addEdge(2, 3);
    g2.addEdge(3, 3);
*/
Graph g3(6);
g3.addEdge(0,3,4);
g3.addEdge(0,1,7);
g3.addEdge(0,5,2);
g3.addEdge(0,4,9);
g3.addEdge(1,4,3);
g3.addEdge(4,2,6);
g3.addEdge(5,3,1);
g3.addEdge(2,1,-1);

g3.printGraph();
//cout<<"\nBFS:\n";
//g3.BFS(0);
//cout<<"\n\n";
//g3.DFS(0);
cout<<"\n";
//g3.dijkstra(0);
cout<<"\n";
//g3.mstPrim();
//cout<<"\n";
//g3.mstKruskal();
//cout<<"\n";
//g3.topoSort();
cout<<"\n";
//g3.bellman_ford(0);
cout<<"\n";
//g3.floyd_warshal();          //all pair shortest path
g3.johnson();                 //all pair shortest path(bellman+dijkstra)(modifying edges)


/*  **********  to store and retrieve from file  *****************
ofstream out("graph");
if(!out)
{
    cout<<"can not open graph file"<<endl;
    return 1;
}
out<<g;
out.close();

ifstream in("graph");
if(!in)
{
    cout<<"can not open graph file"<<endl;
    return 1;
}
char v,extra,c;
int v1,c1;
int i,j=0;
in>>v;             //no. of vertices
//cout<<"v is "<<v<<endl;

v1=v-48;
//cout<<"v1 is "<<v1<<endl;
Graph g1(v1);
for(i=0;i<v1;i++)
{
    in>>extra;


    while(in)
    {
        //cout<<"loop";
        in>>c;
        //cout<<c<<" ";
        if(c=='n') break;
            c1=c-48;
        g1.addEdge(i,c1);
        //j++;
    }
    //cout<<"\n";
}
in.close();
cout<<"\n\n";
g1.printGraph();
*/
}

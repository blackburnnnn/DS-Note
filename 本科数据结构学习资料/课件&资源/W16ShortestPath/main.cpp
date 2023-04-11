#include <iostream>
#include"Graph.h"

using namespace std;

int main()
{
    Graph agraph;
    agraph.LoadGraphFromFile("tmpgraph.txt");
    Graph::node_type src=1;
    Graph::node_type dest=8;
    vector<Graph::node_type> result_path;
    Graph::weight_type mindest=-1;
    agraph.ShortestPath(src,dest,mindest,result_path);
    cout<<src<<"->"<<dest<<"  Shortest Distance:"<<mindest<<endl;
    cout<<"Shortest Path:";
    for(int z=(int)result_path.size()-1;z>=0;z--)
        cout<<result_path[z]<<" ";
    cout<<endl;
    return 0;
}

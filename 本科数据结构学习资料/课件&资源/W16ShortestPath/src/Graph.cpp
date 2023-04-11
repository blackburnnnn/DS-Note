#include "Graph.h"


void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2)
  {
    v.push_back(s.substr(pos1, pos2-pos1));

    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(s.substr(pos1));
}

Graph::Graph()
{
    //ctor
    node_count=0;
}

Graph::~Graph()
{
    //dtor
}

bool Graph::LoadGraphFromFile(string filePath){
    ifstream file(filePath.c_str());
    if(!file)
        return false;
    string str_nodes;
    getline(file, str_nodes);
    vector<string> vec_str_nodes;
    SplitString(str_nodes,vec_str_nodes, " ");
    node_count=(int) vec_str_nodes.size();
    for(int z=0;z<(int)vec_str_nodes.size()+1;z++){
        vector<adjNode> anemptylist;
        adjList.push_back(anemptylist);
    }
    int from, to, weight;
    while(!file.eof()){
        file>>from>>to>>weight;
        adjList[from].push_back(adjNode(to,weight));
        adjList[to].push_back(adjNode(from,weight));
    }
    return true;
}


void Graph::ShortestPath(node_type src, node_type dest, weight_type &mindist, vector<node_type> &result_path){
    weight_type *dist=new weight_type[node_count+1];
    bool *visited=new bool[node_count+1];
    node_type *path=new node_type[node_count+1];
    int INF=99999999;
    //Step 1 Initialize
    for(int z=0;z<=node_count;z++) dist[z]=INF;
    for(int z=0;z<=node_count;z++) visited[z]=false;
    dist[src]=0;
    visited[src]=true;
    path[src]=-1;
    for(int z=1;z<(int)adjList[src].size();z++){
        dist[adjList[src][z].id]=adjList[src][z].weight;
        path[adjList[src][z].id]=src;
    }

    //Step 2 Iteration
    for(int z=1;z<=node_count;z++){
        //Pick the minum
        weight_type currmin=INF;
        node_type currnode=-1;
        for(int zz=1;zz<=node_count;zz++){
            if(!visited[zz] &&dist[zz]<currmin){
                currmin=dist[zz];
                currnode=zz;
            }
        }
        //Check if the dest
        visited[currnode]=true;
        if(currnode==dest){
            mindist=currmin;
            TraceBackPath_(dest,path,result_path);
            delete path;
            delete dist;
            return;
        }
        //else update dist and path;
        for(int zz=0;zz<(int)adjList[currnode].size();zz++){
                node_type updated_node_id=adjList[currnode][zz].id;
                if(adjList[currnode][zz].weight+dist[currnode]<dist[updated_node_id]){
                    dist[updated_node_id]=adjList[currnode][zz].weight+dist[currnode];
                    path[updated_node_id]=currnode;
                }
        }
    }

    delete path;
    delete dist;
    return;
}


void Graph::TraceBackPath_(node_type dest, node_type *path, vector<node_type> &result_path){
    while(dest!=-1){
        result_path.push_back(dest);
        dest=path[dest];
    }
}

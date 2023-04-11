#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<string>
#include<fstream>
#include<iostream>
using namespace std;


void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c);

class Graph
{
    public:
        Graph();
        virtual ~Graph();
        typedef int node_type ;
        typedef int weight_type;
        struct adjNode{
            node_type id;
            weight_type weight;
            adjNode(node_type _id, weight_type _weight):id(_id),weight(_weight){}
        };

        bool LoadGraphFromFile(string filePath);
        void ShortestPath(node_type src, node_type dest, weight_type &mindist, vector<node_type> &path);


    protected:



    private:
        int node_count;
        vector<vector<adjNode> > adjList;
        void TraceBackPath_(node_type dest, node_type *path, vector<node_type> &result_path);

};

#endif // GRAPH_H

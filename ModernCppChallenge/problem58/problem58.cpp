#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Node{
public:

    std::string get_name(){ return name;}
    private:
    std::string name;       
    Node(std::string input_name):name(input_name){}
};

class Edge{
public:
    Edge(int input_length,std::shared_ptr<Node> node1,std::shared_ptr<Node> node2)
     :length(input_length)
    {
        nodes = std::make_pair(node1,node2);
    }
    bool has_node(Node input)
    {
        return (nodes.first->get_name() == input.get_name() || nodes.second->get_name() == input.get_name());
    };
    void get_next_node(Node input)
    {   
        if input.get_name() ==nodes.first->get_name()
        {
        return nodes.second();
        }
        else if input.get_name() ==nodes.second->get_name()
        {
        return nodes.first();
        }
        else{
            std::cout<<"Error input not in edge:"<<input.get_name()<<std::endl;
        }

    }
private:
    std::pair<std::shared_ptr<Node>,std::shared_ptr<Node>> nodes;
    int length;
};

class Graph{
    public: 
    void getShortestPath(Node start_node, Node end_node)
    {
        std::vector<std::vector<Edge>> paths;
        std::vector<int> total_lengths;

    }
    void getPath(Node start, Node end)
    {
        
        std::vector<new_edges> new_edges;
        
        getEdgeFromNode(start,new_edges);
        
        
    }
    void getEdgeFromNode(Node input,  std::vector<Edge> &new_edges)
    {
        for(auto edge : edges)
        {
            if(edge.has_node(input))
            {
                new_edges.push_back(edge);
            }
        }
    }
    private:
    std::vector<Node> nodes;
    std::vector<Edge> edges;
};


int main(){
}
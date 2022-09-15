#include <string>
#include <map>
#include <random>

#include "sparse_graph.h"
#include "vertex.h"

Sparse_Graph::Sparse_Graph(){

}

Sparse_Graph::Sparse_Graph(std::vector<std::vector<std::string>> word_2d_vec){
    for(std::vector<std::string> word_vec: word_2d_vec){
        bool first_ele = true;
        std::string vertex_id;
        std::string neighbor_id;
        for(std::string word: word_vec){
            if(first_ele){
                vertex_id = word;
                add_vertex(vertex_id);
                first_ele = false;
            }
            else{
                neighbor_id = word;
                add_neighbor_one_way(neighbor_id, vertex_id);
            }
        }
    }
}

void Sparse_Graph::add_neighbor_one_way(std::string neighbor_id, std::string vertex_id){
    Vertex& specified_vertex = vertex_map[vertex_id];
    specified_vertex.add_neighbor(neighbor_id);
}

Sparse_Graph& Sparse_Graph::operator= (Sparse_Graph& g){
    vertex_map.clear();
    vertex_map = g.vertex_map;
    return *this;
}

int Sparse_Graph::get_vertex_count(){
    return vertex_map.size();
}

void Sparse_Graph::add_vertex(std::string id){
    if(vertex_exists(id)){
        return;
    }
    Vertex v(id);
    std::pair<std::string, Vertex> p(id, v);
    vertex_map.insert(p);
}

bool Sparse_Graph::vertex_exists(std::string id){
    if(vertex_map.find(id) != vertex_map.end()){
        return true;
    }
    else{
        return false;
    }
}

void Sparse_Graph::add_neighbor_to_vertex(std::string neighbor_id, std::string vertex_id){
    Vertex& new_neighbor = vertex_map[neighbor_id];
    Vertex& specified_vertex = vertex_map[vertex_id];
    if(specified_vertex.already_has_this_neighbor(neighbor_id)){
        return;
    }
    else{
        specified_vertex.add_neighbor(neighbor_id);
        new_neighbor.add_neighbor(vertex_id);
    }
}

void Sparse_Graph::merge_vertexes(std::string vertex1, std::string vertex2){
    Vertex& v1 = vertex_map[vertex1];
    Vertex& v2 = vertex_map[vertex2];

    v1.remove_neighbor(vertex2);
    v2.remove_neighbor(vertex1);

    v1.transfer_neighbors(v2);

    remove_vertex(vertex2);

    replace_vertex_id(vertex2, vertex1);
}

void Sparse_Graph::replace_vertex_id(std::string old_id, std::string new_id){
    for(auto& pair: vertex_map){
        Vertex& v = pair.second;
        v.replace_neighbor_alias(old_id, new_id);
    }
}

void Sparse_Graph::remove_vertex(std::string vertex_id){
    vertex_map.erase(vertex_id);
}

int Sparse_Graph::get_first_vertex_edge_count(){
    Vertex& v1 = vertex_map.begin()->second;
    int edge_count = v1.edge_count();
    return edge_count;
}

void Sparse_Graph::random_merge(){
    int rand_vert_ind1 = (rand() % vertex_map.size());
    int rand_vert_ind2 = (rand() % vertex_map.size());
    std::string vertex_id1 = std::next(std::begin(vertex_map), rand_vert_ind1)->first; 
    std::string vertex_id2 = std::next(std::begin(vertex_map), rand_vert_ind2)->first; 
    merge_vertexes(vertex_id1, vertex_id2);
}


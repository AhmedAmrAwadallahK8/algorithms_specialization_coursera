
#include "path.h"

Path::Path(int city_count):
    dist(0),
    last_added_id(0)
{
    for(int i = 1; i < city_count; i++){
        excluded_ids.push_back(i);
    }
}

Path::Path(Path* parent, int city_to_remove, double dist_increase){
    dist = parent->dist;
    last_added_id = city_to_remove;
    for(auto ids: parent->excluded_ids){
        excluded_ids.push_back(ids);
    }
    remove_potential_id(city_to_remove);
    dist += dist_increase;

    /*TODO*/
}

int Path::get_last_added_id(){
    return last_added_id;
}

double Path::get_dist(){
    return dist;
}

void Path::update_dist(double _dist){
    dist = _dist;
}

void Path::update_last_added_id(int _id){
    last_added_id = _id;
}

/*Technically this shouldn't be used*/
void Path::remove_potential_id(int id){
    for(int i = 0; i < int(excluded_ids.size()); i++){
        if(excluded_ids[i] == id){
            last_added_id = excluded_ids[i];
            excluded_ids.erase(excluded_ids.begin() + i);
            break;
        }
    }
}

std::vector<int> Path::get_excluded_ids(){
    return excluded_ids;
}
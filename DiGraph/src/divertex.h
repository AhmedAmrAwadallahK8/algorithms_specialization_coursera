#ifndef DIVERTEX_H
#define DIVERTEX_H

#include <string>
#include <vector>

class Divertex{
    private:
        std::string id;
        std::vector<Divertex*> paths;
        std::vector<Divertex*> inverse_paths;
        bool visited;
        int finishing_time;
    public:
        Divertex(std::string id);
        void add_path(Divertex* neighbor);
        void remove_path(Divertex* neighbor);
        void remove_inverse_path(Divertex* inverse_neighbor);
        void invert_path(Divertex* neighbor);
        void invert_paths();
        void discovered();
        bool is_discovered();
        void set_finishing_time(int f_time);
        bool has_path_to(Divertex* neighbor);

};

#endif
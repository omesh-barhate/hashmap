#include "hashmap.h"


void create_map(Map *map){
    map->init=init;
    map->put=put;
    map->get=get;
    map->remove=map_remove;
    map->delete=map_delete;
    map->print=map_print;
    map->init(map);
}
extern void test_map_operations();

int main(){
   printf("Running tests...\n");
    test_map_operations();
    return 0;
}

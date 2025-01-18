#include "hashmap.h"

int main() {
    Map my_map;
    create_map(&my_map);

    my_map.put(&my_map, "Kalyan", "City");
    my_map.put(&my_map, "India", "Country");

    printf("Kalyan: %s\n", (char *)my_map.get(&my_map, "Kalyan"));
    printf("India: %s\n", (char *)my_map.get(&my_map, "India"));

    my_map.remove(&my_map, "Kalyan");

    printf("Kalyan after removal: %s\n", (char *)my_map.get(&my_map, "Kalyan"));

    my_map.delete(&my_map);

    return 0;
}

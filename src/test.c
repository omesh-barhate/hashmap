#include <stdio.h>
#include <assert.h>
#include "hashmap.h"

void test_print_int_value(){
    Map map;
    create_map(&map);
    char *key = "age";
    int value = 25;
    map.put(&map,key,&value);
    int *retrieved_value=(int *)map.get(&map, key);
    if(retrieved_value != NULL){
        printf("Value for '%s': %d\n",key,*retrieved_value);
    } 
    else{
        printf("Key '%s' not found in map.\n",key);
    }
}

void test_map_operations(){
    Map map;
    create_map(&map);
    int value1 = 42;
    map.put(&map, "key1", &value1);

    int *retrieved_value = (int *) map.get(&map, "key1");
    assert(retrieved_value != NULL); 
    assert(*retrieved_value == 42);

    int value2 = 100;
    map.put(&map, "key2", &value2);

    retrieved_value = (int *) map.get(&map, "key2");
    assert(retrieved_value != NULL);
    assert(*retrieved_value == 100); 

    map.remove(&map, "key1");
    retrieved_value = (int *) map.get(&map, "key1");
    assert(retrieved_value == NULL); 

    printf("Printing map after removal:\n");
    map.print(&map, "%d");

    retrieved_value = (int *) map.get(&map, "non_existent_key");
    assert(retrieved_value == NULL); 

    map.delete(&map);
    printf("Map deleted successfully.\n");

    printf("All tests passed.\n");
}

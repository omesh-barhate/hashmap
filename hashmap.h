#ifndef HASHMAP_IMPLEMENTATION
#define HASHMAP_IMPLEMENTATION

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#ifndef HASHMAP_SIZE
#define HASHMAP_SIZE 100
#endif
#ifndef HASH_PRIME_NUMBER
#define HASH_PRIME_NUMBER 2
#endif

typedef struct Node {
    char *key;
    void *value;
    struct Node *next;
} Node;

typedef struct Map Map;

struct Map {
    Node *hashmap[HASHMAP_SIZE];

    void (*init)(Map *);
    int (*put)(Map *, char *, void *);
    void *(*get)(Map *, char *);
    int (*remove)(Map *, char *);
    void (*delete)(Map *);
    void (*print)(Map *, const char *);
};

static void map_init(Map *map);
static int map_put(Map *map, char *key, void *value);
static void *map_get(Map *map, char *key);
static int map_remove(Map *map, char *key);
static void map_delete(Map *map);
static void map_print(Map *map, const char *printing_format);
static size_t hashmap_hash(char *key);

inline static void check_null(void *value) {
    if(value==NULL){
        fprintf(stderr,"OUT OF Memory\n");
        exit(1);
    }
}

static size_t hashmap_hash(char *key){
    size_t hash=HASH_PRIME_NUMBER;
    for(size_t i=0; i<strlen(key);i++){
        hash=hash*31+(int)key[i];
    }
    return hash%HASHMAP_SIZE;
}

static void map_init(Map *map){
    for(size_t i=0;i<HASHMAP_SIZE;i++) {
        map->hashmap[i]=NULL;
    }
}

static int map_put(Map *map, char *key, void *value){
    size_t index=hashmap_hash(key);
    Node *current=malloc(sizeof(Node));
    check_null(current);
    current->value=value;
    current->key=malloc(sizeof(char)*(strlen(key)+1));
    check_null(current->key);
    strcpy(current->key,key);
    current->next=map->hashmap[index];
    map->hashmap[index]=current;
    return 0;
}

static void *map_get(Map *map, char *key){
    size_t index=hashmap_hash(key);
    Node *current=map->hashmap[index];
    while(current!=NULL && strcmp(current->key,key)!= 0){
        current=current->next;
    }
    return (current==NULL)?NULL:current->value;
}

static int map_remove(Map *map, char *key){
    size_t index=hashmap_hash(key);
    Node *current=map->hashmap[index];
    if(current==NULL){
        return 1;
    }

    Node *key_to_be_deleted;
    if(strcmp(current->key,key)== 0){
        map->hashmap[index]=current->next;
        key_to_be_deleted=current;
    } else{
        while(current->next!=NULL && strcmp(current->next->key,key)!=0){
            current=current->next;
        }
        if(current->next==NULL){
            return 1;
        }
        key_to_be_deleted=current->next;
        current->next=key_to_be_deleted->next;
    }

    free(key_to_be_deleted->key);
    free(key_to_be_deleted);
    return 0;
}

static void map_delete(Map *map){
    for (size_t i=0; i<HASHMAP_SIZE;i++){
        Node *node=map->hashmap[i];
        while(node!=NULL) {
            Node *next_node=node->next;
            free(node->key);
            free(node);
            node=next_node;
        }
    }
}

static void map_print(Map *map, const char *printing_format){
    for (size_t i=0; i<HASHMAP_SIZE;i++){
        Node *node=map->hashmap[i];
        if(node==NULL){
            continue;
        }
        while (node!=NULL){
            printf("%s: ",node->key);
            printf(printing_format,node->value);
            printf(" -> ");
            node=node->next;
        }
        printf("NULL\n");
    }
}


void create_map(Map *map){
    map->init=map_init;
    map->put=map_put;
    map->get=map_get;
    map->remove=map_remove;
    map->delete=map_delete;
    map->print=map_print;
    map->init(map);
}

#endif

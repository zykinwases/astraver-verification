#include "map.h"
#include <stdlib.h>

int initializeMap(Map *map, int size) {
    map->capacity = size;
    map->count = 0;
    map->items = malloc(size * sizeof(Item));
    if (map->items != NULL) {
        for (int i = 0; i < size; i++) {
            map->items[i].existent = 0;
        }
    }
    return (map->items == NULL) ? 0 : 1;
}

void finalizeMap(Map *map) {
    free(map->items);
    return;
}

int addElement(Map *map, Key *key, Value *value) {
    int prevEmpty = 0;
    for (int i = 0; i < map->capacity; i++) {
        if (map->items[i].existent != 0) {
            if (map->items[i].key.a == key->a && map->items[i].key.b == key->b) {
                map->items[i].value = *value;
                return 1;
            }
        }
    }
    for (int i = 0; i < map->capacity; i++) {
        if (map->items[i].existent == 0) {
            map->items[i].existent = 1;
            map->items[i].key = *key;
            map->items[i].value = *value;
            map->count++;
            return 1;
        }
    }
    return 0;
}

int removeElement(Map *map, Key *key, Value *value) {
    for (int i = 0; i < map->capacity; i++) {
        if (map->items[i].existent != 0) {
            if (map->items[i].key.a == key->a && map->items[i].key.b == key->b) {
                if (value != NULL) {
                    value->c = map->items[i].value.c;
                    value->d = map->items[i].value.d;
                }
                map->items[i].existent = 0;
                map->count--;
                return 1;
            }
        }
    }
    return 0;
}

int getElement(Map *map, Key *key, Value *value) {
    for (int i = 0; i < map->capacity; i++) {
        if (map->items[i].existent != 0) {
            if (map->items[i].key.a == key->a && map->items[i].key.b == key->b) {
                value->c = map->items[i].value.c;
                value->d = map->items[i].value.d;
                return 1;
            }
        }
    }
    return 0;
}
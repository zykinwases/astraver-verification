#include "map.h"
#include <stdlib.h>

int main() {
    Map *map = malloc(sizeof(Map));
    Key k1, k2, k3;
    Value v1, v2, v_res;

    k1.a = 1;
    k1.b = 2;
    k2.a = 2;
    k2.b = 1;
    k3.a = 3;
    k3.b = 3;

    v1.c = 1;
    v1.d = 1;
    v2.c = 2;
    v2.d = 2;

    if (map != NULL) {
        initializeMap(map, 2);
        printf("%d %d\n", map->capacity, map->count);

        addElement(map, &k1, &v1);
        addElement(map, &k2, &v2);
        // adding element out of border
        if (addElement(map, &k3, &v1) != 0) {
            return 1;
        }
        printf("%d %d\n", map->capacity, map->count);

        getElement(map, &k2, &v_res);
        printf("%d %d\n", v_res.c, v_res.d);

        removeElement(map, &k1, &v1);
        printf("%d %d\n", map->capacity, map->count);

        addElement(map, &k1, &v2);
        printf("%d %d\n", map->capacity, map->count);

        getElement(map, &k1, &v_res);
        printf("%d %d\n", v_res.c, v_res.d);

        // get not existing element
        if (getElement(map, &k3, &v_res) != 0) {
            return 1;
        }

        // add element with existing key and different value
        addElement(map, &k1, &v1);
        printf("%d %d\n", map->capacity, map->count);

        getElement(map, &k1, &v_res);
        printf("%d %d\n", v_res.c, v_res.d);

        removeElement(map, &k1, &v2);
        printf("%d %d\n", map->capacity, map->count);

        // remove not existing element
        removeElement(map, &k1, &v1);
        printf("%d %d\n", map->capacity, map->count);

        finalizeMap(map);
        free(map);
    }

    return 0;
}
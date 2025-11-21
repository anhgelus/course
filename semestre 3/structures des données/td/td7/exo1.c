#include <stdio.h>
#include <stdlib.h>

typedef struct Road{
    int u, v;
    double dist;
} Road;

typedef struct RoadCell{
    Road* road;
    struct RoadCell* next;
} RoadCell;

typedef struct City{
    int id;
    int x, y;
    RoadCell* roads; 
} City;

City** init_cities(int n){
    City** cities = (City**) malloc(sizeof(City)*n);
    for (int i = 0; i < n; i++){
        cities[i] = (City*) malloc(sizeof(City));
        cities[i]->id = i;
        cities[i]->x = 0;
        cities[i]->y = 0;
        cities[i]->roads = NULL; 
    }
    return cities;
}

void update_city(City* city, int x, int y){
    city->x = x;
    city->y = x;
}

void add_route(City* c1, City* c2, double dist){
    Road* road = (Road*) malloc(sizeof(Road));
    road->u = c1->id;
    road->v = c2->id;
    road->dist = dist;

    RoadCell* road_1 = (RoadCell*) malloc(sizeof(RoadCell));
    road_1->road = road;
    road_1->next = c1->roads;
    c1->roads = road_1;

    RoadCell* road_2 = (RoadCell*) malloc(sizeof(RoadCell));
    road_2->road = road;
    road_2->next = c2->roads;
    c2->roads = road_2;
}

void print(City** cities, int n){
    printf("Cities len: %d\n", n);
    for (int i = 0; i < n; i++){
        printf("city %d: {x: %d, y: %d}, roads [", i, cities[i]->x, cities[i]->y);
        RoadCell* roads = cities[i]->roads;
        while (roads){
            Road* road = roads->road;
            printf("{from: %d, to: %d, dist: %f},", road->u, road->v, road->dist);
            roads = roads->next;
        }
        printf("]\n");
    }
}

void free_cities(City** cities, int n){
    for (int i = 0; i < n; i++) {
        City* city = cities[i];
        while (city->roads){
            //TODO: free(city->roads->road)
            RoadCell* old = city->roads;
            city->roads = city->roads->next;
            free(old);
        }
        free(city);
    }
    free(cities);
}

int main(){
    City** cities = init_cities(4);
    add_route(cities[0], cities[1], 3);
    add_route(cities[1], cities[2], 4);
    add_route(cities[0], cities[2], 8);
    add_route(cities[3], cities[1], 4.5);
    print(cities, 4);
    return 0;
}

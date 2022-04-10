// Graph interface
#include <cstdbool>
#define Vertex int

struct GraphRep;

struct Edge;

typedef struct GraphRep GraphRep;
typedef struct GraphRep *graph;

typedef struct Edge edge;

void init_graph(graph);

bool valid_vertex(graph, Vertex);
bool Adjacent(graph, edge);

int *Neighbors(graph, Vertex);

void insert_vertex(graph, Vertex);
void delete_vertex(graph, Vertex);

void insert_edge(graph, edge);
void delete_edge(graph, edge);

int first_neighbor(graph, Vertex);
int next_neighbor(graph, Vertex, Vertex);




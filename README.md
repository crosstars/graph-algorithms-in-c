# graph-algorithms-in-c
in this repo I will impliment some basic graph algorithms in c
# The things used in graphrep.c

1. graph structure (self referencial, attributes can be added)

2. label structure (a.k.a start node of the node lists )

3. defined FILEN as "set.txt" (in this input file the first line must contain the node number space the edge number)

4. defined GTYPE as "undirected" ( if this option is not changed then it creates a bidirectional edge , alter this srting to anything and this program will run in directional mode)

5. gnode* create_node(int next_node) (creates a dinamic graph node and then puts the value in the lbl field of the node returns the addres of the new node)

6. void pushnode(label* l,int lbl,int next_node) (inserts the node in main adjacency list)

7. void initialize(label* l,int node) (creates an empty graph with only the nodes)

8. void take_input_list(FILE* fp,int node, label* l,int edges)  (this is the main driver to create the adjacency list)

9. void showlist(label* l, int node) (this shows the adjacency list)

10.  gnode* inMat(FILE* fp ,int node,int edges) (this creates the adjacency matrix dynamically,default weigth of an edge is 1)

11. void showMat(gnode* arr,int node)   (this shows the adjacency matrix)

this is all for now........ thanks..

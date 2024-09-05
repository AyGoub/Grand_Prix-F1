#ifndef GRAPH_H
#define GRAPH_H

/**
 * @brief Structure representing a 2D vector with x and y coordinates.
 */
typedef struct Vector2D {
    int x; /**< The x-coordinate of the vector. */
    int y; /**< The y-coordinate of the vector. */
} Vector2D;

/**
 * @brief Structure representing a terrain map.
 */
typedef struct TerrainMap {
    char** grid; /**< The grid representing the terrain. */
    int width; /**< The width of the terrain map. */
    int height; /**< The height of the terrain map. */
} TerrainMap;

/**
 * @brief Structure representing a node in the graph.
 */
typedef struct GraphNode {
    Vector2D coordinates; /**< The coordinates of the node. */
    Vector2D velocity; /**< The velocity of the node. */
    double cost; /**< The cost of reaching this node. */
    double heuristicCost; /**< The heuristic cost of reaching the goal from this node. */
    double totalCost; /**< The total cost of reaching the goal from this node. */
    struct GraphNode* predecessor; /**< The predecessor node in the path. */
    int fuel; /**< The fuel level of the node. */
    int turbo; /**< The turbo level of the node. */
} GraphNode;

/**
 * @brief Initializes a terrain map with the given width and height.
 * @param width The width of the terrain map.
 * @param height The height of the terrain map.
 * @return The initialized terrain map.
 */
TerrainMap initializeTerrainMap(int width, int height);

/**
 * @brief Displays the terrain map.
 * @param map The terrain map to display.
 */
void displayTerrainMap(TerrainMap map);

/**
 * @brief Creates a graph node with the given coordinates, velocity, fuel, turbo, and predecessor.
 * @param coordinates The coordinates of the node.
 * @param velocity The velocity of the node.
 * @param fuel The fuel level of the node.
 * @param turbo The turbo level of the node.
 * @param from The predecessor node in the path.
 * @return The created graph node.
 */
GraphNode* createGraphNode(Vector2D coordinates, Vector2D velocity, int fuel, int turbo, GraphNode* from);

/**
 * @brief Calculates the heuristic cost from one node to another.
 * @param from The source node.
 * @param to The destination node.
 * @return The heuristic cost from the source node to the destination node.
 */
double calculateHeuristic(GraphNode* from, GraphNode* to);

/**
 * @brief Checks the occupancy of three positions.
 * @param pos The first position.
 * @param second The second position.
 * @param third The third position.
 * @return 1 if the positions are occupied, 0 otherwise.
 */
int checkOccupancy(Vector2D pos, Vector2D second, Vector2D third);

/**
 * @brief Checks if two graph nodes are equal.
 * @param first The first graph node.
 * @param second The second graph node.
 * @return 1 if the nodes are equal, 0 otherwise.
 */
int nodesEqual(GraphNode* first, GraphNode* second);

/**
 * @brief Frees the memory allocated for the terrain map.
 * @param map The terrain map to free.
 */
void freeTerrainMap(TerrainMap map);

/**
 * @brief Frees the memory allocated for a graph node.
 * @param node The graph node to free.
 */
void freeGraphNode(GraphNode* node);

/**
 * @brief Updates the properties of a graph node.
 * @param node The graph node to update.
 * @param position The new position of the node.
 * @param gasLevel The new gas level of the node.
 * @param speed The new speed of the node.
 */
void updateNode(GraphNode *node, Vector2D position, int gasLevel, Vector2D speed);

#endif /* GRAPH_H */

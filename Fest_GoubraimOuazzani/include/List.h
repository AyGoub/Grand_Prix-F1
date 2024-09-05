#ifndef LIST_H
#define LIST_H

#include "graph.h" 

/**
 * @brief Structure representing a list node for graph nodes.
 */
typedef struct GraphNodeList {
    GraphNode *node; /**< Pointer to the graph node. */
    struct GraphNodeList *next; /**< Pointer to the next node in the list. */
} GraphNodeList;

/**
 * @brief Structure representing a list of graph nodes.
 */
typedef struct GraphList {
    GraphNodeList *head; /**< Pointer to the head of the list. */
} GraphList;

/**
 * @brief Creates a new graph list.
 * @return Pointer to the newly created graph list.
 */
GraphList *createGraphList();

/**
 * @brief Adds a graph node to the given graph list.
 * @param list Pointer to the graph list.
 * @param node Pointer to the graph node to be added.
 */
void addGraphNodeToList(GraphList *list, GraphNode *node);

/**
 * @brief Checks if a graph node is present in the given graph list.
 * @param list Pointer to the graph list.
 * @param node Pointer to the graph node to be checked.
 * @return 1 if the node is present, 0 otherwise.
 */
int isGraphNodeInList(GraphList *list, GraphNode *node);

/**
 * @brief Frees the memory occupied by the given graph list.
 * @param list Pointer to the graph list to be freed.
 */
void freeGraphList(GraphList *list);

/**
 * @brief Sorts the graph list if necessary.
 * @param list Pointer to the graph list to be sorted.
 */
void sortGraphList(GraphList *list);

#endif // LIST_H

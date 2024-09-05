#ifndef QUEUE_H
#define QUEUE_H

#include "graph.h"  

/**
 * @brief Structure representing a node in the graph queue.
 */
typedef struct GraphNodeQueue {
    GraphNode *node;                /**< Pointer to the graph node. */
    struct GraphNodeQueue *next;    /**< Pointer to the next node in the queue. */
} GraphNodeQueue;

/**
 * @brief Structure representing a graph queue.
 */
typedef struct GraphQueue {
    GraphNodeQueue *head;   /**< Pointer to the head of the queue. */
} GraphQueue;

/**
 * @brief Creates a new graph queue.
 * @return Pointer to the newly created graph queue.
 */
GraphQueue *createGraphQueue();

/**
 * @brief Enqueues a graph node into the graph queue.
 * @param queue Pointer to the graph queue.
 * @param node Pointer to the graph node to be enqueued.
 */
void enqueueGraph(GraphQueue *queue, GraphNode *node);

/**
 * @brief Dequeues a graph node from the graph queue.
 * @param queue Pointer to the graph queue.
 * @return Pointer to the dequeued graph node.
 */
GraphNode *dequeueGraph(GraphQueue *queue);

/**
 * @brief Checks if the graph queue is empty.
 * @param queue Pointer to the graph queue.
 * @return 1 if the queue is empty, 0 otherwise.
 */
int isGraphQueueEmpty(GraphQueue *queue);

/**
 * @brief Frees the memory allocated for the graph queue.
 * @param queue Pointer to the graph queue.
 */
void freeGraphQueue(GraphQueue *queue);

/**
 * @brief Checks if a graph node is present in the graph queue.
 * @param queue Pointer to the graph queue.
 * @param node Pointer to the graph node to be checked.
 * @return 1 if the node is present in the queue, 0 otherwise.
 */
int isGraphNodeInQueue(GraphQueue *queue, GraphNode *node);

/**
 * @brief Gets a graph node from the graph queue.
 * @param queue Pointer to the graph queue.
 * @param node Pointer to the graph node to be retrieved.
 * @return Pointer to the retrieved graph node, or NULL if not found.
 */
GraphNode *getGraphNodeFromQueue(GraphQueue *queue, GraphNode *node);

/**
 * @brief Removes a graph node from the graph queue.
 * @param queue Pointer to the graph queue.
 * @param node Pointer to the graph node to be removed.
 */
void removeGraphNodeFromQueue(GraphQueue *queue, GraphNode *node);

/**
 * @brief Finds a graph node in the graph queue.
 * @param queue Pointer to the graph queue.
 * @param node Pointer to the graph node to be found.
 * @return 1 if the node is found in the queue, 0 otherwise.
 */
int findGraphNodeInQueue(GraphQueue *queue, GraphNode *node);

#endif // QUEUE_H

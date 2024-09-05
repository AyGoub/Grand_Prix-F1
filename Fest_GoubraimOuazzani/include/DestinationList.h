#ifndef _DESTINATIONLIST_H
#define _DESTINATIONLIST_H

#include "graph.h"

/**
 * @brief Represents a destination with coordinates and estimated distance.
 */
typedef struct Destination {
    Vector2D coordinates; /**< The coordinates of the destination. */
    double estimatedDistance; /**< The estimated distance to the destination. */
} Destination;

/**
 * @brief Represents a list of destinations.
 */
typedef struct DestinationList {
    Destination* entries; /**< The array of destination entries. */
    int count; /**< The number of destinations in the list. */
} DestinationList;

/**
 * @brief Generates a list of destinations based on a terrain map and a starting node.
 *
 * @param map The terrain map.
 * @param start The starting node.
 * @return The generated destination list.
 */
DestinationList generateDestinationList(TerrainMap map, GraphNode* start);

/**
 * @brief Orders the destinations in the list.
 *
 * @param destinations The destination list to be ordered.
 * @return The ordered destination list.
 */
DestinationList orderDestinations(DestinationList destinations);

/**
 * @brief Displays the destinations in the list.
 *
 * @param destinations The destination list to be displayed.
 */
void showDestinationList(DestinationList destinations);

/**
 * @brief Selects the optimal destination from the list based on the second and third vectors.
 *
 * @param destinations The destination list.
 * @param second The second vector.
 * @param third The third vector.
 * @return The optimal destination node.
 */
GraphNode* selectOptimalDestination(DestinationList destinations, Vector2D second, Vector2D third);

/**
 * @brief Displays the optimal destination.
 *
 * @param destination The optimal destination node.
 */
void showOptimalDestination(GraphNode* destination);

/**
 * @brief Compares two destinations for sorting purposes.
 *
 * @param a The first destination.
 * @param b The second destination.
 * @return A negative value if a is less than b, a positive value if a is greater than b, or 0 if they are equal.
 */
int compareDestinations(const void* a, const void* b);

/**
 * @brief Frees the memory allocated for the destination list.
 *
 * @param destinations The destination list to be freed.
 */
void freeDestinationList(DestinationList destinations);

#endif // _DESTINATIONLIST_H
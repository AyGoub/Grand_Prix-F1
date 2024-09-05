#ifndef ASTAR_H
#define ASTAR_H

#include "graph.h"
#include "Queue.h"
#include "List.h"
#include "follow_line.h"
#include "HashTable.h"
#include "DestinationList.h"

/**
 * Calculates the gas consumption based on acceleration, speed, and terrain conditions.
 *
 * @param acc The acceleration vector.
 * @param speed The speed vector.
 * @param inSand Flag indicating if the vehicle is in sand.
 * @return The gas consumption value.
 */
int gasConsumption(Vector2D acc, Vector2D speed, int inSand);

/**
 * Calculates the norm (magnitude) of a vector.
 *
 * @param vect The input vector.
 * @return The norm of the vector.
 */
double Norme(Vector2D vect);




/**
 * Checks if there is a collision between two points on the circuit.
 *
 * @param start The starting point of the line segment.
 * @param end The ending point of the line segment.
 * @param circuit The terrain map.
 * @return 1 if there is a collision, 0 otherwise.
 */
int collisionDetectionV2(Vector2D start, Vector2D end, TerrainMap circuit);


/**
 * Checks if there is a collision between two points on the circuit.
 *
 * @param start The starting point of the line segment.
 * @param end The ending point of the line segment.
 * @param circuit The terrain map.
 * @param secondPosition The position of the second vehicle.
 * @param thirdPosition The position of the third vehicle.
 * @return 1 if there is a collision, 0 otherwise.
 */
int collisionDetection(Vector2D start, Vector2D end, TerrainMap circuit, Vector2D secondPosition, Vector2D thirdPosition);

/**
 * Checks if a vector is out of the boundaries of the circuit.
 *
 * @param vect The input vector.
 * @param circuit The terrain map.
 * @return 1 if the vector is out of boundaries, 0 otherwise.
 */
int OutofBoundries(Vector2D vect, TerrainMap circuit);

/**
 * Calculates the distance between two points on the terrain map.
 *
 * @param map The terrain map.
 * @param start The starting point.
 * @param end The ending point.
 * @return The distance between the two points.
 */
double calulateDistance(TerrainMap map, Vector2D start, Vector2D end);

/**
 * Creates a successor node for the A* algorithm.
 *
 * @param newPosition The new position vector.
 * @param newSpeed The new speed vector.
 * @param currentNode The current node.
 * @param newGas The new gas level.
 * @param circuit The terrain map.
 * @param end The end node.
 * @return The created successor node.
 */
GraphNode* createSuccessor(Vector2D newPosition, Vector2D newSpeed, GraphNode* currentNode, int newGas, TerrainMap circuit, GraphNode* end);

/**
 * Returns the path from the start node to the current node.
 *
 * @param currentNode The current node.
 * @return The path from the start node to the current node.
 */
GraphList* returnPath(GraphNode* currentNode);

/**
 * Initializes the start node for the A* algorithm.
 *
 * @param start The start node.
 * @param gasLevel The gas level.
 * @param currentSpeed The current speed vector.
 * @param end The end node.
 */
void initializeStartNode(GraphNode* start, int gasLevel, Vector2D currentSpeed, GraphNode* end);

/**
 * Calculates the acceleration vector based on the path, current position, current speed, and terrain map.
 *
 * @param path The path from the start node to the current node.
 * @param myPosition The current position vector.
 * @param mySpeed The current speed vector.
 * @param circuit The terrain map.
 * @return The acceleration vector.
 */
Vector2D getAcceleration(GraphList* path, Vector2D myPosition, Vector2D mySpeed, TerrainMap circuit);

/**
 * Checks if a node is reachable from a given position on the terrain map.
 *
 * @param newPos The new position vector.
 * @param circuit The terrain map.
 * @param currentPos The current position vector.
 * @return 1 if the node is reachable, 0 otherwise.
 */
int reachableNode(Vector2D newPos, TerrainMap circuit, Vector2D currentPos);

/**
 * Performs the A* algorithm to find the optimal path from the start node to the end node.
 *
 * @param start The start node.
 * @param end The end node.
 * @param circuit The terrain map.
 * @param secondPosition The position of the second vehicle.
 * @param thirdPosition The position of the third vehicle.
 * @param gasLevel The gas level.
 * @param currentSpeed The current speed vector.
 * @param speedMax The maximum speed.
 * @param occupied Flag indicating if the current node is occupied.
 * @return The optimal path from the start node to the end node.
 */
GraphList* aStar(GraphNode* start, GraphNode* end, TerrainMap circuit, Vector2D secondPosition, Vector2D thirdPosition, int gasLevel,
			Vector2D currentSpeed, int speedMax, int occupied);

/**
 * Checks if the pilot is ahead of the current vehicle.
 *
 * @param myPosition The current position vector.
 * @param secondPosition The position of the second vehicle.
 * @param thirdPosition The position of the third vehicle.
 * @param end The end node.
 * @return 1 if the pilot is ahead, 0 otherwise.
 */
int isPilotAhead(Vector2D myPosition, Vector2D secondPosition, Vector2D thirdPosition, GraphNode* end);

/**
 * Runs the A* algorithm and returns the optimal path from the start node to the end node.
 *
 * @param start The start node.
 * @param end The end node.
 * @param circuit The terrain map.
 * @param secondPosition The position of the second vehicle.
 * @param thirdPosition The position of the third vehicle.
 * @param gasLevel The gas level.
 * @param speed The current speed vector.
 * @param vitesse The speed.
 * @param flag The flag indicating if the current node is occupied.
 * @param path The current path.
 * @return The optimal path from the start node to the end node.
 */
GraphList* run_a_star(GraphNode* start, GraphNode* end, TerrainMap circuit, Vector2D secondPosition, Vector2D thirdPosition, int gasLevel, Vector2D speed, int vitesse, int flag, GraphList* path);

/**
 * Finds the optimal path from the start node to the destination node.
 *
 * @param endList The list of destination nodes.
 * @param start The start node.
 * @param circuit The terrain map.
 * @param secondPosition The position of the second vehicle.
 * @param thirdPosition The position of the third vehicle.
 * @param gasLevel The gas level.
 * @param speed The current speed vector.
 * @param flag The flag indicating if the current node is occupied.
 * @param path The current path.
 * @param end The destination node.
 * @return The optimal path from the start node to the destination node.
 */
GraphList* find_path(DestinationList endList, GraphNode* start, TerrainMap circuit, Vector2D secondPosition, Vector2D thirdPosition, int gasLevel, Vector2D speed, int flag, GraphList* path, GraphNode* end);

#endif // ASTAR_H

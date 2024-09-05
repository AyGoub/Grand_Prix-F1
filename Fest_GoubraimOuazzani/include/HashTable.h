#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "graph.h" 
#define HASH_CAPACITY 1000

/**
 * @struct HashNode
 * @brief Structure representing a node in the hash table.
 */
typedef struct HashNode {
    GraphNode* data;  
    struct HashNode* next;
} HashNode;

/**
 * @struct HashTable
 * @brief Structure representing a hash table.
 */
typedef struct {
    HashNode* array [HASH_CAPACITY];
} HashTable;

/**
 * @brief Hash function to calculate the index of a graph node in the hash table.
 * @param item The graph node to be hashed.
 * @param Terrain The terrain map.
 * @return The index of the graph node in the hash table.
 */
int hash(GraphNode* item, TerrainMap Terrain);

/**
 * @brief Creates a new hash table.
 * @return A pointer to the newly created hash table.
 */
HashTable* createHashTable();

/**
 * @brief Inserts a graph node into the hash table.
 * @param table The hash table.
 * @param item The graph node to be inserted.
 * @param Terrain The terrain map.
 */
void insertGraphNode(HashTable* table, GraphNode* item, TerrainMap Terrain);

/**
 * @brief Searches for a graph node in the hash table.
 * @param table The hash table.
 * @param item The graph node to search for.
 * @param Terrain The terrain map.
 * @return A pointer to the found graph node, or NULL if not found.
 */
GraphNode* searchGraphNode(HashTable* table, GraphNode* item, TerrainMap Terrain);

/**
 * @brief Removes a graph node from the hash table.
 * @param table The hash table.
 * @param item The graph node to be removed.
 * @param Terrain The terrain map.
 */
void removeGraphNode(HashTable* table, GraphNode* item, TerrainMap Terrain);

/**
 * @brief Destroys the hash table and frees the memory.
 * @param table The hash table to be destroyed.
 */
void destroyHashTable(HashTable* table);

/**
 * @brief Checks if a graph node is present in the hash table.
 * @param table The hash table.
 * @param item The graph node to check.
 * @param Terrain The terrain map.
 * @return 1 if the graph node is in the hash table, 0 otherwise.
 */
int isGraphNodeInHashTable(HashTable* table, GraphNode* item, TerrainMap Terrain);

#endif // HASH_TABLE_H

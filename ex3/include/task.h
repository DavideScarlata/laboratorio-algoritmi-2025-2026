#pragma once

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Structure representing a task for the scheduling simulation
 */
typedef struct {
  int id;       /**< Unique task identifier */
  int start;    /**< Arrival time */
  int length;   /**< Execution time */
  int priority; /**< Task priority (higher means more urgent) */
} Task;

/**
 * @brief Compare two tasks by priority
 *
 * @param a pointer to first Task
 * @param b pointer to second Task
 * @return >0 if a has higher priority than b,
 *         0 if equal priority,
 *         <0 otherwise
 */
int task_compare(const void *a, const void *b);

/**
 * @brief Hash function for Task objects
 *
 * @param t pointer to Task
 * @return hash value
 */
unsigned long task_hash(const void *t);

/**
 * @brief output dump all task from a given array of task
 *
 * @param tasks array of task
 * @param count number of task inside the given array
 */
void dump_tasks(Task **tasks, size_t count);
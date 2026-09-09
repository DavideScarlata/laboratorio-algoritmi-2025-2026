#pragma once

#include "task.h"

/**
 * @brief Reads tasks from a CSV file
 *
 * @param filename input CSV file
 * @param tasks outpuut array of Task pointers (allocated inside)
 * @param count output number of task
 * @return 0 on success, -1 on error
 */
int csv_read_tasks(const char *filename, Task ***tasks, size_t *count);

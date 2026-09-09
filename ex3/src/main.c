#include "../include/task.h"
#include "../include/priority_queue.h"
#include "../include/csv.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s 'input_csv' 'output_csv'\n", argv[0]);
        return -1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];

    Task **tasks = NULL;
    size_t task_count = 0;

    if (csv_read_tasks(input_file, &tasks, &task_count) != 0) {
        fprintf(stderr, "Error reading CSV file.\n");
        return -1;
    }

    //dump_tasks(tasks, task_count);
    
    PriorityQueue *pq = priority_queue_create(task_compare, task_hash);
    if (!pq) {
        fprintf(stderr, "PriorityQueue creation failed.\n");
        return -1;
    }

    size_t tasks_done = 0;
    size_t next_task_index = 0;
    int current_time = 0;
    FILE *fp = fopen(output_file, "w");
    if (!fp) {
        return -1;
    }

    while (tasks_done < task_count) {
        while (next_task_index < task_count && tasks[next_task_index]->start <= current_time) {
            priority_queue_push(pq, tasks[next_task_index]);
            next_task_index++;
        }

        if (priority_queue_size(pq) == 0) {
            if (next_task_index < task_count)
                current_time = tasks[next_task_index]->start;
            continue;
        }

        Task *t = priority_queue_top(pq);
        priority_queue_pop(pq);

        fprintf(fp, "%d,%d,%d\n", t->id, current_time, (current_time + t->length));

        current_time += t->length;
        tasks_done++;
    }

    fclose(fp);
    priority_queue_free(pq);
    for (size_t i = 0; i < task_count; i++) {
        free(tasks[i]);
    }
    free(tasks);

    return 0;
}
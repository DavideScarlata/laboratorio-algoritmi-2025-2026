#include "../include/task.h"

int task_compare(const void *a, const void *b) {
    if (!a || !b) {
        return 0;
    }

    const Task *ta = (const Task *)a;
    const Task *tb = (const Task *)b;

    if (ta->priority != tb->priority) {
        return (ta->priority > tb->priority) - (ta->priority < tb->priority);
    }
    return (tb > ta) - (tb < ta);
}

unsigned long task_hash(const void *t) {
    if (!t) return 0;

    const Task *task = (const Task *)t;
    return (unsigned long)(task->id);
}

void dump_tasks(Task **tasks, size_t count) {
    if (!tasks) {
        printf("Error, given a NULL tasks\n");
        return;
    }

    printf("Dumping %zu tasks:\n", count);
    for (size_t i = 0; i < count; i++) {
        if (tasks[i]) {
            printf("Task[%zu]: ID=%d, Start=%d, Length=%d, Priority=%d\n",
                   i,
                   tasks[i]->id,
                   tasks[i]->start,
                   tasks[i]->length,
                   tasks[i]->priority);
        } else {
            printf("Task[%zu]: NULL\n", i);
        }
    }
    printf("End of dump.\n");
}
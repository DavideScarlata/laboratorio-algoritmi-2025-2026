#include "../include/priority_queue.h"
#include "../include/task.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Task *make_task(int id, int start, int length, int priority) {
    Task *t = malloc(sizeof(Task));
    t->id = id;
    t->start = start;
    t->length = length;
    t->priority = priority;
    return t;
}

void test_push_pop_top() {
    printf("Esecuzione test_push_pop_top...\n");

    PriorityQueue *pq = priority_queue_create(task_compare, task_hash);
    assert(pq != NULL);
    assert(priority_queue_size(pq) == 0);

    Task *t1 = make_task(1, 0, 10, 50);
    Task *t2 = make_task(2, 0, 10, 100);
    Task *t3 = make_task(3, 0, 10, 75);

    priority_queue_push(pq, t1);
    priority_queue_push(pq, t2);
    priority_queue_push(pq, t3);

    assert(priority_queue_size(pq) == 3);
    assert(priority_queue_top(pq) == t2);
    priority_queue_pop(pq);
    assert(priority_queue_top(pq) == t3);

    priority_queue_free(pq);
    free(t1); free(t2); free(t3);

    printf("test_push_pop_top passato.\n");
}

void test_contains_and_remove() {
    printf("Esecuzione test_contains_and_remove...\n");

    PriorityQueue *pq = priority_queue_create(task_compare, task_hash);

    Task *t1 = make_task(1, 0, 10, 50);
    Task *t2 = make_task(2, 0, 10, 100);

    priority_queue_push(pq, t1);
    priority_queue_push(pq, t2);

    assert(priority_queue_contains(pq, t1) == 1);
    assert(priority_queue_contains(pq, t2) == 1);

    priority_queue_remove(pq, t2);
    assert(priority_queue_contains(pq, t2) == 0);
    assert(priority_queue_size(pq) == 1);

    priority_queue_free(pq);
    free(t1); free(t2);

    printf("test_contains_and_remove passato.\n");
}

void test_large_heap() {
    printf("Esecuzione test_large_heap...\n");

    PriorityQueue *pq = priority_queue_create(task_compare, task_hash);
    const int N = 1000;
    Task *tasks[N];

    for (int i = 0; i < N; i++) {
        tasks[i] = make_task(i, i, 1, rand() % 1000);
        priority_queue_push(pq, tasks[i]);
    }

    int last_priority = 1001;
    while (priority_queue_size(pq) > 0) {
        Task *t = priority_queue_top(pq);
        priority_queue_pop(pq);
        assert(t->priority <= last_priority);
        last_priority = t->priority;
    }

    for (int i = 0; i < N; i++) free(tasks[i]);
    priority_queue_free(pq);

    printf("test_large_heap ok.\n");
}

int main() {
    test_push_pop_top();
    test_contains_and_remove();
    test_large_heap();

    printf("\nTest finiti\n");
    return 0;
}
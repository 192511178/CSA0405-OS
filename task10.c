
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <time.h>

#define COUNT 1000

static double seconds(struct timespec a, struct timespec b)
{
    return (b.tv_sec - a.tv_sec) +
           (b.tv_nsec - a.tv_nsec) / 1e9;
}

static void *thread_fn(void *arg)
{
    (void)arg;
    return NULL;
}

int main(void)
{
    struct timespec start, end;
    pid_t pids[COUNT];

    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < COUNT; i++) {
        pids[i] = fork();

        if (pids[i] < 0) {
            perror("fork");
            return 1;
        }

        if (pids[i] == 0)
            _exit(0);
    }

    for (int i = 0; i < COUNT; i++)
        waitpid(pids[i], NULL, 0);

    clock_gettime(CLOCK_MONOTONIC, &end);

    printf("1000 processes: %.6f seconds\n",
           seconds(start, end));

    pthread_t threads[COUNT];

    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < COUNT; i++) {
        int rc = pthread_create(
            &threads[i], NULL, thread_fn, NULL);

        if (rc != 0) {
            fprintf(stderr,
                    "pthread_create failed: %d\n", rc);
            return 1;
        }
    }

    for (int i = 0; i < COUNT; i++)
        pthread_join(threads[i], NULL);

    clock_gettime(CLOCK_MONOTONIC, &end);

    printf("1000 threads: %.6f seconds\n",
           seconds(start, end));

    return 0;
}


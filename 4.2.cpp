#include <stdio.h>
#include <stdlib.h>

struct Job {
    char id;
    int deadline;
    int profit;
};

int compare(const void* a, const void* b) {
    return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}

int findMaxDeadline(struct Job jobs[], int n) {
    int max_deadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > max_deadline)
            max_deadline = jobs[i].deadline;
    }
    return max_deadline;
}

void jobSequencing(struct Job jobs[], int n) {
    qsort(jobs, n, sizeof(struct Job), compare);
    int max_deadline = findMaxDeadline(jobs, n);
    char result[max_deadline];
    for (int i = 0; i < max_deadline; i++)
        result[i] = ' ';
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (result[j] == ' ') {
                result[j] = jobs[i].id;
                break;
            }
        }
    }
    printf("Scheduled jobs: ");
    for (int i = 0; i < max_deadline; i++) {
        if (result[i] != ' ')
            printf("%c ", result[i]);
    }
}

int main() {
    struct Job jobs[] = { {'1', 3, 2}, {'2', 3, 4}, {'3', 3, 3}, {'4', 4, 1}, {'5', 4, 10} };
    int n = sizeof(jobs) / sizeof(jobs[0]);
    jobSequencing(jobs, n);
    return 0;
}
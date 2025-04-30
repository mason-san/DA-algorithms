#include <stdio.h>

#define MAX 100

typedef struct {
    int profit, weight, index;
    float ratio;
} Item;

typedef struct {
    int level, profit, weight;
    float bound;
    int taken[MAX];  // solution vector
} Node;

int n, capacity;
Item items[MAX];

// Swap function for sorting
void swap(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

// Sort items by decreasing ratio using simple bubble sort
void sortItems() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

// Calculate bound (upper estimate of max profit from this node)
float getBound(Node u) {
    if (u.weight >= capacity) return 0;

    float bound = u.profit;
    int totalWeight = u.weight;
    int i = u.level + 1;

    while (i < n && totalWeight + items[i].weight <= capacity) {
        totalWeight += items[i].weight;
        bound += items[i].profit;
        i++;
    }

    if (i < n) {
        int remaining = capacity - totalWeight;
        bound += remaining * items[i].ratio;
    }

    return bound;
}

int knapsack() {
    Node queue[1000];
    int front = 0, rear = 0;
    Node u, v;
    int maxProfit = 0;
    int bestTaken[MAX] = {0};

    // Start with dummy node
    v.level = -1;
    v.profit = 0;
    v.weight = 0;
    for (int i = 0; i < n; i++) v.taken[i] = 0;
    v.bound = getBound(v);
    queue[rear++] = v;

    while (front < rear) {
        v = queue[front++];

        if (v.bound <= maxProfit || v.level == n - 1)
            continue;

        u.level = v.level + 1;

        // Case 1: Include item
        u.weight = v.weight + items[u.level].weight;
        u.profit = v.profit + items[u.level].profit;
        for (int i = 0; i < n; i++) u.taken[i] = v.taken[i];
        u.taken[u.level] = 1;

        if (u.weight <= capacity && u.profit > maxProfit) {
            maxProfit = u.profit;
            for (int i = 0; i < n; i++) bestTaken[i] = u.taken[i];
        }

        u.bound = getBound(u);
        if (u.bound > maxProfit) {
            queue[rear++] = u;
        }

        // Case 2: Exclude item
        u.weight = v.weight;
        u.profit = v.profit;
        for (int i = 0; i < n; i++) u.taken[i] = v.taken[i];
        u.taken[u.level] = 0;

        u.bound = getBound(u);
        if (u.bound > maxProfit) {
            queue[rear++] = u;
        }
    }

    // Print solution vector
    printf("Items taken (0 or 1): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", bestTaken[i]);
    }
    printf("\n");

    return maxProfit;
}

int main() {
    // Example input
    n = 4;
    capacity = 10;

    items[0].profit = 40; items[0].weight = 4;
    items[1].profit = 42; items[1].weight = 7;
    items[2].profit = 25; items[2].weight = 5;
    items[3].profit = 12; items[3].weight = 3;

    for (int i = 0; i < n; i++) {
        items[i].index = i;
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    sortItems();

    int result = knapsack();
    printf("Maximum Profit: %d\n", result);

    return 0;
}

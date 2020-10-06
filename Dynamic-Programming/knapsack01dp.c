//Knapsack 0/1 algorithm of this code takes θ(nw) times
//table c has (n + 1).(w + 1) entries, where each entry requires θ(1)  time to compute.
//where n is the number of item and w is the weight

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void knapsack01(int v[], int wt[], int n, int M) {
    int c[MAX][MAX],w,i;
    int keep[MAX][MAX];
    for (w = 0; w <= M; w++) {
        c[0][w] = 0;
    }
    for (i = 0; i <= n; i++) {
        c[i][0] = 0;
    }
    for (i = 1; i <= n; i++) {
        for (w = 1; w <= M; w++) {
            if (wt[i] <= w && (v[i] + c[i-1][w-wt[i]] > c[i-1][w])) {
                c[i][w] = v[i] + c[i-1][w-wt[i]];
                keep[i][w] = 1;
            }
            else {
                c[i][w] = c[i-1][w];
                keep[i][w] = 0;
            }
        }
    }
    printf("\n\n Maximum Profit = %d",c[n][M]);
}

int main() {
    int n,i;
    int weight[MAX], value[MAX];
    int M = 0;
    printf("Enter the number of items: \n");
    scanf("%d",&n);
    for (i = 1; i <= n; i++) {
        printf("Item [%d] Weight and Value: ",i);
        scanf("%d %d",&weight[i],&value[i]);
    }
    printf("\nEnter the capacity of the bag: ");
    scanf("%d",&M);
    knapsack01(value,weight,n,M);
    return 0;
}

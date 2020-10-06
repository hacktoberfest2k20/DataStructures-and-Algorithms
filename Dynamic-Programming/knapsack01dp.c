#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
void knapsack01(int v[], int wt[], int n, int M) {
    int c[100][100],w,i;
    int keep[100][100];
    for (w = 0; w <= M; w++) {
        c[0][w] = 0;
    }
    for (i = 0; i <= n; i++) {
        c[i][0] = 0;
    }
    for (i = 1; i <= n; i++) {
        //int w = wt[i];
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

void main() {
    int n,i;
    int weight[n], value[n];
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
    getch();
}

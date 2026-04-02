int n = 4;
int dist[10][10] = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
int memo[1 << 10][10];

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) return dist[pos][0];
    if (memo[mask][pos] != -1) return memo[mask][pos];
    int ans = 1e9;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0)
            ans = min(ans, dist[pos][city] + tsp(mask | (1 << city), city));
    }
    return memo[mask][pos] = ans;
}
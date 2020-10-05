//THIS ALGORITHM IS KNOWN AS LEE'S ALGORITHM
// TIME COMPEXITY-Since it is an MxN grid
// the time complexity is O(MN)


#include <iostream>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;


#define M 10
#define N 10


struct Node
{
	int x, y, dist;
};


int row[] = { -1, 0, 0, 1 };
int col[] = { 0, -1, 1, 0 };

bool isValid(int mat[][N], bool visited[][N], int row, int col)
{
	return (row >= 0) && (row < M) && (col >= 0) && (col < N)
		&& mat[row][col] && !visited[row][col];
}


void BFS(int mat[][N], int i, int j, int x, int y)// BFS algorithm
{
	
	bool visited[M][N]
	memset(visited, false, sizeof visited);
	queue<Node> q;

	visited[i][j] = true;
	q.push({i, j, 0});
	
	int min_dist = INT_MAX;

	
	while (!q.empty())
	{
		
		Node node = q.front();
		q.pop();
	
		int i = node.x, j = node.y, dist = node.dist;
		if (i == x && j == y)
		{
			min_dist = dist;
			break;
		}
		for (int k = 0; k < 4; k++)
		{
			if (isValid(mat, visited, i + row[k], j + col[k]))
			{
				
				visited[i + row[k]][j + col[k]] = true;
				q.push({ i + row[k], j + col[k], dist + 1 });
			}
		}
	}

	if (min_dist != INT_MAX)
		cout << "The shortest path from source to destination "
				"has length " << min_dist;
	else
		cout << "Destination can't be reached from given source";
}

int main()
{
	// input maze
	int mat[M][N] =
	{
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
		{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },
	};

	// Find shortest path from source (0, 0) to
	// destination (7, 5)
	BFS(mat, 0, 0, 7, 5);

	return 0;
}

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define vi vector<int>
#define ll long long
#define umi unordered_map<int,int>
#define ums unordered_map<char,int>

void prims(vector<pair<int, int> > adj[], int n) {
	vector<int> parent(n, -1);
	vector<bool> mst(n, false);
	vector<int> dist(n, INT_MAX);

	dist[0] = 0;

// TC => O(NlogN)
	// priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > pq;

	// pq.push({0, 0});

	// while (!pq.empty())
	// {
	// 	int u = pq.top().second;
	// 	pq.pop();

	// 	mst[u] = true;

	// 	for (auto it : adj[u]) {
	// 		int v = it.first;
	// 		int weight = it.second;
	// 		if (mst[v] == false && weight < dist[v]) {
	// 			parent[v] = u;
	// 			dist[v] = weight;
	// 			pq.push({dist[v], v});
	// 		}
	// 	}

	// }

// TC => O(N^2)
	// for (int i = 0; i < n; i++) {

	// 	int mini = INT_MAX, u;

	// 	for (int j = 0; j < n; j++) {
	// 		if (!mst[j] && dist[j] < mini)
	// 			mini = dist[j], u = j;
	// 	}
	// 	mst[u] = true;

	// 	for (auto x : adj[u]) {
	// 		if (!mst[x.first] && dist[x.first] > x.second)
	// 			parent[x.first] = u, dist[x.first] = x.second;
	// 	}


	for (int i = 1; i < n; i++)
		cout << parent[i] << " - " << i << " \n";

}



// Driver Code
int main()
{
	int N = 5, m = 6;
	vector<pair<int, int> > adj[N];


	adj[0].push_back({1, 2});
	adj[0].push_back({3, 6});
	adj[1].push_back({0, 2});
	adj[1].push_back({2, 3});
	adj[1].push_back({3, 8});
	adj[1].push_back({4, 5});
	adj[2].push_back({1, 3});
	adj[2].push_back({4, 7});
	adj[3].push_back({0, 6});
	adj[3].push_back({1, 8});
	adj[4].push_back({1, 5});
	adj[4].push_back({2, 7});

	prims(adj, N);

	// for (int i = 1; i <= N; i++) {
	// 	cout << dist[i] << " ";
	// }
}
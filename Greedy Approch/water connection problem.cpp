// https://www.geeksforgeeks.org/water-connection-problem/


#include <bits/stdc++.h>
using namespace std;

int n, p;   //n = number of houses and p = number of pipes

int ending[1100];   // Array rd stores the ending vertex of pipe
int weight[1100];   // Array wd stores the value of diameters between two pipes
int starting[1100]; // Array cd stores the starting end of pipe

vector<int> a;      // Vector a, b, c are used to store the final output
vector<int> b;
vector<int> c;
int ans;

int dfs(int w){
	if (starting[w] == 0)
		return w;
	if (weight[w] < ans)
		ans = weight[w];
	return dfs(starting[w]);
}

void solve(int arr[][3]){
	int i = 0;
	while (i < p) {
		int q = arr[i][0], h = arr[i][1],t = arr[i][2];

		starting[q] = h;
		weight[q] = t;
		ending[h] = q;
		i++;
	}
	a.clear();
	b.clear();
	c.clear();
	for (int j = 1; j <= n; ++j)
		/*If a pipe has no ending vertex but has starting vertex i.e is an outgoing pipe then we need to start DFS with this vertex.*/
		if (ending[j] == 0 && starting[j]) {
			ans = 1000000000;
			int w = dfs(j);
			// We put the details of component in final output array
			a.push_back(j);
			b.push_back(w);
			c.push_back(ans);
		}
	cout << a.size() << endl;
	for (int j = 0; j < a.size(); ++j)
		cout << a[j] << " " << b[j] << " " << c[j] << endl;
}

int main(){
	n = 9, p = 6;
	memset(ending, 0, sizeof(ending));
	memset(starting, 0, sizeof(starting));
	memset(weight, 0, sizeof(weight));

	int arr[][3] = { { 7, 4, 98 },
					{ 5, 9, 72 },
					{ 4, 6, 10 },
					{ 2, 8, 22 },
					{ 9, 7, 17 },
					{ 3, 1, 66 } };
	solve(arr);
	return 0;
}

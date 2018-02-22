#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
	int x;
	int y;
	int weight;
};

int find_shortest_path(vector<Edge>H, Edge e, int v_num){
	int d[v_num+1];

	for (int i = 1; i <= v_num; i++){
		d[i] = 147473647;
	}
	d[e.x] = 0;

	for (int i = 1; i < v_num; i++){
		for (int j = 0; j < H.size(); j++){
			int u = H[j].x, v = H[j].y;
			//cout << "V: " << d[v] << " U: " << d[u] << endl;
 			if (d[v] > d[u] + H[j].weight){
				d[v] = d[u] + H[j].weight;
				//cout << "test1: " << d[v] << " "<< d[u] << " " << H[j].weight << endl;
			}
			
			if (d[u] > d[v] + H[j].weight){
				d[u] = d[v] + H[j].weight;
				//cout << "test2: " << d[u] << " " << d[v] << " " << H[j].weight << endl;
			}
		}
	}

	//cout << "test: " <<  d[e.y] << " " << e.x << " " << e.y << endl;
	return d[e.y];
}

bool compareByWeight(const Edge &a, const Edge &b){
    return a.weight < b.weight;
}

bool compareByVertex(const Edge &a, const Edge &b){
		if (a.x == b.x)
			return a.y < b.y;
    return a.x < b.x;
}


int main(){
	int num_v, num_e;
	double t;
	vector<Edge>l;

	cin >> num_v >> num_e >> t;
	
	while (true){
		int x,y,z;
		cin >> x >> y >> z;

		if (cin.eof())
			break;

		Edge e = {0, 0, z};
		e.x = min(x, y);
		e.y = max(x, y);
		l.push_back(e);
	}

	sort(l.begin(), l.end(), compareByWeight);

	int sum;
	vector<Edge>H;
	for (int i = 0; i < l.size(); i++){
		Edge e = l[i];
		int d = find_shortest_path(H, e, num_v);
		if (t * e.weight < d){
			H.push_back(e);
			sum += e.weight;
		}
	}

	sort(H.begin(), H.end(), compareByVertex);
	cout << H.size() << endl;
	cout << sum << endl;
	for (int i = 0; i < H.size(); i++){
		cout << H[i].x << " " << H[i].y << endl;
	}
	return 0;
}
#include<iostream>
#include<string>
using namespace std;
const int MAXSIZE = 10;
template<class T>
class MGraph {
public:
	MGraph(T a[], int n, int e);
	void dfs(int v);
	void print();
private:
	bool visited[MAXSIZE] = { false };
	T vertex[MAXSIZE];
	int arc[MAXSIZE][MAXSIZE];
	int vnum, arcnum;
};
template<class T>
MGraph<T>::MGraph(T a[], int n, int e) {
	int i, j, k;
	vnum = n;
	arcnum = e;
	for (k = 0; k < n; k++) {
		vertex[k] = a[k];
	}
	memset(arc, 0, sizeof(arc));
	for (k = 0; k < e; k++) {
		cin >> i >> j;
		arc[i][j] = 1;
		arc[j][i] = arc[i][j];
	}
}
template<class T>
void MGraph<T>::dfs(int v){
	cout << vertex[v] << endl;
	visited[v] = true;
	for (int j = 0; j < vnum; j++) {
		if (arc[v][j] == 1 && !visited[j])
			dfs(j);
	}
}
template<class T>
void MGraph<T>::print(){
	for (int i = 0; i < vnum; i++) {
		 for (int j = 0; j < vnum; j++) {
			 cout << arc[i][j] << ' ';
		 }
		 cout << endl;
}
}
int main() {
	string a[6] = { "v1","v2","v3","v4","v5","v6" };
	MGraph<string> A(a, 6, 6);
	A.print();
	A.dfs(0);
}
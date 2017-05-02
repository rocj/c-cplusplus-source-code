#include <iostream>
using namespace std;

class MatrixChain {
public:
	MatrixChain() {
		int i;
		cin >> n;
		p = new int [n+1];
		for(i=0; i<=n; i++) {
			cin >> p[i];
		}
		m = new int * [n];
		for(i=0; i<n; i++)
			m[i] = new int [n];
		s = new int * [n];
		for(i=0; i<n; i++)
			s[i] = new int [n];
	}
	int MChain();
	//int LookupChain();
	//void Traceback();
private:
	int *p, **m, **s, n;
	//int LookupChain(int i, int j);
	//void Traceback(int i, int j);
};

int MatrixChain::MChain() {
	int i, j, r, k, t;
	for(i=0; i<n; i++) {
		m[i][i]=0;
	}
	for(r=2; r<=n; r++) {
		for(i=0; i<=n-r; i++) {
			j=i+r-1;
			m[i][j]=m[i+1][j]+p[i]*p[i+1]*p[j+1];
			s[i][j]=i;
			for(k=i+1; k<j; k++) {
				t=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
				if(t < m[i][j]) {
					m[i][j]=t;
					s[i][j]=k;
				}
			}
		}
	}
	return m[0][n-1];
}

int main() {
	MatrixChain mc;
	cout << mc.MChain();
	return 0;
}
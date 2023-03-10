#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_COUNT 10000000
#define MAX_LOG
#define MAX_RADIX

int aux[100000005], vmerge[100000005];

void merge_2(int v[], int n, int st, int dr) {

	if (st < dr) {
		int mid = (st + dr) / 2;
		merge_2(v,n, st, mid);
		merge_2(v,n, mid + 1, dr);

		int pi = st, pj = mid + 1, pk = 0;
		while (pi <= mid && pj <= dr) {
			if (v[pi - st] <= v[pj - mid - 1]) {
				vmerge[pk++] = v[pi - st];
				pi++;
			}
			else {
				vmerge[pk++] = v[pj - mid - 1];
				pj++;
			}
		}
		while (pi <= mid) {
			vmerge[pk++] = v[pi - st];
			pi++;
		}
		while (pj <= dr) {
			vmerge[pk++] = v[pj - mid - 1];
			pj++;
		}

		for (int i = st; i <= dr; i++) v[i] = vmerge[i];

	}
}

void stl_sort(int v[], int n) {

	sort(v, v + n);
}

void count_sort(int v[], int n) {
	int maxv = v[0];

	for (int i = 0; i < n; i++) {
		aux[v[i]]++;
		maxv = max(maxv, v[i]);
	}
	//for (int i = 0; i < 20; i++) cout << count[i] << ' ';
	int pi = 0;
	for (int i = 0; i <= maxv; i++) {
		while (aux[i]) {
			v[pi++] = i;
			aux[i]--;
		}
	}
}

void insert_sort(int v[], int n) {

	//int* ans = new int[20];

	//for (int i = 0; i < n; i++) ans[i] = v[i];
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		int val = v[i];
		while (j >= 0 && v[j] > val) {
			v[j + 1] = v[j];
			j -= 1;
		}
		v[j + 1] = val;
	}
}

void shell_sort(int v[], int n) {

	for (int salt = n / 2; salt > 0; salt /= 2) {
		for (int i = salt; i < n; i++) {
			int j = i - salt;
			int val = v[i];
			while (j >= 0 && v[j] > val) {
				v[j + salt] = v[j];
				j -= salt;
			}
			v[j + salt] = val;
		}
	}
}

int part(int v[], int st, int dr) {
	int piv = v[dr];
	int pi = (st-1);

	for (int pj = st; pj <= dr - 1; pj++) {
		if (v[pj] < piv) {
			pi++;
			swap(v[pi],v[pj]);
		}
	}
	swap(v[pi + 1], v[dr]);
	return (pi + 1);
}

void quick_sort(int v[], int st, int dr) {

	if (st < dr) {

		int pi = part(v,st,dr);

		//cout << "indexul pl este " << pl << endl;
		quick_sort(v,st,pi - 1);
		quick_sort(v,pi + 1,dr);
	}
}


void count_10(int v[], int n, int exp) {

	int count[10];
	memset(count, 0, sizeof(count));

	for (int i = 0; i < n; i++) {
		count[(v[i] / exp) % 10]++;
	}

	for (int i = 1; i < 10; i++) count[i] += count[i - 1];

	for (int i = n - 1; i >= 0; i--) {
		aux[count[(v[i] / exp) % 10] - 1] = v[i];
		count[(v[i] / exp) % 10]--;
	}

	for (int i = 0; i < n; i++)
		v[i] = aux[i];

}

void count_2(int v[], int n, int exp) {

	int count[2];
	memset(count, 0, sizeof(count));

	for (int i = 0; i < n; i++) {
		count[((v[i] >> exp) & 1)]++;
	}

	count[1] += count[0];

	for (int i = n - 1; i >= 0; i--) {
		aux[count[((v[i] >> exp) & 1)] - 1] = v[i];
		count[((v[i] >> exp) & 1)]--;
	}

	for (int i = 0; i < n; i++)
		v[i] = aux[i];

}

int* radix_sort(int v[], int n, int multip) {
	int maxnum = v[0];
	for (int i = 1; i < n; i++) {
		maxnum = max(maxnum, v[i]);
	}

	/*for (int exp = 1; maxnum / exp > 0; exp *= 10) {
		count_10(v,n,exp);
	}*/

	for (int exp = 0; (maxnum >> exp) > 0; exp++) {
		count_2(v,n,exp);
	}

	return v;
}


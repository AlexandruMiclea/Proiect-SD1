#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_COUNT 100000


int* merge_2(int v[], int st, int dr) {

	if (st < dr) {
		int mid = (st + dr) / 2;
		int* left = new int[20]; //todo modify
		int* right = new int[20]; //todo modify
		int * merge = new int[20]; //todo modify
		left = merge_2(v, st, mid);
		right = merge_2(v, mid + 1, dr);

		int pi = st, pj = mid + 1, pk = 0;
		while (pi <= mid && pj <= dr) {
			if (left[pi - st] <= right[pj - mid - 1]) {
				merge[pk++] = left[pi - st];
				pi++;
			}
			else {
				merge[pk++] = right[pj - mid - 1];
				pj++;
			}
		}
		while (pi <= mid) {
			merge[pk++] = left[pi - st];
			pi++;
		}
		while (pj <= dr) {
			merge[pk++] = right[pj - mid - 1];
			pj++;
		}

		return merge;
	}
	else {
		return &v[st];
	}

	cout << "OPA OPA";
	return NULL;
}

int* stl_sort(int v[], int n) {

	sort(v, v + n);

	return v;
}

int* count_sort(int v[], int n) {
	int count[MAX_COUNT];
	memset(count, 0,sizeof(count));

	for (int i = 0; i < n; i++) {
		count[v[i]]++;
	}
	//for (int i = 0; i < 20; i++) cout << count[i] << ' ';
	int pi = 0;
	for (int i = 0; i < 20; i++) {
		while (count[i]) {
			v[pi++] = i;
			count[i]--;
		}
	}
	//for (int i = 0; i < 20; i++) cout << ans[i] << ' ';
	return v;
}

int* insert_sort(int v[], int n) {

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
	return v;
}

int* shell_sort(int v[], int n) {

	for (int salt = n / 2; salt > 1; salt /= 2) {
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

	return v;
}

int* quick_sort(int v[], int n) {

}
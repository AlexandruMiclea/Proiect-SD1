#include <iostream>
#include "Sortari.h"

using namespace std;

int main() {

    int v[] = {1, 4, 10, 7, 12, 3, 2, 9, 13,11,14,6,5,8};
    // 2 3 4 5 7 10 11 23 31 45 665 6543 7653 76756
    int n = 14;
    //int* ans = merge_2(v, 0, n - 1);
    //int* ans2 = stl_sort(v, n);
    //int* ans3 = count_sort(v, n);
    //int* ans4 = insert_sort(v, n);
    //int* ans5 = shell_sort(v, n);
    quick_sort(v, 0, n - 1);
    /*for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
       cout << ans2[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i++){
        cout << ans3[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans4[i] << ' '; 
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans5[i] << ' '; 
    }
    cout << '\n';*/
    for (int i = 0; i < n; i++) {
        cout << v[i] << ' ';
    }
    return 0;
}
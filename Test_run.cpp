#include <iostream>
#include "Sortari.h"

using namespace std;

int main() {

    int v[] = {4,2,3,7,5,10,31,11,23,45,665,6543,76756,7653};
    // 2 3 4 5 7 10 11 23 31 45 665 6543 7653 76756
    int n = 14;
    int* ans = merge_2(v, 0, n - 1);
    int* ans2 = stl_sort(v, n);
    int* ans3 = count_sort(v, n);
    int* ans4 = insert_sort(v, n);
    int* ans5 = shell_sort(v, n);
    for (int i = 0; i < n; i++) {
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
    return 0;
}
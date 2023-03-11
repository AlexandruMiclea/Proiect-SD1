#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "Sortari.h"

using namespace std;
#pragma warning (disable : 4996)

int v[100000005];
int auxx[100000005];

int main() {

    for (int i = 1; i <= 64; i++) {
        //if (i % 8 > 5 || i % 8 == 0) continue;
        //if (i % 8 == 7 || i % 8 == 0) continue;
        //if (i % 8 != 7 && i % 8 != 0) continue;
        ifstream fin;
        ofstream fout;
        char* fp = new char[strlen("Teste/test1.in") + 1];
        char* fp2 = new char[strlen("Rezul/test1.out") + 1];
        if (i < 10) {
            fp = new char[strlen("Teste/test1.in") + 1];
            fp2 = new char[strlen("Rezul/test1.out") + 1];
            strcpy(fp, "Teste/test1.in");
            strcpy(fp2, "Rezul/test1.out");
            fp[10] = i + '0';
            fp2[10] = i + '0';
        }
        else {
            fp = new char[strlen("Teste/test10.in") + 1];
            fp2 = new char[strlen("Rezul/test10.out") + 1];
            strcpy(fp, "Teste/test10.in");
            strcpy(fp2, "Rezul/test10.out");
            fp[10] = (i/10) + '0';
            fp2[10] = (i/10) + '0';
            fp[11] = (i%10) + '0';
            fp2[11] = (i%10) + '0';
        }
        //cout << fp << endl;
        fin.open(fp);
        fout.open(fp2, std::ios_base::app);
        int n;
        fin >> n;
        cout << i << endl;

        for (int j = 0; j < n; j++) {
            fin >> v[j];
        }

        auto t_start = std::chrono::high_resolution_clock::now();

        //merge_2(v,n, 0, n - 1); DONE pro
        //stl_sort(v, n); DONE *
        //count_sort(v, n); DONE 
        insert_sort(v, n); 
        //shell_sort(v, n); DONE pro
        //quick_sort(v, 0, n - 1, n); DONE
        //radix_sort(v, n, 16, i); DONE pro 

        auto t_end = std::chrono::high_resolution_clock::now();

        double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();


        fout << "Timp necesar pentru sortare la testul " << i << ": " << elapsed_time_ms << " folosind insertSort" << endl;

        /*for (int j = 0; j < n; j++) {
            cout << v[j] << ' ';
        }*/

        //for (int j = 0; j < n; j++) cout << v[j] << ' ';

        for (int k = 0; k < n - 1; k++) {
            if (v[k] > v[k + 1]) {
                cout << "SORTAREA NU A FOST BUNA!";
                return 1;
            }
        }

        fin.close();
        fout.close();
    }

    
    
   /* for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            cout << "SORTAREA NU A FOST BUNA!";
            return 1;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }*/

    return 0;
}
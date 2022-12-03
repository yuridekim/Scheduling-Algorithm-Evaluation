#include <bits/stdc++.h>
using namespace std;
 
void towerOfHanoi(int n, char from_rod, char to_rod,
                  char aux_rod)
{
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}
 
// Driver code
int main(void)
{
    int N =5;
    towerOfHanoi(N, 'A', 'C', 'B');
    return 0;
}
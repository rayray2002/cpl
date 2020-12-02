//PREPEND BEGIN
#include <iostream>

using namespace std;
int main(){

    int N, K;
    int *num, *ans;

    cin >> N >> K;
//PREPEND END

//TEMPLATE BEGIN
    // TODOs

    // 1\. Allocate memory with correct size to num & ans.
    num = new int[N];
    ans = new int[K];

    // 2\. cin N values to num.
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    // 3\. Sort num.
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N-1; i++) {
            if (num[i+1] > num[i]) {
                int temp = num[i+1];
                num[i+1] = num[i];
                num[i] = temp;
            }
        }
    }
    // 4\. Assign K largest value in num to ans.
    for (int i = 0; i < K; i++) {
        ans[i] = num[i];
    }
    // 5\. Free num.
    delete num;
//TEMPLATE END

//APPEND BEGIN
    for (int i = 0; i < K; ++i)
        cout << ans[i] << ' ';
    cout << endl;

    delete [] ans;

    return 0;
}
//APPEND END



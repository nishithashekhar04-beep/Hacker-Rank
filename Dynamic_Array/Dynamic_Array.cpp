#include <iostream>
#include <vector>
using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector<vector<int>> arr(n);
    vector<int> result;
    int lastAnswer = 0;

    for (auto q : queries) {
        int type = q[0];
        int x = q[1];
        int y = q[2];

        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            arr[idx].push_back(y);
        }
        else if (type == 2) {
            int pos = y % arr[idx].size();
            lastAnswer = arr[idx][pos];
            result.push_back(lastAnswer);
        }
    }

    return result;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> queries(q, vector<int>(3));

    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    vector<int> ans = dynamicArray(n, queries);

    for (int x : ans) {
        cout << x << endl;
    }

    return 0;
}

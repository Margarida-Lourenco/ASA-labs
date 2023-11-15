#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int N,M;
    char coma;
    cin >> N >> coma >> M;

    // vector that stores the number of friends of each person
    vector<int>friendships(N+1,0);

    // vector that stores the number of people that have a certain number of friends
    vector<int>friendCount(M+1,0);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        friendships[u]++; // increments the number of friends of u  
    }

    for(int i = 0; i <= M; i++){
        for(int j = 0; j <= N; j++)
            if(friendships[i] == j)
                friendCount[j]++;
    }

    int maxFriends = *max_element(friendships.begin(), friendships.end());

    cout << "Histograma 1" << endl;
    for (int i = 0; i < N; ++i) {
        cout << friendCount[i] << endl;
    }

    cout << "Histograma 2" << endl;
    for (int i = 0; i <= maxFriends; ++i) {
        cout << count(friendships.begin(), friendships.end(), i) << endl;
    }

    return 0;
}

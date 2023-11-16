#include <iostream>
#include <vector>
#include <list>

void printHistograms(const std::list<int>* list, const char* title, int V) {
    std::vector<int> hist(V, 0);

    for (int i = 1; i <= V; i++) {
        hist[list[i].size()]++;
    }
    
    std::cout << title << "\n";
    for (int i = 0; i < V; ++i) {
        std::cout << hist[i] << "\n";
    }

}

int main() {
    int V, E;
    char c;
    int totalFriends = 0;
    int totalPairs = 0;

    //reads paragraph
    std::cin >> V; std::cin >> c; std ::cin >> E;
    std::list<int> *FWAdjList = new std::list<int>[V+1];
    std::list<int> *RevAdjList = new std::list<int>[V+1];
    
    for (int i = 0; i < E; i++) {
        int u, v;
        std::cin >> u; std::cin >> v;
        FWAdjList[u].push_front(v);
        RevAdjList[v].push_front(u);
    }

    std::vector<int> hist;
    hist.resize(V);

    //Prints histograms
    printHistograms(FWAdjList, "Histograma 1", V);
    printHistograms(RevAdjList, "Histograma 2", V);

    //Prints matrix
    std::cout << "Matriz" << "\n";
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            int friends = 0;
            for (std::list<int>::iterator it_i = FWAdjList[i].begin();
                    it_i != FWAdjList[i].end(); it_i++) {
                for (int t: FWAdjList[j]) {
                    if ((*it_i) == t) {
                        friends++;
                    }
                }
            totalFriends += friends;
            totalPairs++;
            }
            std::cout << friends << " ";
        }
        std::cout << "\n";  
    }

    //Prints average
    double averageFriends = (totalPairs > 0) ? static_cast<double>(totalFriends) / totalPairs : 0.0;
    std::cout << "Media de amigos: " << averageFriends << "\n";

    delete[] FWAdjList;
    delete[] RevAdjList;

    return 0;

}

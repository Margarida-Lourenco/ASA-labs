#include <iostream>
#include <vector>
#include <list>

int main() {
    int V, E;
    char c;

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

    //Initializes to 0
    for (int i = 0; i < V; i++) {
        hist[i] = 0;
    }

    //Calculates the histogram
    for (int i = 1; i <= V; i++) {
        hist[FWAdjList[i].size()]++;
    }

    //print histogram
    std::cout << "Histograma 1" << "\n";
    for (int i = 0; i < V; ++i) {
        std::cout << hist[i] << "\n";
    }


    for (int i = 0; i < V; i++) {
        hist[i] = 0;
    }

    for (int i = 1; i <= V; i++) {
        hist[RevAdjList[i].size()]++;
    }

    std::cout << "Histograma 2" << "\n";
    for (int i = 0; i < V; ++i) {
        std::cout << hist[i] << "\n";
    }

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
            }
            std::cout << friends << " ";
        }
        std::cout << "\n";  
    }

    delete[] FWAdjList;
    delete[] RevAdjList;

    return 0;

}

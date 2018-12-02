#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {

    ifstream fileName("advent1.txt");
    string in;
    vector<int> changes;

    int total = 0;
    while (getline(fileName, in)) {
        int number = stol(in);
        changes.push_back(number);
        total += number;
    }
    cout << "p1: " << total << std::endl;

    unordered_set<int> set;
    set.insert(0);
    int total2 = 0;
    while (true) {
        for (int number : changes) {
            total2 += number;
            if (set.find(total2) == set.end()) {
                set.insert(total2);
            } else {
                cout << "p2: " << total2 << endl;
                return 0;
            }
        }
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
using namespace std;

const int INF = 999;

int graph[15][15] = {
    {0, 1, 6, INF, INF, INF, INF, 5, INF, INF, INF, INF, INF, INF, INF},
    {INF, 0, INF, INF, INF, INF, INF, 5, INF, INF, INF, 5, 8, INF, 9},
    {6, INF, 0, 6, 8, INF, INF, 5, INF, INF, INF, INF, INF, 8, INF},
    {INF, INF, 6, 0, 3, INF, INF, 5, INF, 7, INF, INF, INF, INF, INF},
    {INF, INF, 8, 3, 0, 2, INF, INF, INF, 8, INF, INF, INF, 4, INF},
    {INF, INF, INF, INF, 2, 0, 12, INF, INF, 9, INF, INF, INF, 5, INF},
    {INF, INF, INF, INF, INF, 12, 0, INF, 4, 6, 5, INF, INF, INF, INF},
    {5, 5, 5, 5, INF, INF, INF, 0, INF, 6, INF, 4, INF, INF, INF},
    {INF, INF, INF, INF, INF, INF, 4, INF, 0, 5, 3, INF, INF, INF, 5},
    {INF, INF, INF, 7, 8, 9, 6, 6, 5, 0, INF, 5, INF, INF, 8},
    {INF, INF, INF, INF, INF, INF, 5, INF, 3, INF, 0, INF, INF, INF, 3},
    {INF, 5, INF, INF, INF, INF, INF, 4, INF, 5, INF, 0, INF, INF, 6},
    {INF, 8, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, 4},
    {INF, INF, 8, INF, 4, 5, INF, INF, INF, INF, INF, INF, INF, 0, INF},
    {INF, 9, INF, INF, INF, INF, INF, INF, 5, 8, 3, 6, 4, INF, 0}};

void place(int place) {
    switch (place) {
        case 1:
            cout << " FRONT GATE ";
            break;
        case 2:
            cout << " Accounts building ";
            break;
        case 3:
            cout << " Old apartment ";
            break;
        case 4:
            cout << " OBH ";
            break;
        case 5:
            cout << " Canteen ";
            break;
        case 6:
            cout << " NBH ";
            break;
        case 7:
            cout << " Girl's Hostel ";
            break;
        case 8:
            cout << " DSW ";
            break;
        case 9:
            cout << " CSE BUILDING ";
            break;
        case 10:
            cout << " Mechanical Building ";
            break;
        case 11:
            cout << " Electrical Building ";
            break;
        case 12:
            cout << " Library ";
            break;
        case 13:
            cout << " Backgate ";
            break;
        case 14:
            cout << " Civil Building ";
            break;
        case 15:
            cout << " Admission Cell ";
            break;
        default:
            cout << "Invalid place number.";
            break;
    }
}

int getMin(int n, const vector<int>& dist, const vector<bool>& visited) {
    int min = INF, index;
    for (int i = 0; i < n; i++) {
        if (min > dist[i] && !visited[i]) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void repath(const vector<int>& prev, int source, int target) {
    if (prev[target] != source) {
        repath(prev, source, prev[target]);
        place(prev[target] + 1);
        cout << " -> ";
    }
}

void dij(int source, int target, int n) {
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    vector<int> prev(n, -1);
    
    dist[source] = 0;
    int minPoint;
    do {
        minPoint = getMin(n, dist, visited);
        visited[minPoint] = true;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[minPoint] != INF && (dist[minPoint] + graph[minPoint][j]) < dist[j]) {
                dist[j] = graph[minPoint][j] + dist[minPoint];
                prev[j] = minPoint;
            }
        }
    } while (minPoint != target);
    
    place(source + 1);
    cout << "->";
    repath(prev, source, target);
    place(target + 1);
    cout << "\n\n\t\t\t\t\t\tYou Reached!";
    cout << "\n\n\t\t\t\t\t\tHave A Nice Day!";
}

void interface() {
    int place1, place2;
    do {
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t|| Let Us Find You A Short Path ||\n\n\n";
        cout << "\t\t\t\t\tThe List of Places are:\n\n";
        cout << "\t\t\t\t\t   1. Front Gate \n";
    cout << "\t\t\t\t\t   2. Account Building \n";
    cout << "\t\t\t\t\t   3. Old Apartment \n";
    cout << "\t\t\t\t\t   4. OBH \n";
    cout << "\t\t\t\t\t   5. Canteen \n";
    cout << "\t\t\t\t\t   6. NBH \n";
    cout << "\t\t\t\t\t   7. Girl's Hostel \n";
    cout << "\t\t\t\t\t   8. DSW \n";
    cout << "\t\t\t\t\t   9. CSE Building \n";
    cout << "\t\t\t\t\t  10. Mechanical Building \n";
    cout << "\t\t\t\t\t  11. Electrical Building \n";
    cout << "\t\t\t\t\t  12. Library \n";
    cout << "\t\t\t\t\t  13. BackGate \n";
    cout << "\t\t\t\t\t  14. Civil Building \n";
    cout << "\t\t\t\t\t  15. Admission Cell \n";
        
        cout << "\n\n\t\t\t\t\t\tWhere you are Now: ";
        cin >> place1;
        cout << "\n\t\t\t\t\t\tWhere do you Want to Go: ";
        cin >> place2;
        
        if ((place1 <= 15 && place2 <= 15)) {
            cout << "\n\t\t\t\t\t\tShortest Path to reach from '";
            place(place1);
            cout << "' To '";
            place(place2);
            cout << "' is:\n\t\t\t\t\t\t\t";
            dij(place1 - 1, place2 - 1, 15);
        } else if (place1 == place2) {
            cout << "\n\n\t\t\t\t\tTurn Around And Find Yourself At The Place , Voila ! ";
        } else {
            cout << "\n\n\t\t\t\t\t\tEnter the correct places :( ";
        }
        
        int op;
        cout << "\n\n\n\n  \n"<<"PRESS ANY KEY TO CONTINUE";
        cout << "\n  \n"<<"PRESS 2 TO EXIT";
        cout << "\n\n   ";
        cin >> op;
        if (op == 2) {
            cout << "\n\n\n\t\t\t\t\t\tQuick Tip ! Do Not Take Shortcuts In Life !!!";
            cout << "\n\t\t\t\t\t\tBye Bye, See you next time :)";
            exit(0);
        }
    } while (place1 <= 15 && place2 <= 15);
}

int main() {
    cout << "\t\t\t\t  ********************************  \n";
    cout << "\t\t\t\t-------------------------------------------------------- ----------------------------------------------------------------------------------------------  \n\n";
    cout << " \n\n"<<"\t\t\t\t\tWelcome To C.V. Raman Global University ";
    cout << "\t\t\t\t  ----------------------------------------------------------------------------------------------  \n";
    cout << "\t\t\t\********************************  \n\n\n\n";
    
    int option;
    do {
        cout <<"-------------<: Find The Shortest Path to Reach AnyWhere in CGU :>-------------";
        cout << "\n\n\nPRESS 1 TO CONTINUE";
        cout << "\n\n\nPRESS 2 TO EXIT";
        cout << "\n\n  ";
        cin >> option;
        
        switch (option) {
            case 1:
                interface();
                break;
            case 2:
                cout << "\nQuick Tip ! Do Not Take Shortcuts In Life !!!";
                cout << "\nBye Bye, See you next time :)";
                exit(0);
                break;
            default:
                cout << "Please select the correct number (1 OR 2)!\n";
        }
    } while (option != 2);
    
    return 0;
}
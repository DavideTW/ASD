#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//#define DEBUG

struct cell
{
    bool blackhole = false;
    int relevance = INT_MIN;
    bool occupied = false;
};

struct coord
{
    int x, y;
};

struct coordRelevance
{
    coord coordinate;
    int relevance;
};

struct path
{
    vector<coord> steps;
    vector<char> directions;
    bool valid = true;
};

vector<coordRelevance> calculateSortedCoords(vector<vector<cell>>);
path getPath(vector<vector<cell>>, coord, int);
bool compareByRelevanced(const coordRelevance &a, const coordRelevance &b);
coord getRelevancedCoord(vector<vector<cell>> map, vector<coordRelevance> coords, int index);

int main(int argc, char const *argv[])
{
    // Variabiles
    /**
     * C: columns
     * R: rows
     * S: number of snakes
     */

    int C, R, S;
    cin >> C >> R >> S;
    vector<int> snakes(S);
    vector<vector<cell>> map(R);
    for (int i = 0; i < R; ++i)
        map[i].resize(C);
    char tmp[8];

    for (int i = 0; i < S; ++i)
        cin >> snakes[i];

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> tmp;
            if (tmp[0] == '*') // blackhole
            {
                map[i][j].blackhole = true;
            }
            else
            {
                map[i][j].relevance = atoi(tmp);
            }
        }
    }

    vector<coordRelevance> sortedCoords = calculateSortedCoords(map);
    path percorso;
    for (int i = 0; i < S; ++i)
    {
        coord init = getRelevancedCoord(map, sortedCoords, 0);
        cout << init.y << " " << init.x;
        percorso = getPath(map, init, snakes[i]); 
        for (int j = 0; j < (int)percorso.directions.size(); j++){
            cout << " " << percorso.directions[j];
        }
        cout << endl;
        for (int j = 0; j < (int)percorso.steps.size(); j++)
        {

#ifdef DEBUG
            cout << "x: " << percorso.steps[j].x << " y: "<< percorso.steps[j].y << endl;
#endif 
            map[percorso.steps[j].x][percorso.steps[j].y].occupied = true;
        }
    }
#ifdef DEBUG
    for (int j = 0; j < (int)percorso.steps.size(); j++)
        cout << percorso.steps[j].x << " " << percorso.steps[j].y << endl;

#endif

#ifdef DEBUG
    cout << "C: " << C << endl
         << "R: " << R << endl
         << "S: " << S << endl
         << "Snakes: " << endl;

    for (int i = 0; i < S; ++i)
        cout << snakes[i] << " ";
    cout << endl;
#endif // DEBUG

#ifdef DEBUG
    coord max_ = getRelevancedCoord(map, sortedCoords, 0);
    cout << max_.x << " " << max_.y << endl;
#endif // DEBUG

    // occopied non deve contare se è blackhole

    return 0;
}

coord getRelevancedCoord(vector<vector<cell>> map, vector<coordRelevance> coords, int index)
{
    int i = index;

    while (i < (int)coords.size())
    {
        if (!map[coords[i].coordinate.x][coords[i].coordinate.y].occupied)
            break;

        i++;
    }

    return coords[i].coordinate;
}

vector<coordRelevance> calculateSortedCoords(vector<vector<cell>> map)
{

    vector<coordRelevance> sortedCoords((int)map.size());

    for (int i = 0; i < (int)map.size(); ++i)
    {
        for (int j = 0; j < (int)map[i].size(); ++j)
        {
            sortedCoords.push_back({{i, j}, map[i][j].relevance});
        }
    }

    sort(sortedCoords.begin(), sortedCoords.end(), compareByRelevanced);

    return sortedCoords;
}

bool compareByRelevanced(const coordRelevance &a, const coordRelevance &b)
{
    return a.relevance > b.relevance;
}

path getPath(vector<vector<cell>> map, coord init, int len)
{
    path p;
    p.steps.push_back(init);
    coord pos = {init.x, init.y};


#ifdef DEBUG
    cout << "pos: " << pos.x << " " << pos.y << endl;
#endif
    vector<pair<coord, char>    > to_check = {
        {{-1, 0}, 'U'},
        {{1, 0}, 'D'},
        {{0, -1}, 'L'},
        {{0, 1}, 'R'}
    };


    for (int i = 0; i < len - 1; ++i)
    {
        coord best;
        int max_value = INT_MIN;
        char best_dir;
        // cout << " " << !map[1][2].blackhole << endl;
        for (int j = 0; j < (int)to_check.size(); ++j)
        {
            coord current = { (pos.x + to_check[j].first.x + (int)map.size()) % (int)map.size(), (pos.y + to_check[j].first.y + (int)map[0].size()) % (int)map[0].size()};
            if (!map[current.x][current.y].occupied &&
                !map[current.x][current.y].blackhole &&
                map[current.x][current.y].relevance > max_value)
            {
                bool ok = true;
                for (int a = 0; a < (int)p.steps.size(); ++a)
                    if (p.steps[a].x == current.x && p.steps[a].y == current.y)
                        ok = false;

                if (ok)
                {
                    max_value = map[current.x][current.y].relevance;
                    best_dir = to_check[j].second;
                    best.x = current.x;
                    best.y = current.y;
                    // cout << "OK" << endl;
                }
            }
        }

        if (max_value == INT_MIN)
        {
            p.valid = false;
            return p;
        }
        else
        {
            p.steps.push_back({best.x, best.y});
            p.directions.push_back(best_dir);
            pos.x = best.x;
            pos.y = best.y;
        }
    }
    return p;
}

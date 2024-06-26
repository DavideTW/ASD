#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define DEBUG

enum Direction{UP, DOWN, RIGHT, LEFT};

Direction reverse(Direction direction) {
    switch (direction) {
        case UP: return DOWN;
        case DOWN: return UP;
        case RIGHT: return LEFT;
        case LEFT: return RIGHT;
        default: break;
    }
}

struct Coordinate {
    int x, y;
    bool taken;
};

struct SilverPoint {
    Coordinate coord;
    int score;
};

struct TileType {
    char id;
    vector<Direction> possible_moves;
};

struct Tile {
    TileType type;
    int cost;
};

enum TileID{T3, T5,T6, T7, T8,T9,TA,TB,TC,TD,TE,TF};

TileType t3 = {'3', {RIGHT, LEFT} };
TileType t5 = {'5', {DOWN, RIGHT}};
TileType t6 = {'6', {LEFT, DOWN}};
TileType t7 = {'7', {LEFT, RIGHT, DOWN}};
TileType t9 = {'9', {UP, RIGHT}};
TileType tA = {'A', {LEFT, UP}};
TileType tB = {'B', {LEFT, UP, RIGHT}};
TileType tC = {'C', {UP, DOWN}};
TileType tD = {'D', {UP, RIGHT, DOWN}};
TileType tE = {'E', {UP, LEFT, DOWN}};
TileType tF = {'F', {UP, LEFT, DOWN, RIGHT}};

TileType getTileTypeFromName(char value) {
    switch (value) {
        case '3': return t3;
        case '5': return t5;
        case '6': return t6;
        case '7': return t7;
        case '9': return t9;
        case 'A': return tA;
        case 'B': return tB;
        case 'C': return tC;
        case 'D': return tD;
        case 'E': return tE;
        case 'F': return tF;
        default: break;
    }
}

int getMachingTiles(vector<pair<Tile, int>> tiles, Direction direction) {
    Direction reverseDirection = reverse(direction);

    for (int i = 0; i < tiles.size(); i++) {
        for (auto move : tiles[i].first.type.possible_moves) {
            if (move == reverseDirection && move == direction) {
                return i;
            }
        }
    }

    return -1;
}

void move(int& x, int& y, Direction direction) {
    switch (direction) {
        case UP: x--; break;
        case DOWN: x++; break;
        case RIGHT: y++; break;
        case LEFT: y--; break;
        default: break;
    }
}

vector<Coordinate> golden_points;
vector<SilverPoint> silver_points;    
vector<pair<Tile, int>> tiles;
int W, H, G, S, T;
vector<vector<int>> matrix_map;
vector<vector<int>> score_map;


/*                  SCORE
    0 vuoto     |   0
    1 silver    |   score
    2 golden    |   1000

*/

int minGoldenPoint(int startPoint) {
    int minGoldenPoint = -1;
    int minGoldenPointDistance = INT_MAX;

    for (int i=1; i<golden_points.size(); i++) {    
        if (golden_points[i].taken) {
            continue;
        }

        int distance = sqrt(pow(golden_points[startPoint].x-golden_points[startPoint].x, 2) + 
            pow(golden_points[startPoint].y-golden_points[i].y, 2));

        if (distance < minGoldenPointDistance) {
            minGoldenPoint = i;
            minGoldenPointDistance = distance;
        }
    }

    return minGoldenPoint;
}

bool contains(vector<Direction> directions, Direction direction) {
    for (auto dir : directions) {
        if (dir == direction) {
            return true;
        }
    }

    return false;
}

int tileIndex(vector<Direction> dirs) {
    Direction direction = reverse(dirs[0]);
    Direction direction2 = dirs[1];

    for (int i = 0; i < tiles.size(); i++) {
        if (contains(tiles[i].first.type.possible_moves, direction) && contains(tiles[i].first.type.possible_moves, direction2)) {
            return i;
        }
    }

    return -1;
}

int main(int argc, char const *argv[]) {
    
    /* 
        W: width - numero colonne
        H: height - numero righe
        G: golden point - numero di punti d'oro
        S: silver point - numero di punti d'argento
        T: tiles - numero di caselle usbili
    */

    #ifdef DEBUG

    ifstream cin("input.txt");
    ofstream cout("output.txt");

    #endif

    cin >> W >> H >> G >> S >> T;    

    matrix_map.resize(H, vector<int>(W, 0));
    score_map.resize(H, vector<int>(W, 0));

    // Loading golden points

    for (int i = 0; i < G; i++) {
        int x, y;
        cin >> y >> x;

        golden_points.push_back({x, y});
        matrix_map[x][y] = 2;
        score_map[x][y] = 1000;
    }

    // Loading silver points

    for (int i = 0; i < S; i++) {
        int x, y, score;
        cin >> y >> x >> score;
        silver_points.push_back({{x, y}, score});
        matrix_map[x][y] = 1;
        score_map[x][y] = score;
    }

    // Loading tiles

    for (int i = 0; i < T; i++) {
        char id;
        int cost;
        int nTiles;
        cin >> id >> cost >> nTiles;
        tiles.push_back({{getTileTypeFromName(id), cost}, nTiles});
    }

    golden_points[0].taken = true;

    int minGoldenPointIndex = minGoldenPoint(0);

    int x = golden_points[0].x;
    int y = golden_points[0].y;

    bool first = true;
    
    while (minGoldenPointIndex != -1) {

        int goldenPointX = golden_points[minGoldenPointIndex].x;
        int goldenPointY = golden_points[minGoldenPointIndex].y;

        vector<Direction> direzioni;

         while (!(x == goldenPointX && y == goldenPointY)) {
            Direction direction;

            if (goldenPointX == x) {
                if (goldenPointY > y) {
                    direction = RIGHT;
                } else {
                    direction = LEFT;
                }
            } else {
                if (goldenPointX > x) {
                    direction = DOWN;
                } else {
                    direction = UP;
                } 
            }

            // cout << direction << endl;
            direzioni.push_back(direction);

            if (direzioni.size() == 2) {

                if (first) {
                    first = false;
                    cout << tiles[tileIndex(direzioni)].first.type.id << " " << x << " " << y;
                } else {
                    cout << endl << tiles[tileIndex(direzioni)].first.type.id << " " << x << " " << y;
                }

                // chiamare funzione
                /*cout << endl;
                cout << "{";
                cout << "direction: " << reverse(direzioni[0]) << " direction2: " << direzioni[1] << endl;
                cout << "}" << endl; 

                cout << "index: " << tileIndex(direzioni) << " " << tiles[tileIndex(direzioni)].first.type.id << endl;
                */
                direzioni.erase(direzioni.begin());
            }
            
            move(x, y, direction);

            /*

            int index = getMachingTiles(tiles, direction);
            if (index != -1) {
                #ifdef DEBUG

                #endif

                move(x, y, direction);

                tiles[index].second--;
            }*/
        }
    
        golden_points[minGoldenPointIndex].taken = true;
        minGoldenPointIndex = minGoldenPoint(minGoldenPointIndex);
    }
    
    /*#ifdef DEBUG

    //stampa
    for(int i = 0; i < H; i++){

        for(int j = 0; j < W; j++){
            cout << matrix_map[i][j] << " ";
        }
        
        cout << endl;
    }

    cout << endl << "------------------------" << endl << endl;

    for(int i = 0; i < H; i++){

        for(int j = 0; j < W; j++){
            cout << "  " << score_map[i][j] << "  ";
        }
        
        cout << endl;
    }
    
    #endif*/

    /* OUTPUT:
    
    Each line consists of:

    a string representing the Tile ID chosen
    an integer representing the X coordinate on the system grid
    an integer representing the Y coordinate on the system grid
    
    */
    return 0;
}
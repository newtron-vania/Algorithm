#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

#define SIZE 4
#define INF 101

vector<int> cards;
vector<pair<int,int>> cardLoc[7];

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int answer = 1e9;

bool safe(int y, int x) {
    return y>=0 && x>=0 && y<SIZE && x<SIZE;    
}

int get_dist(vector<vector<int>> &board, int sy, int sx, int ty, int tx) {
    vector<vector<int>> dist(SIZE, vector<int>(SIZE, INF));
    priority_queue<tuple<int,int,int>> pq;
    
    pq.push({0, sy, sx});
    dist[sy][sx] = 0;
    
    // 다익스트라 알고리즘으로 두 지점 거리 구하기
    while(!pq.empty()) {
        auto [cnt, y, x] = pq.top(); pq.pop();
        cnt = -cnt;
        
        if(y == ty && x == tx) return cnt;
        
        for(int d=0; d<4; ++d) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            
            if(!safe(ny, nx)) continue;
            
            if(cnt + 1 < dist[ny][nx]) {
                dist[ny][nx] = cnt + 1;
                pq.push({-(cnt+1), ny, nx});
            }
            
            // Ctrl + 방향키
            while(safe(ny, nx) && board[ny][nx] == 0) {
                ny += dy[d];
                nx += dx[d];
            }
            if(!safe(ny, nx)) {
                ny -= dy[d];
                nx -= dx[d];
            }
            
            if(cnt + 1 < dist[ny][nx]) {
                dist[ny][nx] = cnt + 1;
                pq.push({-(cnt+1), ny, nx});
            }
        }
    }
    
    return -1;
}

void func(vector<vector<int>> &board, int idx, int ans, int y, int x) {
    if(idx == cards.size()) {
        answer = min(answer, ans);
        return;
    }
    
    int card = cards[idx];
    pair<int,int> loc1 = cardLoc[card][0]; 
    pair<int,int> loc2 = cardLoc[card][1]; 
    
    // 카드 다른 순서로 뒤집기
    int dist1 = get_dist(board, y, x, loc1.first, loc1.second) + 
        get_dist(board, loc1.first, loc1.second, loc2.first, loc2.second) + 2;
    
    int dist2 = get_dist(board, y, x, loc2.first, loc2.second) +
        get_dist(board, loc2.first, loc2.second, loc1.first, loc1.second) + 2;
        
    board[loc1.first][loc1.second] = 0;
    board[loc2.first][loc2.second] = 0;
    
    func(board, idx+1, ans+dist1, loc2.first, loc2.second);
    func(board, idx+1, ans+dist2, loc1.first, loc1.second);
    
    board[loc1.first][loc1.second] = card;
    board[loc2.first][loc2.second] = card;
}

int solution(vector<vector<int>> board, int r, int c) {
    for(int i=0; i<SIZE; ++i) {
        for(int j=0; j<SIZE; ++j) {
            if(board[i][j]) {
                cards.push_back(board[i][j]); // 모든 카드 담기
                cardLoc[board[i][j]].push_back({i, j});
            }
        }
    }
    
    sort(cards.begin(), cards.end());
    cards.erase(unique(cards.begin(), cards.end()), cards.end());
    
    do {
        func(board, 0, 0, r, c);
    } while(next_permutation(cards.begin(), cards.end()));
    
    return answer;
}
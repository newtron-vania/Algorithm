#include <iostream>
#include <vector>
#include <cmath>

const int MAX = 100010;
using namespace std;

int N, K;
int Arr[MAX];
vector<int> SegmentTree;
vector<pair<char, pair<int, int>>> Cmd;
vector<char> Answer;

void Initialize() {
    SegmentTree.clear();
    Cmd.clear();
    Answer.clear();
}


void Input() {
    for (int i = 0; i < N; i++) cin >> Arr[i];
    for (int i = 0; i < K; i++) {
        char C; int a, b;
        cin >> C >> a >> b;
        Cmd.push_back(make_pair(C, make_pair(a, b)));
    }
}


int Invert(int x) {
    if (x == 0) return 0;
    else return x > 0 ? 1 : -1;
}


int Make_SegmentTree(int Node, int Start, int End) {
    if (Start == End) {
        return SegmentTree[Node] = Invert(Arr[Start]);
    }
    int Mid = (Start + End) / 2;
    int Left_Result = Make_SegmentTree(Node * 2, Start, Mid);
    int Right_Result = Make_SegmentTree(Node * 2 + 1, Mid + 1, End);
    return SegmentTree[Node] = Left_Result * Right_Result;
}


int Update(int Node, int Start, int End, int Idx, int Value) {
    if (Idx < Start || Idx > End) return SegmentTree[Node];
    if (Start == End) {
        return SegmentTree[Node] = Invert(Value);
    }
    int Mid = (Start + End) / 2;
    int Left_Result = Update(Node * 2, Start, Mid, Idx, Value);
    int Right_Result = Update(Node * 2 + 1, Mid + 1, End, Idx, Value);
    return SegmentTree[Node] = Left_Result * Right_Result;
}


int Query(int Node, int Start, int End, int Left, int Right) {
    if (Right < Start || Left > End) return 1;
    if (Left <= Start && End <= Right) return SegmentTree[Node];
    int Mid = (Start + End) / 2;
    int Left_Result = Query(Node * 2, Start, Mid, Left, Right);
    int Right_Result = Query(Node * 2 + 1, Mid + 1, End, Left, Right);
    return Left_Result * Right_Result;
}


void Solution() {
    int Tree_Height = (int)ceil(log2(N));
    int Tree_Size = (1 << (Tree_Height + 1));
    SegmentTree.resize(Tree_Size);
    Make_SegmentTree(1, 0, N - 1);

    for (auto& command : Cmd) {
        char C = command.first;
        if (C == 'C') {
            int Index = command.second.first - 1;
            int Value = command.second.second;
            Update(1, 0, N - 1, Index, Value);
        } else {
            int Index = command.second.first - 1;
            int Index2 = command.second.second - 1;
            int Result = Query(1, 0, N - 1, Index, Index2);
            if (Result == 0) Answer.push_back('0');
            else Answer.push_back(Result > 0 ? '+' : '-');
        }
    }
    for (char ans : Answer) cout << ans;
    cout << endl;
}


void Solve() {
    while (cin >> N >> K) {
        Initialize();
        Input();
        Solution();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
    return 0;
}

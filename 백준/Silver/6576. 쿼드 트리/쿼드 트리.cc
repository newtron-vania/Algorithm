#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
string s;

vector<vector<int>> arr(600, vector<int>(600));
vector<vector<string>> res(600, vector<string>(600));
string hex_ = "0123456789abcdef";


void init(){
    cin >> N;
    cin >> s;
}

void sol(string::iterator &it, int y, int x, int size){
    char head = *it;
    it++;
    if(head == 'B' || head == 'W'){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                arr[y+i][x+j] = head == 'B' ? 1 : 0;
            }
        }
    }else{
        int half = size/2;
        sol(it, y, x, half);
        sol(it, y, x+half, half);
        sol(it, y+half, x, half);
        sol(it, y+half, x+half, half);
    }
}

string DECtoHEX(int n){
    string a, b;
    a = hex_[n/16];
    b = hex_[n%16];
    return "0x"+a+b+",";
}

void change(){
    int temp;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N/8; j++){
            temp = 0;
            for(int k = 0; k < 8; k++) temp += arr[i][j*8 + k] * pow(2,k);
            res[i][j] = DECtoHEX(temp);
        }
    }
}

void print_arr(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void print_res(){
    cout << "#define quadtree_width " << N << "\n";
    cout << "#define quadtree_height " << N <<"\n";
    cout << "static char quadtree_bits[] = {\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N/8; j++){
            cout << res[i][j];
        }
        cout << "\n";
    }
    cout <<"};";
}

int main() {
    init();
    string::iterator it = s.begin();
    sol(it, 0, 0, N);
    change();
	print_res();
	return 0;
}

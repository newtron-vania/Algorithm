#include <string>  
#include <vector>  
#include <iostream>  
#include <queue>  
using namespace std;  
  
int inde[1000005];  
int outde[1000005];  
vector<vector<int>> path(1000005);  
int t8=0,t1=0,t0=0;  
  
void check(int start){  
	queue<int> q;  
	q.push(start);  
	bool isvisted = false;   //시작점을 방문 했는지
	while(!q.empty()){  
		int now = q.front();  
		q.pop();  
		if(now == start && isvisted){  
			t0++;  
			return;  
		}  
  
		if(path[now].size() >= 2){  
			t8++;  
			return;  
		}  
  
		for(int i=0; i< path[now].size(); i++){  
			q.push(path[now][i]);  
		}	  
		isvisted = true;  
	}  
	t1++;  
	return;  
}  
  
  
vector<int> solution(vector<vector<int>> edges) {  
	vector<int> answer;  
  
	for(int i=0; i<edges.size(); i++){  
		inde[edges[i][1]]++;  
		outde[edges[i][0]]++;  
		path[edges[i][0]].push_back(edges[i][1]);  
	}  
  
	for(int i=1; i<1000005; i++){  
		if(inde[i] == 0 && outde[i] >=2){  
			answer.push_back(i);  
		}  
	}  
  
	vector<int> start = path[answer[0]];  
	for(int i=0; i<start.size(); i++){  
		check(start[i]);  
	}  
	answer.push_back(t0);  
	answer.push_back(t1);  
	answer.push_back(t8);  
  
	return answer;  
}
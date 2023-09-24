#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> answer;
vector<vector<string>> input_tickets;
vector<bool> visited;

void dfs(string start, vector<string>& path, int cnt)
{
	path.push_back(start);

	// 모든 항공권을 사용했을 경우
	if (cnt == input_tickets.size())
	{
		answer = path;
		return;
	}

	for (int i = 0; i < input_tickets.size(); i++)
	{
		if (input_tickets[i][0] == start && !visited[i]) 
		{
			visited[i] = true;
			dfs(input_tickets[i][1], path, cnt + 1);
			visited[i] = false; 
            
			if (!answer.empty()) 
                return;
		}
	}
	path.pop_back();
}

vector<string> solution(vector<vector<string>> tickets)
{
	input_tickets = tickets;
	visited.resize(input_tickets.size(), false);
	sort(input_tickets.begin(), input_tickets.end()); 
	vector<string> path; 
	dfs("ICN", path, 0);
	return answer;
}
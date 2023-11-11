#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool CheckSkillTreeFine(string skill_tree, int parent[26]){
    bool visited[26];
    fill_n(visited, 26, false);
    
    for(char s : skill_tree){
        int num = 0 + (s - 'A');
        if(parent[num] == num)
            visited[num] = true;
        else{
            if(!visited[parent[num]]){
                return false;
            }
            else{
                visited[num] = true;
            }
        }
    }
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int parent[26];
    for(int i =0; i < 26; i++){
        parent[i] = i;
    }
    for(int i = 1; i < skill.length(); i++){
        parent[(skill[i] - 'A')] = (skill[i-1] - 'A');
    }
    
    for(string skill_tree : skill_trees){
        //copy
        int parent_copy[26];
        copy(begin(parent), end(parent), begin(parent_copy));
        
        if(CheckSkillTreeFine(skill_tree, parent_copy)) 
        {
            answer++;
        }
    }
    
    return answer;
}
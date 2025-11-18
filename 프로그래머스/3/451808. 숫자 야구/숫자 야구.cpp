#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

extern string submit(int);

vector<int> unique_digits_numbers;

string get_clue(int my_guess, int answer)
{
    string password = to_string(answer);
    string guess = to_string(my_guess);
    int strike = 0, ball = 0;

    for (int i = 0; i < 4; i++)
    {
        if (guess[i] == password[i])
        {
            strike++;
        } else if (password.find(guess[i]) != string::npos)
        {
            ball++;
        }
    }

    return to_string(strike) + "S " + to_string(ball) + "B";
}

int get_best_guess(vector<int> candidates) 
{
    int best_guess = -1;
    int min_max_group_size = candidates.size();

    for (int guess : unique_digits_numbers) 
    {
        map<string, int> group_sizes;

        for (int answer : candidates)
        {
            string clue = get_clue(guess, answer);
            group_sizes[clue]++;
        }

        int max_group_size = 0;
        for (const auto& entry : group_sizes) 
        {
            if (entry.second > max_group_size)
            {
                max_group_size = entry.second;
            }
        }

        if (max_group_size < min_max_group_size) 
        {
            min_max_group_size = max_group_size;
            best_guess = guess;
        }
    }


    return best_guess;
}

int solution(int n)
{
    for (int i = 1234; i <= 9876; i++) 
    {
        string num_str = to_string(i);
        if (num_str.find('0') != string::npos) continue;  // 0 포함 제외
        if (num_str[0] != num_str[1] && num_str[0] != num_str[2] &&
            num_str[0] != num_str[3] && num_str[1] != num_str[2] &&
            num_str[1] != num_str[3] && num_str[2] != num_str[3]) 
        {
                unique_digits_numbers.push_back(i);
        }
    }

    vector<int> candidates = unique_digits_numbers;

    while (candidates.size() > 1 && n-- > 0) 
    {
        int guess = get_best_guess(candidates);

        string clue = submit(guess);

        vector<int> new_candidates;
        for (int num : candidates) {
            string ans = get_clue(guess, num);
            if (ans == clue) {
                new_candidates.push_back(num);
            }
        }
        candidates = new_candidates;

        //cout << "Guess: " << guess << ", Clue: " << clue << ", Remaining candidates: " << candidates.size() << endl;
    }

    return candidates[0];
}

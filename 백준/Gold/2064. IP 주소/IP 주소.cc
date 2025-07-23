#include <bits/stdc++.h>
using namespace std;

vector<int> split(string str, char delim)
{
    vector<int> result;
    string tmp;
    stringstream ss(str);
    while (getline(ss, tmp, delim))
    {
        result.push_back(stoi(tmp));
    }
    return result;
}

// 32비트 int → "A.B.C.D" 문자열
string to_string_ip(int ip) 
{
    stringstream ss;
    for (int i = 3; i >= 0; --i) 
    {
        ss << ((ip >> (i * 8)) & 0xFF);
        if (i != 0) ss << '.';
    }
    return ss.str();
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> ips;
    ips.reserve(n);

    // IP 문자열을 32비트 int로 변환
    for (int i = 0; i < n; ++i)
     {
        string address;
        cin >> address;
        auto parts = split(address, '.');
        int ip = 0;
        for (int j = 0; j < 4; ++j)
        {
            ip |= parts[j] << (8 * (3 - j));
        }
        ips.push_back(ip);
    }

    int ip_min = *min_element(ips.begin(), ips.end());
    int ip_max = *max_element(ips.begin(), ips.end());
    int diff   = ip_min ^ ip_max;

    int prefix_len = 32;
    if (diff != 0)
     {
        for (int i = 31; i >= 0; --i) 
        {
            if ((diff >> i) & 1) 
            {
                // bit i가 첫 번째 1이라면, 상위 비트(31..i+1)는 같다.
                prefix_len = 31 - i;
                break;
            }
        }
    }

    int mask = (prefix_len == 0)
             ? 0
             : ((~0) << (32 - prefix_len));

    int network = ip_min & mask;

    cout << to_string_ip(network) << "\n"
         << to_string_ip(mask)    << "\n";
    return 0;
}

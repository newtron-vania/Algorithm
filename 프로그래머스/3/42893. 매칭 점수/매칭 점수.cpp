#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <string>

using namespace std;

// 알파벳이 아닌 경우
bool wordChange(char c) {
	return c == '\'' || !isalpha(c);
}

// first는 내림차순 second는 오름차순
bool comp(pair<double, int> a, pair<double, int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

int solution(string word, vector<string> pages) {
	// word 소문자로 치환
	transform(word.begin(), word.end(), word.begin(), ::tolower);

	// url이름과 그에 맞는 index 저장
	map<string, int> urlName;
	// 각 index가 가지고 있는 url 링크 저장
	vector<vector<string>> links;
	// 각 index가 가지고 있는 기본 점수
	vector<int> basicScore;
    // 매칭 점수와 인덱스
	vector<pair<double, int>> matchScore;

	for (int i = 0; i < pages.size(); i++) {
		// 웹페이지 소문자 치환
		transform(pages[i].begin(), pages[i].end(), pages[i].begin(), ::tolower);

		// 웹페이지 url 알아내고 저장
		string content = "<meta property=\"og:url\" content=\"https://";
		int contentPos = pages[i].find(content);
		int contentStart = contentPos + content.size();
		int contentEnd = pages[i].substr(contentStart).find("\"/>");
		urlName[pages[i].substr(contentStart, contentEnd)] = i + 1;

		// body 파트 분리
		int bodyStartIdx = pages[i].find("<body>");
		int bodyEndIdx = pages[i].find("</body>");
		string bodyPage = pages[i].substr(bodyStartIdx, bodyEndIdx - bodyStartIdx);

		// 외부 링크 탐색
		vector<string> link;
		string href = "<a href=\"https://";
		int hrefPos = bodyPage.find(href);
		while (hrefPos != std::string::npos)
		{
			int hrefStart = hrefPos + href.size();
			int hrefEnd = bodyPage.substr(hrefStart).find("\">");
			link.push_back(bodyPage.substr(hrefStart, hrefEnd));
			hrefPos = bodyPage.find(href, hrefStart + hrefEnd);
		}

		// index가 가진 외부 링크 저장
		links.push_back(link);

		// 특수 문자들도 분리하기 위해 알파벳이 아닐시 싹다 공백으로 변환
		replace_if(bodyPage.begin(), bodyPage.end(), wordChange, ' ');

		// body 파트에서 검색어와 비교해 기본 점수 저장
		int score = 0;
		istringstream iss(bodyPage);
		string token;
		while (getline(iss, token, ' ')) {
			if (word.compare(token) == 0)
				score++;
		}
		basicScore.push_back(score);
	}
    
    // 각 인덱스에 기본 점수를 넣어준다
	for (int i = 0; i < links.size(); i++) {
		matchScore.push_back(make_pair(basicScore[i], i));
	}
    
    // 각 인덱스에 링크 점수를 추가한다
	for (int i = 0; i < links.size(); i++) {
		int linkSize = links[i].size();
		for (int j = 0; j < linkSize; j++) {
            // url이 존재할 경우에만 계산
			if (urlName[links[i][j]] != 0) {
				matchScore[urlName[links[i][j]] - 1].first += (double)basicScore[i] / (double)linkSize;
			}
		}
		
	}
    
    // 매칭 점수를 정렬한다(점수는 내림차순으로 인덱스는 오름차순으로)
	sort(matchScore.begin(), matchScore.end(), comp);
    
    // 매칭점수가 제일 높은 것들 중 인덱스가 가장 작은 경우
	return matchScore[0].second;
}
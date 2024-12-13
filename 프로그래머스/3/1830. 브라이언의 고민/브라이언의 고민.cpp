#include <string>
#include <vector>
#include <cstring>

using namespace std;

int sentenceLength;
vector<int> groupIndex;
vector<bool> rule1Applied;
vector<bool> rule2Applied;
vector<bool> usedCharacters;
int wordIndex;

struct CharInfo 
{
    int start, end, count;
};

bool applyRule1(string& sentence, CharInfo charInfo, char c)
{
    if (usedCharacters[c - 'a'])
    {
        return false;
    }
    if (charInfo.start - 1 < 0 || charInfo.end + 1 >= sentenceLength)
    {
        return false;
    }
    if (islower(sentence[charInfo.start - 1]) || islower(sentence[charInfo.end + 1]))
    {
        return false;
    }

    int lowercaseCount = 0, uppercaseCount = 0;
    for (int i = charInfo.start - 1; i <= charInfo.end + 1; ++i)
    {
        char current = sentence[i];
        if (islower(current))
        {
            if (current == c)
            {
                groupIndex[i] = wordIndex;
                ++lowercaseCount;
                uppercaseCount = 0;
            }
            else
            {
                return false;
            }
        }
        else if (isupper(current))
        {
            lowercaseCount = 0;
            ++uppercaseCount;

            if (rule1Applied[i])
            {
                return false;
            }
            else 
            {
                groupIndex[i] = wordIndex;
                rule1Applied[i] = true;
            }
        }

        if (lowercaseCount > 1 || uppercaseCount > 1)
        {
            return false;
        }
    }

    ++wordIndex;
    usedCharacters[c - 'a'] = true;
    return true;
}

bool applyRule2(string& sentence, CharInfo charInfo, char c)
{
    if (usedCharacters[c - 'a'])
    {
        return false;
    }
    if (charInfo.end - charInfo.start < 2)
    {
        return false;
    }

    groupIndex[charInfo.start] = wordIndex;
    groupIndex[charInfo.end] = wordIndex;

    for (int i = charInfo.start + 1; i < charInfo.end; ++i)
    {
        char current = sentence[i];
        if (isupper(current))
        {
            if (rule2Applied[i])
            {
                return false;
            }
            else 
            {
                groupIndex[i] = wordIndex;
                rule2Applied[i] = true;
            }
        }
    }

    ++wordIndex;
    usedCharacters[c - 'a'] = true;
    return true;
}

CharInfo getCharInfo(string& sentence, char c)
{
    int start = -1;
    int count = 0;
    int end = 0;

    for (int i = 0; i < sentenceLength; ++i)
    {
        if (sentence[i] == c)
        {
            if (start < 0)
            {
                start = i;
            }
            ++count;
            end = i;
        }
    }

    return {start, end, count};
}

bool canDecrypt(string &sentence)
{
    for (int i = 0; i < sentenceLength; ++i)
    {
        char current = sentence[i];
        if (current == ' ')
        {
            return false;
        }

        if (groupIndex[i] == 0)
        {
            if (isupper(current))
            {
                if (i + 1 >= sentenceLength)
                {
                    groupIndex[i] = wordIndex++;
                    continue;
                }

                char next = sentence[i + 1];
                if (isupper(next))
                {
                    groupIndex[i] = wordIndex++;
                }
                else if (islower(next))
                {
                    CharInfo charInfo = getCharInfo(sentence, next);
                    if (charInfo.count == 2)
                    {
                        groupIndex[i] = wordIndex++;
                    }
                    else
                    {
                        if (!applyRule1(sentence, charInfo, next))
                        {
                            return false;
                        }
                    }
                }
            }
            else if (islower(current))
            {
                CharInfo charInfo = getCharInfo(sentence, current);
                if (charInfo.count == 2)
                {
                    if (isupper(sentence[i + 1]) && rule2Applied[i + 1])
                    {
                        if (!applyRule1(sentence, charInfo, current))
                        {
                            return false;
                        }
                    }
                    else
                    {
                        if (!applyRule2(sentence, charInfo, current))
                        {
                            return false;
                        }
                    }
                }
                else
                {
                    if (!applyRule1(sentence, charInfo, current))
                    {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

string constructAnswer(string &sentence)
{
    int lastGroupIndex = 0;
    for (int i = 0; i < sentenceLength; ++i)
    {
        if (isupper(sentence[i]))
        {
            lastGroupIndex = groupIndex[i];
            break;
        }
    }

    string answer = "";
    for (int i = 0; i < sentenceLength; ++i)
    {
        char current = sentence[i];
        if (isupper(current))
        {
            if (groupIndex[i] != lastGroupIndex)
            {
                answer += ' ';
            }
            answer += current;
            lastGroupIndex = groupIndex[i];
        }
    }
    return answer;
}

string solution(string sentence)
{
    sentenceLength = sentence.size();
    groupIndex = vector<int>(sentenceLength);
    rule1Applied = vector<bool>(sentenceLength);
    rule2Applied = vector<bool>(sentenceLength);
    usedCharacters = vector<bool>(26);
    wordIndex = 1;

    if (!canDecrypt(sentence))
    {
        return "invalid";
    }

    return constructAnswer(sentence);
}

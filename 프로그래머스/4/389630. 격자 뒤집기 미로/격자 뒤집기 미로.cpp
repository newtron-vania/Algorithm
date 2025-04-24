#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int NEG_INF = -1e9;

int getOneBitCnt(int mask)
{
    int result = 0;
    while (mask)
    {
        result += mask % 2;
        mask /= 2;
    }
    return result;
}

int solution(vector<vector<int>> visible, vector<vector<int>> hidden, int k)
{
    int nRows = visible.size();
    if (nRows == 0)
    {
        return 0;
    }

    int nCols = visible[0].size();
    int initSum = 0;

    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            initSum += visible[i][j];
        }
    }

    vector<vector<int>> diff(nRows, vector<int>(nCols, 0));
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            diff[i][j] = hidden[i][j] - visible[i][j];
        }
    }

    bool canVisitAllCells = false;
    if (nRows >= 2 && nCols >= 2)
    {
        if (((nRows + nCols) % 2 == 0) && ((nRows * nCols) % 2 == 0))
        {
            canVisitAllCells = true;
        }
    }

    int answer = NEG_INF;

    for (int rowMask = 0; rowMask < (1 << nRows); rowMask++)
    {
        int flipCount = getOneBitCnt(rowMask);
        int rowCost = flipCount * k;
        int baseScore = initSum - rowCost;

        vector<int> colFlippedSum(nCols, 0), colNotFlippedSum(nCols, 0);

        for (int col = 0; col < nCols; col++)
        {
            int sumFlipped = 0, sumNotFlipped = 0;
            for (int row = 0; row < nRows; row++)
            {
                if (rowMask & (1 << row))
                {
                    sumFlipped += diff[row][col];
                }
                else
                {
                    sumNotFlipped += diff[row][col];
                }
            }
            colFlippedSum[col] = sumFlipped;
            colNotFlippedSum[col] = sumNotFlipped;
        }

        if (!canVisitAllCells)
        {
            int colTotalScore = 0;
            for (int col = 0; col < nCols; col++)
            {
                colTotalScore += max(colFlippedSum[col], colNotFlippedSum[col] - k);
            }
            answer = max(answer, baseScore + colTotalScore);
        }
        else
        {
            vector<int> minOddScoreColNotFlipped(nCols, INF);
            vector<int> minOddScoreColFlippped(nCols, INF);

            for (int col = 0; col < nCols; col++)
            {
                for (int row = 0; row < nRows; row++)
                {
                    if (((row + col) & 1) == 1)
                    {
                        int oddScoreColNotFlipped;
                        int oddScoreColFlipped;

                        if (rowMask & (1 << row))
                        {
                            oddScoreColNotFlipped = visible[row][col] + diff[row][col];
                            oddScoreColFlipped = visible[row][col];
                        }
                        else
                        {
                            oddScoreColNotFlipped = visible[row][col];
                            oddScoreColFlipped = visible[row][col] + diff[row][col];
                        }

                        minOddScoreColNotFlipped[col] = min(minOddScoreColNotFlipped[col], oddScoreColNotFlipped);
                        minOddScoreColFlippped[col] = min(minOddScoreColFlippped[col], oddScoreColFlipped);
                    }
                }
            }

            vector<int> thresholds;
            for (int col = 0; col < nCols; col++)
            {
                thresholds.push_back(minOddScoreColNotFlipped[col]);
                thresholds.push_back(minOddScoreColFlippped[col]);
            }

            sort(thresholds.begin(), thresholds.end());
            thresholds.erase(unique(thresholds.begin(), thresholds.end()), thresholds.end());

            int bestScore = NEG_INF;

            for (int threshold : thresholds)
            {
                bool valid = true;
                int profitSum = 0;
                int globalOddMin = INF;

                for (int col = 0; col < nCols; col++)
                {
                    int bestColProfit = NEG_INF;
                    int chosenOdd = INF;

                    if (minOddScoreColNotFlipped[col] >= threshold)
                    {
                        bestColProfit = colFlippedSum[col];
                        chosenOdd = minOddScoreColNotFlipped[col];
                    }

                    if (minOddScoreColFlippped[col] >= threshold)
                    {
                        int profitOpt = colNotFlippedSum[col] - k;
                        if (profitOpt > bestColProfit)
                        {
                            bestColProfit = profitOpt;
                            chosenOdd = minOddScoreColFlippped[col];
                        }
                    }

                    if (bestColProfit == NEG_INF)
                    {
                        valid = false;
                        break;
                    }

                    profitSum += bestColProfit;
                    globalOddMin = min(globalOddMin, chosenOdd);
                }

                if (valid)
                {
                    bestScore = max(bestScore, baseScore + profitSum - globalOddMin);
                }
            }

            answer = max(answer, bestScore);
        }
    }

    return answer;
}

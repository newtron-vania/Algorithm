#include <string>
#include <vector>

using namespace std;

struct Point
{
    unsigned char nRow;
    unsigned char nCol;
};

union Block
{
    long int nDword;

    struct
    {
        unsigned char type;
        unsigned char number;
        Point stBaseLoc;
    };
};

bool bCheckArray[201];
Block stBlockArray[200];
int nBlockCnt;
int N;

Point GetLeftTopPoint(Block stBlock)
{
    Point p;
    if (stBlock.type == 4)
    {
        p.nRow = stBlock.stBaseLoc.nRow - 2;
        p.nCol = stBlock.stBaseLoc.nCol;
    }
    else if (stBlock.type == 7)
    {
        p.nRow = stBlock.stBaseLoc.nRow - 1;
        p.nCol = stBlock.stBaseLoc.nCol;
    }
    else if (stBlock.type == 9)
    {
        p.nRow = stBlock.stBaseLoc.nRow - 1;
        p.nCol = stBlock.stBaseLoc.nCol;
    }
    else
    {
        p.nRow = stBlock.stBaseLoc.nRow;
        p.nCol = stBlock.stBaseLoc.nCol;
    }

    return p;
}

Point GetEmptyPoint(Block stBlock, int nEmptyPointIndex)
{
    if (stBlock.type == 3)
    {
        if (nEmptyPointIndex == 0)
        {
            Point p;
            p.nRow = stBlock.stBaseLoc.nRow;
            p.nCol = stBlock.stBaseLoc.nCol + 1;
            return p;
        }
        else
        {
            Point p;
            p.nRow = stBlock.stBaseLoc.nRow;
            p.nCol = stBlock.stBaseLoc.nCol + 2;
            return p;
        }
    }

    else if (stBlock.type == 7)
    {
        if (nEmptyPointIndex == 0)
        {
            Point p;
            p.nRow = stBlock.stBaseLoc.nRow;
            p.nCol = stBlock.stBaseLoc.nCol;
            return p;
        }
        else
        {
            Point p;
            p.nRow = stBlock.stBaseLoc.nRow;
            p.nCol = stBlock.stBaseLoc.nCol + 1;
            return p;
        }
    }

    else if (stBlock.type == 9)
    {
        if (nEmptyPointIndex == 0)
        {
            Point p;
            p.nRow = stBlock.stBaseLoc.nRow;
            p.nCol = stBlock.stBaseLoc.nCol;
            return p;
        }
        else
        {
            Point p;
            p.nRow = stBlock.stBaseLoc.nRow;
            p.nCol = stBlock.stBaseLoc.nCol + 2;
            return p;
        }
    }

    else if (stBlock.type == 4)
    {
        if (nEmptyPointIndex == 0)
        {
            Point p;
            p.nRow = stBlock.stBaseLoc.nRow;
            p.nCol = stBlock.stBaseLoc.nCol;
            return p;
        }
        else
        {
            Point p;
            p.nRow = stBlock.stBaseLoc.nRow + 1;
            p.nCol = stBlock.stBaseLoc.nCol;
            return p;
        }
    }

    else
    {
        if (nEmptyPointIndex == 0)
        {
            Point p;
            p.nRow = stBlock.stBaseLoc.nRow;
            p.nCol = stBlock.stBaseLoc.nCol + 1;
            return p;
        }
        else
        {
            Point p;
            p.nRow = stBlock.stBaseLoc.nRow + 1;
            p.nCol = stBlock.stBaseLoc.nCol + 1;
            return p;
        }
    }
}

void FindBlock(vector<vector<int>>& board, int num, int row, int col)
{
    if (bCheckArray[num] == true)
        return;

    bCheckArray[num] = true;

    // type 3
    if ((col + 2 < N) && (row + 1 < N)
        && board[row + 1][col] == num && board[row + 1][col + 1] == num && board[row + 1][col + 2] == num)
    {
        stBlockArray[nBlockCnt].type = 3;
        stBlockArray[nBlockCnt].number = num;
        stBlockArray[nBlockCnt].stBaseLoc.nRow = row;
        stBlockArray[nBlockCnt].stBaseLoc.nCol = col;

        nBlockCnt++;
        return;
    }

    // type 7
    if ((col + 2 < N) && (row - 1 >= 0)
        && board[row][col + 1] == num && board[row][col + 2] == num && board[row - 1][col + 2] == num)
    {
        stBlockArray[nBlockCnt].type = 7;
        stBlockArray[nBlockCnt].number = num;
        stBlockArray[nBlockCnt].stBaseLoc.nRow = row - 1;
        stBlockArray[nBlockCnt].stBaseLoc.nCol = col;

        nBlockCnt++;
        return;
    }

    // type 9
    if ((col + 2 < N) && (row - 1 >= 0)
        && board[row][col + 1] == num && board[row][col + 2] == num && board[row - 1][col + 1] == num)
    {
        stBlockArray[nBlockCnt].type = 9;
        stBlockArray[nBlockCnt].number = num;
        stBlockArray[nBlockCnt].stBaseLoc.nRow = row - 1;
        stBlockArray[nBlockCnt].stBaseLoc.nCol = col;

        nBlockCnt++;
        return;
    }

    // type 4
    if ((col + 1 < N) && (row - 2 >= 0)
        && board[row][col + 1] == num && board[row - 1][col + 1] == num && board[row - 2][col + 1] == num)
    {
        stBlockArray[nBlockCnt].type = 4;
        stBlockArray[nBlockCnt].number = num;
        stBlockArray[nBlockCnt].stBaseLoc.nRow = row - 2;
        stBlockArray[nBlockCnt].stBaseLoc.nCol = col;

        nBlockCnt++;
        return;
    }

    // type 6
    if ((col + 1 < N) && (row + 2 < N)
        && board[row + 1 ][col] == num && board[row + 2][col] == num && board[row + 2][col + 1] == num)
    {
        stBlockArray[nBlockCnt].type = 6;
        stBlockArray[nBlockCnt].number = num;
        stBlockArray[nBlockCnt].stBaseLoc.nRow = row;
        stBlockArray[nBlockCnt].stBaseLoc.nCol = col;

        nBlockCnt++;
        return;
    }
}

bool IsRemovable(vector<vector<int>>& board, Point stPoint)
{
    for (int row = stPoint.nRow; row >= 0; row--)
    {
        if (board[row][stPoint.nCol] != 0)
            return false;
    }

    return true;
}

void CleanUpBoard(vector<vector<int>>& board, Block stBlock)
{
    int endCol = (stBlock.stBaseLoc.nCol + 3) > N ? N : (stBlock.stBaseLoc.nCol + 3);
    int endRow = (stBlock.stBaseLoc.nRow + 3) > N ? N : (stBlock.stBaseLoc.nRow + 3);

    for (int col = stBlock.stBaseLoc.nCol; col < endCol; col++)
    {
        for (int row = stBlock.stBaseLoc.nRow; row < endRow; row++)
            if (board[row][col] == stBlock.number)
                board[row][col] = 0;
    }
}

bool RemoveBlock(vector<vector<int>>& board)
{
    for (int nBlockIndex = 0; nBlockIndex < nBlockCnt; nBlockIndex++)
    {
        Block stBlock = stBlockArray[nBlockIndex];
        Point stPoint0 = GetEmptyPoint(stBlock, 0);
        Point stPoint1 = GetEmptyPoint(stBlock, 1);
        if (IsRemovable(board, stPoint0) == true && IsRemovable(board, stPoint1) == true)
        {
            CleanUpBoard(board, stBlock);
            stBlockArray[nBlockIndex].nDword = stBlockArray[nBlockCnt - 1].nDword;
            nBlockCnt--;
            return true;
        }
    }

    return false;
}

int solution(vector<vector<int>> board)
{
    int answer = 0;

    N = board.size();

    for (int col = 0; col < N; col++)
    {
        for (int row = 0; row < N; row++)
            if (board[row][col] != 0)
                FindBlock(board, board[row][col], row, col);
    }

    while (RemoveBlock(board) == true)
    {
        answer++;
    }

    return answer;
}

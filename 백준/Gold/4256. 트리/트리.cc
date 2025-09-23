#include <bits/stdc++.h>
using namespace std;

int n;
int preorder[1001], inorder[1001];
int pos[1001];

// 후위 순회 출력 (직접 재귀 함수 정의)
void postorder(int preL, int preR, int inL, int inR)
{
    if (preL > preR || inL > inR)
    {
        return;
    }

    int root = preorder[preL];
    int idx = pos[root]; // inorder에서 root 위치
    int leftSize = idx - inL;

    // 왼쪽 서브트리
    postorder(preL + 1, preL + leftSize, inL, idx - 1);

    // 오른쪽 서브트리
    postorder(preL + leftSize + 1, preR, idx + 1, inR);

    // 후위순회 출력
    printf("%d ", root);
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &preorder[i]);
        }

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &inorder[i]);
            pos[inorder[i]] = i;
        }

        postorder(0, n - 1, 0, n - 1);
        printf("\n");
    }
    return 0;
}

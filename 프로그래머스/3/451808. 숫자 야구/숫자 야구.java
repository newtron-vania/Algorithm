import java.util.function.Function;
import java.util.*;

class Solution {
    public int solution(int n, Function<Integer, String> submit) {
        List<Integer> list = new ArrayList<>();
        insertAllCase(list);

        while (list.size() != 1) {
            int num = list.get(0);
            String result = submit.apply(num);
            list = filterList(list, num, result.charAt(0) - '0', result.charAt(3) - '0');
        }

        return list.get(0);
    }

    // 3024개 전체 경우 생성
    private void insertAllCase(List<Integer> list) {
        for (int a = 1; a <= 9; a++) {
            for (int b = 1; b <= 9; b++) {
                if (a == b) continue;
                for (int c = 1; c <= 9; c++) {
                    if (a == c || b == c) continue;
                    for (int d = 1; d <= 9; d++) {
                        if (a == d || b == d || c == d) continue;
                        list.add(1000 * a + 100 * b + 10 * c + d);
                    }
                }
            }
        }
    }

    // submit 결과에 따른 list 업데이트
    private List<Integer> filterList(List<Integer> list, int num, int strike, int ball) {
        List<Integer> newList = new ArrayList<>();
        String strNum = Integer.toString(num);
        Set<Character> numSt = new HashSet<>();
        numSt.add(strNum.charAt(0));
        numSt.add(strNum.charAt(1));
        numSt.add(strNum.charAt(2));
        numSt.add(strNum.charAt(3));

        for (int ele : list) {
            String strEle = Integer.toString(ele);
            int strikeCnt = 0;
            int ballCnt = 0;

            for (int i = 0; i < 4; i++) {
                if (strNum.charAt(i) == strEle.charAt(i)) {
                    strikeCnt++;
                } else if (numSt.contains(strEle.charAt(i))) {
                    ballCnt++;
                }
            }

            if (strikeCnt == strike && ballCnt == ball) {
                newList.add(ele);
            }
        }

        return newList;
    }
}
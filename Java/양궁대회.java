package Algorithm;

class Solution {
    static private int[] result = new int[11]; //점수차가 최대일 때, 라이언이 쏜 화살 배열
    static private int[] lion = {-1}; //정답을 출력할 배열
    static private int max = Integer.MIN_VALUE; //최대 값을 담아 놓을 변수
    public int[] solution(int n, int[] info) {
        back(0, n, info);//라이언이 쏜 화살에 대한 조합
        if (max == -1) {//라이언이 어피치를 못 이길떄 (max가 계속해서 -1일 때)
            lion = new int[1];
            lion[0] = -1;
        }
        return lion;
    }
    public static void back(int depth, int n, int[] info) { //조합 찾기
        if (depth == n) { //화살 다 꽂았을때
            int diff = score(info);//점수차 구하기
            if (max <= diff) {//점수차 최대값 갱신
                max = diff;
                lion = result.clone(); //최대값을 갱신했을 때의 result 값을 lion에 클론으로 생성시키기
            }
            return;
        }
        //result[i]<=info[i] -> i 과녁에 라이언이 화살을 더 많이 맞추면 반복문 종료한다.
        for (int i = 0; i < info.length && result[i] <= info[i]; i++) { //백트래킹 (조합 찾기)
            result[i] += 1; //다음 조합을 찾아 +1 해주기
            back(depth + 1, n, info);
            result[i] -= 1; //모두 실행되고나면 다음 조합을 찾기 위해 한 단계 전으로 되돌리기
        }
    }
    //점수차 구하기
    public static int score(int[] info) {
        int apeach = 0, lion = 0; //초기화
        for (int i = 0; i < result.length; i++) {
            if (info[i] == 0 && result[i] == 0) continue;//i원소에 둘다 0개 맞췄을땐 무시.
            if (info[i] >= result[i]) apeach += (10 - i); //라이언보다 어피치가 더 많이 맞췄으면 어피치에게 점수
            else lion += (10 - i); //아니면 라이언에게 점수 주기
        }
        int diff = lion - apeach; //점수 차 구학
        if (diff <= 0) return -1; //차이가 음수면 라이언이 진거므로 -1을 리턴
        return diff;
    }
}

package Algorithm;
public class Main {
    public static void main(String[] args) {
        String s = "one4seveneight";
        Solution sl = new Solution();
        int answer = sl.solution(s);
        System.out.println(answer);
    }
}

class Solution {
    String[] word = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    String[] wti = {"0","1","2","3","4","5","6","7","8","9"};

    public int solution(String s) {
        int answer = 0;
        String sb = "";
        String result = "";
        for (int i = 0; i < s.length(); i++) { //주어진 문자열만큼 반복
            sb = sb + s.substring(i,i+1);
            for (int j = 0; j < word.length; j++) { //검사하기위해 0~9까지 반복
                if(sb.equals(word[j])) {
                    result = result + wti[j];
                    sb = "";
                }
                else if (sb.equals(wti[j])) {
                    result = result + wti[j];
                    sb = "";
                }
            }
        }
        answer = Integer.parseInt(result);
        return answer;
    }
}
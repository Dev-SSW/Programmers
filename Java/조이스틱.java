package Algorithm;

class Solution {
    public int solution(String name) {
        int answer = 0;
        // 오른쪽으로 쭉 가는 경우 조이스틱을 움직인 수
        int cost = name.length() - 1;
        for (int i = 0; i < name.length(); i++) {
            char dst = name.charAt(i);
            int count = 0;
            if (dst != 'A') { //각 글자의 조이스틱 최소 움직임 수를 구하는 조건문
                count = min(dst); //정방향으로 갔을 때와 역방향으로 갔을 때 중 최소인 것을 count에 저장
            }
            answer += count; //최종적으로 최소인 값을 answer에 더해준다. (다른 글자들도 만들어줘야하므로) A이면 count = 0이다.
            // 왼쪽으로 돌아가는 경우 조이스틱을 움직인 수
            int nextIndex = i + 1;

            // 연속된 A가 끝난 인덱스가 nextIndex
            while (nextIndex < name.length() && name.charAt(nextIndex) == 'A')
                nextIndex++; //i+1부터 nextIndex가 'A'가 아닐 때까지  반복, (name의 길이를 벗어나지 않는 선에서)
            // i * 2를 통해 0번 인덱스까지 돌아가는 횟수를 구한다.
            // 그리고 name.length()에서 nextIndex를 빼 0에서 뒤로 가는데 필요한 횟수를 구한다.
            cost = Math.min(cost, (i * 2) + name.length() - nextIndex);
            cost = Math.min(cost, (name.length() - nextIndex) * 2 + i);
            cost = Math.min((i * 2) + name.length() - nextIndex, (name.length() - nextIndex) * 2 + i);
            //정방향으로 갔을 때의 cost와 비교
            //i * 2의 이유, JBXAAAAAAB의 경우 현 위치가 만약 X일 때, JBX로 움직였다가 다시 XBJ로 돌아가므로, 왔다갔다를 해서
            //*2를 해주는 것이다. 그 다음에 name.length()에서 nextIndex를 빼면 오른쪽 마지막 문자열부터 nextIndex까지의
            //거리를 구할 수 있다.
            //결론, 반복문을 통해서 각 문자열로 가는 최소를 min함수로 구하고, 왼쪽으로 갈지 오른쪽으로 갈지에 대한 최소를
            //while문과 Math.min을 통해 구한 후 두 최소값을 answer에 더해준다.
            //각 문자열의 최소는 바로 더해줘도 상관 없지만 조이스틱 왼쪽 오른쪽은 가장 최소인 것을 더해줘야하므로 나중에 더해준다.
            //생각해볼 테스트 케이스 AAAAAABB, BABAAAAABB, BBBBBBAA 세 개정도
            //for문을 계속 돌며 현재 인덱스에서 좌우 조이스틱을 어디로 움직여야 최소인지를 계속해서 탐색한다.
        }
        answer += cost;
        return answer;
    }

    public int min(char dst) {
        return Math.min(dst - 'A', ('Z' - 'A' + 1) - (dst - 'A'));
        //JAZ라고 했을 때, J에서 A까지의 거리가 더 빠른지, 아니면 반대로 갔을 때가 빠른지를 확인하는 함수
        //Z에서 A까지의 거리 + 1 에서 J에서 A까지의 거리를 빼면 Z에서 J까지의 거리가 나온다.
        //한번 더 가야지 J가 적용되므로 + 1를 한 것이다.
    }
}

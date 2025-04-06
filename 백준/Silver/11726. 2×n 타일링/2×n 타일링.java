

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Integer.parseInt;

public class Main {

    static final int DIVIDER = 10_007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = parseInt(br.readLine());

        Long[] arr = new Long[N+1];
        arr[1] = 1L;
        if(N >= 2)arr[2] = 2L;
        for(int i=3;i<=N;i++){
            arr[i] = (arr[i-1]+ arr[i-2]) % DIVIDER;
        }
        System.out.println(arr[N]);
    }
}

// dp[i] = dp[i-1] + dp[i-2]
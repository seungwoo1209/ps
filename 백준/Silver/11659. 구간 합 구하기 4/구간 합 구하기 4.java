

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Integer.parseInt;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = parseInt(st.nextToken());
        int cases = parseInt(st.nextToken());

        int[] arr = new int[N+1];
        st = new StringTokenizer(br.readLine());
        for(int i=1;i<=N;i++){
            arr[i] = parseInt(st.nextToken());
        }

        int[] sum = new int[N+1];
        sum[1] = arr[1];
        for(int i=2;i<=N;i++){
            sum[i] = sum[i-1] + arr[i];
        }

        StringBuilder sb = new StringBuilder();
        for(int i=1;i<=cases;i++){
            st = new StringTokenizer(br.readLine());
            int start = parseInt(st.nextToken());
            int end = parseInt(st.nextToken());
            sb.append(sum[end] - sum[start-1]).append("\n");
        }

        System.out.println(sb);

    }

}

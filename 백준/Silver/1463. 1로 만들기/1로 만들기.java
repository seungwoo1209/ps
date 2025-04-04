
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import static java.lang.Integer.parseInt;
import static java.lang.Math.min;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = parseInt(br.readLine());

        int[] arr = new int[1_000_001];
        arr[1] = 0;
        arr[2] = 1;
        arr[3] = 1;
        for(int i=4;i<=1_000_000;i++){
            int i1 = (i % 2 == 0) ? arr[i/2] : Integer.MAX_VALUE;
            int i2 = (i % 3 == 0) ? arr[i/3] : Integer.MAX_VALUE;
            int i3 = arr[i-1];
            int min = min(i3,min(i1, i2));
            arr[i] = min + 1;
        }

        System.out.println(arr[N]);
    }

}

//N에 대해 최솟값 arr[N] 은 min(arr[N/3] if N is divided by 3, arr[N/2] if N is divided by 2, arr[N-1]) + 1

// int 1000 * 1000 * 32 => 32MB
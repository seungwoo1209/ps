

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

import static java.lang.Integer.parseInt;
import static java.lang.Math.min;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = parseInt(br.readLine());
        int[] arr = new int[11];
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 4;
        for(int i=4;i<=10;i++){
            arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
        }

        for(int i=0;i<T;i++){
            int n = parseInt(br.readLine());
            System.out.println(arr[n]);
        }

    }

}

// 4
// (1)
// 1 1 1
// 2 1
// 1 2
// 3 1

// (2)
// 1 1
// 2

// (1)
// 1 3

// arr[N] = (arr[N-1], 1) + (arr[N-2], 2) + (arr[N-3] + 3)
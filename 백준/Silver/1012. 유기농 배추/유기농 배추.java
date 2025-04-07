

import jdk.jfr.Unsigned;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Integer.parseInt;

public class Main {

    static boolean[][] arr;
    static int M;
    static int N;
    static int K;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            M = parseInt(st.nextToken());
            N = parseInt(st.nextToken());
            K = parseInt(st.nextToken());

            arr = new boolean[M][N];

            for (int j = 0; j < K; j++) {
                st = new StringTokenizer(br.readLine());
                int x = parseInt(st.nextToken());
                int y = parseInt(st.nextToken());
                arr[x][y] = true;
            }

            int neededBugs = 0;
            for (int k = 0; k < M; k++) {
                for (int l = 0; l < N; l++) {
                    if (arr[k][l]) {
                        mark(k, l);
                        neededBugs++;
                    }
                }
            }

            System.out.println(neededBugs);
        }
    }

    // limit: k : m-1 l: n-1
    static void mark(int k, int l) {
        arr[k][l] = false;
        if (k < M - 1 && arr[k + 1][l]) {
            mark(k + 1, l);
        }
        if (l < N - 1 && arr[k][l + 1]) {
            mark(k, l + 1);
        }
        if (k > 0 && arr[k - 1][l]) {
            mark(k - 1, l);
        }
        if (l > 0 && arr[k][l - 1]) {
            mark(k, l - 1);
        }
    }
}


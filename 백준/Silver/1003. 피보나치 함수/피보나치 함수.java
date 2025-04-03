

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.stream.IntStream;

import static java.lang.Integer.parseInt;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = parseInt(br.readLine());

        Pair[] arr = new Pair[41];
        arr[0] = new Pair(1,0);
        arr[1] = new Pair(0,1);

        for(int i=2; i<=40;i++){
            arr[i] = new Pair(arr[i-1],arr[i-2]);
        }

        StringBuilder sb = new StringBuilder();
        for(int i=0;i<T;i++){
            int N = parseInt(br.readLine());
            sb.append(arr[N].first).append(" ").append(arr[N].second).append("\n");
        }
        System.out.println(sb);
    }

}

class Pair {
    public int first;
    public int second;

    Pair(int first, int second){
        this.first = first;
        this.second = second;
    }

    Pair(Pair fp, Pair sp){
        this.first = fp.first + sp.first;
        this.second = fp.second + sp.second;
    }
}

//0 -> 1 0
//1 -> 0 1
//2 -> f(1) + f(0)
//3 -> f(2) + f(1)
//4 -> f(3) + f(2)
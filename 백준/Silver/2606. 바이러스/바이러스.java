

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

        int N = parseInt(br.readLine());

        ArrayList<HashSet<Integer>> list = new ArrayList<>();

        int M = parseInt(br.readLine());
        for (int i = 0; i < M; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int first = parseInt(st.nextToken());
            int second = parseInt(st.nextToken());

            ArrayList<HashSet<Integer>> temp = new ArrayList<>();
            for (HashSet<Integer> hs : list) {
                if (hs.contains(first) || hs.contains(second)) {
                    temp.add(hs);
                }
            }

            if(temp.size() == 1){
                HashSet<Integer> set = temp.get(0);
                set.add(first);
                set.add(second);
            } else if (temp.size() == 2){
                HashSet<Integer> set1 = temp.get(0);
                HashSet<Integer> set2 = temp.get(1);
                set1.addAll(set2);
                list.removeIf((set) -> (set == set2));
            } else if(temp.isEmpty()) {
                list.add(new HashSet<>(Arrays.asList(first, second)));
            }
        }



        boolean flag = false;
        for (HashSet<Integer> hs : list) {
            if (hs.contains(1)) {
                System.out.println(hs.size() - 1);
                flag = true;
                break;
            }
        }
        if(!flag){
            System.out.println(0);
        }

    }

}

//7
//13
//1 2
//1 3
//1 4
//1 5
//1 6
//1 7
//2 1
//2 2
//2 3
//2 4
//2 5
//2 6
//2 7
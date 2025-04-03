

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

        int N = parseInt(br.readLine());
        ArrayList<Integer> list = new ArrayList<>(N);

        String times = br.readLine();
        StringTokenizer st = new StringTokenizer(times);
        while(st.hasMoreTokens()){
            list.add(parseInt(st.nextToken()));
        }
        Collections.sort(list);

        IntStream.range(1,list.size())
                .forEach(i -> list.set(i, list.get(i) + list.get(i-1)));

        int sum = list.stream().mapToInt(Integer::intValue).sum();
        System.out.println(sum);

//
//        for(int i=1;i<N;i++){
//            list.set(i,list.get(i) + list.get(i-1));
//        }

//        list.forEach(System.out::println);
    }

}

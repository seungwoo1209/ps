

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int M = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < M; i++) {
            String line = br.readLine();
            String[] arr = line.split("\\s");
            String op = arr[0];
            int value;
            if(arr.length >= 2) {
                value  = Integer.parseInt(arr[1]);
            } else {
                value = -1;
            }

            if(op.equals("add")){
                mySet.add(value);
            } else if (op.equals("remove")){
                mySet.remove(value);
            } else if (op.equals("check")){
                sb.append(mySet.check(value));
                sb.append("\n");
            }else if (op.equals("toggle")){
                mySet.toggle(value);
            }else if (op.equals("all")){
                mySet.all();
            }else if (op.equals("empty")){
                mySet.empty();
            }
        }

        System.out.println(sb);

    }

}

class mySet {

    static Long bits = 0L;

    static void add(int value) {
        bits = bits | 1L << (value-1);
    }

    static void remove(int value) {
        bits = bits & ~(1L << (value-1));
    }

    static int check(int value) {
        return (int) ((bits >> (value-1)) & 1);
    }

    static void toggle(int value) {
        bits = bits ^(1L << (value-1));
    }

    static void all() {
        bits = bits | 0b11111_11111_11111_11111;
    }

    static void empty() {
        bits = 0L;
    }

}


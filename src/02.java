import java.util.Scanner;
//import java.util.Arrays;
import java.util.Map;
import java.util.HashMap;

class MyClass {
    public static void main(String[] args) {
        String[] colors = {"red", "green", "blue"};
        int[] maximums = {12, 13, 14};
        Scanner sc = new Scanner(System.in);
        int answer1 = 0, answer2 = 0;
        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            String[] dotsSplit = line.split(":");
            assert(dotsSplit.length == 2);
            int gameNumber = Integer.parseInt(dotsSplit[0].substring(5));
            String[] parts = dotsSplit[1].split("; ");
            boolean valid = true;
            Map<String, Integer> minimumBallCount = new HashMap<String, Integer>();
            for (String color : colors) {
                minimumBallCount.put(color, 0);
            }
            for (String part : parts) {
                String[] balls = part.split(", ");
                Map<String, Integer> ballCount = new HashMap<String, Integer>();
                for (String color : colors) {
                    ballCount.put(color, 0);
                }
                for (String ballTmp : balls) {
                    String[] ball = ballTmp.strip().split(" ");
                    String ballColor = ball[1];
                    int ballNumber = Integer.parseInt(ball[0]);
                    ballCount.put(ballColor, ballCount.get(ballColor) + ballNumber);
                }
                for (int i = 0; i < 3; i++) {
                    if (ballCount.get(colors[i]) > maximums[i]) {
                        valid = false;
                        break;
                    }
                }
                for (String color : colors) {
                    minimumBallCount.put(color, Math.max(minimumBallCount.get(color), ballCount.get(color)));
                }
            }
            if (valid) {
                answer1 += gameNumber;
            }
            answer2 += minimumBallCount.get("red") * minimumBallCount.get("green") * minimumBallCount.get("blue");
            //System.out.println(Arrays.toString(parts));
        }
        System.out.println(answer1); //199 too low
        System.out.println(answer2);
        sc.close();
    }
}
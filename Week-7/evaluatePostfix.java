import java.util.*;

public class evaluatePostfix {
    public static int evalPostfix(String expression) {
        Stack<Integer> st = new Stack<>();

        String[] tokens = expression.split(" ");

        for (String token : tokens) {

            if (token.equals("+") || token.equals("-") ||
                token.equals("*") || token.equals("/")) {

                int b = st.pop();
                int a = st.pop();

                int result = 0;

                switch (token) {
                    case "+":
                        result = a + b;
                        break;

                    case "-":
                        result = a - b;
                        break;

                    case "*":
                        result = a * b;
                        break;

                    case "/":
                        result = a / b;
                        break;
                }

                st.push(result);
            } 
            else {
                st.push(Integer.parseInt(token));
            }
        }

        return st.pop();
    }
    public static void main(String[] args) {
        String a = "1 2 + 3 *";
        System.out.println(evalPostfix(a));
    }
}
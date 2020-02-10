import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int lsum = lineSum(i);
            if(i + lsum == n) {
                ans = i;
                break;
            }
        }
        System.out.println(ans);
    }
	
    private static int lineSum(int n) {
        int sum = 0;
        while(n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
}

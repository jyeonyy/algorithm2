import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] x = new int[n];
        int[] y = new int[n];
        int[] ans = new int[n];
        for(int i = 0; i < n; i++) {
            x[i] = scan.nextInt();
            y[i] = scan.nextInt();
        }
		
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j)
                    continue;
                if(x[i] < x[j] && y[i] < y[j])
                    ans[i]++;
            }
        }
		
        for(int rank : ans) {
            System.out.print((rank+1) + " ");
        }
    }	
}

import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		Scanner sc = new Scanner(System.in);
		boolean stop = false;
		while(!stop) {
			int N = sc.nextInt();
			if(N==0) {
				stop = true;
				break;
			}
				
			int[] nums = new int[N];
			for (int i=0; i<N; i++) {
				nums[i] = sc.nextInt();
				
			}
			int[] me = new int [6];
			puts(nums,me,0,0);
			System.out.println();
			
		}
		
	}
	
	public static void puts(int[] nums, int[] me, int idx, int cnt) {
		
		if(idx > nums.length-1)
			return;
		
		int[] nme = me.clone();
		nme[cnt] = nums[idx];
		cnt ++;
		
		
		if(cnt == 6) {
			for (int j=0; j<6; j++) {
				System.out.print(nme[j] + " ");
			}
			System.out.println();
			puts(nums,me,idx+1,cnt-1);
			return;
		}
		
		puts(nums,nme,idx+1,cnt);
		puts(nums,me,idx+1,cnt-1);
		
	}

}

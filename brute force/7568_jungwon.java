import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
        
        	Scanner sc = new Scanner(System.in);
			int T;
            T=sc.nextInt();
        Man[] mList = new Man[T];

        for(int i=0; i<T; i++) {
            int w = sc.nextInt();
            int h = sc.nextInt();
            mList[i] = new Man(w,h);
            
        }
        
        for (int j=0; j<T; j++) {
        	
        	for(int h=0; h<T; h++) {
        		mList[j].setRank(mList[h].w,mList[h].h);
        		
        	}
        }
        
    	for(int h=0; h<T; h++) {
   		 System.out.println(mList[h].r);
   		
   	}
        
        
        
        
        
        
    }
}

class Man{
    int w;
    int h;
    int r;
    
    Man(int w, int h){
        this.w = w;
        this.h = h;
        this.r = 1;
        }
    
    void setRank(int w, int h){
    	if( this.w < w && this.h < h) this.r += 1;
    }
    
};

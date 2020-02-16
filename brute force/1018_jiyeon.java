import java.util.*;
 
public class BaekJoon1018 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int Min = M*N;
        char[][] Chess = new char[N][M];
        char[][] Test1 = {{'W','B','W','B','W','B','W','B'},{'B','W','B','W','B','W','B','W'},
                        {'W','B','W','B','W','B','W','B'},{'B','W','B','W','B','W','B','W'},
                        {'W','B','W','B','W','B','W','B'},{'B','W','B','W','B','W','B','W'},
                        {'W','B','W','B','W','B','W','B'},{'B','W','B','W','B','W','B','W'}};
        char[][] Test2 = {{'B','W','B','W','B','W','B','W'},{'W','B','W','B','W','B','W','B'},
                        {'B','W','B','W','B','W','B','W'},{'W','B','W','B','W','B','W','B'},
                        {'B','W','B','W','B','W','B','W'},{'W','B','W','B','W','B','W','B'},
                        {'B','W','B','W','B','W','B','W'},{'W','B','W','B','W','B','W','B'}};
        for( int i = 0 ;i < N ; i++){
            String line = sc.next();
            for(int j = 0; j < M ; j++){
                Chess[i][j] = line.charAt(j);
            }
        }
        for(int i =0 ; i < N-7 ; i++) {
            for (int j = 0; j < M - 7; j++) {
                int ChangeCount1 = 0;
                int ChangeCount2 = 0;
                int Exchange=0;
                for(int x = 0; x < 8;x++){
                    for(int y = 0; y < 8 ; y++){
                        if(Chess[i+x][j+y] != Test1[x][y]){
                            ChangeCount1++;
                        }
                    }
                }
                for(int x = 0; x < 8;x++){
                    for(int y = 0; y < 8 ; y++){
                        if(Chess[i+x][j+y] != Test2[x][y]){
                            ChangeCount2++;
                        }
                    }
                }
                Exchange = (ChangeCount1>ChangeCount2) ? ChangeCount2 : ChangeCount1;
                if(Min > Exchange) Min = Exchange;
            }
        }
                System.out.print(Min);
        
 
    }
}

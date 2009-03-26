package uno;
import java.util.*;

public class miclase{
	int la;
	int lb;
	String lc[];
	
	miclase(){
		lc = 0;
		la = 1;
		lb = 2;
	}
	
	miclase(int a, int b){
		la = a;
		lb = b;
	}

	public static void main(String args[]){
		if(la>lb){
			miclase m = new miclase(1,2);
		}
		else{
			for(int i = 0; i < 10; i++){
				int j;
				while( j < 100 || (i + 10) > 30) {
					switch (j){
					case 10:						
						miclase m = new miclase(1,2);					
						j = 1+la;
					break;
					case 20:
						miclase m = new miclase(1,2);
						j = 1+lb;
					break;
					default:
						miclase m = new miclase(1,2);
						j = 1+lc;			
					}
				}
			}
		}
		System.out.println(la + lb + lc);
	}
}
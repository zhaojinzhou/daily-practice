package abstractfatory;

import java.util.Scanner;

public class io {
	public static void main(String[] args) {
		System.out.println("pls input a choose 1:chrismas man? 2:chrismas woman? 3:newyear man? 4:newyear woman?");
		Scanner in =new Scanner(System.in);
		while(in.hasNext()){
			String string=in.nextLine();
			
			if(string.equals("1")){
				personfactory personfactory1=new chrismasfactory();
				man man1=personfactory1.createman();
				man1.drawman();
				
				
			}
			else if(string.equals("2")){
				personfactory personfactory1=new chrismasfactory();
				woman women1=personfactory1.createwoman();
				women1.drawwoman();
			}
			else if(string.equals("3")){
				personfactory personfactory1=new newyearfatory();
				man man1=personfactory1.createman();
				man1.drawman();
				
			}
			else if(string.equals("4")){
				personfactory personfactory1=new newyearfatory();
				woman women1=personfactory1.createwoman();
				women1.drawwoman();
			}
			else {
				System.err.println("input error");
			}
			
				
		}
		
		
		
	}

}

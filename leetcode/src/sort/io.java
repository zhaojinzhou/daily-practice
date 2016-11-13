
package sort;

import java.util.Scanner;

public class io {
		
	public static void main(String[] args) {
		int size = 0;
		
		System.out.println("pls input the size of array and then the name of sort algorithm");
		Scanner in=new Scanner(System.in);
		try {
			while (in.hasNext()) {
				 size = (int) in.nextInt();
				 
				 if (in.hasNext()) {
					String name = in.nextLine();
					name=name.trim();
					System.out.println(name);
					factory factory = new factory();
					sortinterface tmp = factory.sorting(name);
					if(tmp==null) {
						System.out.println("input error");
						return ;
						}
					int []a = new int[size];
					for (int i = 0; i < size; i++) {
						a[i] = (int) (Math.random() * size);
					}
					for (int i : a) {
						System.out.print(i + " ");
					}
					System.out.println();
					tmp.sort(a, size);
					for (int i : a) {
						System.out.print(i + " ");
					}
					System.out.println();
				}
					
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		
	}

}

package sort;

public class factory {
	public sortinterface sorting(String key) {
		
		if("quicksort".equals(key)) {
			sortinterface tmp=new quicksort();
			return tmp;	
			
		}
		if("heapsort".equals(key)) {
			sortinterface tmp=new heapsort();
			return tmp;	
			
		}
		if("mergesort".equals(key)) {
			sortinterface tmp=new mergesort();
			return tmp;	
			
		}
		if("shellsort".equals(key)) {
			sortinterface tmp=new shellsort();
			
			return tmp;			
		}
		//System.out.println("input error");
		return null;
		
		
		
	}

}

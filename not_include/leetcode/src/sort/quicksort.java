package sort;



public class quicksort implements sortinterface {
	
	public  void quicksorts(int[] a,int left, int right)
	{
		if(left>right) return ;
		int i=left,j=right,tmp=a[left];
		while(i!=j){
			while(i<j&&a[j]>=tmp){
				--j;
			}
			while(i<j&&a[i]<=tmp){
				++i;
			}
			if(i!=j){
				int tmp1=a[i];
				a[i]=a[j];
				a[j]=tmp1;
			}
			
				
		}
		a[left]=a[i];
		a[i]=tmp;
		quicksorts(a,left,i-1);
		quicksorts(a,i+1,right);
			
	}

	public void sort(int[] a, int size) {
		quicksorts(a,0,size-1);
		// TODO Auto-generated method stub
		
	}
}

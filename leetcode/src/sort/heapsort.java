package sort;

public class heapsort implements sortinterface {

	@Override
	public void sort(int[] a, int size) {
		// TODO Auto-generated method stub
		heapsorts(a,size);

	}
	

	private void heapsorts(int[] a, int size) {
		// TODO Auto-generated method stub
		while(size>0){
			for(int i=(size-2)/2;i>=0;i--){
				heapfilter(a,i,size);
				
			}
			int tmp=a[0];
			a[0]=a[size-1];
			a[size-1]=tmp;
			size--;
		}
	}


	private void heapfilter(int[] a, int left, int size) {
		// TODO Auto-generated method stub
		int j=left*2+1;
		while(j<size&&j+1<size){
			if(a[left]<a[j]&&a[left]<a[j+1]) return;
			if(a[j+1]<a[j]) {
				int tmp=a[j+1];
				a[j+1]=a[left];
				a[left]=tmp;
			}
			else{
				int tmp=a[j];
				a[j]=a[left];
				a[left]=tmp;
			}
			j=2*left+1;
		}
		while(j<size&&a[left]>a[j])	{
			int tmp=a[j];
			a[j]=a[left];
			a[left]=tmp;
		}	
	}

}

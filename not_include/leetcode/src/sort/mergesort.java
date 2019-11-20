package sort;

public class mergesort implements sortinterface {
	public  void meergearray(int[] a, int left,int mid ,int right , int []tmp) {
		// TODO Auto-generated method stub
		int i=left,j=mid+1,k=0;
		while(i<=mid&&j<=right){
			if(a[j]<a[i]){
				tmp[k++]=a[j++];
				
			}
			else{
				tmp[k++]=a[i++];
			}
		}
		while(i<=mid){
			tmp[k++]=a[i++];
		}
		while(j<=right){
			tmp[k++]=a[j++];
		}
		
		for(int m=0;m<k;m++){
			a[left+m]=tmp[m];
		}
		
	}
	
	public  void meergeee(int[] a, int left,int right, int []tmp) {
		// TODO Auto-generated method stub
		int mid=(left+(right-left)/2);
		if(left<right){
			meergeee(a, left, mid, tmp);
			meergeee(a, mid+1, right, tmp);
			meergearray(a, left, mid, right, tmp);
		}
	}

	private void mergesorts(int[] a, int size) {
		int [] tmp= new int [size];
		// TODO Auto-generated method stub
		meergeee(a,0,size-1,tmp);
	}
	public void sort(int[] a, int size) {
		mergesorts(a,size);
		// TODO Auto-generated method stub

	}

}

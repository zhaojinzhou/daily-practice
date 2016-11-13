package sort;

public class shellsort implements sortinterface {

	@Override
	public void sort(int[] a, int size) {
		// TODO Auto-generated method stub
		for(int gap=size/2;gap>0;gap/=2)
			for(int j=gap;j<size;j++)
				for(int i=j-gap;i>=0&&a[i+gap]<a[i];i-=gap)
				{
					int tmp=a[i];
					a[i]=a[i+gap];
					a[i+gap]=tmp;
				}

	}
	
	

}

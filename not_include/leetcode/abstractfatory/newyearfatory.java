package abstractfatory;

public class newyearfatory implements personfactory{

	@Override
	public man createman() {
		// TODO Auto-generated method stub
		man man1= new newyearfatoryman();
		return man1;
	}

	@Override
	public woman createwoman() {
		// TODO Auto-generated method stub
		woman woman1=new newyearfatorywoman();
		return woman1;
	}

	
	

}

package abstractfatory;

public class chrismasfactory implements personfactory{
	
	public man createman() {
		// TODO Auto-generated method stub
		man man1= new chrismasfactoryman();
		return man1;
	}
	@Override
	public woman createwoman() {
		// TODO Auto-generated method stub
		woman woman1= new chrismasfactorywoman();
		return woman1;
	}

}

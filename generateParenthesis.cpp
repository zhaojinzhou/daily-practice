import java.util.LinkedList;
import java.util.List;

public class Solution {
    public List<String> generateParenthesis(int n) {
        
        List<String> ret = new LinkedList<String>();
		String tmp = "";
		generateParenthesis(n, n, tmp, ret);
		return ret;   
    }
    
    public void generateParenthesis(int left, int right, String tmp, List<String> ret) {
		
		if (left == 0 && right == 0) {
			ret.add(tmp);
			return;
		}
		
		if (left != 0) generateParenthesis(left - 1, right, tmp + "(", ret);
		
		if (left < right) { //the end condition of the program is the right bracket first

			generateParenthesis(left, right - 1, tmp + ")", ret);
		}
	}
    
    public static void main(String [] args){
    	Solution so=new Solution() ;

    	List<String> ret = new LinkedList<String>();
    	ret=so.generateParenthesis(3);
    	for (int i=0;i<ret.size();i++){
    		System.out.println(ret.get(i));
    		
    	}
    	
    } 
}
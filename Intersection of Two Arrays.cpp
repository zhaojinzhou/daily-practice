#include <iostream>
#include<vector> 
using namespace std;
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
       	
       	vector<int>::iterator it4=unique(nums1.begin(),nums1.end());
       	vector<int>::iterator it=nums1.begin();
		sort(nums2.begin(),nums2.end());
        
        vector<int>::iterator it2=unique(nums2.begin(),nums2.end());
        vector<int>::iterator it1=nums2.begin();
       
      
        vector<int> intersect;
       
        for (it=nums1.begin();it<it4;it++)
        {
        	for (it1=nums2.begin();it1<it2;it1++){	
			
	       		if (*it1==*it) {
        		
				intersect.push_back(*it1);
        		}
			}
        }
	return intersect;	
}
        




int main(int argc, char *argv[])
{
	int jin[]={1,2,7,8,9,6,6,5,3,3,3,2,34,54,76,7,2,7,7};
	int jin1[]={1,2,7,8,9,6,6,5,3,3,3,2,34,54,76,7,2,7,7};
	vector<int> a(jin,jin+sizeof(jin)/sizeof(*jin));
	vector<int> b(jin1,jin1+sizeof(jin1)/sizeof(*jin1));
	
	
	vector<int> c;
	c=intersection(a,b);
	vector<int>::iterator it=c.begin();
	for (;it<c.end();it++)
	cout<<*it<< ' ';

	
	
	return 0;
}
	

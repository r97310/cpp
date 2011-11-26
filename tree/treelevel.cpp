/* Any extra functions you would like to add, code here*/
vector<long> sum (10000,0);
int printSum(node *p, int level){
	if(p==NULL)
		return level;
	if(level == 0){		
		sum[0] = p->val;
		printSum(p->left,level+1);
		printSum(p->right, level+1);	
	}	
	else{
		sum[level] += p->val;
		printSum(p->left,level+1);
		printSum(p->right,level+1);
	}	
}



void sumEachLevel(node * root) {
/* For your reference
   struct node {
	struct node *left,*right;
	int val;
};
*/
	
	int level = printSum(root, 0);
	for(int i=0;i<level;i++)
		cout<<sum[i]<<endl;
}

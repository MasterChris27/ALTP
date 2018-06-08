
int f(int x,int y){

	int r,j;
	r=x;
	j=y;
	if(r==j){
		return r; 
	}else{
		return j;
	}

};

main() {

	int b=10,c;

	int a=5,i;  

	int r=1,d=0;	
	int g=0;
    int f1,f2;

	if(b==22){
		if(c==1){	
			i=10;
		}else {
			i=2;
		}
	 }


	for(i=0;i<5;i++){

		a=a+i;
	}

	while(r<5){
		d++;
		r++;
	}


	while(c<5){

		for(i=0;i<5;i++){
			g=g+i;
		}
	
	c++;

	}

	f1=f(a,b);
    f2=f(c,i);



}

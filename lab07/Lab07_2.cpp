#include<iostream>
#include<cstring>
#include<cstdlib>
#include<iomanip>
using namespace std;
int main(){
	bool flag;
	char input[100];
	while(cin.getline(input,100)){
		if(strlen(input)==0){
			cout<<0<<endl;
			break;
		}
		for(int i = 1 ;i<=strlen(input);i++){
			flag = true;
			for (int j = i; j < strlen(input); j ++)
				if (input[j]!= input[j % i]){
		        	flag = false;
		        	break;
				}
		    
		 	if(flag&&strlen(input)% i ==0){
		 		cout<< i <<endl;
				break;	
			}
		}
	}
}

 

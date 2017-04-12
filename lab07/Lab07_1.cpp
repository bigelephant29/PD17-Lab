#include<iostream>
#include<cstring>
#include<cstdlib>
#include<iomanip>
using namespace std;
void deleteDirtyCode(char *p){
	for(int i=0;i<strlen(p);i++){
		if(p[i] =='&'||p[i] =='$'||p[i]=='%'||p[i]=='^'||p[i]=='*'){
			for(int j =i+1;j<=strlen(p);j++){
				p[j-1]=p[j];
			}
			i -- ;
		}
	}
}
int main(){
	char input[100];
	while(cin.getline(input,100)){
		deleteDirtyCode(input);
		cout<<input<<endl;
	}	
	return 0;
}

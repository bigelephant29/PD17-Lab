#include<iostream>
using namespace std;
int* addingTrans(int* hist,int num, int remain);
class Deposit{
	private:
		int  remainDeposit;
		int  transNum;
		int* historyNum;
	public:
		Deposit(int num);
		void  depositShow();
		void  withdrawal(int withdrawalNum);
		void  save(int saveNum);
		void  transcationShow();
		~ Deposit();
};
int main(){
	int initial,option,savings,withdrawals;
	cin >> initial;
	Deposit account(initial);
	while(cin>>option){
		if(option == 1){
			account.depositShow();
		}
		else if(option ==2){
			account.transcationShow();
		}
		else if(option==3){
			cin>>savings;
			account.save(savings);
		}
		else if(option==4){
			cin>>withdrawals;
			account.withdrawal(withdrawals);
		}
		else if(option == 5){
			account.~Deposit();
		}
		else{
			cout<<"System error";
		}
	}
	return 0;
}
Deposit::Deposit(int num){
	remainDeposit = num ;
	transNum = 0 ;
	historyNum = new int[1];
	historyNum[0] = num ;
}
void Deposit::withdrawal(int withdrawalNum){
	remainDeposit = remainDeposit - withdrawalNum;
	historyNum = addingTrans(historyNum,transNum,remainDeposit);
	transNum ++ ;
}

void Deposit::save(int saveNum){
	remainDeposit = remainDeposit + saveNum;
	historyNum = addingTrans(historyNum,transNum,remainDeposit);
	transNum ++ ;
} 
void Deposit::depositShow(){
	cout<<"Remain Balance is "<<remainDeposit<<endl;
} 
void Deposit::transcationShow(){
	cout<<"History Balance is ";
	for(int i = 0; i < transNum; i++){
		cout<< historyNum[i]<<" ";
	}
	cout<<historyNum[transNum]<<endl;
}
Deposit::~Deposit(){
	delete[] historyNum;
}
int* addingTrans(int hist[],int num,int remain){
	int* temp = hist;
	hist = new int[num + 1];
	for(int i = 0; i< num + 1 ; i ++){
		hist[i] = temp[i];
	}
	hist[num + 1] = remain;
	delete[] temp;
	return hist;	
}

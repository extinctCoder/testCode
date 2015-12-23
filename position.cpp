#include <iostream>
using namespace std;
int main(){
	int position = 0;
	while(1){
		cin >> position;	
		if(position>10){
			position=position%10;
		} 
		
		if(0<=position&&position<1){
			cout<<"loop is in a to b"<<endl;
		}
		else if(1<=position&&position<3){
			cout<<"loop is in b to c"<<endl;
		}
		else if(4<=position&&position<6){
			cout<<"loop is in c to d"<<endl;
		}
		else{
			cout<<"loop is in d to a"<<endl;
		}
	}
	return 0;
}

#include <iostream>
using namespace std;

//returns number of steps and prints them
int tower_of_hanoi(char src,char dest,char helper,int n){
	static int steps=0;
	if(n==0)
		return steps;
	tower_of_hanoi(src,helper,dest,n-1);
	cout<<"Move Disk "<<n<<" from "<<src<<" to "<<dest<<"\n";
	steps++;
	tower_of_hanoi(helper,dest,src,n-1);
	return steps;
}

int main()
{	
	int s=tower_of_hanoi('A','B','C',3);
	cout<<"Steps="<<s;
	return 0;
}
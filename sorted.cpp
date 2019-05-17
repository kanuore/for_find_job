#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#include "sorted_common.h"

int main(int argc, char const *argv[])
{
	cout << "sorted " << endl;
	
	vector<int> data(400,0);
	for(int i = 0; i < 400; i++){
		data[i] = i;
	}
	random_shuffle(data.begin(),data.end());
	
	cout << endl ;
	//merge(data,0,399);
	

	radix(data);
	/*
	cout << "result: " <<endl;
	for(int i = 0; i < 400; i++){
		cout << data[i] << " ";
	}
	cout << endl;
	*/
	draw_last(data);
	//排序算法，并显示过程
	
	random_shuffle(data.begin(),data.end());
	bubble(data);
	draw_last(data);


	random_shuffle(data.begin(),data.end());
	insert(data);
	draw_last(data);


	random_shuffle(data.begin(),data.end());
	fast_1(data,0,399);
	draw_last(data);

	random_shuffle(data.begin(),data.end());
	merge(data,0,399);
	draw_last(data);

	random_shuffle(data.begin(),data.end());
	count_1(data);
	draw_last(data);

	return 0;
}
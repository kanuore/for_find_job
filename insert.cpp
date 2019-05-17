#include <iostream>
#include <vector>
using namespace std;
#include "sorted_common.h"

void insert(vector<int> &data)
{
	int end = 0;
	for(int i=1;i<400;i++){

		int temp = data[i];
		//原址排序，第i个数据，与前面i-1个数据的空间是可使用的空间
		int j;
		for(j = i-1 ; j>=0 ; j--){
			if(data[j] > temp){
				data[j+1] = data[j];
			}
			else break;
		}
		data[j+1] = temp;

		draw_black(data); 
	}
}
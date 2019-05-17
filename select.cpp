#include <iostream>
#include <vector>
using namespace std;
#include "sorted_common.h"

void select(vector<int> &data)
{
	//冒泡：
	for(int i=0;i<400;i++){
		for(int j = i;j<400;j++){
			if(data[j] < data[i]){
				int temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
		draw_black(data);
	}
}
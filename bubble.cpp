#include <iostream>
#include <vector>
using namespace std;
#include "sorted_common.h"

void bubble(vector<int> &data)
{
	//冒泡：
	for(int i=400;i>0;i--){
		//看内循环的走向，反正一次也是确定一个位置，
		//但可以有升级，某一次没有发生交换就不用排序了
		for(int j = 0;j<i;j++){
			if(data[j] > data[j+1]){
				int temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
		draw_black(data);
	}
}
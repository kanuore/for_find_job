#include <iostream>
#include <vector>
using namespace std;
#include "sorted_common.h"

void fast_1(vector<int> &data,int start_id,int end_id)
{
	//有些限制不知不觉帮你排除了很多情况
	if(end_id > start_id){
		int base_id = end_id;
		int j = end_id - 1 ;
		int i = start_id;
		int temp;
		while( i < j ){
			if(data[i] >= data[base_id]){
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
				j--;
			}
			else{
				i++;
			}
		}

		//i == j 不同情况，i == j 所处的位置不同；
		if(data[j] <= data[base_id]){
			temp = data[base_id];
			data[base_id] = data[j+1];
			data[j + 1] = temp;
			j = j + 2;
		}
		else{
			temp = data[base_id];
			data[base_id] = data[j];
			data[j] = temp;
			j = j+1;
			i = i-1;
		}
		fast_1(data,start_id,i);
		fast_1(data,j,end_id);
		draw_black(data);
		
	}
}
//左右指针法和挖坑法只能针对顺序序列进行排序，如果是对一个链表进行排序只能用前后指针
void fast_2(vector<int>& data,int start_id,int end_id)
{
	if(end_id > start_id){
		int i = start_id - 1;//i指向小于基准值的最后一个数
		int j = start_id;
		int temp;
		for(;j<end_id;j++){
			if(data[j] < data[end_id]){
				i++;
				temp = data[j];
				data[j] = data[i];
				data[i] = temp;
			}
		}
		//后移
		//此时j应该指向最后
		//放置基准，应该放置到i之后
		temp = data[j];
		data[j] = data[i+1];
		data[i+1] = temp;
		/*
		cout << " i " << i << " j " << j << " " <<temp << endl;
		for(int n = 0; n <= 9; n++){
			cout << data[n] << " ";
		}
		cout << endl;
		*/
		draw_black(data);
		fast_2(data,start_id,i);
		fast_2(data,i+2,end_id);
	}
}
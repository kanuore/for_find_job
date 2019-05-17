#include <iostream>
#include <vector>
using namespace std;
#include "sorted_common.h"

//先进入递归过程进行拆分，然后根据拆分后的情况进行分情况处理
void count_1(vector<int> &data)
{
	if(!data.empty()){
		//找最大
		vector<int> temp_data(data);
		int max_value = data[0];
		for(int i = 1;i<data.size();i++){
			if(max_value < data[i]){
				max_value = data[i];
			}
		}
		//纪律频数与相应的位置,从0开始的话，其实是400个数
		vector<int> count_index(max_value+1,0);
		for(int i = 0 ; i < data.size();i++ ){
			count_index[data[i]]++;
		}
		//频数累加形成索引
		for(int i = 1; i < count_index.size(); i++){
			count_index[i] = count_index[i] + count_index[i-1];
		}
		//按照记录的索引，排序，并且更改索引
		for(int i = 0; i < temp_data.size(); i++){
			int index = count_index[temp_data[i]]--;
			data[index-1] = temp_data[i];
		}
	}



}
	
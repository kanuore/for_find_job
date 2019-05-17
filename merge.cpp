#include <iostream>
#include <vector>
using namespace std;
#include "sorted_common.h"

//先进入递归过程进行拆分，然后根据拆分后的情况进行分情况处理
void merge(vector<int> &data,int start_id,int end_id)
{
	//只要符合一个区间就进入循环
	if(end_id > start_id){
		//进入分治
		int mid_id = (end_id + start_id)/2;
		merge(data,start_id,mid_id);
		merge(data,mid_id+1,end_id);
		
		//分治返回后，区间內大于两个元素，拆分，融合
		if(end_id - start_id > 1){
			vector<int> temp_1;
			vector<int> temp_2;
			for(int i = start_id;i<=end_id;i++){
				if(i<=mid_id){
					temp_1.push_back(data[i]);
				}
				else{
					temp_2.push_back(data[i]);
				}
			}
			//添加一个最大值哨兵，融合操作方便多了。
			temp_1.push_back(9999);
			temp_2.push_back(9999);

			int p = start_id;
			int p_1 = 0;
			int p_2 = 0;
			
			while(p <= end_id){
				if(temp_1[p_1] <= temp_2[p_2]){
					data[p] = temp_1[p_1++];
				}
				else{
					data[p] = temp_2[p_2++];
				}
				p++;
			}
		}
		//区间里只有两个元素交换
		if(end_id - start_id == 1){
			if(data[end_id] < data[start_id]){
				swap(data[end_id],data[start_id]);	
			}
		}
		//区间里只有一个元素返回
	}
	draw_black(data); 
}
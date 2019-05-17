#include <iostream>
#include <vector>
using namespace std;
#include "sorted_common.h"


void radix(vector<int> &data)
{

	vector<int> bucket_0;
	vector<int> bucket_1;
	vector<int> bucket_2;
	vector<int> bucket_3;
	vector<int> bucket_4;
	vector<int> bucket_5;
	vector<int> bucket_6;
	vector<int> bucket_7;
	vector<int> bucket_8;
	vector<int> bucket_9;

	vector<vector<int> > buckets;
	buckets.push_back(bucket_0);
	buckets.push_back(bucket_1);
	buckets.push_back(bucket_2);
	buckets.push_back(bucket_3);
	buckets.push_back(bucket_4);
	buckets.push_back(bucket_5);
	buckets.push_back(bucket_6);
	buckets.push_back(bucket_7);
	buckets.push_back(bucket_8);
	buckets.push_back(bucket_9);

	int flag = 0;
	static int base = 1;
	
	for(int i = 0 ; i < data.size() ; i++){
		flag = flag + data[i] / (base * 10);
		buckets[data[i] % (base*10) / base].push_back(data[i]);
	}

	int count = 0;
	
	for(int i =0 ;i<10;i++){
		for(int j =0;j<buckets[i].size();j++){
			data[count] = buckets[i][j];
			count++;
		}
		draw_black(data);
	}
	base = base * 10;

	if(flag != 0 ){
		radix(data);
	}
	
	return;

}


//给主函数调用看的
//画板
void draw_black(vector<int> &data);
void draw_last(vector<int> &data);
//冒泡
void bubble(vector<int> &data);

//选择
void select(vector<int> &data);

//插入
void insert(vector<int> &data);

//快速排序
void fast_1(vector<int> &data,int start_id,int end_id);
void fast_2(vector<int> &data,int start_id,int end_id);

//归并排序
void merge(vector<int> &data,int start_id,int end_id) ;

//计数排序
void count_1(vector<int> &data);

//基数排序
void radix(vector<int> &data);

//就剩下 堆排序 和 希尔排序
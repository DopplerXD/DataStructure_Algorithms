# STL

## 1 set

```cpp
s.earse(it1,it2); 删除 [it1,it2) 这个区间（迭代器）对应位置的元素
iterator lower_bound( const key_type &key ); 返回一个迭代器，指向键值 >= key 的第一个元素。
iterator upper_bound( const key_type &key ); 返回一个迭代器，指向键值 > key 的第一个元素

Set 的定义：
struct T1{
	int key,value;
	bool operator < (const T1 &a) const {
		return key<a.key;//按照升序排列 
	}
};
struct T2{
	int key,value;
};
struct T2cmp{
	bool operator () (const int &a,const int &b){
		if(abs(a-b)<=k)
			return false;
		return a<b;
	}
}; 
int main(){
	int i,j;
	set<T1> s1;
	set<T2,T2cmp> s2;
	set<string> ss1;//等于 set<string,less<int> > ss1; 从小到大
	set<string,greater<string> > ss2;//从大到小
	set<string,greater<string> > ::iterator itsey;
	//set 的遍历
	set<string> :: iterator it; 
	for(it = ss1.begin();it!=ss1.end();it++){
		cout<<*it<<endl;
	}
	return 0;
}
Multiset
c.erase(elem) 删除与 elem 相等的所有元素，返回被移除的元素个数。
c.erase(pos) 移除迭代器 pos 所指位置元素，无返回值。
```

## 2 map

```cpp
mp.find(key): 在 map 中查找 key 并返回其 iterator, 找不到的话返回 mp.end() O(logn)
mp.count(key): 在 map 中找 key 的数量，由于每个 key 都是唯一的，只会返回 0 或 1
mp[key] 可以直接访问到键值队 key---value 中的 value，如果不存在，则 mp[key] 返回的是 value 类型默认构造器所构造的值，并将该键值对插入到 map 中
哈希表：
#include <unordered_map>
unordered_map
```

## 3 pair

```cpp
#include <utility>头文件中
pair<T1, T2> p1; //创建一个空的 pair 对象（使用默认构造），它的两个元素分别是 T1 和 T2 类型，采用值初始化。
pair<T1, T2> p1(v1, v2); //创建一个 pair 对象，它的两个元素分别是 T1 和 T2 类型，其中 first 成员初始化为 v1，second 成员初始化为 v2。
make_pair(v1, v2); // 以 v1 和 v2 的值创建一个新的 pair 对象，其元素类型分别是 v1 和 v2 的类型。
p1 < p2; // 两个 pair 对象间的小于运算，其定义遵循字典次序
// 如 p1.first < p2.first 或者 !(p2.first < p1.first) && (p1.second < p2.second) 则返回 true。
p1 == p2// 如果两个对象的 first 和 second 依次相等，则这两个对象相等；该运算使用元素的==操作符。
```

## 4 vector

```cpp
v.resize(n); // 把 v 的长度重新设定为 n 个元素
v.erase(unique(v.begin(), v.end()), v.end()); // 去重
```

## 5 priority_queue

```cpp
pq.top(): 获取优先级最高的元素 O(1)
优先队列的定义：
priority_queue<int> q1; //默认从大到小，大顶堆 
priority_queue<int ,vector<int>,less<int> > q2; //降序队列，大顶堆 
priority_queue<int ,vector<int>,greater<int> > q3; //升序队列，小顶堆

对于结构体定义：
struct T1{//法一 强烈推荐 
	int x,y;
	friend bool operator < (T1 a,T1 b){
		return a.x<b.x;
	}
};
priority_queue<T1> q1;

struct T1{//法二
	int x,y;
	bool operator < (const T1 &a) const{
		return x<a.x; //大顶堆 
	}
};
priority_queue<T1> q1; 
```

## 其他

```cpp
lower_bound(begin,end,num)：二分查找第一个大于或等于 num 的数字，找到返回该数字的地址，不存在则返回 end
upper_bound(begin,end,num)：二分查找第一个大于 num 的数字
在从大到小的排序数组中，重载 lower_bound() 和 upper_bound()
lower_bound(begin,end,num,greater()): 二分查找第一个小于或等于 num 的数字
upper_bound(begin,end,num,greater()): 二分查找第一个小于 num 的数字
```


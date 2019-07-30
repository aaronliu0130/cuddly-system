/*
 * util.h
 *
 *  Created on: Apr 12, 2019
 *      Author: jerron
 */

#ifndef UTIL_H_
#define UTIL_H_


#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <algorithm>
#include <set>
#include <list>
#include <queue>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <cassert>
#include <initializer_list>

using namespace std;


#ifdef __DEBUG
#define LOGGER(x) cout<<x
#else
#define LOGGER(x)
#endif

template <typename T, std::size_t N>
constexpr std::size_t countof(T const (&)[N]) noexcept{
	return N;
}

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode():val(INT_MIN),next(nullptr){}
    explicit ListNode(int val):val(val),next(nullptr) {}
    ListNode(const initializer_list<int>& l):val(*l.begin()),next(nullptr) {
    	auto prev=&next;
    	for(auto i=l.begin();++i!=l.end();prev=&(*prev)->next)
    		*prev=new ListNode(*i);
    }
    bool del(){
    	if(val==INT_MIN){
    		LOGGER("Probably trying to delete pointer already deleted!!!!!"<<endl);
    		return false;
    	}
		if(next&&next->del())
			delete next;
		val=INT_MIN;
		return true;
    }
};
inline void assertl(ListNode*l1,ListNode*l2){
	if(l1){
		assert(l2);
		assert(l1->val==l2->val);
		assertl(l1->next,l2->next);
	}
	else
		assert(!l2);
}

class RandomListNode{
public:
    int label;
	RandomListNode *next,*random;
	RandomListNode():label(INT_MIN),next(nullptr),random(nullptr){}
    explicit RandomListNode(int val):label(val),next(nullptr),random(nullptr) {}
    RandomListNode(const initializer_list<int>& l1,const initializer_list<int>& l2):label(*l1.begin()),next(nullptr),random(nullptr){
    	map<int,RandomListNode*> M{{label,this}};
    	auto head=this;
    	for(auto i=l1.begin();++i!=l1.end();){
    		head->next=new RandomListNode(*i);
    		M[*i]=head=head->next;
    	}
    	auto i=l2.begin();
    	for(head=this;head;head=head->next,++i)
    		if(M.count(*i))
    			head->random=M[*i];
    }
    bool del(){
    	if(label==INT_MIN){
    		LOGGER("Probably trying to delete pointer already deleted!!!!!"<<endl);
    		return false;
    	}
		if(next&&next->del())
			delete next;
		label=INT_MIN;
		return true;
    }
};
inline void assertr(RandomListNode*l1,RandomListNode*l2){
	if(l1){
		assert(l2);
		assert(l1->label==l2->label);
		if(l1->random)
			assert(l2->random && l1->random->label==l2->random->label);
		else
			assert(!l2->random);
		assertr(l1->next,l2->next);
	}
	else
		assert(!l2);
}
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode() :val(INT_MIN),left(nullptr),right(nullptr){};
    TreeNode(int val) :val(val),left(nullptr),right(nullptr){};
    TreeNode(const initializer_list<int>& l):val(*l.begin()),left(nullptr),right(nullptr){
    	list<TreeNode**>Q{&left,&right};
    	for(auto i=l.begin();++i!=l.end();Q.pop_front())
    		if(*i>INT_MIN){
				auto next=Q.front();
				*next=new TreeNode(*i);
    			Q.push_back(&(*next)->left);
    			Q.push_back(&(*next)->right);
    	}
    };
    bool isBST()const{
    	if(left)
    		if(left->val>val||!left->isBST())
    			return false;
    	if(right)
    		if(right->val<val||!right->isBST())
    			return false;
    	return true;
    }
    TreeNode* find(int v){
    	if(val==v)
    		return this;
    	if(v<val)
    		return left?left->find(v):nullptr;
    	else
    		return right?right->find(v):nullptr;
    }
    bool del(){
    	if(val==INT_MIN){
    		LOGGER("Probably trying to delete pointer already deleted!!!!!"<<endl);
    		return false;
    	}
		if(left&&left->del())
			delete left;
		if(right&&right->del())
			delete right;
		val=INT_MIN;
		return true;
    }
};
inline void assertt(TreeNode*l1,TreeNode*l2){
	if(l1){
		assert(l2);
		assert(l1->val==l2->val);
		assertt(l1->left,l2->left);
		assertt(l1->right,l2->right);
	}
	else
		assert(!l2);
}



template<class T>
void enumerate(T&& dfs){
	int i=0;
	for (;dfs.next();++i)
		cout << dfs.getResult()<<" : " <<i<< endl;
}

using intVec=vector<int>;

template <class T>
ostream& operator<<(ostream& os, const vector<T>& source){
	for(auto i:source)
		os<<i<<" ";
	return os;
}
template<class T>
void assertv(const vector<T>&v1,const vector<T>&v2){
	assert(v1.size()==v2.size());
	for(auto i1=v1.begin(),i2=v2.begin();i1!=v1.end();++i1,++i2)
		assert(*i1==*i2);
}
template<class T>
void del(vector<T*>v){
	for(auto i:v)
		i->del();
}

#endif /* UTIL_H_ */

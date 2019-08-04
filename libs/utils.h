/*
 * utils.h
 *
 *  Created on: Jul 30, 2019
 *      Author: Aaron
 */

#ifndef CUDDLY_UTILS
#define CUDDLY_UTILS
#include <utility>
#include <algorithm>
#include <initializer_list>
#include "cttrie.h"
using namespace std;
template<typename KeyType, typename FunPtrType, typename Comp>
/**
 * A legacy implementation of switch for string.
 */
void switchslegacy(const KeyType &value,
		initializer_list<pair<const KeyType, FunPtrType>> sws, Comp comp) {
	typedef pair<const KeyType &, FunPtrType> KVT;
	auto cmp =
			[&comp](const KVT &a,const KVT &b) {return comp(a.first,b.first);};
	auto val = KVT(value, FunPtrType());
	auto r = lower_bound(sws.begin(), sws.end(), val, cmp);
	if ((r != sws.end()) && (!cmp(val, *r))) {
		r->second();
	}
}
#endif /* UTILS_H_ */

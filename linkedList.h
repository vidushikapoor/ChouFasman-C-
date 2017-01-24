/*
s * linkedList.h
 *
 *  Created on: Nov 15, 2015
 *      Author: vidushikapoor
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


#include<iostream>
#include "node.h"
#include"data.h"
#include<string.h>
using namespace std;

class linkedList
{
	public:
		void appendToEnd(data addData);
		void PrintList();
		int length();

		node* head;
		node* tail;
};




#endif /* LINKEDLIST_H_ */

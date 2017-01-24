/*
 * linkedList.cpp
 *
 *  Created on: Nov 15, 2015
 *      Author: vidushikapoor
 */
#include<iostream>
#include"node.h"
#include"linkedList.h"
#include"data.h"
#include<string.h>
#include<cstdlib>
using namespace std;

void linkedList::appendToEnd(data addData)
{
	{
	     node *ptr;
	     if(!head)
	     {
	         head = tail = new node;
	         head->prev= nullptr;
	         head->next = nullptr;
	         head->number = addData;
	     }
	     else
	     {
	             ptr = new node;
	             ptr->prev =tail;
	             tail->next=ptr;
	             ptr->next=NULL;
	             ptr->number=addData;
	             tail=ptr;
	     }
	  }
}

int linkedList::length() {
	int count = 0;
	node* trav = head;
	while(trav != NULL){
		count = count +1;
		trav = trav->next;
	}
	return count;
}

void linkedList::PrintList()
{
	node* trav = head;
	while(trav != NULL){
		cout << trav->number <<endl;
		trav = trav->next;
	}
}

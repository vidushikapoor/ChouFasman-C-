/*
 * node.cpp
 *
 *  Created on: Nov 15, 2015
 *      Author: vidushikapoor
 */

#include<iostream>
#include"node.h"
using namespace std;

node::node()
{
	next=NULL;
	prev=NULL;
}

node::node(data newMem)
{
	number=newMem;
	next=NULL;
	prev=NULL;
}
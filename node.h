/*
 * node.h
 *
 *  Created on: Nov 15, 2015
 *      Author: vidushikapoor
 */

#ifndef NODE_H_
#define NODE_H_
#include"data.h"

class node
{
public:
	node();
	node(data);
	node* prev;
	node* next;
	data number;

};




#endif /* NODE_H_ */

/*
 * data.cpp
 *
 *  Created on: Nov 15, 2015
 *      Author: vidushikapoor
 */
#include<iostream>
#include"data.h"
#include"linkedList.h"
using namespace std;

data::data()
{
	Pa=0;
	Pb=0;
	Pturn=0;
	fi=0.0;
	fi1=0.0;
	fi2=0.0;
	fi3=0.0;
}
data::data(int A, int B, int T, float F,float F1, float F2, float F3)
{
	Pa=A;
	Pb=B;
	Pturn=T;
	fi=F;
	fi1=F1;
	fi2=F2;
	fi3=F3;
}

ostream& operator<<(ostream& osObject, const data& list)
{
	osObject << list.Pa;
	osObject << ", ";
	osObject << list.Pb;
	osObject << ", ";
	osObject << list.Pturn;
	osObject << ", ";
	osObject << list.fi;
	osObject << ", ";
	osObject << list.fi1;
	osObject << ", ";
	osObject << list.fi2;
	osObject << ", ";
	osObject << list.fi3;
	//cout<<"   done"<<endl;
	return osObject;
}










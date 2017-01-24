/*
 * data.h
 *
 *  Created on: Nov 15, 2015
 *      Author: vidushikapoor
 */

#ifndef DATA_H_
#define DATA_H_
using namespace std;
class data
{
	friend ostream& operator<<(ostream& osObject, const data& );
	public:
		data();
		data(int,int,int,float,float,float,float);

		int Pa;
		int Pb;
		int Pturn;
		float fi;
		float fi1;
		float fi2;
		float fi3;
};




#endif /* DATA_H_ */

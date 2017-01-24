/*
 * main.cpp
 *
 *  Created on: Nov 5, 2015
 *      Author: vidushikapoor
 */
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <vector>
#include "data.h"
#include "linkedList.h"
#include "node.h"
using namespace std;

/**
	Function that assigns values to the amino acid codes from the data provided.
	
	@param read string that contains the amino acids
	@param link linked list containing "data" objects storing a number of values as defined in the source data
	
*/
void assignValues(string read, linkedList& link)
{
	data numbers;
	for(int i=0;i<read.size();i++)
	{
		if(read[i]=='A')
		{
			numbers= data(142,83,66,0.06,0.076,0.035,0.058);
			link.appendToEnd(numbers);
		}
		else if(read[i]=='R')
		{
			numbers= data(98,93,95,0.070,0.106,0.099,0.085);
			link.appendToEnd(numbers);
		}
		else if(read[i]=='D')
		{
			numbers=data(101,54,146,0.147,0.110,0.179,0.081);
			link.appendToEnd(numbers);
		}
		else if(read[i]=='N')
		{
			numbers=data( 67,89,156,0.161,0.083,0.191,0.091);
			link.appendToEnd(numbers);
		}
		else if (read[i]=='C')
		{
			numbers=data( 70,119,119,0.149,0.050,0.117,0.128);
			link.appendToEnd(numbers);
		}
		else if (read[i]=='E')
		{
			numbers=data(151,37,74,0.056,0.060,0.077,0.064);
			link.appendToEnd(numbers);
		}
		else if (read[i]=='Q')
		{
			numbers=data(111,110,98,0.074,0.098,0.037,0.098);
			link.appendToEnd(numbers);
		}
		else if(read[i]=='G')
		{
			numbers=data(57,75,156,0.102,0.085,0.190,0.152);
			link.appendToEnd(numbers);
		}
		else if (read[i]=='H')
		{
			numbers=data(100,87,95,0.140,0.047,0.093,0.054);
			link.appendToEnd(numbers);
		}
		else if (read[i]=='I')
		{
			numbers=data(108,160,47,0.043,0.034,0.013,0.056);
			link.appendToEnd(numbers);
		}
		else if(read[i]=='L')
		{
			numbers= data(121,130,59,0.061,0.025,0.036,0.070);
			link.appendToEnd(numbers);
		}
		else if(read[i]=='K')
		{
			numbers= data(114,74,101,0.055,0.115,0.072,0.095);
			link.appendToEnd(numbers);
		}
		else if(read[i]=='M')
		{
			numbers=data(145,105,60,0.068,0.082,0.014,0.055);
			link.appendToEnd(numbers);
		}
		else if(read[i]=='F')
		{
			numbers=data(113,138,60,0.059,0.041,0.065,0.065);
			link.appendToEnd(numbers);
		}
		else if (read[i]=='P')
		{
			numbers=data(57,55,152,0.102,0.301,0.034,0.068);
			link.appendToEnd(numbers);
		}
		else if(read[i]=='S')
		{
			numbers=data(77,75,143,0.120,0.139,0.125,0.106);
			link.appendToEnd(numbers);
		}
		else if(read[i]=='T')
		{
			numbers=data(83,119,96,0.086,0.108,0.065,0.079);
			link.appendToEnd(numbers);
		}
		else if(read[i]=='W')
		{
			numbers=data(108,137,96,0.077,0.013,0.064,0.167);
			link.appendToEnd(numbers);
			cout<<"doingW"<<endl;
		}
		else if (read[i]=='Y')
		{
			numbers=data(69,147,114,0.082,0.065,0.114,0.125);
			link.appendToEnd(numbers);
		}
		else if (read[i]=='V')
		{
			numbers=data(106,170,50,0.062,0.048,0.028,0.053);
			link.appendToEnd(numbers);
		}
		else
			cout<<"Sorry, wrong amino acid"<<endl;

	}
}

/**
	Function that checks for presence of alpha helix. 
	
	@param file a linked list containing "data" objects
*/
void checkAlphaHelix(linkedList& file)
{

	int countMove=0;
	int countMove2=0;
	node*temp=file.head;
	node*mover=file.head;
	node*chou;
	node*mid;
	node*mouse;
	mid=file.head;

	while(mid->next!=file.tail)
	{
		temp=mid;
		chou=mid;
		mover=mid;
		while(temp->next!=NULL)
		{
			int count=0;
			temp=mover;
			chou=temp->next->next->next->next->next;
			while(temp!=chou->next)
			{
				if (temp->number.Pa>100)
				{
					count=count+1;
					temp=temp->next;
				}
				else
					temp=temp->next;
			}
			if(count>=4)
			{
				//cout<<"alpha helix found"<<endl;
				//cout<<"countMove is  "<<countMove<<"and count is"<<count<<endl;
				break;
			}
			else
			{
				mover=mover->next;
				countMove=countMove+1;
			}
		}
		countMove2=countMove+6;
		mover=chou->next;
		temp=chou->next;
		while(temp->next!=NULL)
		{
			int sum=0;
			temp=mover;
			chou=temp->next->next->next;
			mouse=chou;
			while(temp!=chou->next)
			{
				sum=sum+temp->number.Pa;
				temp=temp->next;
			}
			if (sum/4<100)
			{
				//cout<<"end of alpha helix found"<<endl;
				//cout<<"countMove2 is  "<<countMove2<<endl;
				break;
			}
			else
			{
				mover=mover->next;
				countMove2=countMove2+1;
			}
		}
		countMove=countMove2;
		mid=chou->next;
	}

}

/**
    Function that checks for the presence of beta sheet in the sequence
    
    @param fileNew linked list containing "data" objects pertaining to the amino acids
*/

void checkBetaSheet(linkedList& fileNew)
{

	int countMove	=0;
	int countMove2	=0;
	node* temp		=fileNew.head;
	node* mover		=fileNew.head;
	node* mid		=fileNew.head;
	node* chou;
	node* mouse;

	while(mid->next!=fileNew.tail)
	{
		temp =mid;
		chou =mid;
		mover=mid;
		while(temp->next!=NULL)
		{
			int count=0;
			temp=mover;
			chou=temp->next->next->next->next;
			while(temp!=chou->next)
			{
				if (temp->number.Pb>100)
				{
					count=count+1;
					temp=temp->next;
				}
				else
					temp=temp->next;

			}
			if(count>=3)
			{
				//cout<<"beta sheet found"<<endl;
				//cout<<"countMove is  "<<countMove<<"and count is"<<count<<endl;
				break;
			}
			else
			{
				mover=mover->next;
				countMove=countMove+1;
			}
		}
		countMove2=countMove+6;
		mover=chou->next;
		temp=chou->next;
		while(temp->next!=NULL)
		{
			int sum=0;
			temp=mover;
			chou=temp->next->next->next;
			mouse=chou;
			while(temp!=chou->next)
			{
				sum=sum+temp->number.Pb;
				temp=temp->next;
			}
			if (sum/4<100)
			{
				//cout<<"end of beta sheet found"<<endl;
				//cout<<"countMove2 is  "<<countMove2<<endl;
				break;
			}
			else
			{
				mover=mover->next;
				countMove2=countMove2+1;
			}
		}
		countMove=countMove2;
		mid=chou->next;
	}

}


//p(t) = f(j)f(j+1)f(j+2)f(j+3)

//where the f(j+1) value for the j+1 residue is used, the f(j+2) value for the j+2 residue is used and the f(j+3) value for the j+3 residue is used.
//If: (1) p(t) > 0.000075; (2) the average value for P(turn) > 1.00 in the tetrapeptide; and (3) the averages for the tetrapeptide obey the
//inequality P(a-helix) < P(turn) > P(b-sheet), then a beta-turn is predicted at that location.

// Main driver function

int main()
{
	//read a file
	ifstream fin("seq.txt");
	char arr[500];

	//save in vector
	vector<string> readData;
	while (fin>>arr)
	{
		readData.push_back(arr);
	}

	//save in array

	for(int i=0;i<readData.size();i++)
	{
		string file=readData[i];
	}
	//cout<<"array is"<<arr<<endl;
	linkedList chou;
	assignValues(arr,chou);
	
	linkedList chouBeta;
	assignValues(arr,chouBeta);
	checkBetaSheet(chouBeta);

}

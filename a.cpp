
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <iostream>
#include <std_msgs/Empty.h>
#include <cstring>
#include <ctype.h>
#include <cmath>
using namespace std;
bool check_number(string str) 
{
	bool isPass;
   int i;
   if (str[0] == '-')
   {
   	i = 1;
   }
   else 
   {
    i = 0;
   }
   bool check = true;
   for (i; i < str.length(); i++)
   {
   	if (isdigit(str[i]) == false)
	{
		if(str[i] == '.')
		{
			isPass =  true;
		}
		else
			isPass = false;
	}
	else{
	    isPass = true;
	}
   }
      return isPass;
}
int main(int argc, char** argv)
{
 float goals [50][3];
 string check;
 //float goals [4][3] = { {1.4,0.3,1.5708}, { 1.4,1.4,3.13}, {0.3,1.4,-1.5708},{0.3,0.3,0}};
 //float goals [5][3] = { {2.7,0.3,0}, { 0.9,2.1, 1.57}, {3.96,3.96,0},{3.3,1.5,-1.57},{3.9,0.3,0}};
 // location of 5 waypoints (4 fires 1 exit at final waypoint).
 //get waypoints
 int x;
 cout << "Enter number of waypoints: ";
 cin >> x;
 for(int i = 0; i < x; i++)
 {
 	cout << "xEnter the value (x ,y, theta(rad)) with x,y in range (3.9,3.9) of waypoint " << (i+1) <<" : ";
 	for(int j = 0; j < 3; j ++)			
 	{
 		cin >> check;
 		if(check_number(check))
 		{
 			goals[i][j] = std::stof(check);
 		}
 		else 
 		{
			for (int k = 2; k > j; k--)
						{
							cin >> check;
						}
 			cout << "1Error! Invalid input. Please try again" << endl << "Enter the value (x ,y, theta(rad)) with x,y in range (3.9,3.9) of waypoint " << (i+1) <<" : ";
 			j = -1;
 		}
 	}
 	while(goals[i][0] < 0 || goals[i][1] <0 || goals[i][0] > 3.98 || goals[i][1] > 3.98 || abs(goals[i][2]) > 3.1416)
 	{
 		cout << "2Error! Invalid input. Please try again" << endl << "Enter the value (x ,y, theta(rad)) with x,y in range (3.9,3.9) of waypoint " << (i+1) <<" : ";
 		for(int j = 0; j < 3; j ++)			
 	{
 		cin >> check;
 		if(check_number(check))
 		{
 			goals[i][j] = std::stof(check);
 		}
 		else 
 		{
			for (int k = 2; k > j; k--)
						{
							cin >> check;
						}
 			cout << "1Error! Invalid input. Please try again" << endl << "Enter the value (x ,y, theta(rad)) with x,y in range (3.9,3.9) of waypoint " << (i+1) <<" : ";
 			j = -1;
 		}
 	}
 	}
 }
 //loop that send robot to waypoint
 return 0;
}

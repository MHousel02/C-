/*
CMPSC201 - <Fall> <2021>

Program Name: <Project 3>
Author: <Michael Housel>
Date Submitted: <11/18/2021>
Description:
  <Monte Carlo and fibinacci>

Sources:
  <detail any sites, people, or whatever that influenced the code as per the syllabus>
*/

// Uncomment the items below needed for your project.
#include <iostream> // basic cout/cin commands, et al.
#include <iomanip>  //advanced input/output commands and features
#include <math.h>   //math functions (sometimes seen as "math.h"
//#include <fstream>  //file input/output commands
//#include <string>   //string (basically an array of characters)
#include <ctime>    //use of certain time functions

using namespace std;

// Global Variables Go Before Main
// NOTE: We will not use these in our code, but they are discussed

// Function Declarations Go Before Main
// NOTE: We will discuss functions later in the course

const double pi = 3.14159;
// All functions declared
double GetR(int);
double GetX(double);
double GetY(double);
void Task1(int, double);
void Task2(int, double);
int main()
{ 
	// setting variables to control the number of trials
	int TrialTask1 = 10;
	int TrialTask2 = 250;
	// seeding the for randnu.
	srand((unsigned)time(0));
	// declaring and getting a randum number between 2-20 for to use get the sequence number used in the fib
	int randnum;
	randnum = rand() % (18) + 2;
	// declaring a varible for the radius
	double radius;
	// get radius from function
	radius = GetR(randnum);
	// Out put the position in the squence and the radius that equates from that
	cout << "The random value selected was the " << randnum << " position in the fibinacci sequence." << endl;
	cout << "This means the radius is: " << radius << endl;
	// Running task 1 and 2 uncomment them to run or comment them to not run
	Task1(TrialTask1,radius);
	//Task2(TrialTask2, radius);
	return (0);
}

//Function Code Goes After Main
// This function is the Fib sequence and will be used to get the radius of the circle
double GetR(int pos)
{
	int current = 1;
	int previous = 0;
	int next = 1;
	for (int i = 2; i < pos; i++)
	{
		next = current + previous;
		previous = current;
		current = next; 
	}
	return next;
}
// GetX and GetY are used to get the random X and Y points inside the Box around the circle with the radius from GetR
double GetX(double radius)
{
	double x;
	x = -radius + ((double)rand() / RAND_MAX) * (radius - -radius);
	return x;
}
double GetY(double radius)
{
	double y;
	y = -radius + ((double)rand() / RAND_MAX) * (radius - -radius);
	return y;
}
// Task1 Is just doing 10 trials and outputting the percentage of hits in the circle
void Task1(int num, double radius)
{
	double totalhits = 0; 
	double averagehits;
	double squarearea;
	double circlearea;
	double prob;
	double diameter;
	double percent;
	diameter = radius * 2;
	squarearea = pow(diameter, 2);
	circlearea = pi * pow(radius, 2);
	prob = circlearea / squarearea * 100;
	
	cout << "The probability(in precent form) of a point falling in the circle is (cirlceArea/Square area)*100 \nSo, the probability for our Monte Carlo is: "
		<< fixed << setprecision(2) << circlearea << "/" << squarearea << "=" << prob << "%" << endl;
	for (int i = 1; i <= num; i++)
	{
		double hit = 0;
		for (int z = 1; z <= 1000000; z++)
		{
			
			double X;
			double Y;
			Y = GetY(radius);
			X = GetX(radius);
			if (radius >= sqrt(pow(X, 2) + pow(Y, 2)))
			{
				hit++;
			}
			
		}
		cout << "For Trial #" << i << " the number of hits was " << fixed<< setprecision(0) << hit;
		percent = (hit / 1000000) * 100;
		cout << " or " << fixed << setprecision(2) << percent << "%" << endl;
	}
}
// Task 2 is doing 250 trials and totaling all there hits to find an average number of hits 
void Task2(int num, double radius)
{
	double totalhits = 0;
	double averagehits;
	for (int i = 1; i <= num; i++)
	{
		int hit = 0;
		for (int z = 1; z <= 1000000; z++)
		{

			double X;
			double Y;
			Y = GetY(radius);
			X = GetX(radius);
			if (radius >= sqrt(pow(X, 2) + pow(Y, 2)))
			{
				hit++;
			}

		}
		cout  << "For Trial #" << setfill('0') << setw(3) << i << " the number of hits was " << fixed << hit << endl;
		totalhits += hit;
	}
	averagehits = totalhits / num;
	cout <<"The average number of hits is " << setprecision(0) << averagehits << endl;
}
/* Sample Run Task1
The random value selected was the 5 position in the fibinacci sequence.
This means the radius is: 3
The probability(in precent form) of a point falling in the circle is (cirlceArea/Square area)*100
So, the probability for our Monte Carlo is: 28.27/36.00=78.54%
For Trial #1 the number of hits was 784703 or 78.47%
For Trial #2 the number of hits was 785836 or 78.58%
For Trial #3 the number of hits was 784861 or 78.49%
For Trial #4 the number of hits was 785503 or 78.55%
For Trial #5 the number of hits was 784986 or 78.50%
For Trial #6 the number of hits was 785421 or 78.54%
For Trial #7 the number of hits was 785508 or 78.55%
For Trial #8 the number of hits was 785263 or 78.53%
For Trial #9 the number of hits was 785162 or 78.52%
For Trial #10 the number of hits was 785280 or 78.53%

C:\Users\18145\source\repos\HouselM_P3\Debug\HouselM_P3.exe (process 19528) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/
 /* Sample Run Task2
The random value selected was the 11 position in the fibinacci sequence.
This means the radius is: 55
For Trial #001 the number of hits was 785397
For Trial #002 the number of hits was 785471
For Trial #003 the number of hits was 784972
For Trial #004 the number of hits was 785578
For Trial #005 the number of hits was 784761
For Trial #006 the number of hits was 785675
For Trial #007 the number of hits was 784829
For Trial #008 the number of hits was 784947
For Trial #009 the number of hits was 785221
For Trial #010 the number of hits was 784599
For Trial #011 the number of hits was 785174
For Trial #012 the number of hits was 784799
For Trial #013 the number of hits was 785308
For Trial #014 the number of hits was 785322
For Trial #015 the number of hits was 784856
For Trial #016 the number of hits was 785427
For Trial #017 the number of hits was 785580
For Trial #018 the number of hits was 786031
For Trial #019 the number of hits was 785245
For Trial #020 the number of hits was 784251
For Trial #021 the number of hits was 785808
For Trial #022 the number of hits was 785039
For Trial #023 the number of hits was 785403
For Trial #024 the number of hits was 785121
For Trial #025 the number of hits was 785132
For Trial #026 the number of hits was 785537
For Trial #027 the number of hits was 785776
For Trial #028 the number of hits was 785119
For Trial #029 the number of hits was 785281
For Trial #030 the number of hits was 785663
For Trial #031 the number of hits was 785101
For Trial #032 the number of hits was 785217
For Trial #033 the number of hits was 785779
For Trial #034 the number of hits was 785051
For Trial #035 the number of hits was 785157
For Trial #036 the number of hits was 785776
For Trial #037 the number of hits was 786703
For Trial #038 the number of hits was 785241
For Trial #039 the number of hits was 785226
For Trial #040 the number of hits was 785152
For Trial #041 the number of hits was 785263
For Trial #042 the number of hits was 785106
For Trial #043 the number of hits was 785221
For Trial #044 the number of hits was 784971
For Trial #045 the number of hits was 784876
For Trial #046 the number of hits was 785149
For Trial #047 the number of hits was 784628
For Trial #048 the number of hits was 785064
For Trial #049 the number of hits was 785679
For Trial #050 the number of hits was 784910
For Trial #051 the number of hits was 785312
For Trial #052 the number of hits was 785971
For Trial #053 the number of hits was 785792
For Trial #054 the number of hits was 785794
For Trial #055 the number of hits was 785734
For Trial #056 the number of hits was 785232
For Trial #057 the number of hits was 785245
For Trial #058 the number of hits was 785939
For Trial #059 the number of hits was 786115
For Trial #060 the number of hits was 786221
For Trial #061 the number of hits was 785387
For Trial #062 the number of hits was 785325
For Trial #063 the number of hits was 785171
For Trial #064 the number of hits was 785151
For Trial #065 the number of hits was 785156
For Trial #066 the number of hits was 784778
For Trial #067 the number of hits was 786017
For Trial #068 the number of hits was 785159
For Trial #069 the number of hits was 785609
For Trial #070 the number of hits was 785178
For Trial #071 the number of hits was 785617
For Trial #072 the number of hits was 785616
For Trial #073 the number of hits was 785372
For Trial #074 the number of hits was 785253
For Trial #075 the number of hits was 784755
For Trial #076 the number of hits was 785078
For Trial #077 the number of hits was 785361
For Trial #078 the number of hits was 785263
For Trial #079 the number of hits was 785321
For Trial #080 the number of hits was 784809
For Trial #081 the number of hits was 784648
For Trial #082 the number of hits was 785592
For Trial #083 the number of hits was 785201
For Trial #084 the number of hits was 785854
For Trial #085 the number of hits was 785416
For Trial #086 the number of hits was 785653
For Trial #087 the number of hits was 785238
For Trial #088 the number of hits was 785531
For Trial #089 the number of hits was 784687
For Trial #090 the number of hits was 784614
For Trial #091 the number of hits was 785512
For Trial #092 the number of hits was 784954
For Trial #093 the number of hits was 785477
For Trial #094 the number of hits was 785024
For Trial #095 the number of hits was 785158
For Trial #096 the number of hits was 785339
For Trial #097 the number of hits was 785072
For Trial #098 the number of hits was 785513
For Trial #099 the number of hits was 784946
For Trial #100 the number of hits was 785045
For Trial #101 the number of hits was 785335
For Trial #102 the number of hits was 785607
For Trial #103 the number of hits was 785115
For Trial #104 the number of hits was 785263
For Trial #105 the number of hits was 785770
For Trial #106 the number of hits was 785934
For Trial #107 the number of hits was 785050
For Trial #108 the number of hits was 786149
For Trial #109 the number of hits was 784441
For Trial #110 the number of hits was 785430
For Trial #111 the number of hits was 785239
For Trial #112 the number of hits was 785297
For Trial #113 the number of hits was 785708
For Trial #114 the number of hits was 785639
For Trial #115 the number of hits was 785935
For Trial #116 the number of hits was 785414
For Trial #117 the number of hits was 784756
For Trial #118 the number of hits was 785903
For Trial #119 the number of hits was 785596
For Trial #120 the number of hits was 785638
For Trial #121 the number of hits was 785330
For Trial #122 the number of hits was 785521
For Trial #123 the number of hits was 784863
For Trial #124 the number of hits was 786520
For Trial #125 the number of hits was 784611
For Trial #126 the number of hits was 785430
For Trial #127 the number of hits was 785184
For Trial #128 the number of hits was 785136
For Trial #129 the number of hits was 784774
For Trial #130 the number of hits was 785587
For Trial #131 the number of hits was 785826
For Trial #132 the number of hits was 784981
For Trial #133 the number of hits was 785217
For Trial #134 the number of hits was 785146
For Trial #135 the number of hits was 784770
For Trial #136 the number of hits was 785521
For Trial #137 the number of hits was 785480
For Trial #138 the number of hits was 785010
For Trial #139 the number of hits was 785188
For Trial #140 the number of hits was 786082
For Trial #141 the number of hits was 784972
For Trial #142 the number of hits was 785791
For Trial #143 the number of hits was 785282
For Trial #144 the number of hits was 785388
For Trial #145 the number of hits was 785921
For Trial #146 the number of hits was 785728
For Trial #147 the number of hits was 785172
For Trial #148 the number of hits was 785669
For Trial #149 the number of hits was 785612
For Trial #150 the number of hits was 785289
For Trial #151 the number of hits was 785582
For Trial #152 the number of hits was 785808
For Trial #153 the number of hits was 786016
For Trial #154 the number of hits was 785071
For Trial #155 the number of hits was 785738
For Trial #156 the number of hits was 785230
For Trial #157 the number of hits was 785189
For Trial #158 the number of hits was 785853
For Trial #159 the number of hits was 784928
For Trial #160 the number of hits was 785575
For Trial #161 the number of hits was 785358
For Trial #162 the number of hits was 785620
For Trial #163 the number of hits was 784575
For Trial #164 the number of hits was 785182
For Trial #165 the number of hits was 784588
For Trial #166 the number of hits was 784937
For Trial #167 the number of hits was 784939
For Trial #168 the number of hits was 785693
For Trial #169 the number of hits was 785182
For Trial #170 the number of hits was 786135
For Trial #171 the number of hits was 785156
For Trial #172 the number of hits was 785378
For Trial #173 the number of hits was 784859
For Trial #174 the number of hits was 784463
For Trial #175 the number of hits was 785684
For Trial #176 the number of hits was 785264
For Trial #177 the number of hits was 785122
For Trial #178 the number of hits was 785593
For Trial #179 the number of hits was 785792
For Trial #180 the number of hits was 785596
For Trial #181 the number of hits was 784683
For Trial #182 the number of hits was 786222
For Trial #183 the number of hits was 786100
For Trial #184 the number of hits was 784737
For Trial #185 the number of hits was 785423
For Trial #186 the number of hits was 785500
For Trial #187 the number of hits was 785219
For Trial #188 the number of hits was 785698
For Trial #189 the number of hits was 784838
For Trial #190 the number of hits was 785295
For Trial #191 the number of hits was 785974
For Trial #192 the number of hits was 785436
For Trial #193 the number of hits was 785549
For Trial #194 the number of hits was 785096
For Trial #195 the number of hits was 785371
For Trial #196 the number of hits was 785193
For Trial #197 the number of hits was 785474
For Trial #198 the number of hits was 785401
For Trial #199 the number of hits was 785376
For Trial #200 the number of hits was 785991
For Trial #201 the number of hits was 785139
For Trial #202 the number of hits was 785601
For Trial #203 the number of hits was 785941
For Trial #204 the number of hits was 785501
For Trial #205 the number of hits was 785584
For Trial #206 the number of hits was 786086
For Trial #207 the number of hits was 785174
For Trial #208 the number of hits was 785117
For Trial #209 the number of hits was 785583
For Trial #210 the number of hits was 785779
For Trial #211 the number of hits was 785035
For Trial #212 the number of hits was 785820
For Trial #213 the number of hits was 785177
For Trial #214 the number of hits was 786041
For Trial #215 the number of hits was 785156
For Trial #216 the number of hits was 785679
For Trial #217 the number of hits was 785464
For Trial #218 the number of hits was 785357
For Trial #219 the number of hits was 785360
For Trial #220 the number of hits was 785159
For Trial #221 the number of hits was 785121
For Trial #222 the number of hits was 785222
For Trial #223 the number of hits was 785423
For Trial #224 the number of hits was 784900
For Trial #225 the number of hits was 785876
For Trial #226 the number of hits was 784970
For Trial #227 the number of hits was 785582
For Trial #228 the number of hits was 784871
For Trial #229 the number of hits was 785670
For Trial #230 the number of hits was 784941
For Trial #231 the number of hits was 785415
For Trial #232 the number of hits was 785940
For Trial #233 the number of hits was 784835
For Trial #234 the number of hits was 786003
For Trial #235 the number of hits was 786204
For Trial #236 the number of hits was 785976
For Trial #237 the number of hits was 784660
For Trial #238 the number of hits was 784751
For Trial #239 the number of hits was 784994
For Trial #240 the number of hits was 785607
For Trial #241 the number of hits was 785793
For Trial #242 the number of hits was 785088
For Trial #243 the number of hits was 785840
For Trial #244 the number of hits was 785651
For Trial #245 the number of hits was 785138
For Trial #246 the number of hits was 786086
For Trial #247 the number of hits was 784999
For Trial #248 the number of hits was 785501
For Trial #249 the number of hits was 784745
For Trial #250 the number of hits was 785128
The average number of hits is 785358

C:\Users\18145\source\repos\HouselM_P3\Debug\HouselM_P3.exe (process 24188) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

 */
#include <iostream>
#include<limits.h>
#include<time.h>
#include<cmath>
#include "random.cpp"
#include "plane.cpp"
#include "runway.cpp"
#include "Extend_queue.cpp" 
using namespace std; 
void initialize(int &end_time,int &queue_limit,
				double &arrival_rate,double &departure_rate);
void run_idle(int time,int n);
int main()//Airport simulation program
/*Pre:The user must supply the number of time intervals the simulation is to run,
	  the expected number of planes arriving,the expected number of planes
	  departing per time interval,and the maximum allowed size for runway queues.
  Post:The program performs a random simulation of the airport,showing the
	   status of the runway at each time interval,and prints out a summary of
	   airport operation at the conclusion.
  Uses:Classes Runway,Plane,Random and fuctions run_idle,initialize.*/
{
	int end_time;//time to run simulation
	int queue_limit;//size of Runway queues
	int flight_number=0;
	double arrival_rate,departure_rate;
	initialize(end_time,queue_limit,arrival_rate,departure_rate);
	Random variable;
	Runway small_airport(queue_limit);//初始化跑道1 

	for (int current_time=0;current_time<end_time;current_time++){
		//loop over time intervals
		int number_arrivals=variable.poisson(arrival_rate);//随机产生降落数量
		//current arrival requests
		cout<<"      飞机降落："<<number_arrivals<<endl;
		for (int i=0;i<number_arrivals;i++){
			Plane current_plane(flight_number++,current_time,arriving);//构造每一架降落飞机
			if (small_airport.can_land(current_plane)!=success)//若无法降落则拒绝降落
				current_plane.refuse();
		}
		int number_departures=variable.poisson(departure_rate);//随机产生起飞飞机数量
		//current departure requests
		cout<<"      飞机起飞："<<number_departures<<endl;
		for (int j=0;j<number_departures;j++){
			Plane current_plane(flight_number++,current_time,departing);//构造每一架起飞飞机
			if (small_airport.can_depart(current_plane)!=success)//若无法起飞则拒绝起飞
				current_plane.refuse();
		}
		
		Plane moving_plane;
		switch (small_airport.activity(current_time,moving_plane)){
			//Let at most one Plane onto the Runway at current_time.
			case land:
				moving_plane.land(current_time,1);
				break;
			case take_off:
				moving_plane.fly(current_time,1);
				break;
			case idle:
				run_idle(current_time,1);
		}
	}
	small_airport.shut_down(end_time);
}

void run_idle(int time,int n)
{
	cout<<time<<":Runway "<<n<<" is idle"<<endl;
}

void initialize(int &end_time,int &queue_limit,
				double &arrival_rate,double &departure_rate)
/*Pre:The user specifies the number of time units in the simulation,the maximal
	  queue sizes premitted,and the expected arrival and departure rates for the
	  airport.
  Post:The program prints instructions and initializes the parameters end_time,
	   queue
*/
{
	cout<<"This program simulates an airport with one runway."<<endl
		<<"One plane can land or depart in each unit of time."<<endl;
	cout<<"Up to what number of planes can be waiting to land "
		<<"or take off at any time?"<<flush;
	cin>>queue_limit;
	cout<<"How many units of time will the simulation run?"<<flush;
	cin>>end_time;
	bool acceptable;
	do{
		cout<<"Expected number of arrivals per unit time?"<<flush;
		cin>>arrival_rate;
		cout<<"Expected number of departures per unit time?"<<flush;
		cin>>departure_rate;
		if (arrival_rate<0.0||departure_rate<0.0)
			cerr<<"These rates must be nonnegative."<<endl;
		else
			acceptable=true;
		if (acceptable && arrival_rate+departure_rate>1.0)
			cerr<<"Safety Warning:This airport will become saturated"<<endl;
}while (!acceptable);
}

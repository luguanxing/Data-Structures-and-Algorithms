#ifndef RUNWAY_H
#define RUNWAY_H
#include "Extend_queue.cpp"
enum Runway_activity{idle,land,take_off};//枚举类型跑道状态
class Runway{
public:
	Runway(int limit);
	Error_code can_land(const Plane &current);
	Error_code can_depart(const Plane &current);
	Runway_activity activity(int time,Plane &moving);
	void shut_down(int time) const;
	int landsize();
	int flysize();
	void Refuseland();
	void Refusefly();
private:
	Extend_queue landing;
	Extend_queue takeoff;
	int queue_limit;
	int num_land_requests;//number of planes asking to land
	int num_takeoff_requests;//number of planes asking to take off
	int num_landings;//number of planes that have landed
	int num_takeoffs;//number of planes that have taken off
	int num_land_accepted;//number of planes queued to land
	int num_takeoff_accepted;//number of planes queued to take off
	int num_land_refused;//number of planes rufuesed
	int num_takeoff_refused;//number of departing planes refused  
	int land_wait;//total time of planes waiting to land
	int takeoff_wait;//total time of planes waiting to take off
	int idle_time;//total time runway is idle
};	

Runway::Runway(int limit)//初始化操作
{
	queue_limit=limit;
	num_land_requests=num_takeoff_requests=0;
	num_landings=num_takeoffs=0;
	num_land_refused=num_takeoff_refused=0;
	num_land_accepted=num_takeoff_accepted=0;
	land_wait=takeoff_wait=idle_time=0;
}

Error_code Runway::can_land(const Plane &current)//查询是否可降落
{
	Error_code result;
	if (landing.size()<queue_limit)//队列大小满足要求
		result=landing.append(current);
	else 
		result=fail;
	num_land_requests++;//计数
	if (result!=success)//不满足要求就拒绝
		num_land_refused++;
	else
		num_land_accepted++;
	return result;
}

void Runway::Refuseland()
{
	num_land_refused++;
}

void Runway::Refusefly()
{
	num_takeoff_refused++;
}


Error_code Runway::can_depart(const Plane &current)
{
	Error_code result;
	if (takeoff.size()<queue_limit)
		result=takeoff.append(current);
	else 
		result=fail;
	num_takeoff_requests++;
	if (result!=success)
		num_takeoff_refused++;
	else 
		num_takeoff_accepted++;
	return result;
}
int Runway::landsize()//返回着陆队列大小
{
	return landing.size(); 
}
int Runway::flysize()//返回起飞队列大小
{
	return takeoff.size(); 
}
Runway_activity Runway::activity(int time, Plane &moving)
{
	Runway_activity in_progress;//执行起飞或者降落操作
	if(!landing.empty())//优先考虑降落
	{
		landing.retrieve(moving);//取这个队头以便之后输出信息然后出队
		land_wait+=time-moving.started();//计算等待时间
		num_landings++;
		in_progress=land;
		landing.serve();
	}
	else if (!takeoff.empty())
	{
		takeoff.retrieve(moving);//取这个队头以便之后输出信息然后出队
		takeoff_wait+=time-moving.started();//计算等待时间
		num_takeoffs++;
		in_progress=take_off;
		takeoff.serve();
	}
	else
	{
		idle_time++;
		in_progress=idle;
	}
	return in_progress;
}
void Runway::shut_down(int time)const
{
	 int n1,n2; 
	 n1=num_landings;
	 n2=num_takeoffs;
	 if  (num_landings==0)//防止为0 
	 n1++;
	 if  (num_takeoffs==0)//防止为0 
     n2++;
	cout<<"Simulation has conluded after "<<time<<" time units."<<endl
		<<"Total number of planes processed "
		<<(num_land_requests+num_takeoff_requests)<<endl
		<<"Total number of planes asking to land "
		<<num_land_requests<<endl
		<<"Total number of planes asking to take off "
		<<num_takeoff_requests<<endl
		<<"Total number of planes accepted to land "
		<<num_land_accepted<<endl
		<<"Total number of planes accepted to take off "
		<<num_takeoff_accepted<<endl
		<<"Total number of planes refused to land "
		<<num_land_refused<<endl
		<<"Total number of planes refused to take off "
		<<num_takeoff_refused<<endl
		<<"Total number of planes that landed "
		<<num_landings<<endl
		<<"Total number of planes that took off "
		<<num_takeoffs<<endl
		<<"Total number of planes left in landing queue "
		<<landing.size()<<endl
		<<"Total number of planes left in takeoff queue "
		<<takeoff.size()<<endl;
	cout<<"Percentage of time runway idle "
		<<100.0*((float)idle_time/(float)time)<<"%"<<endl;
	cout<<"Average wait in landing queue "
		<<((float)land_wait/(float)n1)<<" time units"<<endl;
	cout<<"Average wait in takeoff queue "
		<<((float)takeoff_wait/(float)n2)<<" time units"<<endl;
	cout<<"Average observed rate of plane wanting to land "
		<<((float)num_land_requests/(float)time)<<" per time units"<<endl;
	cout<<"Average observed rate of plane wanting to land "
		<<((float)num_takeoff_requests/(float)time)<<" per time units"<<endl;
}
#endif

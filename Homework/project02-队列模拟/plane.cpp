#ifndef PLANE_H
#define PLANE_H
enum Plane_status{null,arriving,departing};
class Plane{
public:
	Plane();
	Plane(int flt,int time,Plane_status status);
	void refuse() const;
	void land(int time,int n) const;
	void fly(int time,int n) const;
	int started() const;
private:
	int flt_num;
	int clock_start;
	Plane_status state;

};

Plane::Plane(int flt,int time,Plane_status status)
{
	flt_num=flt;
	clock_start=time;
	state=status;
	cout<<"Plane number "<<flt<<" ready to ";
	if(status==arriving)
	{
		cout<<"land."<<endl;
	}
	else
		cout<<"take off."<<endl;
}

Plane::Plane()
{
	flt_num=-1;
	clock_start=-1;
	state=null;
}

void Plane::refuse()const
{
	cout<<"Plane number "<<flt_num;
	if(state==arriving)
		cout<<" directed to another airport"<<endl;
	else
		cout<<" told to try to takeoff again later"<<endl;
}

void Plane::land(int time,int n)const
{
	int wait=time-clock_start;
	cout<<time<<":Plane number "<<flt_num<<" landed after "
		<<wait<<" time unit"<<((wait==1)?"":"s")<<" in the landing queue "
		<<" to runway "<<n<<endl;
}

void Plane::fly(int time,int n)const
{
	int wait=time-clock_start;
	cout<<time<<":Plane number "<<flt_num<<" took off after "
		<<wait<<" time unit"<<((wait==1)?"":"s")<<" in the takeoff queue "
		<<" to runway "<<n<<endl;
}
int Plane::started()const
{
	return clock_start;
}
#endif

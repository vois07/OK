#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <set>
using namespace std;

//args: n m

struct Task
{
	int time,begin,end;
};

struct TimeNumberPair
{
	int time, number;
};

bool fncomp (TimeNumberPair lhs, TimeNumberPair rhs) {return lhs.time < rhs.time;}

int main(int argc,char **argv)
{
	ostringstream convert;
	ifstream ifile;
    ofstream sfile;
    int n, m, cmax=0;
    if (argc < 2) {cout<< "Too few arguments given\n"; return -1;}
    
	convert << "dane//" << argv[1];
	ifile.open(convert.str().c_str());
	convert.str("");	

	convert<< "wyniki//solution_" << argv[1];
	sfile.open(convert.str().c_str());

	
	ifile>>m>>n;
	sfile<<m<<" "<<n<<endl;

	bool(*fn_pt)(TimeNumberPair,TimeNumberPair) = fncomp;
	multiset<TimeNumberPair,bool(*)(TimeNumberPair,TimeNumberPair)> chooseProc(fn_pt);

	TimeNumberPair tnp;
	for(int i=0; i<m; i++) {tnp.time=0; tnp.number=i; chooseProc.insert(tnp);}

	sfile<<"task times: ";
	Task *taskLib = new Task[n];
	for(int i=0; i<n; i++) {ifile>>taskLib[i].time; sfile<<taskLib[i].time<<", ";}
	

	sfile<<endl<<"proc_nr | curr_time | task_nr | task_beg | task_time | task_end"<<endl;
	for (int i=0; i<n; i++)
	{
		int id = (*(chooseProc.begin())).number;
		int time = (*(chooseProc.begin())).time;
		chooseProc.erase(chooseProc.begin());
		
		sfile << "\t" << id << "\t" << time << "\t";
		taskLib[i].begin = time;
		taskLib[i].end = time + taskLib[i].time;
		time += taskLib[i].time;
		tnp.number = id;
		tnp.time = time;
		chooseProc.insert(tnp);
		sfile << i << "\t" << taskLib[i].begin << "\t" << taskLib[i].time << "\t" <<taskLib[i].end<<endl;
        	if(taskLib[i].end > cmax) cmax = taskLib[i].end;
	}
	sfile<<cmax;
	cout<< "C_max = " << cmax << endl;
	
	delete[] taskLib;
	return 0;
}

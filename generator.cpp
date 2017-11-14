#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

//args: m n

int main(int argc, char **argv)
{
	ostringstream convert;
	ofstream sfile;
	string name;
	int n, m;

	if (argc > 2) {n = atoi(argv[1]); m = atoi(argv[2]);}
	else if (argc == 2) {n = atoi(argv[1]); m = 2;}
    if (argc < 2 || n == 0) {n = rand()%1000+1;}
    if (m == 0) m = 2;

	convert << "dane//dane" << n <<"_"<< m;
	name = convert.str() ;

	sfile.open(name.c_str());
	sfile<<m<<"\n"<<n<<"\n";

	srand (time(NULL));
	for (int i = 0; i < n; i++)
	{
		sfile<<rand()%(10*n)+1<<"\n";
	}

	sfile.close();
	return 0;	
}

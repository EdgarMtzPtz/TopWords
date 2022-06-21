#include "frases.h"
#include<time.h>

int main()
{

	//

	clock_t startTime = clock();
	
	//create main thing
	frasestops maps;
	
	//feed it
	//"hw2_huckleberryFinn.txt"
	maps.feed("hw2_huckleberryFinn.txt"); //37.837 seconds
	maps.feed("hw2_tomSawyer.txt"); //27.333
	//maps.feed("test.txt"); //27.333
	//64.306 secs
	
	maps.print();
	//print out the top 10 phrases 
	cout << double(clock() - startTime) / (double)CLOCKS_PER_SEC << " seconds." << endl;
	
	cout << "Assignment complete." << endl;
	system("pause");
	return 0;
}
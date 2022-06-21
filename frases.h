#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <fstream>



using namespace std;

class frasestops {

public:
	class info {
	public:
		info(string x, int y, string z) {
			nada = x;
			num = y;
			fbook1 = y;
			fbook2 = y;
			book1 = z;
		}
		string nada;
		string book1;
		int num;
		
		//string book2;
		int fbook1;
		int fbook2;
	};

	//feed()
	void feed(string y)
	{
		//y is just the txt file
		ifstream f;
		f.open(y);

		string wordone;
		string wordtwo;
		string wordthree;
		string wordfour;
		string wordfive;
		string wordsix;
		string wordseven;
		string wordeight;
		string wordnine;
		string wordten;

		f >> wordone;
		f >> wordtwo;
		f >> wordthree;
		f >> wordfour;
		f >> wordfive;
		f >> wordsix;
		f >> wordseven;
		f >> wordeight;
		f >> wordnine;
		f >> wordten;

			while (!f.eof())
			{
				//cout << "Main loop: " << endl;
				string word;
				

				f >> word;
				//cout << word << endl;
				//mapit(word, onefrases, onefrase); //here it should take, the word, it's respective map and top ten
				//unordered_map<string, info*> frases;
				//vector<info*>topten;

				string fone = wordone;
				string ftwo = fone + " " + wordtwo;
				string fthree = ftwo + " " + wordthree;
				string ffour = fthree + " " + wordfour;
				string ffive = ffour + " " + wordfive;
				string fsix = ffive + " " + wordsix;
				string fseven = fsix + " " + wordseven;
				string feight = fseven + " " + wordeight;
				string fnine = feight + " " + wordnine;
				string ften = fnine + " " + wordten;
				
				//cout << "		This is fone:" << fone << endl;
				/*cout << "		This is 2:" << ftwo << endl;
				cout << "		This is fthree:" << fthree << endl;
				cout << "		This is ffour:" << ffour << endl;
				cout << "		This is ffive:" << ffive << endl;
				cout << "		This is fsix:" << fsix << endl;
				cout << "		This is fseven:" << fseven << endl;
				cout << "		This is feight:" << feight << endl;
				cout << "		This is fnine:" << fnine << endl;
				cout << "		This is ften:" << ften << endl << endl;*/

				mapit(fone, onefrases, onefrase,y);
				mapit(ftwo, twofrases, twofrase,y);
				mapit(fthree, threefrases, threefrase,y);
				mapit(ffour, fourfrases, fourfrase,y);
				mapit(ffive, fivefrases, fivefrase,y);
				mapit(fsix, sixfrases, sixfrase,y);
				mapit(fseven, sevenfrases, sevenfrase,y);
				mapit(feight, eightfrases, eightfrase,y);
				mapit(fnine, ninefrases, ninefrase,y);	
				mapit(ften, tenfrases, tenfrase,y);

				shiftwords(wordone, wordtwo, wordthree, wordfour, wordfive, wordsix, wordseven, wordeight, wordnine, wordten,word);
				if (f.eof())
				{
					//cout << endl;
					word.clear();
					while (!wordone.empty()) {
						//shiftwords(wordone, wordtwo, wordthree, wordfour, wordfive, wordsix, wordseven, wordeight, wordnine, wordten, word);
						 fone = wordone;
						 ftwo = fone + " " + wordtwo;
						 fthree = ftwo + " " + wordthree;
						 ffour = fthree + " " + wordfour;
						 ffive = ffour + " " + wordfive;
						 fsix = ffive + " " + wordsix;
						 fseven = fsix + " " + wordseven;
						 feight = fseven + " " + wordeight;
						fnine = feight + " " + wordnine;
						ften = fnine + " " + wordten;

						//cout << "		This is fone:" << fone << endl;
						/*cout << "		This is 2:" << ftwo << endl;
						cout << "		This is fthree:" << fthree << endl;
						cout << "		This is ffour:" << ffour << endl;
						cout << "		This is ffive:" << ffive << endl;
						cout << "		This is fsix:" << fsix << endl;
						cout << "		This is fseven:" << fseven << endl;
						cout << "		This is feight:" << feight << endl;
						cout << "		This is fnine:" << fnine << endl;
						cout << "		This is ften:" << ften << endl << endl;*/


						if (!fone.empty()) {
							mapit(fone, onefrases, onefrase,y);
						}
						if (!ftwo.empty()) {
							mapit(ftwo, twofrases, twofrase,y);
						}
						if (!fthree.empty()) {
							mapit(fthree, threefrases, threefrase,y);
						}
						if (!ffour.empty()) {
							mapit(ffour, fourfrases, fourfrase,y);
						}
						if (!ffive.empty()) {
							mapit(ffive, fivefrases, fivefrase,y);
						}
						if (!fsix.empty()) {
							mapit(fsix, sixfrases, sixfrase,y);
						}
						if (!fseven.empty()) {
							mapit(fseven, sevenfrases, sevenfrase,y);
						}
						if (!feight.empty()) {
							mapit(feight, eightfrases, eightfrase,y);
						}
						if (!fnine.empty()) {
							mapit(fnine, ninefrases, ninefrase,y);
						}
						if (!ften.empty()) {
							mapit(ften, tenfrases, tenfrase,y);
						}
						shiftwords(wordone, wordtwo, wordthree, wordfour, wordfive, wordsix, wordseven, wordeight, wordnine, wordten, word);
					}
				}
				//cout << endl;
			}
			f.close();

			
	}
	

	void mapit(string x, unordered_map<string, info*> &map, vector<info*> &top, string book) {
		//cout << x << endl;
		//take in a text and loops it to get data
		//string x = getword();

		//look for it in the map
		unordered_map<string,info*>::const_iterator got =map.find(x);
		//cout << "		did found it ";
		info* tmp = nullptr;
		//cout << "tmp did work ";
		if (got == map.end()) {
			//cout << " not on data mapper ";
			map.emplace(x, tmp = new info(x, 1,book));
		}
		else
		{
			tmp = got->second;
			//cout << " in data mapper ";
			//update the number
			tmp->num++;
			if (tmp->book1 == book) {
				tmp->fbook1++;
			}
			else
			{
				tmp->fbook2++;
			}
		}
		//cout << " emplace it";
		//goes to top function
		topit(tmp,top);
		//cout << " top it ";
		list.push_back(tmp);
		//cout << " finish with it" << endl;
		//cout << endl;

	}

	//print()
	void print() {
		ofstream myfile;
		myfile.open("example.txt");
		//prints the tops 10 of the vector
		print("one", onefrase, myfile);
		print("two", twofrase, myfile);
		print("three", threefrase, myfile);
		print("four", fourfrase, myfile);
		print("five", fivefrase, myfile);
		print("six", sixfrase, myfile);
		print("seven", sevenfrase, myfile);
		print("eight", eightfrase, myfile);
		print("nine", ninefrase, myfile);
		print("ten", tenfrase, myfile);
		myfile.close();
		
	}


private:

	void shiftwords(string &one, string &two, string &three, string &four, string &five, string &six, string &seven, string &eight, string &nine, string &ten, string &eleven) {
		one = two;
		two = three;
		three = four;
		four = five;
		five = six;
		six = seven;
		seven = eight;
		eight = nine;
		nine = ten;
		ten = eleven;
	}

	void print(string y,vector<info*>&x, ofstream &myfile) {

		//ofstream myfile;
		//myfile.open("example.txt");
		//myfile << "Writing this to a file.\n";
		

		//cout << endl;
		//this is the top ten list for 
		myfile << "this is the top ten list for "<< y << " word phrases" << endl;
		for (int i = 0; i < x.size(); i++) {
			myfile << i+1 << "'st\" "<< x[i]->nada << "\"	 with score of	:" << x[i]->fbook1+ x[i]->fbook2 << endl;
			myfile << "frequency_in_Huckleberry_Finn :" << x[i]->fbook1 << endl;
			myfile << "frequency_in_Tom_Sawyer :" << x[i]->fbook2 << endl;
			myfile << endl;
			//cout << x[i]->book1 << endl;
		}
		//myfile.close();
		myfile << endl << endl;
		//phrase frequency_in_Tom_Sawyer frequency_in_Huckleberry_Finn 
	}
//class info {
//	public:
//		info(string x, int y) {
//			nada = x;
//			num = y;
//		}
//		string nada;
//		int num;
//	};
	//wee need a hash table takes a stirng as key
	//the kay then gives the value that needs to be updated
	//had to change it to string, pointer to something because you can't change the value of an int
	unordered_map<string, info*> onefrases;
	unordered_map<string, info*> twofrases;
	unordered_map<string, info*> threefrases;
	unordered_map<string, info*> fourfrases;
	unordered_map<string, info*> fivefrases;
	unordered_map<string, info*> sixfrases;
	unordered_map<string, info*> sevenfrases;
	unordered_map<string, info*> eightfrases;
	unordered_map<string, info*> ninefrases;
	unordered_map<string, info*> tenfrases;

	//we need a vector
	//I decided to make the vector hold something that has two values
	//this vector will hold our pointers to the list ;)
	vector<info*> list;
	//this vector will keep top10
	vector<info*>onefrase;
	vector<info*>twofrase;
	vector<info*>threefrase;
	vector<info*>fourfrase;
	vector<info*>fivefrase;
	vector<info*>sixfrase;
	vector<info*>sevenfrase;
	vector<info*>eightfrase;
	vector<info*>ninefrase;
	vector<info*>tenfrase;
	
	
	string getword() {
		string x;

		//reads from file then returns the string


		return x;
	}
	void checkifitcanmoveupagain(int index, info* tmp, vector<info*> &top) {
		//cout << "cheecking if it can move up" << endl;
		//cout << "		" << top[index]->nada << " this is tmp: " << tmp->nada << endl;
		if (index == 0) {
			//exit
		}
		else if (top[index]->num < top[index - 1]->num) {
			
		}
		else
		{	
			//cout <<tmp->nada<< " cheecking if it can move up" << endl;
			//top[x]->num >= top[x - 1]->num)
			info* caca = top[index]; //will hold the x value
			info* popo = top[index- 1]; // will hold the x-1 value
			top[index] = popo;
			top[index - 1] = caca;
			checkifitcanmoveupagain(index-1, tmp, top); //where is at, it's tmp, and the list
		}
	}

	bool onthelist(info* tmp, vector<info*> &top) {

		if (tmp == top[0]) {
			//because it's at the top then it's not require to move
			//cout << "enter in the top" << endl;
			return true;
		}
		else {
			//cout << "enter not at the top" << endl;
			bool i = 0;//this is no
			for (int x = 0; x < top.size(); x++) {
				if (tmp == top[x]) {
					//cout << "the tmp and top[x] are equal";
					i = 1; //this ensures that when the pointer is found in top teen then we return true
					if (top[x]->num > top[x - 1]->num) //x is bigger or equal to the number previous to it, this will never value 0 because that was the first case
					{
						//cout << "this is on the list and it adds a number" << endl;
						//swap the firsts place with the second because one is bigger than the other one
						info* caca = top[x]; //will hold the x value
						info* popo = top[x - 1]; // will hold the x-1 value
						top[x] = popo;
						top[x - 1] = caca;
						checkifitcanmoveupagain(x-1,tmp, top); //where is at, it's tmp, and the list
					}
				}

			}
			return i;
		}
	}
	void topit(info* tmp, vector<info*> &top) {
		//if top ten empty then just push
		if (top.empty()) {
			//cout << "top is empty" << endl;
			top.push_back(tmp);
		}
		else
			if (onthelist(tmp,top)) {
				//check if already on top ten with function
				//if it is it takes care of it
				//cout << "exit on the list" << endl;
			}
			else if (top.size() < 10) {
				//top then is not full
				top.push_back(tmp);
				//cout << "this was just push back" << endl;
			}
			else
				//compare with last one, if bigger or equal then replace
			{
				//cout << "it was compare with the last one to see if it was bigger";
				if (top[9]->num < tmp->num) {
					top[9] = tmp;
					checkifitcanmoveupagain(9, tmp, top); //must check if it can move up after being place in the list in case all the others ones are 1 and this one is 2
				//	cout << ": it was bigger" << endl;
				}
				//cout << endl;
			}
	}
};


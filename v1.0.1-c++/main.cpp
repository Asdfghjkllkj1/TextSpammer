#include <iostream>

#include <iostream>

#include <fstream>

#include <sstream>

#include <windows.h>

#include <vector>

#include <map>

#include <limits>
using namespace std;

map<char,int> charHex;
int offset;

void spam(vector<string> lines, bool difLine = true, int rep = 1, string line="")
{
	//for regular letter pressing
	INPUT ip;
	ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    //for shift pressing
	INPUT ip2;
	ip2.type = INPUT_KEYBOARD;
	ip2.ki.wScan = 0; // hardware scan code for key
	ip2.ki.time = 0;
	ip2.ki.dwExtraInfo = 0;
	//for newlining
	INPUT ip3;
	ip3.type = INPUT_KEYBOARD;
	ip3.ki.wScan = 0; // hardware scan code for key
	ip3.ki.time = 0;
	ip3.ki.dwExtraInfo = 0;
	cout << "Run." << endl;
	Sleep(5000);
	if (lines.size()>0) {
		//print all stuff in line
		for (auto line : lines) {
			//print line in lines
			for (char& ch : line) {
				//print ch in line
				bool chUpper = isupper(ch);
				if (chUpper) {
					ip2.ki.wVk = VK_SHIFT; // virtual-key code for the key left shift
					ip2.ki.dwFlags = 0; // 0 for key press
					SendInput(1, &ip2, sizeof(INPUT));
				}
				ip.ki.wVk = charHex[ch]; // virtual-key code for the key through charHex map
				ip.ki.dwFlags = 0; // 0 for key press
				SendInput(1, &ip, sizeof(INPUT));
				ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &ip, sizeof(INPUT));
				if (chUpper) {
					ip2.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
					SendInput(1, &ip2, sizeof(INPUT));
				}
			}
			if (difLine) {
				ip3.ki.wVk = VK_RETURN; // virtual-key code for the key \n
				SendInput(1, &ip3, sizeof(INPUT));
				ip3.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
				SendInput(1, &ip3, sizeof(INPUT));
			}
			Sleep(offset);
		}
	}
	else {
		for (int i = 0; i<rep; i++) {
			for (char& ch : line) {
				//print ch in line
				bool chUpper = isupper(ch);
				if (chUpper) {
					ip2.ki.wVk = VK_SHIFT; //code for shift
					ip2.ki.dwFlags = 0; //0 for key press mode
					SendInput(1, &ip2, sizeof(INPUT));
				}
				ip.ki.wVk = charHex[ch]; //charhex char
				ip.ki.dwFlags = 0; //0 for key press mode
				SendInput(1, &ip, sizeof(INPUT));
				ip.ki.dwFlags = KEYEVENTF_KEYUP; //key release
				SendInput(1, &ip, sizeof(INPUT));
				if (chUpper) {
					ip2.ki.dwFlags = KEYEVENTF_KEYUP; //shift key release
					SendInput(1, &ip2, sizeof(INPUT));
				}
			}
			if (difLine) {
				ip3.ki.wVk = VK_RETURN; //code for enter
				SendInput(1, &ip3, sizeof(INPUT));
				ip3.ki.dwFlags = KEYEVENTF_KEYUP; //key release
				SendInput(1, &ip3, sizeof(INPUT));
			}
			Sleep(offset);
		}
	}
	ip3.ki.wVk = VK_RETURN; //code for enter
	SendInput(1, &ip3, sizeof(INPUT));
	ip3.ki.dwFlags = KEYEVENTF_KEYUP; //key release
	SendInput(1, &ip3, sizeof(INPUT));
	//^^ final enter press
}

int parse_txt(string filename, vector<string> &out)
{
	ifstream file;
	string line;
	file.open(filename);
	if (file.is_open()) {
		while (getline(file,line)) {
			out.push_back(line);
		}
		return 0;
	}
	else {
		cout << "Unable to open file " << filename << endl;
		return 1;
	}
}

void pCHex()
{
	charHex.insert(pair<char,int>(' ',0x20));
	charHex.insert(pair<char,int>('\n',0x0D));
	//lowercase
	charHex.insert(pair<char,int>('a',0x41));
	charHex.insert(pair<char,int>('b',0x42));
	charHex.insert(pair<char,int>('c',0x43));
	charHex.insert(pair<char,int>('d',0x44));
	charHex.insert(pair<char,int>('e',0x45));
	charHex.insert(pair<char,int>('f',0x46));
	charHex.insert(pair<char,int>('g',0x47));
	charHex.insert(pair<char,int>('h',0x48));
	charHex.insert(pair<char,int>('i',0x49));
	charHex.insert(pair<char,int>('j',0x4A));
	charHex.insert(pair<char,int>('k',0x4B));
	charHex.insert(pair<char,int>('l',0x4C));
	charHex.insert(pair<char,int>('m',0x4D));
	charHex.insert(pair<char,int>('n',0x4E));
	charHex.insert(pair<char,int>('o',0x4F));
	charHex.insert(pair<char,int>('p',0x50));
	charHex.insert(pair<char,int>('q',0x51));
	charHex.insert(pair<char,int>('r',0x52));
	charHex.insert(pair<char,int>('s',0x53));
	charHex.insert(pair<char,int>('t',0x54));
	charHex.insert(pair<char,int>('u',0x55));
	charHex.insert(pair<char,int>('v',0x56));
	charHex.insert(pair<char,int>('w',0x57));
	charHex.insert(pair<char,int>('x',0x58));
	charHex.insert(pair<char,int>('y',0x59));
	charHex.insert(pair<char,int>('z',0x5A));
	//uppercase
	charHex.insert(pair<char,int>('A',0x41));
	charHex.insert(pair<char,int>('B',0x42));
	charHex.insert(pair<char,int>('C',0x43));
	charHex.insert(pair<char,int>('D',0x44));
	charHex.insert(pair<char,int>('E',0x45));
	charHex.insert(pair<char,int>('F',0x46));
	charHex.insert(pair<char,int>('G',0x47));
	charHex.insert(pair<char,int>('H',0x48));
	charHex.insert(pair<char,int>('I',0x49));
	charHex.insert(pair<char,int>('J',0x4A));
	charHex.insert(pair<char,int>('K',0x4B));
	charHex.insert(pair<char,int>('L',0x4C));
	charHex.insert(pair<char,int>('M',0x4D));
	charHex.insert(pair<char,int>('N',0x4E));
	charHex.insert(pair<char,int>('O',0x4F));
	charHex.insert(pair<char,int>('P',0x50));
	charHex.insert(pair<char,int>('Q',0x51));
	charHex.insert(pair<char,int>('R',0x52));
	charHex.insert(pair<char,int>('S',0x53));
	charHex.insert(pair<char,int>('T',0x54));
	charHex.insert(pair<char,int>('U',0x55));
	charHex.insert(pair<char,int>('V',0x56));
	charHex.insert(pair<char,int>('W',0x57));
	charHex.insert(pair<char,int>('X',0x58));
	charHex.insert(pair<char,int>('Y',0x59));
	charHex.insert(pair<char,int>('Z',0x5A));
	//numbers
	charHex.insert(pair<char,int>('0',0x30));
	charHex.insert(pair<char,int>('1',0x31));
	charHex.insert(pair<char,int>('2',0x32));
	charHex.insert(pair<char,int>('3',0x33));
	charHex.insert(pair<char,int>('4',0x34));
	charHex.insert(pair<char,int>('5',0x35));
	charHex.insert(pair<char,int>('6',0x36));
	charHex.insert(pair<char,int>('7',0x37));
	charHex.insert(pair<char,int>('8',0x38));
	charHex.insert(pair<char,int>('9',0x39));
}

int main()
{
	pCHex();
	char mode;
	string filename;
	vector<string> out;
	cout << "Spammer v1.0.1 C++ by AJ; 1/29/2021\nNOTE: *The author* is not responsible for any actions preformed using this script.\nNOTE 2: Special characters are not yet supported\nModes:\ns: prints every line from text file with enters in between\nb: concatenates all lines in text file into one big line and press enter\nm: manual; you enter what you want spammed and how many times you need it spammed\nWhat mode? ";
	cin >> mode;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	try {
		cout << "How much time (sec) between spams? ";
		cin >> offset;
	}
	catch (exception){
		cout << "Invalid type for time. Defaulting to 0.75s. " << endl;
		offset = 0.75;
	}
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	offset*=1000;
	if (mode=='s'||mode=='b') {
		cout << "What filename (to spam with)? ";
		cin >> filename;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		if (parse_txt(filename, out)==0){
			if (mode=='s') {
				spam(out);
			}
			else {
				spam(out,false);;
			}
		}
		else {
			cout << "Exiting... " << endl;
			system("pause");
			return 0;
		}
	}
	else if (mode=='m') {
		string body;
		cout << "What to spam? ";
		cin >> body;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		int rep;
		cout << "Spam '" << body << "' how many times? ";
		cin >> rep;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		vector<string> blank;
		spam(blank, true, rep, body);
	}
	else {
		cout << "Unrecognized command. (Check that you only entered one letter (the name of the mode)?), exiting..." << endl;
		system("pause");
		return 0;
	}
	cout << "Spamming complete." << endl;
	system("pause");
	return 0;
}

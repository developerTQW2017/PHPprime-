#include<iostream>
using namespace std;
string zipString(string iniString){
        // write code here        
	int length = iniString.size();
        if(length == 0)
            return "";
        int i = 0;
        int j = 0;
        string str;
        while(i < length)        {
            while(i < length && iniString[i] == iniString[j])
                i++;
            str += iniString[j];
            str += to_string(i-j);
            j=i;        }
        if(str.size() >= length)
            return iniString;
        else
            return str;
        return iniString;}
string unzipString(String decodestring){
        int length = decodestring.size();
    if(length == 0)
        return "";
    int i = 0;
    int j = 0;
    string str;
    while(i < length)    {
        while(i < length && decodestring[i] >'0' &&decodestring[i] < '9')
            str += decodestring[j];
            i++;
                str += to_string(i-j);
        j=i;    }
    if(str.size() >= length)
        return iniString;
    else
        return str;
    return iniString;}
int main(){
    string str;
    while(cin>>str){
        cout << zipString(str) << endl;
    }
    return 0;
}

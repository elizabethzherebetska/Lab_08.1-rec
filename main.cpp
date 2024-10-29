#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int Count(const char* str, int i) {
    if (str[i] == '\0' || str[i + 1] == '\0') 
        return 0;

    if (str[i] == ',' && str[i + 1] == '-')
        return 1 + Count(str, i + 2); 
    else
        return Count(str, i + 1); 
}

char* Change(const char* str, char* dest, int i) {
    if (str[i] == '\0') { 
        *dest = '\0'; 
        return dest;
    }

    if (str[i] == ',' && str[i + 1] == '-') { 
        *dest++ = '*'; 
        return Change(str, dest, i + 2); 
    }
    else {
        *dest++ = str[i]; 
        return Change(str, dest, i + 1); 
    }
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int count = Count(str, 0);
    cout << "String contained " << count << " groups of ',-'" << endl;

    char* dest = new char[strlen(str) * 2 + 1]; 
    Change(str, dest, 0); 

    cout << "Modified string (param): " << str << endl; 
    cout << "Modified string (result): " << dest << endl; 

    delete[] dest; 
    return 0;
}

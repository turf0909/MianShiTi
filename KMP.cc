#include <iostream>
using namespace std;

int getsize(char* s) {
    if(s == NULL)
        return 0;
    int size = 0;
    while(*(s+size) != '\0') {
        size++;
    }
    return size;
}


int* getNextArray(char match[], int *next) {
    if(match == NULL || getsize(match) < 2) {
        next[0] = -1;
        return next;
    }

    int pos = 2;
    int cn = 0;
    next[0] = -1;
    next[1] = 0;

    while(pos < getsize(match)) {
        if(match[pos-1] == match[cn])
            next[pos++] = ++cn;
        else if(cn > 0)
            cn = next[cn];
        else
            next[pos++] = 0;
    }
    return next;
}

int getindex(char* s, char* m, int* na) {
    if(s == NULL || m == NULL || getsize(s) < getsize(m))
        return -1;

    int si = 0;
    int mi = 0;
    int *next = getNextArray(m,na);

    while(si < getsize(s) && mi < getsize(m)) {
        if(s[si] == m[mi]) {
            si++;
            mi++;
        }
        else if(next[mi] == -1) {
            si++;
        }
        else {
            mi = next[mi];
        }
    }
    return mi == getsize(m) ? si-mi : -1;
}

int main() {
    char s[] = "acbc";
    char m[] = "bc";
    int *next = new int[getsize(m)];
    cout<<getindex(s,m,next)<<endl;
    delete []next;
    next = NULL;

    char s1[] = "acbc";
    char m1[] = "bcc";
    int *next1 = new int[getsize(m)];
    cout<<getindex(s1,m1,next1)<<endl;
    delete []next1;
    next1 = NULL;

    return 0;
}


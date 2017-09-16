#ifndef GOLF_H_INCLUDED
#define GOLF_H_INCLUDED

const int cLen = 40;
const int ctabSize = 4;
struct golf
{
    char fullname[cLen];
    int handicap;
};

void setgolf(golf & g, const char * name, int hc);

void setgolf(golf & g);

void deletegolf(golf & g);

void handicap(golf & g,int hc);

void showgolf(const golf & g);

void showall(const golf g[]);

bool menu(golf g[],int tsize);

#endif // GOLF_H_INCLUDED

#ifndef ILIST_HH
#define ILIST_HH

class iList{

public:
    virtual bool add(int element,int& position)=0;
    virtual bool rm(int& position)=0;
    virtual iList get(int& postition)=0;
    virtual unsigned int size()=0;
    virtual int find(int& identificator)=0;
};

#endif
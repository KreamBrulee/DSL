#include <iostream>

using namespace std;

struct flts{
    float dat;
    flts *next;
};
class nums{
    float *head;

    public:
    nums(){
        head = NULL;
    }

    void add(float dat){
        flts *nn = new flts;

        if(!nn)
            return;
        nn->next
    }
};
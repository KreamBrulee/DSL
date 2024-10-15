#include <iostream>
using namespace std;

struct song
{
    int sid;
    string title;
    string artist;
    float duration;
    song *next;
    song *prev; 
};

    
class playlist
{
    song *header;
    public:
    
    playlist()
    {
        header = NULL;
    }

    void setSong(string tit, int id)
    {
        song *ns = new song;
        ns->title = tit;
        ns->sid = id;
        ns->next = NULL;

        if(header == NULL)
        {
            header = ns;
        }
        else
        {
            song *tempf = header;
            while(tempf->next)
            {
                tempf = tempf->next;
            }

            tempf->next = ns;
            ns->prev = tempf; 
        }
    }
    void getSong(int s)
    {
        song *tempf = header;
        while(tempf)
        {
            if(tempf->sid == s)
            {
                playSong(tempf);
            }
            tempf = tempf->next;
        } 
    }

    void getSong(string tit)
    {
        song *tempf = header;
        while(tempf)
        {
            if(!tempf->title.compare(tit))
            {
                playSong(tempf);
            }
            tempf = tempf->next;
        }
    }

    void playAll()
    {
        song *tempf = header;
        while(tempf)
        {
            playSong(tempf);
            tempf = tempf->next;
        }
    }

    void playSong(song *s)
    {
        cout<<s->sid<<"\t"<<s->title<<"\n";
        return;
    }

    void operator+(playlist two)
    {

        song *tempf = header;
        if(!header)
        {
            cout<<"Empty playlists cant be merged.";
            return;
        }
        
        while(tempf->next)
        {
            tempf = tempf->next;
        }
        tempf->next = two.header;

    }
};

int main()
{
    playlist p;
    p.setSong("your mom", 5);
    p.setSong("her mom", 6);
    p.setSong("his mom", 9);
    p.setSong("therir mom", 2);

    cout<<"\n";
    p.getSong(6);               //Find by id

    cout<<"\n";
    p.getSong("your mom");      //find by title

    cout<<"\n";
    p.playAll();
    return(0);
}

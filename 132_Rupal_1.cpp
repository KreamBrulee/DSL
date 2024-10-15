/*
Consider a student database of SY COMP class (at least 15 records). Database contains different
fields of every student like Roll No, Name and SGPA.
a. Design a roll call list, arrange list of students according to roll numbers in ascending order
using Insertion Sort
b. Arrange list of students alphabetically using shell sort
c. Arrange list of students to find out first ten toppers from a class using Radix sort
*/

#include<iostream>
#include<string>

using namespace std;


class Student {

    // private data members
    public:
    string name;
    string prn;
    int SGPA;

    public:
    void setdata(string name, string prn, int SGPA) {
        this->name = name;
        this->prn = prn;
        this->SGPA = SGPA;
    }

    void showdata() {
        cout<<"\t\t\t"<<name<<"\t\t\t"<<prn<<"\t\t\t"<<SGPA<<endl;
    }

    string get_name() {
        return name;
    }

    int getSGPA() {
        return SGPA;
    }

    friend void insertion_Sort_by_SGPA(Student *arr,int no_of_studs);
    friend void Shell_Sort_by_Name(Student *arr,int no_of_studs);
    friend void Radix_Sort_to_get_toppers(Student *arr,int no_of_studs);

};

void insertion_Sort_by_SGPA(Student arr[],int no_of_studs) {
    for(int i=0; i<no_of_studs; i++) {
        Student key = arr[i];

        int j = i-1;
        while(j >=0 && arr[j].SGPA > key.SGPA) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void Shell_Sort_by_Name(Student arr[], int n) {
   
   for(int gap = n/2; gap > 0; gap/=2) {
        for(int i=gap; i<n; i++) {
            Student temp = arr[i];
            int j = i;
            while(j >= gap && arr[j-gap].get_name() > temp.get_name()) {
                    arr[j] = arr[j-gap];
                    j -= gap;
            }
            arr[j] = temp;
        }
   }
}


int getmax(Student s[], int n) {
    int mx = s[0].getSGPA();
    
    for (int i = 0; i < n; i++) {
        if (s[i].getSGPA() > mx) {
            mx = s[i].getSGPA();
        }
    }
    return mx;
}

void radixsort(Student s[], int n, int b) {
    Student output[n];
    int count[10] = {0};
    
    for (int i = 0; i < n; i++) {
        count[(s[i].getSGPA() / b) % 10]++;
    }
    
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (s[i].getSGPA() / b) % 10;
        output[count[digit] - 1] = s[i];
        count[digit]--;
    }
    
    for (int i = 0; i < n; i++) {
        s[i] = output[i];
    }
} 

void Radix_Sort_to_get_toppers(Student s[], int n) {
    int m = getmax(s, n);
    for (int b = 1; m / b > 0; b *= 10) {
        radixsort(s, n, b);
    }
}

void get_top_ten_toppers(Student s[]) {
    cout<<"\t\t\t\t\t<---------------TOP TEN TOPPERS ARE--------------->"<<endl;
    cout<<"\t\t\t\tNAME\t\t\t\tPRN\t\t\t\tSGPA"<<endl;
    for(int i=19; i>=10; i--) {
        s[i].showdata();
    }
}

int main() {
    Student s[20];
    int n = 20;

    // Data of 20 Students
    s[0].setdata("Aarav Patel", "000A1A001", 6);
    s[1].setdata("Maya Sharma", "001B2B002", 7);
    s[2].setdata("Ravi Kumar", "002C3C003", 8);
    s[3].setdata("Sanya Verma", "003D4D004", 6);
    s[4].setdata("Ishaan Gupta", "004E5E005", 7);
    s[5].setdata("Neha Singh", "005F6F006", 8);
    s[6].setdata("Arjun Rao", "006G7G007", 7);
    s[7].setdata("Priya Menon", "007H8H008", 8);
    s[8].setdata("Rohit Desai", "008I9I009", 5);
    s[9].setdata("Kavya Reddy", "009J0J010", 9);
    s[10].setdata("Vikram Joshi", "010K1K011", 10);
    s[11].setdata("Tanuja Rao", "011L2L012", 9);
    s[12].setdata("Amit Patel", "012M3M013", 6);
    s[13].setdata("Ritika Shah", "013N4N014", 8);
    s[14].setdata("Ankit Sharma", "014O5O015", 5);
    s[15].setdata("Pooja Kumar", "015P6P016", 9);
    s[16].setdata("Manish Gupta", "016Q7Q017", 7);
    s[17].setdata("Sneha Agarwal", "017R8R018", 6);
    s[18].setdata("Nitin Patel", "018S9S019", 6);
    s[19].setdata("Kiran Mehta", "019T0T020", 8);


	

     
    cout<<"Before: "<<endl;
    cout<<"\t\t\t\tNAME\t\t\t\tPRN\t\t\t\tSGPA"<<endl;
    for (int i=0; i<n; i++) {
        s[i].showdata();
    }

    cout<<"After: "<<endl;

    // Sort the Students in acending order of their SGPA
    insertion_Sort_by_SGPA(s,20);
    cout<<"\t\t\t\tNAME\t\t\t\tPRN\t\t\t\tSGPA"<<endl;
    for (int i=0; i<n; i++) {
        s[i].showdata();
    }

    // Sort the Students in alphabetical order of their names
    // Shell_Sort_by_Name(s,n);
    // cout<<"\t\t\t\tNAME\t\t\t\tPRN\t\t\t\tSGPA"<<endl;
    // for (int i=0; i<n; i++) {
    //     s[i].showdata();
    // }

    // Sort the Students in ascending order of their SGPA and find top 10 Toppers
    // Radix_Sort_to_get_toppers(s,n);
    // get_top_ten_toppers(s);

    return 0;
}
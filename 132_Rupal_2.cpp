/*
Consider Employee database of PCCOE (at least 20 records). Database contains different fields of
every employee like EMP-ID, EMP-Name and EMP-Salary.
a. Arrange list of employees according to EMP-ID in ascending order using Quick Sort
b. Arrange list of Employee alphabetically using Merge Sort
*/

#include<iostream>
#include<string>
using namespace std;

class Employee {
    int EMP_ID;
    string EMP_name;
    long long int EMP_SALARY;

    public:

    void setdata(int EMP_ID, string EMP_name, long long int EMP_SALARY) {
        this->EMP_ID = EMP_ID;
        this->EMP_name = EMP_name;
        this->EMP_SALARY = EMP_SALARY;
    }

    void showdata() {
        cout<<"\t\t\t"<<EMP_name<<"\t\t\t"<<EMP_ID<<"\t\t\t"<<EMP_SALARY<<endl;
    }

    int getID() {
        return EMP_ID;
    }

    string get_EMP_NAME() {
        return EMP_name;
    }

};


int Partition(Employee emp[], int low, int high) {
    Employee pivot = emp[low];
    int i = low;
    int j = high;

    while( i < j) {
        while(emp[i].getID() <= pivot.getID() && i <= high-1) {
            i++;
        }

        while(emp[j].getID() > pivot.getID() && j >= low+1) {
            j--;
        }

        if(i<j) {
            swap(emp[i],emp[j]);
        }
    }
    swap(emp[low],emp[j]);
    return j;
}

void Divide_Quick(Employee emp[], int low, int high) {
    if(low < high) {
        int pIndex = Partition(emp, low, high);
        Divide_Quick(emp,low,pIndex-1);
        Divide_Quick(emp,pIndex+1,high);
    }
}

void Merge_Sort_by_Name(Employee emp[], int s, int mid, int e) {
        Employee new_emp[e-s+1];

        int idx_of_1 = s;
        int idx_of_2 = mid+1;
        int x = 0;

        while(idx_of_1 <= mid && idx_of_2 <= e) {
            if( emp[idx_of_1].get_EMP_NAME() < emp[idx_of_2].get_EMP_NAME() ) {
                    new_emp[x++] = emp[idx_of_1++];
            } else {
                    new_emp[x++] = emp[idx_of_2++];
            }
        }

        while(idx_of_1 <= mid) {
            new_emp[x++] = emp[idx_of_1++];
        }

        while(idx_of_2 <= e) {
            new_emp[x++] = emp[idx_of_2++];
        }

        for(int i=0; i<x; i++) {
            emp[s+i] = new_emp[i];
        }
}


void Divide_merge(Employee emp[], int s, int e) {

    if(s < e) {
        int mid = s + (e-s)/2;
        Divide_merge(emp,s,mid);
        Divide_merge(emp,mid+1,e);
        Merge_Sort_by_Name(emp,s,mid,e);
    } 
}


int main()
{
    int n = 20;
    Employee emp[n];

    // data of 20 employees
    emp[0].setdata(1012, "Aarav Patel", 75000);
    emp[1].setdata(1002, "Maya Sharma", 56000);
    emp[2].setdata(1015, "Ravi Kumar", 82000);
    emp[3].setdata(1013, "Sanya Verma", 69000);
    emp[4].setdata(1016, "Ishaan Gupta", 90000);
    emp[5].setdata(1017, "Neha Singh", 47000);
    emp[6].setdata(1007, "Arjun Rao", 60000);
    emp[7].setdata(1019, "Priya Menon", 78000);
    emp[8].setdata(1020, "Rohit Desai", 51000);
    emp[9].setdata(1010, "Kavya Reddy", 73000);
    emp[10].setdata(1011, "Vikram Joshi", 85000);
    emp[11].setdata(1001, "Tanuja Rao", 64000);
    emp[12].setdata(1004, "Amit Patel", 59000);
    emp[13].setdata(1014, "Ritika Shah", 92000);
    emp[14].setdata(1003, "Ankit Sharma", 46000);
    emp[15].setdata(1005, "Pooja Kumar", 87000);
    emp[16].setdata(1006, "Manish Gupta", 55000);
    emp[17].setdata(1018, "Sneha Agarwal", 98000);
    emp[18].setdata(1008, "Nitin Patel", 62000);
    emp[19].setdata(1009, "Kiran Mehta", 70000);

    cout<<"Before: "<<endl;
    cout<<"\t\t\tEMP_NAME\t\t\tEMP_ID\t\t\tEMP_SALARY"<<endl;
    for (int i=0; i<n; i++) {
        emp[i].showdata();
    }
    
    // to Arrange list of Employee alphabetically using Merge Sort
    // Divide_merge(emp,0,n-1);

    // to Arrange list of employees according to EMP-ID in ascending order using Quick Sort
    Divide_Quick(emp,0,n-1);

    cout<<"After: "<<endl;
    cout<<"\t\t\tEMP_NAME\t\t\tEMP_ID\t\t\tEMP_SALARY"<<endl;
    for (int i=0; i<n; i++) {
        emp[i].showdata();
    }


    return 0;
}
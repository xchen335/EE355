#include <iostream>
using namespace std;

class Grade{
    public:
        string name;

    private:
        int grade;

    public:
        void set_grade(string n, int g){
            name = n;
            grade = g;
        }
        int get_grade(){
            return grade;
        }    
    //
};

class GradeBook{
    //Note: assume the length of array is fixed (8).
    private:
        Grade gradeBk[8];
    public:
        void set_value(string *name, int *grades){
            for(int i=0; i<8; i++){

                gradeBk[i].set_grade(name[i], grades[i]);
            }
        }
        // Constructor with parameters.
        GradeBook(string *name, int *grades){
            for(int i=0; i<8; i++){
                gradeBk[i].set_grade(name[i], grades[i]);
            }
        }
/*
        void Sort(){
            int tmpG = -1;
            int isSorted;
            string tmpN;

            for(int i=0; i<8-1; i++){
                isSorted = 1;
                for(int j=0; j<8-1-i; j++){
                    if(gradeBk[j].get_grade() < gradeBk[j+1].get_grade()){
                        tmpG = gradeBk[j].get_grade();
                        tmpN = gradeBk[j].name;
                        gradeBk[j].set_grade(gradeBk[j+1].name, gradeBk[j+1].get_grade());
                        gradeBk[j+1].set_grade(tmpN, tmpG);
                        isSorted = 0;
                    }
                }
                if(isSorted){
                    break;
                }
            }
        }
*/        
        void print_book(){
            for(int i=0; i<8; i++){
                cout << "The " << i << "th student is:" << gradeBk[i].name <<". Grade is: " << gradeBk[i].get_grade() << endl;
            }            
        }
        void print_top(int n){
            // Sort first

            //
            int tmpG = -1;
            int isSorted;
            string tmpN;

            for(int i=0; i<8-1; i++){
                isSorted = 1;
                for(int j=0; j<8-1-i; j++){
                    if(gradeBk[j].get_grade() < gradeBk[j+1].get_grade()){
                        tmpG = gradeBk[j].get_grade();
                        tmpN = gradeBk[j].name;
                        gradeBk[j].set_grade(gradeBk[j+1].name, gradeBk[j+1].get_grade());
                        gradeBk[j+1].set_grade(tmpN, tmpG);
                        isSorted = 0;
                    }
                }
                if(isSorted){
                    break;
                }
            }

            if (n>8){
                n = 8;
            }
            else if (n<1){
                n = 1;
            }
            for(int i=0; i<n; i++){
                cout << "The " << i+1 << "th rank student is:" << gradeBk[i].name <<". Grade is: " << gradeBk[i].get_grade() << endl;
            }            
        }
};

int main(){
    int grades[8] = {80,87,92,91,29,68,76,88};
    string names[8] = {"a","b","c","d","e","f","g","h"};

    //Write your code here
    //GradeBook myGreedbook;

    GradeBook myGreedbook(names, grades);

    //myGreedbook.set_value(names,grades);
    myGreedbook.print_book();
    cout << "Test Print top n:" << endl;
    myGreedbook.print_top(3);

    return 0;
}

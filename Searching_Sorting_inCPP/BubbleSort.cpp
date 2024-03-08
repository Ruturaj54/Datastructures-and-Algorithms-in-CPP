//---------------------------------------------------------
//**********************Bubble Search**********************
//---------------------------------------------------------


//NOTE -> Array should be sorted here; 

//Bestcase : O(1)
//WrostCase: O(n)
//Avg case : O(0-9)

#include<iostream>
using namespace std;

class Array
{
    private:
        int * Arr;
        int iSize;

    public:
        Array(int X)        // Parametrised Constructor
        {
            iSize = X;
            Arr = new int[iSize];
        }

        ~Array()            // Destructor
        {   
            delete []Arr;
        }

        void Accept()       // Member function
        {
            int iCnt = 0;
            cout<<"Please enter the elements : "<<endl;
            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                //int Check = Arr[iCnt];
                //int Check = Arr[iCnt];
                cin>>Arr[iCnt];
                // if(Arr[iCnt] < Check)
                // {
                    
                // }
            }
        }

        void Display()      // Member function
        {
            cout<<"Elements of the array are : "<<endl;
            int iCnt = 0;
            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cout<<Arr[iCnt]<<"\t";
            }
            cout<<endl;
        }

        void BubbleSortAssen()
        {
            int iTemp = 0;
            int i = 0,j = 0;
            
            //printf("Assending order Bubble Sort...");
            for(i = 0;i < iSize;i++)
            {
                //cout<<"Data after pass : "<<(i+1)<<"\n";
                for(j = 0;j < iSize-i-1;j++)
                {
                    if(Arr[j] > Arr[j + 1])
                    {
                        iTemp = Arr[j];
                        Arr[j] = Arr[j+1];
                        Arr[j+1] = iTemp;
                    }
                }
                //Display();
            }

        }

        void BubbleSortDecending()
        {
            int iTemp = 0;
            int i = 0,j = 0;

            printf("Decending order Bubble Sort...");
            for(i = 0;i < iSize;i++)
            {
                for(j = 0;j < iSize-i-1;j++)
                {
                    if(Arr[j] < Arr[j+1])
                    {
                        iTemp = Arr[j];
                        Arr[j] = Arr[j+1];
                        Arr[j+1] = iTemp;
                    }
                }
            }

        }

};  // End of class

int main()
{
    int iLength = 0;
    int iRet = 0;
    int iValue = 0;
    bool bRet = false;

    cout<<"Enter the number of elements: "<<endl;
    cin>>iLength;

    Array *aobj = new Array(iLength);

    aobj->Accept();
    aobj->Display();


    aobj->BubbleSortAssen();
    aobj->Display();

    aobj->BubbleSortDecending();
    aobj->Display();

    delete aobj;

    return 0;
}
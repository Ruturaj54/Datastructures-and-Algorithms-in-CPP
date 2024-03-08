//---------------------------------------------------------
//**********************Linear Search**********************
//---------------------------------------------------------

//Generally data is unsorted in array so this LinearSearch can be used
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
                cin>>Arr[iCnt];
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

        bool LinearSearch(int iNo)
        {
            int iCnt = 0;
            bool bFlag = false;

            for(iCnt = 0;iCnt < iSize;iCnt++)
            {
                if(Arr[iCnt] == iNo)
                {
                    bFlag = true;
                    break;
                }
            }
            return bFlag;

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

    cout<<"Enter the Element that you want to search : \n";
    cin>>iValue;

    bRet = aobj->LinearSearch(iValue);
    if(bRet == true)
    {
        cout<<"The Value : "<<iValue<<" is PRESENT in array\n";
    }
    else
    {
        cout<<"The Value : "<<iValue<<" is NOT PRESENT in array\n";
    }

    delete aobj;

    return 0;
}
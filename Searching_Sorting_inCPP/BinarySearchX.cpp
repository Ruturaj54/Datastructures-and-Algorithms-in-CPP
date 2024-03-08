//---------------------------------------------------------
//**********************Efficient BinarySearch Linear Search**********************
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

        bool BinarySearchX(int iNo)
        {
            int iStart = 0;
            int iEnd = 0;
            int iMid = 0;
            bool bFlag = false;

            iStart = 0;
            iEnd = iSize - 1;

            while(iStart <= iEnd)
            {
                iMid = iStart + (iEnd-iStart)/2;
                if((Arr[iMid] == iNo) || (Arr[iStart] == iNo) || (Arr[iEnd] == iNo))
                {
                    bFlag = true;
                    break;
                }
                else if(Arr[iMid] < iNo)
                {
                    iStart = iMid+1;
                }
                else if(Arr[iMid] > iNo)
                {
                    iEnd = iMid-1;
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

    bRet = aobj->BinarySearchX(iValue);
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
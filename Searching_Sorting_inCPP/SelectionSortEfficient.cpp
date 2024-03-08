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

       void SelectionSortEfficient(char choice)
        {
            int min_index = 0;
            int i = 0, j = 0;
            int iTemp = 0;

            if(choice == 'I')
            {
            for(i = 0; i < iSize-1; i++)
            {
                min_index = i;
                for(j = i+1; j < iSize; j++)
                {
                    if(Arr[j] < Arr[min_index])
                    {
                        min_index = j;
                    }
                }
                if(i != min_index)
                {
                    iTemp = Arr[i];
                    Arr[i] = Arr[min_index];
                    Arr[min_index] = iTemp;
                }
            }
            }
            else if(choice == 'D')
            {

            for(i = 0; i < iSize-1; i++)
            {
                min_index = i;
                for(j = i+1; j < iSize; j++)
                {
                    if(Arr[j] > Arr[min_index])
                    {
                        min_index = j;
                    }
                }
                if(i != min_index)
                {
                    iTemp = Arr[i];
                    Arr[i] = Arr[min_index];
                    Arr[min_index] = iTemp;
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
    char cChoice = '\0';

    cout<<"Enter the number of elements: "<<endl;
    cin>>iLength;

    Array *aobj = new Array(iLength);

    aobj->Accept();
    aobj->Display();

    cout<<"Please enter your choice for sorting : \n";
    cout<<"I : Increasing order\n";
    cout<<"D : Decreasing Order\n";

    cin>>cChoice;

    aobj->SelectionSortEfficient(cChoice);
    aobj->Display();

    delete aobj;

    return 0;
}
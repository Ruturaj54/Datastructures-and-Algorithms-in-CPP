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
            cout<<"Elements of the array are : \n"<<endl;
            int iCnt = 0;
            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cout<<Arr[iCnt]<<"\t";
            }
            cout<<endl;
        }

        void BubbleSortEfficient(char choice)
        {
            int iTemp = 0;
            int i = 0,j = 0;
            bool bFlag = false;
            
            if(choice == 'I' || choice == 'i')
            {
                printf("Increasing order Bubble Sort...\n");
                for(i = 0;i < iSize;i++)
                {
                    bFlag = false;
                    cout<<"Data after pass : "<<(i+1)<<"\n";
                    for(j = 0;j < iSize-i-1;j++)
                    {
                        if(Arr[j] > Arr[j + 1])
                        {
                            iTemp = Arr[j];
                            Arr[j] = Arr[j+1];
                            Arr[j+1] = iTemp;
                            bFlag = true;
                        }
                    }
                    if(bFlag == false)
                    {
                        break;
                    }
                    Display();

                }
            }
            else if(choice == 'D' || choice == 'd')
            {
                printf("Decreasing order Bubble Sort...\n");
                for(i = 0;i < iSize;i++)
                {
                    bFlag = false;
                    cout<<"Data after pass : "<<(i+1)<<"\n";
                    for(j = 0;j < iSize-i-1;j++)
                    {
                        if(Arr[j] > Arr[j + 1])
                        {
                            iTemp = Arr[j];
                            Arr[j] = Arr[j+1];
                            Arr[j+1] = iTemp;
                            bFlag = true;
                        }
                    }
                    if(bFlag == false)
                    {
                        break;
                    }
                    Display();
                }
            }
            else
            {
                cout<<"Invalid Choice\n";
                cout<<"USE BELOW CHOICE !!! \n";
                cout<<"I or i : for INCREASING ORDER\n";
                cout<<"D or d : for DECREASING ORDER\n";
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

    aobj->BubbleSortEfficient(cChoice);
    aobj->Display();


    delete aobj;

    return 0;
}
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

void partition(vector <int>  ar) {
    int key =ar.at(0);

    vector <int> final;
    vector <int> out;
    final=ar;
   
    ar.push_back(0);
    swap(ar.at(0),ar.at(ar.size()-1));
    
    int i=-1;
    int p=0;
    int r=ar.size()-1;
    
    for(int j=0;j<ar.size();j++)
        {
        if(ar.at(j)<=key)
            {
            i++;
            swap(ar.at(i),ar.at(j));
        }
    }
    
    swap(ar.at(i+1),ar.at(r));
    
    for(int k=1;k<ar.size();k++)
        cout<<ar.at(k)<<" ";
     
    cout<<endl;

    for(int k=0;k<final.size();k++)
        cout<<final.at(k)<<" ";

      cout<<endl;


       for(int k=0;k<final.size();k++)
       {
        if(final.at(k)<key)
          out.push_back(final.at(k));
       }

       out.push_back(key);

       for(int k=0;k<final.size();k++)
       {
        if(final.at(k)>key)
          out.push_back(final.at(k));
       }

       for(int k=0;k<out.size();k++)
        cout<<out.at(k)<<" ";

    
   

}


void quickSort(vector <int> &arr) {
   // Complete this function
    int key=arr.at(0);
    if(arr.size()<2)
        {
        //cout<<arr.at(0);
        return;
    }
        
    if(arr.size()==2)
        {
        if(arr.at(0)>arr.at(1))
            swap(arr.at(0),arr.at(1));
        cout<<arr.at(0)<<" "<<arr.at(1);
        return;
    }
    
    if(arr.size()>2)
        {
        vector <int> part1;
        vector <int> part2;
        vector <int> part3;
        for(int k=0;k<arr.size();k++)
       {
        if(arr.at(k)<key)
          part1.push_back(arr.at(k));
       }
        
        for(int k=0;k<arr.size();k++)
       {
        if(arr.at(k)>key)
          part2.push_back(arr.at(k));
       }
       
        
        quickSort(part1);
        quickSort(part2);


        for(int k=0; k<part1.size();k++)
            {
            part3.push_back(part1.at(k));
        }
        
        part3.push_back(key);
        
        for(int k=0; k<part2.size();k++)
            {
            part3.push_back(part2.at(k));
        }
        
        for(int k=0; k<part3.size();k++)
            {
            cout<<part3.at(k)<<" ";
        }
      return;  
    }

 }
    


int main()
{
    int n;
    cin>>n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}


/*int main(void) {
   vector <int>  _ar;
   int _ar_size;
cin >> _ar_size;
for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
   int _ar_tmp;
   cin >> _ar_tmp;
   _ar.push_back(_ar_tmp); 
}

partition(_ar);
   
   return 0;
}
*/
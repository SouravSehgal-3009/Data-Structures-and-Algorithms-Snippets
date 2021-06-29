#include <bits/stdc++.h>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length=0;
    int low=0;
    int high=length-1;

public:
    Array()
    {
        size=15;
        A= new int[size];
    }
    Array(int size)
    {
        this->size=size;
        A= new int[size];
    }

    Array(int arr[], int size, int length)
    {
        this->size=size;
        A=new int[size];
        this->length=length;
        for (int i=0; i<length; i++)
        {
            A[i]=arr[i];
        }
    }

    void create_array()
    //To create the array and let user give the elements in input
    {
        cout<<"Enter number of elements you want to insert in array";
        cin>>length;
        for (int i=0; i<length; i++)
        {
            cout<<"Enter element";
            cin>>A[i];
        }
    }

    void display()
    //To display the error
    {  
        cout<<"Array: ";
        for (int i=0; i<length; i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<"\n";
    }

    int len()
    //To return length of the array
    {
        return length;
    }

    int arrSize()
    //To return size of the array

    {
        return size;
    }

    int at(int index)
    //To return the element at the given index
    {
        if (index>=0 && index<length)
            return A[index];
    }

    void set_value(int index, int value)
    //To set the value at given index
    {
        if (index>=0 && index<length)
            A[index]=value;
    }

    bool isSorted()
    //Checks whether the array is sorted or not
    {
        for (int i=0; i<length-1; i++)
        {
            if (A[i]>A[i+1])
                return false;
        }
        return true;
    }

    void append(int x)
    {
        if (this->isSorted())   
        //If array is sorted array, then element will be inserted in such a manner that resultant array is also sorted.
            insert_sorted(x);
        else   
        //Element will be appended at the end of the array
        {
            A[length]=x;
            length++;
        }
    }

    void insert_sorted(int x)
    //To insert the element in sorted array in such a manner that resultant array is also sorted.
    {
        A[length]=x;
        
        for (int i=length; i>0; i--)
        {
            if (A[i]<A[i-1])
                swap(A[i], A[i-1]);
        }
        length++;
    }

    void insert(int index, int value)
    //Inserts the given element at the given index 
    {
        if (index>=0 && index<length)
        {
            for (int i=length; i>index; i--)
            {
                A[i]=A[i-1];
            }
            A[index]=value;
            length++;
        }
    }

    void remove(int index)
    //Removes the element at given index from the array
    {
        if (index>=0 && index<length)
        {
            for (int i=index; i<length-1;i++)
            {
                A[i]=A[i+1];
            }
            length--;
        }
    }

    int sum()
    //Computes sum of all the elements of the array
    {
        int s=0;
        for (int i=0; i<length; i++)
            s+=A[i];
        return s;
    }

    int min()
    //Returns integer with minimum value in the array

    {
        int min_elem=A[0];
        for (int i=0; i<length; i++)
        {
            if (A[i]<min_elem)
                min_elem=A[i];

        }
        return min_elem;
    }

    int max()
    //Returns integer with maximum value in the array
    {
        int max_elem=A[0];
        for (int i=0; i<length; i++)
        {
            if (A[i]>max_elem)
                max_elem=A[i];

        }
        return max_elem;
    }

    float average()
    //Computes the average of all the elements of array
    {
        return this->sum()*1.0/length;
    }

    int linear_search(int elem)
    //Performs linear search to find the index of given element otherwise returns -1

    {
        for (int i=0; i<length; i++)
        {
            if (A[i]==elem)
                return i;
        }
        return -1;
    }

    int binary_search(int low, int high,int elem)
    //Performs binary search to find the index of given element otherwise returns -1
    {
        if (low<=high)
        {
            int mid=(low+high)/2;
            if (A[mid]==elem)
                return mid;
            else if (A[mid]<elem)
                low=mid+1;
            else
                high=mid-1;
            return binary_search(low, high, elem);
        }
        return -1;
    }

    void reverse()
    //To reverse the array
    {
        for (int i=0,j=length-1;i<j; i++, j--)
        {
            swap(A[i],A[j]);
        }
    }

    void left_shift()
    //To left shift the array by one position
    {
        for (int i=0; i<length-1; i++)
        {
            A[i]=A[i+1];
        }
        A[length-1]=0;
    }

    void left_rotate()
    //Rotates the elements in the array to left by one position.
    {
        int temp=A[0];
        left_shift();
        A[length-1]=temp;
    }

    void right_shift()
    //To right shift the array by one position
    {
        for (int i=length-1; i>=1; i--)
        {
            A[i]=A[i-1];
        }
        A[0]=0;
    }

    void right_rotate()
    //Rotates the elements in the array to right by one position.
    {
        int temp=A[length-1];
        right_shift();
        A[0]=temp;
    }

    void proper_sequence()
    //All negative integers will be in left of the array and positive ones at right
    {
        int i=0, j=length-1;
        while(i<j)
        {
            while(A[i]<0){i++;}
            while(A[j]>=0){j--;}
            if (i<j)
                swap(A[i], A[j]);

        }
    }

    Array arr_symmDiff(Array &arr2);

    friend Array merge(Array &arr1,Array &arr2);
    friend Array arr_union(Array &arr1, Array &arr2);
    friend Array arr_intersection(Array &arr1, Array &arr2);
    
    ~Array()
    {
        delete []A;
    }
};

Array merge(Array &arr1,Array &arr2)
{
    int size=arr1.size+arr2.size;
    Array arr3(size);
    int i=0, j=0, k=0;
    while (i<arr1.len() && j< arr2.len())
    {
        if (arr1.at(i)<=arr2.at(j))
        {
            arr3.append(arr1.at(i));
            i++;
        }
        else
        {
            arr3.append(arr2.at(j));
            j++;
        }
        k++; 
    }
    while(i<arr1.len())
    {
        arr3.append(arr1.at(i));
        i++;
        k++;
    }
    while(j<arr2.len())
    {
        arr3.append(arr2.at(j));
        j++;
        k++;
    }
    arr3.length=arr1.length+arr2.length;
    return arr3;
}

Array arr_union(Array &arr1, Array &arr2)
{
    int size=arr1.size+arr2.size;
    Array arr3(size);
    int i=0, j=0, k=0;
    while (i<arr1.len() && j< arr2.len())
    {
        if (arr1.at(i)<arr2.at(j))
        {
            arr3.append(arr1.at(i));
            i++;
        }
        else if (arr1.at(i)>arr2.at(j))
        {
             arr3.append(arr2.at(j));
            j++;
        }
        else{
            arr3.append(arr1.at(i));
            i++; j++;
        }
        k++; 
    }
    while(i<arr1.len())
    {
        arr3.append(arr1.at(i));
        i++;
        k++;
    }
    while(j<arr2.len())
    {
        arr3.append(arr2.at(j));
        j++;
        k++;
    }
    arr3.length=k;
    return arr3;
}

Array arr_intersection(Array &arr1, Array &arr2)
{
    int size=arr1.size+arr2.size;
    Array arr3(size);
    int i=0, j=0, k=0;
    while (i<arr1.len() && j< arr2.len())
    {
        if (arr1.at(i)<arr2.at(j))
        {
            i++;
        }
        else if (arr1.at(i)>arr2.at(j))
        {
            j++;
        }
        else{
            arr3.append(arr1.at(i));
            i++; j++;k++; 
        }
        
    }
    arr3.length=k;
    return arr3;
}

Array Array::arr_symmDiff(Array &arr2)
{
    int size=this->size+arr2.size;
    Array arr3(size);
    int i=0, j=0, k=0;
    while (i<this->len() && j< arr2.len())
    {
        if (this->at(i)<arr2.at(j))
        {
            arr3.append(this->at(i));
            i++;
            k++; 
        }
        else if (this->at(i)>arr2.at(j))
        {
            j++;
        }
        else{
            i++; j++;
        }
        
    }
    while(i<this->len())
    {
        arr3.append(this->at(i));
        i++;
        k++;
    }
    arr3.length=k;
    return arr3;
}

int main()
{
    Array arr1(1000);
    arr1.create_array();
    arr1.display();
    int a[5]={3,6,9,12,15};
    Array arr2(a, 12, 5);
    arr2.display();
    cout<<arr1.len()<<" "<<arr1.arrSize()<<endl;
    cout<<arr2.len()<<" "<<arr2.arrSize()<<endl;
    Array arr3=merge(arr1,arr2);
    arr3.display();
    arr3.append(25);
    arr3.display();
    arr3.right_rotate();
    arr3.display();
    arr3.reverse();
    arr3.display();
    arr3.remove(2);
    arr3.display();
    arr3.append(-7);
    arr3.proper_sequence();
    arr3.display();
    cout<<arr3.max()<<endl;
    cout<<arr3.average()<<endl;
    cout<<arr3.at(2)<<endl;
    Array arr4=arr_union(arr1, arr2);
    cout<<"Union of two arrays"<<endl;
    arr4.display();
    Array arr5=arr_intersection(arr1, arr2);
    cout<<"Intersection of two arrays: "<<endl;
    arr5.display();
    Array arr6=arr1.arr_symmDiff(arr2);
    cout<<"Symmetric Difference"<<endl;
    arr6.display();
}

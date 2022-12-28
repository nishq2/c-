#include <iostream>
#define MAX 10
using namespace std;

class spm{
    int r,c,v;
public:
    int read(spm a[]);
    void displaymatrix(spm a[]);
    void transpose(spm a[],spm b[]);
    void display();
    void elesearch(spm a[]);
    void add(spm a[],spm b[]);
};

int spm::read(spm a[]){
    int k=1,m,n,ele,cnt=0;
    cout<<"Enter number of columns and rows: ";
    cin>>m>>n;
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cin>>ele;
            if (ele==0){
                continue;
            }
            a[k].r=i;
            a[k].c=j;
            a[k++].v=ele;
            cnt++;
        }
    }
    a[0].r=m;
    a[0].c=n;
    a[0].v=k-1;
    return cnt;
}

void spm::transpose(spm a[],spm b[]){
    int k=1;
    b[0].r=a[0].c;
    b[0].c=a[0].r;
    b[0].v=a[0].v;
    for(int i=0;i<a[0].c;i++){
        for (int j=1;j<=a[0].v;j++){
            if (i==a[j].c){
                b[k].c=a[j].r;
                b[k].r=a[j].c;
                b[k].v=a[j].v;
                k++;
            }
        }
    }
}

void spm::displaymatrix(spm a[]){
    int k=1;
    for(int i=1;i<a[0].r+1;i++){
        for(int j=1;j<a[0].c+1;j++){
            if (i==a[i].r && j==a[j].c){
                cout<<a[k].v<<"   ";
                k++;
            }
            else{
                cout<<"0   ";
            }
        }
        cout<<endl;
    }
}

void spm::display(){
        cout<<r<<' '<<c<<' '<<v<<endl;
    }

void spm::elesearch(spm a[]){
    int k=1,flag=0,i;
    int key;
    cout<<"\nEnter key: ";
    cin>>key;
    for(i=1;i<a[0].v+1;i++){
        if (key==a[i].v){
            flag=1;
            break;
        }
    }
    if (flag==1){
        cout<<"\nElement found at "<<a[i].r<<", "<<a[i].c;
    }
    else{
        cout<<"\nElement not found...";
    }
}

int main(){

    spm a[MAX],b[MAX],a1;
    int cnt=a1.read(a);
    a1.transpose(a,b);
    char res;
    do{
        int ch;
        cout<<"MENU\n1.Read\n2.Display\n3.Search Element4.Add\n5.Multiply\n6.Transpose\n7.Exit\n\nEnter your choice: ";
        cin>>ch;
        switch (ch){
        case 1:
            int cnt=a1.read(a);
            break;

        case 2:
            for(int k=0;k<=cnt;k++){
            a[k].display();
            }
            break;

        case 3:
            a1.elesearch(a);
            break;

        case 4:
            a1.add(a,b);
            break;

        case 5:
            a1.multiply(a,b);
            break;

        case 6:
            cout<<"\nAFTER TRANSPOSE:"<<endl;
            for(int k=0;k<=cnt;k++){
                b[k].display();
            }
            break;

        case 7:
            return 0;
        }
        cout<<"Do you want to continue?(y/n)";
        cin>>res;
    } while(res=='y');
return 0;
}

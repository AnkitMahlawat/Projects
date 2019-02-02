/*

In this program i remeorized (which i kind of forgotten by now) a conecept that memory allocated on stack frees when the function acquiring that stack memory goes out of scope  
os allocates memory on stack when we donot use new operator during allocation of memory.
In this program my heap class requires a array based memory whose size will vary so I had to assign memory on runtime so in constructor of heap class I didnot use new operator
instead i wrote line no 128 and some other places in class heap as flight temp[CAPACITY];(rest of the code changed accoring to this line but this line was the main culprit) which allocated memory on stack and when
constuctor function ended it all vanished and the list in heap class was pointing to a freed memory location hence SIGSEV error came.now I changed it to list = new flight[CAPACITY]
which allocated memory on heap and everything is fine now.

*/
#include <bits/stdc++.h>
using namespace std;


int new_arrTime(int arrTime){
    if(arrTime%100<30){
        return arrTime+30;
    }else return arrTime+70;
}

class flight{
	int Atime=-0100,Dtime,price,to,from;
	string plane;
public:
	flight(){}

	flight(const flight& a){
		Atime=a.Atime;
		Dtime=a.Dtime;
		to=a.to;
		from=a.from;
		price=a.price;
		plane=a.plane;
	}
	
	flight(int from,int to,int Dtime,int Atime ,string plane,int price){
		this->Atime=Atime;
		this->Dtime=Dtime;
		this->price=price;
		this->to=to;
		this->from=from;
		this->plane=plane;
	}
	
	bool compare(flight a){
			return this->Dtime>a.Dtime;
	}
	
	int get_Deptime(){
	    return Dtime;
	}
	
	int get_Arrtime(){
	    return Atime;
	}
	
	int get_from(){
	    return from;
	}
	
	int get_to(){
	    return to;
	}
	
	int get_price(){
	    return price;
	}

	void printFlight(){
		cout<<this->from<<" "<<this->to<<" "<<this->Dtime<<" "<<this->Atime<<" "<<this->plane<<" "<<this->price<<endl;
	}
	

};

class node{
    flight f;
    int Tprice=0;
    bool valid=false;
    node* link=nullptr;
public:
    node(){}
   
    node(flight fl,int Tpr,node* l,bool v){
        Tprice=Tpr;
        f=fl;
        link=l;
        valid=v;
    }
    
    flight get_flight(){
        return f;
    }
    
    bool get_valid(){
        return valid;
    }
    
    node* get_link(){
        return link;
    }
    
    int get_Tprice(){
        return Tprice;
    }
    
    void set_valid(bool v){
        valid=v;
    }
    
    void set_ptr(node* ptr){
        link=ptr;
    }
    
    void print(){
        if(valid==true){
            cout<<"new link: ";
            f.printFlight();
            cout<<Tprice<<" "<<valid<<" "<<link<<endl;
        }
        if(link!=nullptr){
            link->print();
        }
    }
};

class a_list{
    node* a;
    int size;
    int* size_n;
    //node a[n];
public:
    a_list(int size){
        this->size=size;
        a=new node[size];
        size_n=new int[size];
        for (int i = 0; i < size; i++) {
            size_n[i]=0;
        }
    }
    
    node get_i(int i){
        return a[i];
    }
    
    bool check(int index,int Dep_time,int to_i,flight current,int *ptr ){
        node check_node=a[index];
        node* nodeptr=check_node.get_link();
        while(true){
            if(new_arrTime(check_node.get_flight().get_Arrtime())<=Dep_time){
                if(!a[to_i].get_valid()||(current.get_Arrtime()<a[to_i].get_flight().get_Arrtime() || current.get_price()+check_node.get_Tprice()<a[to_i].get_Tprice())){
                    *ptr=current.get_price()+check_node.get_Tprice();
                    return true;
                }
            }
            if(nodeptr==nullptr){
                return false;
            }else{
                check_node=*nodeptr;
                nodeptr=check_node.get_link();
            }
        }
    }
    
    void add(int index,node n){
        node add_node=a[index];
        if(!add_node.get_valid()){
            a[index]=n;
            return;
        }
        if(add_node.get_Tprice()>=n.get_Tprice()){
            a[index]=n;
            n.set_ptr(&add_node);
            return;
        }
        
        node* ahead=add_node.get_link();
        node* follow=&add_node;
        while(follow!=nullptr){
            if(ahead==nullptr){
                follow->set_ptr(&n);
                return;
            }
            if(ahead->get_Tprice()>n.get_Tprice()){
                n.set_ptr(ahead);
                follow->set_ptr(&n);
            }
            follow=ahead;
            ahead=ahead->get_link();
        }
                    

        return;
    }
    
    void print(){
        for (int i = 0; i < size; i++) {
            cout<<i<<": ";
            a[i].print();
        }
    }

};


class heap{
	int CAPACITY;
	int size;
	flight* list;
	
	int parent(int i){
		return (i-1)/2;
	}

	int firstChild(int i){
		return 2*i+1;
	}

	int secondChild(int i){
		return 2*i+2;
	}

	void heapifyUP(){
		int i=size-1;
		int parent=this->parent(i);
		while(i!=0){
			if (list[parent].compare(list[i])){
				flight temp = list[i];
				list[i]=list[parent];
				list[parent]=temp;
				i=parent;
				parent=this->parent(i);
			}else break;	
		}
	}

	int minChild(int i){
		int firstChild=this->firstChild(i);
		int minChild=firstChild;
		int secondChild=this->secondChild(i);
		if (secondChild<size){
			if (list[firstChild].compare(list[secondChild])){
				minChild=secondChild;
			}
		}
		return minChild;
	}

	void heapifyD(int i=0){
		int firstChild=this->firstChild(i);
		int secondChild=this->secondChild(i);
		int minChild=this->minChild(i);
		while(firstChild<size){
			if (list[i].compare(list[minChild])){
				flight temp=list[i];
				list[i]=list[minChild];
				list[minChild]=temp;
				i=minChild;
				firstChild=this->firstChild(i);
				secondChild=this->secondChild(i);
				minChild=this->minChild(i);
			}else break;
		}
	}

	void heapify(){
		int lastMember=size-1;
		int parent=this->parent(lastMember);
		for (int i =parent ; i >=0 ; --i){
			heapifyD(i);
		}
	}
public:
	heap(int capacity){
		CAPACITY=capacity;
		list = new flight[CAPACITY];
		size=0;
	}

	heap(const heap& a){
		CAPACITY=a.CAPACITY;
		size=a.size;
        
		list =new flight[CAPACITY];
		for (int i = 0; i < size; ++i){
			
			list[i]=a.list[i];
		}
		
	}

	bool isEmpty(){
		return size==0;
	}

	void resize(){
		CAPACITY=2*CAPACITY;
		flight *temp = new flight[CAPACITY];
		for (int i = 0; i < size; ++i){
			temp[i]=list[i];
		}
		list=temp;
	}

	void insert(flight l[],int size,int capacity){
		CAPACITY=capacity;
	    this->size=size;
		list=l;
		heapify();
	}

	void insert(flight f){
		if (size==CAPACITY)
			resize();
		list[size]=f;
		size++;
		heapifyUP();
	}

	flight deleteMin(){
		if (isEmpty()){
			flight temp;
			return temp;
		}
		flight temp=list[0];
		list[0]=list[size-1];
		size--;
		heapifyD();
		return temp;
	}
	
	flight getMin(){
	    return list[0];
	}

	void printHeap(){
		for (int i = 0; i < size; ++i){
			printf("%d: ",i);
			list[i].printFlight();	
		}
	}
	
};

void fun_tripPlanner(int start_city,int end_city,int Dep_time,int Arr_time,heap temp,int Ncities,int Nplanes){
    a_list arr_list(Ncities+1);
	flight fl;
	node src(fl,0,nullptr,true);
	arr_list.add(start_city,src);
	while(temp.getMin().get_Deptime()<Arr_time&&!temp.isEmpty()){
	    flight current=temp.deleteMin();
	   // cout<<"-------------------------------------------------------------"<<endl;
	   // current.printFlight();
	    if(current.get_Deptime()>=Dep_time&&current.get_Arrtime()<=Arr_time){
            node from_node=arr_list.get_i(current.get_from());
            if(from_node.get_valid()){
                int ptr_price;
                if(arr_list.check(current.get_from(),current.get_Deptime(),current.get_to(),current,&ptr_price)){
                    node to_add(current,ptr_price,nullptr,true);
                    arr_list.add(current.get_to(),to_add);
                }
            }
	    }
	   // arr_list.print();
	}
	
	if(arr_list.get_i(end_city).get_valid()){
	    cout<<arr_list.get_i(end_city).get_Tprice()<<endl;
	}else cout<<-1<<endl;

}

int main(int argc, char const *argv[]){
// 	if (argc!=2){
// 		printf("usage:%s filename\n",argv[0] );
// 		exit(0);
// 	}

// 	#ifndef ONLINE_JUDGE
//     // for getting input from input.txt
//     freopen(argv[1], "r", stdin);
//     // for writing output to output.txt
//     freopen("output.txt", "w", stdout);
// 	#endif

    int Ncities,Nplanes;
    cin>>Ncities>>Nplanes;
    
    flight list[Nplanes]; 
    heap H(Nplanes);

    for (int i = 0; i <Nplanes; ++i){
    	int from,to,Dep,Arrv,price;
    	string plane;
    	cin>>from>>to>>Dep>>Arrv>>plane>>price;
    	flight temp(from,to,Dep,Arrv,plane,price);
    	list[i]=temp;
    }
    
    H.insert(list,Nplanes,Nplanes);
    
    int Queries;
    cin>>Queries;

    for (int i = 0; i < Queries; ++i){

    	heap temp(H);
    	int start_city,end_city,Dep_time,Arr_time;
    	cin>>start_city>>end_city>>Dep_time>>Arr_time;
    	fun_tripPlanner(start_city,end_city,Dep_time,Arr_time,temp,Ncities,Nplanes);
    }
	return 0;
}

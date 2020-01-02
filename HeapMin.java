package dataStructure;

import java.util.HashMap;

public class HeapMin {

	double _positiveInfinity = Double.POSITIVE_INFINITY;
	final int INIT_SIZE = 10;
	private node _a[];
	private int _size;
	private int insert=0;
	public HashMap<Integer, Integer> position = new HashMap<Integer, Integer>(); // key --> position in array
	public HeapMin(node arr[]){
		_size = arr.length;
		_a = new node[_size];
		for (int i=0; i<_size; i++){
			_a[i]=arr[i];
		}
	}
	
	public HeapMin(int size){
		this._size=size;
		_a = new node[size];
	}
	/** returns the heap size*/
	public int getSize(){return insert;}
	/** returns the heap array */
	public node[] getA(){ return _a;}
	
	/** parent returns the parent of key  i*/
	private  int parent(int i){return (i-1)/2;}
	
	/** leftChild returns the left child of key  i*/
	private  int leftChild(int i){return 2*i+1;}
	/** rightChild returns the right child of key  i*/
	private  int rightChild(int i){return 2*i+2;}
	/** returns the heap minimum */
	public node heapMinimum(){return _a[0];}
	/** returns true if the heap is empty, otherwise false */
	public boolean isEmpty(){
		boolean ans = false;
		if (insert == 0) ans = true;
		return ans;
	}
	/** the minHeapfy function maintains the min-heap property */
	private void minHeapify(int v, int heapSize){
		int smallest;
		int left = leftChild(v);
		int right = rightChild(v);
		if (left<heapSize && _a[left].getWeight()<_a[v].getWeight()){
			smallest = left;
		}
		else{
			smallest = v;
		}
		if (right<heapSize && _a[right].getWeight()<_a[smallest].getWeight()){
			smallest = right;
		}
		if (smallest!=v){
			exchange(v, smallest);
			minHeapify(smallest, heapSize);
		}		
	}
	/** the heap minimum element extraction */
	public node heapExtractMin(){
		double min = _positiveInfinity; 
		node v=null;
		if (!isEmpty()){
			v = _a[0];
			min = v.getWeight();
			_a[0]=_a[insert-1];
			position.remove(v.getKey());
			insert = insert-1;
			minHeapify(0, insert);
		}
		return v;
	}
	/** the heapDecreaseKey implements the Decrease Key operation*/
	public void heapDecreaseKey(node_data b){
		int v = b.getKey();
		int i = position.get(v);
			while (i>0 && _a[parent(i)].getWeight()>_a[i].getWeight()){
				exchange(i, parent(i));
				i = parent(i);
			}
		}

	/** minHeapInsert function implements the Insert-Key operation*/
	public void minHeapInsert(node_data b){
		if(insert==_size) resize(_size);
		_a[insert++] = (node)b;
		position.put(b.getKey(),insert-1 );
		heapDecreaseKey(b);
	}
	/** increment an array*/
	private void resize(int increment){
		node temp[] = new node[_size+increment];
		for (int i=0; i<_size; i++){
			temp[i]=_a[i];
		}
		_a = temp;
		_size = _size+increment;
	}	
	/** exchange two array elements*/
	private void exchange(int i, int j){
		node t = _a[i];
		_a[i] = _a[j];
		_a[j] = t;
		position.replace(_a[j].getKey(), j);
		position.replace(_a[i].getKey(), i);
	}
/*	*//** print a heap array **//*
	public void print(){
		for (int i=0; i<_size; i++){
			System.out.print(_a[i]+"; ");
		}
		System.out.println();
	}*/
	public boolean contains(int key){
		boolean ans = false;
		for (int i=0; !ans && i<insert; i++){
			if (_a[i].getKey() == key) ans = true;
		}
		return ans;
	}
/*	public static void main(String[] args) {
		// TODO Auto-generated method stub
		node nodes1[] = {new node(16,0),
						 new node(5,1),
						 new node(8,2),
						 new node(4,3),
						 new node(2,4),
						 new node(1,5)}; 
		//int nodes1[] = {16,8,4,2,1}; 
		//int nodes2[] = {5,13,2,25,7,17,2,8,4}; 
		//int nodes3[] = {16,14,10,8,7,9,3,2,4,1}; 
		HeapMin hp = new HeapMin(nodes1);
		hp.buildMinHeap();
		hp.print();
		node node = new node(3,nodes1.length);
		hp.minHeapInsert(node);
		hp.print();
		System.out.println("min = "+ hp.heapExtractMin());
		hp.print();
		System.out.println("min = "+ hp.heapExtractMin());
		hp.print();
/// heap sort
		
		HeapMin hps = new HeapMin(nodes1);
		hps.heapSort();
		hps.print();
	}
*/
}
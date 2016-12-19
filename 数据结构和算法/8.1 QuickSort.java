class QuickSort{
	private int[] sources;
	public QuickSort(int[] sources) {
		this.sources = sources;
	}
	
	public void quickSort(){
		recQuickSort(0, sources.length - 1);
	}
	
	private void recQuickSort(int left, int right){
		if(right - left <= 0){
			return;
		}else{
			int pivot = sources[right];
			int partition = partitionIt(left, right, pivot);
			recQuickSort(left, partition - 1);
			recQuickSort(partition + 1, right);
		}
	}
	
	private int partitionIt(int left, int right, int pivot){
		int leftPtr = left - 1;
		int rightPtr = right;
		while(true){
			while(sources[++leftPtr] < pivot);
			while(rightPtr > 0 && sources[--rightPtr] > pivot);
			if(leftPtr >= rightPtr){
				break;
			}else{
				swap(leftPtr, rightPtr);
//				sources[leftPtr] = sources[leftPtr] + sources[rightPtr];
//				sources[rightPtr] = sources[leftPtr] - sources[rightPtr];
//				sources[leftPtr] = sources[leftPtr] - sources[rightPtr];
			}
		}
//		sources[leftPtr] = sources[leftPtr] + sources[right];
//		sources[right] = sources[leftPtr] - sources[right];
//		sources[leftPtr] = sources[leftPtr] - sources[right];
		swap(leftPtr, right);
		return leftPtr;
	}
	
	private void swap(int dex1, int dex2){
		int temp = sources[dex1];
		sources[dex1] = sources[dex2];
		sources[dex2] = temp;
	}
	
}
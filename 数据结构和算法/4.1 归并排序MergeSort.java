package com.tiantian.algorithms;
/**
 * 归并排序
 * 归并所用时间：O(N*logN)
比插入排序快得多
如果数据项是10000，插入排序N^2就是100000000，而N*logN则是40000
如果归并排序需要40秒，插入排序需要近28小时
归并排序的思想就是把一个数组分成两半，排序每一半，然后用merge方法把数组的两半归并成一个有序数组。
然后不断的递归下去。。。
 */
public class MergeSort {
	private int[] sources;
	private int len;

	public MergeSort(int[] sources) {
		this.sources = sources;
		len = sources.length;
	}

	public void mergeSort() {
		recMergeSort(sources, 0, len - 1);
	}

	/*
	 * 将索引从left到right范围的数组元素进行归并排序 data 待排序数组 left 待排序数组的第一个元素索引 right
	 * 待排序数组的最后一个元素索引
	 */
	private void recMergeSort(int[] data, int left, int right) {
		if (left < right) {
			int center = (left + right) / 2; // 找出中间索引
			recMergeSort(data, left, center); // 对左边数组进行递归
			recMergeSort(data, center + 1, right); // 对右边数组进行递归
			merge(data, left, center, right); // 合并

		}
	}

	/*
	 * 将两个数组进行归并，归并前两个数组已经有序，归并后依然有序 data 数组对象 left 左数组的第一个元素的索引 center
	 * 左数组的最后一个元素的索引，center+1是右数组第一个元素的索引 right 右数组的最后一个元素的索引
	 */
	private void merge(int[] data, int left, int center, int right) {
		int[] tmpArr = new int[data.length];
		int mid = center + 1;
		int third = left; // third记录中间数组的索引
		int tmp = left;
		while (left <= center && mid <= right) {
			if (data[left] < data[mid]) { // 从两个数组中取出最小的放入中间数组
				tmpArr[third++] = data[left++];
			} else {
				tmpArr[third++] = data[mid++];
			}
		}
		while (mid <= right) { // 剩余部分依次放入中间数组
			tmpArr[third++] = data[mid++];
		}
		while (left <= center) {
			tmpArr[third++] = data[left++];
		}
		while (tmp <= right) { // 将中间数组中的内容复制回原数组
			data[tmp] = tmpArr[tmp++];
		}
		// System.out.println(Arrays.toString(data));
	}
}

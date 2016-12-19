package com.tiantian.algorithms;
/**
 * �鲢����
 * �鲢����ʱ�䣺O(N*logN)
�Ȳ��������ö�
�����������10000����������N^2����100000000����N*logN����40000
����鲢������Ҫ40�룬����������Ҫ��28Сʱ
�鲢�����˼����ǰ�һ������ֳ����룬����ÿһ�룬Ȼ����merge���������������鲢��һ���������顣
Ȼ�󲻶ϵĵݹ���ȥ������
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
	 * ��������left��right��Χ������Ԫ�ؽ��й鲢���� data ���������� left ����������ĵ�һ��Ԫ������ right
	 * ��������������һ��Ԫ������
	 */
	private void recMergeSort(int[] data, int left, int right) {
		if (left < right) {
			int center = (left + right) / 2; // �ҳ��м�����
			recMergeSort(data, left, center); // �����������еݹ�
			recMergeSort(data, center + 1, right); // ���ұ�������еݹ�
			merge(data, left, center, right); // �ϲ�

		}
	}

	/*
	 * ������������й鲢���鲢ǰ���������Ѿ����򣬹鲢����Ȼ���� data ������� left ������ĵ�һ��Ԫ�ص����� center
	 * ����������һ��Ԫ�ص�������center+1���������һ��Ԫ�ص����� right ����������һ��Ԫ�ص�����
	 */
	private void merge(int[] data, int left, int center, int right) {
		int[] tmpArr = new int[data.length];
		int mid = center + 1;
		int third = left; // third��¼�м����������
		int tmp = left;
		while (left <= center && mid <= right) {
			if (data[left] < data[mid]) { // ������������ȡ����С�ķ����м�����
				tmpArr[third++] = data[left++];
			} else {
				tmpArr[third++] = data[mid++];
			}
		}
		while (mid <= right) { // ʣ�ಿ�����η����м�����
			tmpArr[third++] = data[mid++];
		}
		while (left <= center) {
			tmpArr[third++] = data[left++];
		}
		while (tmp <= right) { // ���м������е����ݸ��ƻ�ԭ����
			data[tmp] = tmpArr[tmp++];
		}
		// System.out.println(Arrays.toString(data));
	}
}

package project.main;

import project.object.ListArray;

import java.util.ArrayList;
import java.util.List;

public class MergeSort {
    public static void addThreadSort(ListArray array) {
        array.setStartTime(System.currentTimeMillis());
        List<Thread> threads = new ArrayList<>();

        int arraySize = array.getArray().length;
        int arrayThread = array.getThread();

        boolean isInteger = arraySize % arrayThread == 0;
        int size = isInteger ? arraySize / arrayThread : arraySize / (arrayThread - 1);
        size = size < arrayThread ? arrayThread : size;

        for (int i = 0; i < arraySize; i+= size) {
            int start = i;
            int end = (arraySize - i) < size ? (i + arraySize - 1) : (i + size - 1);

            SortThreads temp = new SortThreads(array.getArray(), start, end);
            threads.add(temp);
        }

        for (Thread temp : threads) {
            try {
                temp.join();
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }

        for (int i = 0; i < arraySize; i += size) {
            int mid = i == 0 ? 0 : (i - 1);
            int end = (arraySize - i) < size ? (i + arraySize - 1) : (i + size - 1);

            merge(array.getArray(), 0, mid, end);
        }

        array.setEndTime(System.currentTimeMillis());
    }

    private static class SortThreads extends Thread {
        public SortThreads(int array[], int start, int end) {
            super(() -> {
                MergeSort.mergeSort(array, start, end);
            });

            this.start();
        }
    }

    public static void mergeSort(int array[], int start, int end) {
        if (start < end) {
            int mid = (start + end) / 2;

            mergeSort(array, start, mid);
            mergeSort(array, mid + 1, end);

            merge(array, start, mid, end);
        }
    }

    public static void merge(int array[], int start, int mid, int end) {
        int temp[] = new int[(end - start + 1)];

        int i = start, j = mid + 1, k = 0;

        while (i <= mid && j <= end) {
            if (array[i] <= array[j]) {
                temp[k] = array[i];
                i++;
            } else {
                temp[k] = array[j];
                j++;
            }
            k++;
        }

        while (i <= mid) {
            temp[k] = array[i];
            i++;
            k++;
        }

        while (j <= end) {
            temp[k] = array[j];
            j++;
            k++;
        }

        for (i = start, k = 0; i <= end; i++, k++) {
            array[i] = temp[k];
        }
    }
}

package project.object;

import java.util.ArrayList;
import java.util.List;

public class ListArray {

    private int array[];
    private int thread;
    private long startTime;
    private long endTime;


    public ListArray(int size, int thread) {
        setArray(size);

        setThread(thread);

        setStartTime(0);
        setEndTime(0);
    }

    /* Setter */
    public void setArray(int size) {
        this.array = new int[size];
    }
    public void setThread(int thread) {
        this.thread = thread;
    }
    public void setStartTime(long time) {
        this.startTime = time;
    }
    public void setEndTime(long time) {
        this.endTime = time;
    }
    public void setElementByIndex(int index, int value) {
        this.array[index] = value;
    }

    /* Getter */
    public int[] getArray() {
        return this.array;
    }
    public int getThread() {
        return this.thread;
    }
    public long getStartTime() {
        return this.startTime;
    }
    public long getEndTime() {
        return this.endTime;
    }

    @Override
    public String toString() {
        int array[] = this.getArray();
        String arrayString = "[";

        for (int i = 0; i < array.length; i++) {
            if (i < (array.length - 1)) {
                arrayString += array[i] + ", ";
            } else {
                arrayString += array[i];
            }
        }
        arrayString += "]";

        return "[Thread: " + this.getThread() + "] Time: (Run: " + (this.getEndTime() - this.getStartTime()) + " | Start: " + this.getStartTime() + " | End: " + this.getEndTime() + ")\n[Thread: " + this.getThread() + "] Array: " + arrayString;
    }

    public void printRunTime() {
        System.out.println("[Thread: " + this.getThread() + "]: " + (this.getEndTime() - this.getStartTime()) + "ms");
    }
}

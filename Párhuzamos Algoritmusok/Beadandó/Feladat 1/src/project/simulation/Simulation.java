package project.simulation;

import project.main.MergeSort;
import project.object.ListArray;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Simulation {
    private static int THREAD_COUNT = 4;

    public static void startSimulation(int arraySize) {
        int i;
        Random rand = new Random();
        List<ListArray> list = new ArrayList<>();

        /* Init Array */
        for (i = 0; i < THREAD_COUNT; i++) {
            list.add(new ListArray(arraySize, (int)Math.pow(2, i)));
        }

        for (i = 0; i < arraySize; i++) {
            int randNum = rand.nextInt(arraySize + (arraySize - 1) - (arraySize - 1));

            for (int j = 0; j < THREAD_COUNT; j++) {
                list.get(j).setElementByIndex(i, randNum);
            }
        }

        /* Merge */
        for (i = 0; i < THREAD_COUNT; i++) {
            MergeSort.addThreadSort(list.get(i));
        }

        /* Print */
        System.out.println("============= [[ " + arraySize + " ]] =============");
        /*
        System.out.println(list.get(0).toString());
        System.out.println(list.get(1).toString());
        System.out.println(list.get(2).toString());
        System.out.println(list.get(3).toString());
        */
        list.get(0).printRunTime();
        list.get(1).printRunTime();
        list.get(2).printRunTime();
        list.get(3).printRunTime();
        System.out.println("\n");
    }
}

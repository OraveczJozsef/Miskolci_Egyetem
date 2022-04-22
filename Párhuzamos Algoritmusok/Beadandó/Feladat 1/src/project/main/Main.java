package project.main;

import project.simulation.Simulation;

public class Main {
    public static void main(String[] args) {
        for (int i = 0; i <= 200000; i = i + 10000) {
            Simulation.startSimulation(i);
        }
    }
}

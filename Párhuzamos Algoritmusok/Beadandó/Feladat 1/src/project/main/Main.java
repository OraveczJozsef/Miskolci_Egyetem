package project.main;

import project.simulation.Simulation;

public class Main {
    public static void main(String[] args) {
        Simulation.startSimulation(10000);
        //for (int i = 200000; i >= 0; i -= 10000) {
        //for (int i = 0; i <= 200000; i += 10000) {
        for (int i = 0; i <= 2000000; i += 100000) {
            Simulation.startSimulation(i);
        }
    }
}

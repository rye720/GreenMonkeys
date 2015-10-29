/**
 * @author The Green Monkeys Inc.
 */

import java.util.*;

public class Driver {
    
    public static void main(String[] args){
        GeneticAlgorithm ga = new GeneticAlgorithm();
        GAUtils gUtils = new GAUtils();
        
        //make up a couple sets of genes
        int[] b1genes = {9,9,9,9};
        int[] b2genes = {7,2,1,6};
        int[] b3genes = {5,1,7,7};
        int[] b4genes = {1,2,2,5};
        List<Animal> population = new ArrayList<Animal>();
            
        //instantiate a couple animals        
        Animal bear1 = new Animal("Ursus americanus",b1genes,'m', 0);
        Animal bear2 = new Animal("Ursus americanus",b2genes,'f', 0);
        Animal bear3 = new Animal("Ursus americanus",b3genes,'m', 0);
        Animal bear4 = new Animal("Ursus americanus",b4genes,'f', 0);
        Collections.addAll(population, bear1, bear2, bear3, bear4);
        ga.EvalPopFitness(population);
        //run some methods with em
        System.out.println("Population Before Crossover: ");
        gUtils.PopOut(population);
        population = ga.Combination(population);
        System.out.println("Population After Crossover: ");
        gUtils.PopOut(population);
        System.out.println("Population After Sort: ");
        population = gUtils.ranking(population);
        gUtils.PopOut(population);
        //System.out.println("Parents");
        //System.out.println(bear1);
        //System.out.println(bear2);
        //System.out.println("Child");
        //System.out.println(bear3);
        
    }
}

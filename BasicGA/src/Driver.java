
/**
 * @author The Green Monkeys Inc.
 */
import java.util.*;

public class Driver {

    public static void main(String[] args) {
        GeneticAlgorithm ga = new GeneticAlgorithm();
        GAUtils gUtils = new GAUtils();
        Visuals v = new Visuals();
        Scanner s = new Scanner(System.in);
        int generations;
        int animalNum;
        int geneNum;
        //Generate popualtion, get their fitness, and rank them
        System.out.println("How many genes? ");
        geneNum = s.nextInt();
        System.out.println("How many animals? ");
        System.out.println("If visual mode, must be at least 5");
        animalNum = s.nextInt();
        List<Animal> population = ga.GeneratePop("Ursus americanus", animalNum, geneNum, 0);
        ga.EvalPopFitness(population);
        population = gUtils.ranking(population);

        System.out.println("Visual mode? y or n: ");
        String str = s.next();
        if (str.equalsIgnoreCase("y")) {
            //run visual mode
            v.init(population);
        } else {
            //run in console
            System.out.println("How many generations? ");
            generations = s.nextInt();
            //Run the GA for how many generations specified 
            for (int i = 0; i < generations; i++) {
                population = ga.Combination(population, population.size());
                population = gUtils.ranking(population);
                population = ga.Selection(population, population.size() - 1);
                //System.out.println("Generation: " + (i+1));
                //gUtils.PopOut(population);
            }
            gUtils.PopOut(population);
        }
    }
}

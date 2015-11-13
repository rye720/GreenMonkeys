
// Should probably use a package name; Java assumes that things are in packages and the use of the
// default (none) package is discouraged

/**
 * @author The Green Monkeys Inc.
 */
import java.util.*;

import org.apache.commons.cli.CommandLine;
import org.apache.commons.cli.CommandLineParser;
import org.apache.commons.cli.DefaultParser;
import org.apache.commons.cli.Option;
import org.apache.commons.cli.OptionBuilder;
import org.apache.commons.cli.Options;
import org.apache.commons.cli.ParseException;

public class Driver {

  // Usually it's better to instantiate your object and run a method on the objec rather than doing
  // all of your work from the main() method.
  //
  void run() {
  }

    private static final String ARG_GENE = "g";
    private static final String ARG_ANIMAL = "a";

    public static void main(String[] args) throws ParseException {




        GeneticAlgorithm ga = new GeneticAlgorithm();
        GAUtils gUtils = new GAUtils();
        Visuals v = new Visuals();
        Scanner s = new Scanner(System.in);
        int generations;
        int animalNum;
        int geneNum;
        //Generate popualtion, get their fitness, and rank them
        //
        // Bleh; you'll find it much easier to script this if you do command-line flags instead of
        // interactive commands.
        // System.out.println("How many genes? ");
        // geneNum = s.nextInt();
        // System.out.println("How many animals? ");
        // animalNum = s.nextInt();
        
        Options options = new Options();
        options.addOption(
            Option.builder(ARG_GENE)
                .longOpt("genes")
                .hasArg()
                .type(Integer.class)
                .desc("How many genes to include")
                .build());
        options.addOption(
            Option.builder(ARG_ANIMAL)
                .longOpt("animals")
                .hasArg()
                .type(Integer.class)
                .desc("How many animals to include")
                .build());

        CommandLineParser parser = new DefaultParser();
        CommandLine commandLine = parser.parse(options, args);

        if (!commandLine.hasOption(ARG_GENE)) {
          System.err.format("Argument \"%s\" required.\n", ARG_GENE);
          System.exit(-1);
        }
        if (!commandLine.hasOption(ARG_ANIMAL)) {
          System.err.format("Argument \"%s\" required.\n", ARG_ANIMAL);
          System.exit(-2);
        }

        animalNum = Integer.parseInt(commandLine.getOptionValue(ARG_ANIMAL));
        geneNum = Integer.parseInt(commandLine.getOptionValue(ARG_GENE));

        List<Animal> population = ga.GeneratePop("Ursus americanus", animalNum, geneNum, 0);
        ga.EvalPopFitness(population);
        population = gUtils.ranking(population);

        System.out.println("Visual mode? y or n: ");
        String str = s.next();
        if (str.equalsIgnoreCase("y")) {
            v.init(population);
        } else {
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

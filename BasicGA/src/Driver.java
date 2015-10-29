/**
 * @author The Green Monkeys Inc.
 */


public class Driver {
    
    public static void main(String[] args){
        GeneticAlgorithm ga = new GeneticAlgorithm();   
        
        //make up a couple sets of genes
        int[] b1genes = {4,3,7,8};
        int[] b2genes = {7,2,1,6};
        
        //instantiate a couple animals        
        Animal bear1 = new Animal("Ursus americanus",b1genes,'m');
        Animal bear2 = new Animal("Ursus americanus",b2genes,'f');
        
        //run some methods with em
        Animal bear3 = ga.Combination(bear1, bear2);
        System.out.println("Parents");
        System.out.println(bear1);
        System.out.println(bear2);
        System.out.println("Child");
        System.out.println(bear3);
        
    }
}

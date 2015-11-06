
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;
import java.util.List;
import java.util.ArrayList;

public class Visuals extends JPanel {

    protected JFrame frame;
    protected JButton button = new JButton("Next Generation");
    protected JLabel label = new JLabel();
    protected List<Animal> population = new ArrayList<>();
    protected GeneticAlgorithm ga = new GeneticAlgorithm();
    protected GAUtils gUtils = new GAUtils();
    protected int generation = 1;

    public Visuals() {

    }

    public void init(List<Animal> pop) {
        JFrame f = new JFrame("Basic G.A.");
        f.setLocationRelativeTo(null);
        f.setDefaultCloseOperation(frame.EXIT_ON_CLOSE);
        f.setSize(480, 600);
        this.add(button);
        f.add(this);
        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                population = ga.Combination(population, population.size());
                population = gUtils.ranking(population);
                population = ga.Selection(population, population.size() - 1);
                repaint();
                generation++;
            }
        });
        f.setResizable(false);
        f.setVisible(true);
        population = pop;
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.drawString("Generation: " + Integer.toString(generation), 10, 15);
        g.drawString("Top 5 Animals: ", 10, 30);
        g.drawString("1: " + population.get(0).tag, 10, 40);
        g.drawString("2: " + population.get(1).tag, 10, 50);
        g.drawString("3: " + population.get(2).tag, 10, 60);
        g.drawString("4: " + population.get(3).tag, 10, 70);
        g.drawString("5: " + population.get(4).tag, 10, 80);
        g.drawString("Animals: " + population.size(), 10, 100);
        g.drawOval(346, 346, 16, 16);
        for (int i = 0; i < population.size(); i++) {
            g.fillOval((int) population.get(i).position.x,
                    (int) population.get(i).position.y, 8, 8);
        }
    }

}

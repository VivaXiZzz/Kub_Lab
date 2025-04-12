import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
public class MyPanel extends JPanel {
    JLabel l1,l2,l3;
    JTextField f1,f2,f3;
    JTextArea a;
    JButton b1,b2,b3,b4;
    MyPanel(){
    l1 = new JLabel("name");
    l2 = new JLabel("num");
    l3 = new JLabel("yo");
    f1 = new JTextField();
    f2 = new JTextField();
    f3 = new JTextField();
    f1.setColumns(10);
    f2.setColumns(10);
    f3.setColumns(10);
    b1= new JButton("add");
    b2= new JButton("remove");
    b3= new JButton("findByAtr");
    b4= new JButton("Sort");
    }
}

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class MyPanel extends JPanel
{
    private JLabel l1, l2, l3, l4, l5, l6, l7;
    private JTextField t1, t2, t3, t4, t5, t6, t7;
    private JButton b1, b2, b3, b4;
    private JTextArea ta1, ta2;
    private AutoArList arl;

    MyPanel()
    {
        l1 = new JLabel("Номер");
        l2 = new JLabel("Марка");
        l3 = new JLabel("Пробег");
        l4 = new JLabel("Цена");
        l5 = new JLabel("Год выпуска");
        l6 = new JLabel("Объём двигателя");
        l7 = new JLabel("Номер");
        t1 = new JTextField();
        t2 = new JTextField();
        t3 = new JTextField();
        t4 = new JTextField();
        t5 = new JTextField();
        t6 = new JTextField();
        t7 = new JTextField();
        t1.setColumns(8);
        t2.setColumns(8);
        t3.setColumns(6);
        t4.setColumns(6);
        t5.setColumns(5);
        t6.setColumns(6);
        t7.setColumns(8);
        b1 = new JButton("Добавить");
        b2 = new JButton("Удалить");
        b3 = new JButton("Сортировать");
        b4 = new JButton("Вывод");
        ta1 = new JTextArea();
        ta2 = new JTextArea();
        ta1.setColumns(47);
        ta1.setRows(15);

        add(l1);
        add(t1);
        add(l2);
        add(t2);
        add(l3);
        add(t3);
        add(l4);
        add(t4);
        add(l5);
        add(t5);
        add(l6);
        add(t6);

        add(b1);
        add(ta1);

        add(l7);
        add(t7);
        add(b2);

        add(b3);

        add(b4);
        add(ta2);

        arl = new AutoArList();
        MyListener1 m1 = new MyListener1();
        b1.addActionListener(m1);
        MyListener2 m2 = new MyListener2();
        b2.addActionListener(m2);
        MyListener4 m4 = new MyListener4();
        b4.addActionListener(m4);
    }

    class MyListener1 implements ActionListener
    {
        @Override
        public void actionPerformed(ActionEvent e)
        {
            String nomer = t1.getText();
            String marka = t2.getText();
            int probeg = Integer.parseInt(t3.getText());
            int price = Integer.parseInt(t4.getText());
            int year = Integer.parseInt(t5.getText());
            int obyom = Integer.parseInt(t6.getText());
            Auto a = new Auto(nomer, marka, probeg, price, year, obyom);
            arl.add(a);
            t1.setText("");
            t2.setText("");
            ta1.setText(arl.toString());
        }
    }

    class MyListener2 implements ActionListener
    {
        @Override
        public void actionPerformed(ActionEvent e)
        {
            String nomer = t7.getText();
            arl.del(nomer);
            ta1.setText(arl.toString());
            t7.setText("");
        }
    }

    class MyListener4 implements ActionListener
    {
        boolean isChetCifra(String s)
        {
            for(int i=0;i<s.length();++i)
            {
                char a = s.charAt(i);
                if (a>='0' && a<='9' && a%2==0) return true;
            }
            return false;
        }

        @Override
        public void actionPerformed(ActionEvent e)
        {
            String str = "";
            ArrayList<Auto> a = new ArrayList<>(arl.getA());
            int n = a.size();
            a.sort((a1, a2)->a1.getMarka().compareTo(a2.getMarka()));
            for(int i=0;i<n;++i)
                if(!isChetCifra(a.get(i).getNomer()) && (i==0 || !a.get(i).getMarka().equalsIgnoreCase(a.get(i-1).getMarka())))
                    str += a.get(i).toString();
            ta2.setText(str);
            ta1.setText(arl.toString());
        }
    }
}

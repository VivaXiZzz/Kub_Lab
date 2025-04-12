import javax.swing.*;

public class MyFrame extends JFrame
{
    MyFrame()
    {
        setSize(1200, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        MyPanel p = new MyPanel();
        add(p);
        setVisible(true);
    }
}

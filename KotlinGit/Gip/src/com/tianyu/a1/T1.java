package com.tianyu.a1;

import javax.swing.SwingUtilities;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class T1 extends JFrame {
    private JButton
        b1 = new JButton("Button 1"),
        b2 = new JButton("Button 2");
    private JTextField jTextField = new JTextField("",20);
    private JTextArea jTextArea = new JTextArea(20,20);
    private ActionListener bl = new ActionListener(){
        public void actionPerformed(ActionEvent e){
            String name = ((JButton)e.getSource()).getText();
            jTextField.setText(name+name+name+name);
            jTextArea.setText(name+"\n"+name);
        }
    };
    public T1(){
        b1.addActionListener(bl);
        b2.addActionListener(bl);
        setLayout(new FlowLayout());
        add(b1);
        add(b2);
        add(jTextField);
        add(jTextArea);
    }
    public static void run(JFrame jf, final int width,final int height) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run(){
                jf.setVisible(true);
                jf.setDefaultCloseOperation(EXIT_ON_CLOSE);
                jf.setBounds((1920-width)/2,(1080-height)/2,width, height);
                jf.setTitle(jf.getClass().getSimpleName());
            }
        });
    }

    public static void main(String[] args) {
        run(new T1(),1000,800);
    }
}
